#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void grep(const char *file_name, const char *search_text) {
    int fd = open(file_name, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    int n;
    while ((n = read(fd, buffer, BUFFER_SIZE)) > 0) {
        if (strstr(buffer, search_text) != NULL) {
            if (write(1, buffer, n) == -1) {  // Write to standard output
                perror("write");
                close(fd);
                exit(1);
            }
        }
    }

    if (n == -1) {
        perror("read");
        close(fd);
        exit(1);
    }

    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <file_name> <search_text>\n", argv[0]);
        exit(1);
    }

    grep(argv[2], argv[1]);

    return 0;
}
