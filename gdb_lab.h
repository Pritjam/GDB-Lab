#include <stddef.h>
#include<stdint.h>

typedef struct warehouse_shelf {
    uint64_t shelf_size;
    struct warehouse_shelf *next_shelf;
} warehouse_shelf_t;
