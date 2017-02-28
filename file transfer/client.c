/***********************************************************************
Author: Sesha Susmitha Yellamraju
Desc  : TCP client that logs in to server and downloads required file
************************************************************************/

#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

/* Error Handling */

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    char flag[256];
    char filenum[100],filepath[50];
    char downloadfilename[100];
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];
    //char buffer1[256];
    char c;
    int i;

    if (argc < 3)
    {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }

    portno = atoi(argv[2]);

    /* Creating a socket */

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    /* Checking if a socket is created and printing an error in case if it is not created */

    if (sockfd < 0)
        error("ERROR opening socket");

    /* Getting server name from run time arguments */

    server = gethostbyname(argv[1]);

    /* Printing error message if mentioned host is not known */

    if (server == NULL)
    {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    /* Initializing the socket structure */

    serv_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);

    serv_addr.sin_port = htons(portno);

    /* Connecting to server and printing error if not connected */

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");


    while(read(sockfd,flag,255))
    {
        /* Reading message from socket to enter username and password*/

        if(!strcmp(flag,"true"))
        {
            n = read(sockfd,buffer,255);
            if (n < 0)
                 error("ERROR reading from socket");
            printf("%s\n",buffer);

        /* Entering user name and sending it to server*/
            bzero(buffer,256);
            fgets(buffer,255,stdin);
            n = write(sockfd,buffer,strlen(buffer));

        /*Entering password and writing it to server*/

            char *buffer1=getpass("Password:");
            n = write(sockfd,buffer1,strlen(buffer1));
        }

        else if(!strcmp(flag,"false"))
        {
            printf("\nDear client, Your login is success\n\n");
            read(sockfd,buffer,256);
            printf("%s",buffer);

            /*Sending file number to server */

            bzero(filenum,9);
            fgets(filenum,9,stdin);
            n = write(sockfd,filenum,strlen(filenum));

        /* File Transfer */

        while(read(sockfd,flag,255))
       {
            FILE *fp;
            char buffernew[256];
            char nfile[10];
            read(sockfd,buffernew,100);
            if(!strcmp(flag,"true"))
            {
                if(buffernew[0]=='\0')
                {
                    printf("couldn't read from the file\n");
                }
                else
                {
                    filenum[strlen(filenum)-1]='\0';
                    char *absolute_path = NULL;//"Downloads/";
                    char newfile[100];
                    sprintf(newfile,"newfile%s.txt",filenum);
                    absolute_path = malloc(strlen("Downloads/")
                                           + strlen(newfile));
                    strncat(absolute_path, "Downloads/", strlen("Downloads/"));
                    strncat(absolute_path, newfile, strlen(newfile));
                    fp=fopen(absolute_path,"w");
                    printf("You selected file%s\n",filenum);
                    fprintf(fp,"%s",buffernew);
                    printf("The file was received successfully\n");
                    printf("The new file created is newfile%s.txt\n\n",filenum);

                }
            }
            else
            {
                printf("Invalid file selection\n");
                bzero(buffer,256);
                n = read(sockfd,buffer,255);
                if (n < 0)
                     error("ERROR reading from socket");
                printf("%s\n",buffer);
             }
        }
    }
    else
    {
        printf("%s",flag);
    }
}

 /* Closing socket connection */

    close(sockfd);
    return 0;
}
