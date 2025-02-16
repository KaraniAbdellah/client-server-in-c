// Start Code The Server Side
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>


void error(const char *msg) {
    perror(msg);
    exit(1);
}


int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Port Number not provided. Programm terminated\n");
        exit(0);
    }

    int sockfd, newsockfd, portno;
    char buffer[255];// message must contain just 254 character

    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;


    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("error opening Socket.");
    bzero((char *) &serv_addr,  sizeof(serv_addr));
    portno = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Binding Failed");
    }

    listen(sockfd, 5); // number of client that can connect to server at the time

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

    if (newsockfd < 0) {
        error("Error Can Not Listen");
    }


    while(1) {
        bzero(buffer, 255);
        int n = read(newsockfd, buffer, 255);
        if (n < 0) error("Error on Reading.");
        printf("Client: %s", buffer);
        bzero(buffer, 255);
        fgets(buffer, 255, stdin);
        
        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0) error("Error on Writing.");

        int i = strncmp("Bye", buffer, 3);
        if (i == 0) break;
    }

    close(newsockfd);
    close(sockfd);
    return 0;

}



