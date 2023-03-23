#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Create a 5-byte character array
    char buffer[5];

    // Write "omkar" to the buffer
    buffer[0] = 'o';
    buffer[1] = 'm';
    buffer[2] = 'k';
    buffer[3] = 'a';
    buffer[4] = 'r';

    // Write the buffer to a binary file
    ofstream outfile("unOrderedMap", ios::out | ios::binary);
    outfile.write(buffer, sizeof(buffer));
    outfile.close();

    return 0;
}

