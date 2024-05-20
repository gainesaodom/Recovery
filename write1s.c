#include <stdint.h>
#include <stdbool.h>
#include "spi23x640/spi23x640.c"

uint16_t img_write() {

    spi23x640_init(5000000);
	uint16_t address_idx;
	for (address_idx = 0; address_idx <= SPI23X640_MAX_ADDRESS; address_idx++) {
		//printf("%x\n", address_idx);
		uint8_t next_value = 0xff;
		spi23x640_write_byte(address_idx, next_value);

		//printf("Writing value %04" PRIx16 "\n", next_value);

	}	
    
    spi23x640_close();
    printf("Done Writing all 1s to Chip.");
    return 0;
}

int main()
{
    if (img_write() != 0)  {
        printf("Error: image not written.");
    }
}