#include <stdio.h>
#include "string.h"

#define PASSWORD_OK    1
#define PASSWORD_FAIL  2

void load_secret_password(char * buffer);
void clear_secret_password(char * buffer);
void flush_input(void);

#define PASSWORD_OK    1
#define PASSWORD_FAIL  2

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