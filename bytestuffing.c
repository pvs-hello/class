#include <stdio.h>
#include <string.h>

void byteStuffing(char data[])
{
    char FLAG = '~';
    char ESC = '\\';
    printf("Framed Data: %c", FLAG);

    for (int i = 0; i < strlen(data); i++)
    {
        if (data[i] == FLAG || data[i] == ESC)
        {
            printf("%c", ESC);
        }
        printf("%c", data[i]);
    }

    printf("%c\n", FLAG);
}

int main() {
    char data[] = "Hello~World\\Test";
    byteStuffing(data);
    return 0;
}
