#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {

    int fd;

    fd = open("/dev/hello",O_RDONLY);

    if ( fd < 0) {
        printf("Device file was not opened\n");
    }

    close(fd);

    fd = open("/dev/hello",O_WRONLY);

    if ( fd < 0) {
        printf("Device file was not opened\n");
    }

    close(fd);

        
    fd = open("/dev/hello",O_WRONLY);

    if ( fd < 0) {
        printf("Device file was not opened\n");
    }

    close(fd);
}
