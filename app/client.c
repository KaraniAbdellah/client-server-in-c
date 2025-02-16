// Start Code The Client Side
/*
    filename server_ip_addr portno
*/
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
    if (argc < 3) {
        printf("Port Number or/and Server IP Addr not provided. Programm terminated\n");
        exit(0);
    }

    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[255]; // message must contain just 254 character

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("error opening Socket.");

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        error("Error, No Such Host");
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Connection Failed");
    }

    while (1) {
        bzero(buffer, 255);
        fgets(buffer, 255, stdin);
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) error("Error on Writing");
        

        bzero(buffer, 255);
        n = read(sockfd, buffer, 255);
        if (n < 0) error("Error on Reading");

        printf("Server: %s", buffer);

        int i = strncmp("Bye", buffer, 3);
        if (i == 0) break;
    }
    
    close(sockfd);





    return 0;
}
