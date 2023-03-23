#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>

using namespace std;
#define FILENAME argv[1]
int main(int argc, const char *argv[] )
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        std::cerr << "Error creating socket" << std::endl;
        return 1;
    }

    sockaddr_in server_addr, client_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Error binding socket" << std::endl;
        return 1;
    }

    listen(sockfd, 1);
    std::cout << "Server listening on port 8080" << std::endl;

    socklen_t client_len = sizeof(client_addr);
    int client_sockfd = accept(sockfd, (sockaddr*)&client_addr, &client_len);
    if (client_sockfd < 0) {
        std::cerr << "Error accepting client connection" << std::endl;
        return 1;
    }

//    std::string filename = "example.txt";
    std::string filename = FILENAME;
    if (send(client_sockfd, filename.c_str(), filename.length() + 1, 0) < 0) {
        std::cerr << "Error sending filename to client" << std::endl;
        return 1;
    }
    else 
    {
    	cout<<"File name send ->"<<FILENAME<<endl;
    }

    close(client_sockfd);
    close(sockfd);

    return 0;
}
