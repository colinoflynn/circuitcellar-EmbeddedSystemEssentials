/* A simple password comparison example */

#include <stdio.h>
#include "pico/stdlib.h"
#include "string.h"

#define PASSWORD_OK    1
#define PASSWORD_FAIL  2

#pragma GCC push_options
#pragma GCC optimize ("O0")

void flush_input(void)
{
    getchar_timeout_us(0);
    getchar_timeout_us(0);
    getchar_timeout_us(0);
    getchar_timeout_us(0);
    getchar_timeout_us(0);
}

void load_secret_password(char * buffer)
{
    buffer[0] = '1';
    buffer[1] = '3';
    buffer[2] = '3';
    buffer[3] = '7';
    buffer[4] = 'l';
    buffer[5] = '1';
    buffer[6] = '4';
    buffer[7] = 'e';
    buffer[8] = 0;
}

void clear_secret_password(char * buffer)
{
    for(int i = 0; i < 16; i++){
        buffer[i] = 0;
    }
}

int receive_and_process_password(void){

    //Local variables
    char c;
    char * buf;
    int auth_level;
    char correct_password[16];
    char command_buffer[64];

    //Password gets set to incorrect on comparison fail
    auth_level = PASSWORD_OK;

    //Load secret password dynamically
    load_secret_password(correct_password);

    //Command buffer pointer - set first character to something
    //defined so loop enters below
    buf = command_buffer;
    c = 0;

    //Receive until user hits enter (newline or CR)
    while ((c != '\n') && (c != '\r')){
        c = getchar();
        *buf++ = c;
    }

    flush_input();

    //Compare against length of stored password
    //Avoid a break statement in this to reduce timing leakage
    for(int i = 0; i < strlen(correct_password); i++){
        if (correct_password[i] != command_buffer[i]){
            auth_level = PASSWORD_FAIL;
        }
    }

    return auth_level;
}

#pragma GCC pop_options

int main() {
    char c;
    int response;
    stdio_init_all();

    while (true) {
        printf("Password Please:\n");
        if (receive_and_process_password() == PASSWORD_OK) {
            printf("ACCESS GRANTED - WELCOME\n");
            while(1);
        } else {
            printf("INVALID PASSWORD\n");
            sleep_ms(1000);
        }

    }
}
