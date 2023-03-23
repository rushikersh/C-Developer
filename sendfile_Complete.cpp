#include <iostream>
#include <fstream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/sendfile.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 8080
//#define FILEPATH "example.txt"
#define FILEPATH argv[1]

int main(int argc, char const *argv[]) 
{
	int sockfd, newsockfd, filefd, addrlen, sent_bytes;
	struct sockaddr_in address;
	char buffer[1024];
	off_t offset;

	// Create socket file descriptor
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		std::cerr << "Error creating socket\n";
		return 1;
	}

	// Set server address and port
	std::memset(&address, 0, sizeof(address));
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	// Bind socket to address and port
	if (bind(sockfd, (struct sockaddr*)&address, sizeof(address)) < 0) {
		std::cerr << "Error binding socket to address and port\n";
		return 1;
	}

	// Listen for incoming connections
	if (listen(sockfd, 5) < 0) {
		std::cerr << "Error listening for incoming connections\n";
		return 1;
	}

	std::cout << "Server is listening on port " << PORT << "...\n";

	// Accept incoming connection
	addrlen = sizeof(address);
	newsockfd = accept(sockfd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
	if (newsockfd < 0) {
		std::cerr << "Error accepting incoming connection\n";
		return 1;
	}

	std::cout << "Server accepted incoming connection from " << inet_ntoa(address.sin_addr) << ":" << ntohs(address.sin_port) << "\n";

	// Open file to send
	filefd = open(FILEPATH, O_RDONLY);
	if (filefd < 0) {
		std::cerr << "Error opening file " << FILEPATH << "\n";
		return 1;
	}

	// Send file using sendfile system call
	offset = 0;
	sent_bytes = sendfile(newsockfd, filefd, &offset, 1024);
	while (sent_bytes > 0) {
		sent_bytes = sendfile(newsockfd, filefd, &offset, 1024);
	}

	if (sent_bytes < 0) {
		std::cerr << "Error sending file\n";
		return 1;
	}

	std::cout << "File sent successfully\n";

	// Close file and sockets
	close(filefd);
	close(newsockfd);
	close(sockfd);

	return 0;
}
