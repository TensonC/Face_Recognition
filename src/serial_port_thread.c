#include <serial_port_thread.h>

#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <fcntl.h>

#define USART_NAME "/dev/ttyXXX" 
#define USART_BAUD B9600

static int serial_config(int fd) {
    struct termios options;

    tcgetattr(fd,&options);

    cfsetispeed(&options,USART_BAUD);
    cfsetospeed(&options,USART_BAUD);

    options.c_cflag &= ~CSIZE;
    //size: 8
    options.c_cflag |= CS8;
    //parity: NONE
    options.c_cflag |= ~PARENB;
    options.c_cflag |= ~PARODD;
    //stop bit: 1
    options.c_cflag &= ~CSTOPB;

    cfmakeraw(&options);
    options.c_cflag |= (CLOCAL | CREAD);

    tcflush(fd,TCIFLUSH);
    tcsetattr(fd,TCSANOW,&options);

    return 0;
}

void is_pass_send(char is_pass) {
    int fd = open(USART_NAME,O_RDWR | O_NOCTTY);

    if(fd == -1) {
        perror("Open usart failed");
        return;
    }
    serial_config(fd);

    int len = write(fd,&is_pass,1);
    if(len < 0) {
        perror("Send failed");
    }

    close(fd);
    return;
}






