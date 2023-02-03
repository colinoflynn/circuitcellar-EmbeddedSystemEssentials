#include "hal.h"
#include <stdint.h>
#include <stdlib.h>

volatile uint8_t test_value[] = {0xFE,0xED,0xFA,0xCE,0xCA,0xFE,0xBE,0xEF};

int main(void)
{
    platform_init();
    init_uart();

    while(1) {
        test_value[0] = test_value[0];
    }
}
