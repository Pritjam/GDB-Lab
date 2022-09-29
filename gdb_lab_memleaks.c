#include <stdio.h>
#include "gdb_lab.h"
#include "csbrk.h"

int main() {

    warehouse_shelf_t *dummy_shelf = (warehouse_shelf_t *) csbrk(sizeof(warehouse_shelf_t));
    warehouse_shelf_t *a_shelf = (warehouse_shelf_t *) csbrk(sizeof(warehouse_shelf_t));
    warehouse_shelf_t *another_shelf = (warehouse_shelf_t *) csbrk(sizeof(warehouse_shelf_t));

    // What do you expect to see here?
    printf("Next pointer of 'dummy_shelf': %p\n", dummy_shelf->next_shelf);
    printf("====================\n");

    // hook up the linked list here
    dummy_shelf->next_shelf = a_shelf;
    a_shelf->next_shelf = another_shelf;
    another_shelf->next_shelf = NULL;


    // now to traverse the linked list
    warehouse_shelf_t *current = dummy_shelf;
    while(current != NULL) {
        
        printf("Size of this shelf: %ld\n", current->shelf_size);
        current = current->next_shelf; // We have to move forward *after* referencing the current node
    
    }




    printf("====================\n");

    // Now let's remove 'another_shelf'
    a_shelf->next_shelf = NULL;
    // Is that it?

    // Let's also remove 'a_shelf'
    dummy_shelf->next_shelf = NULL;

    // Now let's add a few more elements
    current = dummy_shelf; // reuse that 'current' ptr
    for (int i = 0; i < 5; i++) {
        current->next_shelf = (warehouse_shelf_t *) csbrk(sizeof(warehouse_shelf_t));
        current = current->next_shelf;
    }

    current->next_shelf = NULL;
    // Set the last pointer to NULL

    // Now let's print everything again
    current = dummy_shelf;
    while(current != NULL) {
        printf("Size of this shelf: %ld\n", current->shelf_size);
        current = current->next_shelf;

    }
    // What went wrong?

    printf("====================\n");



    printf("All done!\n");
}