#include <iostream>
#include <fstream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#define PORT 8080

using namespace std;
int main(int argc, char const *argv[]) 
{
	int sock = 0, valread;
	struct sockaddr_in serv_addr;
	char buffer[1024] = {0};

	// Create a socket
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	{
		std::cerr << "Socket creation error" << std::endl;
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	// Convert IPv4 and IPv6 addresses from text to binary form
	if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) 
	{
		std::cerr << "Invalid address / Address not supported" << std::endl;
		return -1;
	}

	// Connect to the server
	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
	{
		std::cerr << "Connection Failed" << std::endl;
		return -1;
	}

	// Receive the file size from the server
	off_t file_size;
	valread = recv(sock, &file_size, sizeof(off_t), 0);
	if (valread == -1) 
	{
		std::cerr << "Error receiving file size" << std::endl;
		return -1;
	}

	// Open a file for writing
	std::ofstream outfile("received_file.bin", std::ios::binary);

	// Receive the file from the server
	off_t total_bytes_read = 0;
	while (total_bytes_read < file_size) 
	{
		valread = recv(sock, buffer, 1024, 0);
		if (valread == -1) 
		{
			std::cerr << "Error receiving file" << std::endl;
			return -1;
		}
		total_bytes_read += valread;
		outfile.write(buffer, valread);
	}

	// Close the file and socket
	outfile.close();
	close(sock);

	return 0;
}
