#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>

int main()
{
    int source, copy;
    char buffer[100];
    int bytes;

    source = open("C:\\Users\\rehan\\Downloads\\program 2 txt.txt", O_RDONLY);

    if (source == -1)
    {
        printf("Unable to open source file.\n");
        return 1;
    }

    copy = open("C:\\Users\\rehan\\Downloads\\copy.txt",
                O_WRONLY | O_CREAT | O_TRUNC,
                S_IREAD | S_IWRITE);

    if (copy == -1)
    {
        printf("Unable to create destination file.\n");
        close(source);
        return 1;
    }

    while ((bytes = read(source, buffer, sizeof(buffer))) > 0)
    {
        write(copy, buffer, bytes);
    }

    close(source);
    close(copy);

    printf("File copied successfully.\n");

    return 0;
}
