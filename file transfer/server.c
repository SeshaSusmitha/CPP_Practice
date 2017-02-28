/***********************************************************************
Author: Sesha Susmitha Yellamraju
Desc  : TCP server that authenticates client and performs file transfer
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "sha1.h"
#include <gcrypt.h>

#define NUM_OF_USERS 3
#define MAX_RETRIES 3
#define NUM_TRIAL 3

const char *usernames[NUM_OF_USERS];
 char *passwords[NUM_OF_USERS];

const char *file_names[4];

char *sha1(char *);


typedef int bool;
#define true 1
#define false 0

bool success;

int trial =0;

int
get_username_and_out_passwords(char* filename, char *buffer, char *buffer1);

/* Method for error handling */

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
     int sockfd, newsockfd, portno,n,c,s;
     socklen_t clilen;
     char file[10],newfile[10];
     char buffer[256];
     char username[16];
     char password[16];
     char buffer1[256];
     struct sockaddr_in serv_addr, cli_addr;
     int file_index;

    /* Printing error if port num is not provided */

     if (argc < 2)
     {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }

     file_names[0] = "DummyFile";
     file_names[1] = "file1.txt";
     file_names[2] = "file2.txt";
     file_names[3] = "file3.txt";


    /* Creating a socket */

     sockfd = socket(PF_INET, SOCK_STREAM, 0);
     printf("\nSocket Created\n");

    /* Checking if a socket is created and printing an error in case if it is not created */

     if (sockfd < 0)
        error("ERROR opening socket");

     bzero((char *) &serv_addr, sizeof(serv_addr));

     portno = atoi(argv[1]);

    /* Printing the port number */

     printf("Running on port %d \n\n", portno);

    /* Initializing the socket structure */

     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);

    /* Binding host address */

     if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    /* Listening to client */

     listen(sockfd,5);

     clilen = sizeof(cli_addr);

    /* Accepting connection form client */
    while(1)
    {
         newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr, &clilen);

         if (newsockfd < 0)
            error("ERROR on accept");

         bzero(buffer,256);
         bzero(buffer1,256);

        /*Acknowledge client that message is recieved */

         write(newsockfd,"true",64);
         n = write(newsockfd,"\nPlease enter your username and password\n",64);

         if (n < 0)
            error("ERROR writing to socket");
        printf("Client entered\n");
        n = read(newsockfd,buffer,255);
        printf("username:%s",buffer);
        n = read(newsockfd,buffer1,255);
        printf("password:%s\n",buffer1);

        /* Function call to authenticate credentials */

        char *filename="usernamepass.txt";
        get_username_and_out_passwords(filename,buffer,buffer1) ;

    /* Checking the no of trial to initiate file transfer */

    while((trial>0) && (trial < 3) && (!success))
    {
        printf("Client is in his trial - %d\n",trial);
        write(newsockfd,"true",64);
        write(newsockfd,"\nInvalid username/password..Please try again\n",64);
        read(newsockfd,buffer,255);
        printf("username:%s",buffer);
        read(newsockfd,buffer1,255);
        printf("password:%s\n",buffer1);

        get_username_and_out_passwords(filename,buffer,buffer1) ;
    }

    /* Sending error if user has exceeded maximum login attempts */

     if(trial>=3)
    {
        printf("Exceeded maximum limit....\n");
        write(newsockfd,"Exceeded maximum limit\n  ",64);
        exit(0);
    }

    /* Initiating file transfer */

    else if(((trial ==0) && (success))  || ((trial < 3) && (success)))
    {
        write(newsockfd,"false",64);
        write(newsockfd,"Please select one file from below to download.....\n1.file1\n2.file2\n3.file3\n ",256);
        read(newsockfd,file,9);
        file[1]='\0';
        file_index = atoi(file);
        printf("file_index - %d\n",file_index);

        if((file_index>=1) && (file_index<=3))
        {
            printf("Client selected %s\n",file_names[file_index]);

            FILE *f;
            long lSize;
            char *buffernew;
            f = fopen ( file_names[file_index] , "rb" );
            //printf("index:%d\n",file_index);
            if( !f ) printf("No such file\n"),exit(1);
            fseek( f , 0L , SEEK_END);
            lSize = ftell( f );
            rewind( f );

            /* allocate memory for entire content */

            buffernew = calloc( 1, lSize+1 );
            if( !buffernew ) fclose(f),fputs("memory alloc fails",stderr),exit(1);

            /* copy the file into the buffer */
            if( 1!=fread( buffernew , lSize, 1 , f) )

              fclose(f),free(buffernew),fputs("entire read fails",stderr),exit(1);

            write(newsockfd,"true",100);
            write(newsockfd,buffernew,strlen(buffernew));
            printf("The file was sent successfully\n");

            fclose(f);
            free(buffernew);

        }
        else
        {
            printf("Client has selected invalid file input..Sending message to client\n");
            write(newsockfd,"false",100);
            write(newsockfd,"Filename is invalid",64);

        }
    }
    close(newsockfd);

}

    /* Closing sockets */

        close(sockfd);

     return 0;
}

    /* User Autentication method */

int
get_username_and_out_passwords(char* filename,char *buffer, char *buffer1)
{

    char line[200];
    FILE *fp;
    int a,b,j,m;
    char buf[100],buf1[100];
    fp=fopen(filename,"r");
    if(!fp)
    {
        perror("could not find the file");
        exit(0);
    }
    int k = 0;
    for (int i =0 ; fgets ( line, 200, fp ) != NULL ; i++)
    {
        int index = strlen(line)-1;
        if (line[index] == '\n')
        {
            line[index] = '\0';
        }

        if(i%2 == 0)
        {
            usernames[k] = strdup(line);
        }
        else
        {
            passwords[k++] = strdup(line);
        }
    }

    for(j = 0; j < strlen(buffer)-1; j++)
    {
        buf[j] = buffer[j];
    }
    for(m = 0; m < strlen(buffer1)-1; m++)
    {
        buf1[m] = buffer1[m];
    }


    for (int i=0; i<NUM_OF_USERS; i++ )
    {
        a = strcmp(buf,usernames[i]);
        char *m = sha1(buffer1);
       // printf("The SHA1 of client is: %s\n", m);
       // printf("Stored message digest is %s\n",passwords[i]);

        b = strcmp(m,passwords[i]);
        if((a==0) && (b==0))
            break;
    }

    printf("\nclient hash is %s\n\n",sha1(buffer1));

    if((a!=0) || (b!=0))
    {
            trial=trial+1;
            success=false;
            printf("Client entered invalid credentials\n");
            return trial;
    }
    else
    {
        success=true;
        printf("Client trial--%d\n",trial+1);
        printf("Client entered valid credentials\n");
        printf("\nSending message to client to select file to be downloaded\n");
        return trial;
    }
}

/* Method to calculate hash of the client password */

char *sha1( char *val )
{

   int msg_length = strlen( val );
   int hash_length = gcry_md_get_algo_dlen( GCRY_MD_SHA1 );
   unsigned char hash[ hash_length ];
   char *out = (char *) malloc( sizeof(char) * ((hash_length*2)+1) );
   char *p = out;
   gcry_md_hash_buffer( GCRY_MD_SHA1, hash, val, msg_length );
   int i;
   for ( i = 0; i < hash_length; i++, p += 2 ) {
      snprintf ( p, 3, "%02x", hash[i] );
   }

   return out;
}
