#include <stdio.h>

int main()
{
    char buffer[] = {0x01, 0x02, 0x03, 0x04};
    FILE *fp = fopen("unOrderedMap", "wb+");
    fwrite(buffer, sizeof(char), sizeof(buffer), fp);
    fclose(fp);
    return 0;
}

