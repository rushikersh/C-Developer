#include <iostream>
#include <string>

int main() {
    char filename[256] = "/tmpdata/workspace/Error/test";

    // Convert the filename string to a std::string
    std::string str(filename);

    // Find the position of the last forward slash in the string
    std::size_t pos = str.find_last_of("/");

    // Extract the substring after the last forward slash
    std::string substr = str.substr(pos + 1);

    // Print the extracted substring
    std::cout << substr << std::endl;

    return 0;
}

