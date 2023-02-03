static uint8_t[176] aes_state;

/* XOR means the same function used for hiding or unhiding the AES state */
void hide_or_unhide(void){
    for(int i = 0; i < 176; i++){
        aes_state[i] = aes_state[i] ^ 0xAB ^ i;
    }
}