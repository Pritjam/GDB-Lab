#include "csbrk.h"
#include <stdlib.h>
#include <stdint.h>

void *csbrk(size_t size) {
    void *temp = malloc(size);
    uint8_t *temp_byte = (uint8_t *) temp;
    for (int i = 0; i < size; i++) {
        temp_byte[i] = rand();
    }

    return temp;
}