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
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~PARODD;
    //stop bit: 1
    options.c_cflag &= ~CSTOPB;

    cfmakeraw(&options);
    options.c_cflag |= (CLOCAL | CREAD);

    tcflush(fd,TCIFLUSH);
    if(tcsetattr(fd,TCSANOW,&options) < 0) {
        return -1;
    }

    tcdrain(fd);
    return 0;
}

void is_pass_send(int is_pass) {
    int fd = open(USART_NAME,O_RDWR | O_NOCTTY | O_NONBLOCK);
    char passed = (is_pass ? 'P' : 'U');

    if(fd == -1) {
        perror("Open usart failed");
        return;
    }

    fcntl(fd,F_SETFL,0);

    if(serial_config(fd) == -1) {
        perror("Config failed");
        close(fd);
        return;
    }

    int wl = write(fd,&passed,1);
    tcdrain(fd);

    if(wl < 0) {
        perror("Send failed");
    }

    //要不要加个等待下位机返回?

    close(fd);
    return;
}






