#include <stdio.h> 
#include <stdint.h> 
#include <stdlib.h> 
#include <string.h>
#include <errno.h> 


#include <wiringPi.h>
#include <wiringSerial.h>

// ARDUINO_UNO "/dev/ttyACM0"
// FTDI_PROGRAMMER "/dev/ttyUSB0"
// HARDWARE_UART "/dev/ttyAMA0"
char device[] = "/dev/ttyACM0";

int fd;
unsigned long baud = 9600;
unsigned long time = 0;

int cardrfid() {
    while (1) {
        fflush(stdout);

        if ((fd = serialOpen(device, baud)) < 0) {
            fprintf(stderr, "Unable to open serial device: %s\n", strerror(errno));
            exit(1);
        }

        if (wiringPiSetup() == -1) {
            fprintf(stdout, "Unable to start wiringPi: %s\n", strerror(errno));
            exit(1); 
        }

        // read signal
        if (serialDataAvail(fd)) {
            int newChar = serialGetchar(fd);
            printf("%d", newChar);
            return newChar;
            break;
        }
    }
}

