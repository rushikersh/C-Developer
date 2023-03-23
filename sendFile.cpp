#include <sys/types.h>
#include <sys/sendfile.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#define PORT 8080

using namespace std;
int main(int argc, char *argv[]) 
{
	int sockfd, newsockfd, n;
	socklen_t clilen;
	struct sockaddr_in serv_addr, cli_addr;
	char buffer[1024];
	int filefd;
	off_t offset = 0;
	size_t remaining;
	ssize_t sent_bytes;

	// Create a socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) 
	{
		perror("ERROR opening socket");
		exit(1);
	}

	// Initialize socket structure
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(PORT);

	// Bind the host address
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
	{
		perror("ERROR on binding");
		exit(1);
	}

	// Start listening for the clients
	listen(sockfd, 5);
	clilen = sizeof(cli_addr);

	// Accept actual connection from the client
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
	if (newsockfd < 0) 
	{
		perror("ERROR on accept");
		exit(1);
	}

	// Open the binary file for reading
//	filefd = open("binaryfile", O_RDONLY);
	filefd = open(argv[1], O_RDONLY);
	if (filefd == -1) 
	{
		perror("Failed to open file");
		exit(1);
	}
	else 
	{
		cout<<"File open \n";
	}

	// Transfer the file data over the network
	remaining = lseek(filefd, 0, SEEK_END);
	lseek(filefd, 0, SEEK_SET);

	while (remaining > 0) {
		sent_bytes = sendfile(newsockfd, filefd, &offset, 1024);
		if (sent_bytes == -1) {
			perror("Error sending file");
			exit(1);
		}
		remaining -= sent_bytes;
	}

	close(filefd);
	close(newsockfd);
	close(sockfd);
	return 0;
}

