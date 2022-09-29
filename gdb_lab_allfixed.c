#include <stdio.h>
#include "gdb_lab.h"
#include "csbrk.h"

void recursive_free(warehouse_shelf_t *shelf) {
    if(shelf->next_shelf == NULL) {
        return;
    } else {
        recursive_free(shelf->next_shelf);
    }
    free(shelf->next_shelf);
}

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
    free(a_shelf->next_shelf);
    a_shelf->next_shelf = NULL;
    // Is that it?
    // No, we have to free the memory too, like above


    // Let's also remove 'a_shelf'
    free(dummy_shelf->next_shelf);
    dummy_shelf->next_shelf = NULL;
    // Same issue here

    // Now let's add a few more elements
    current = dummy_shelf; // reuse that 'current' ptr
    for (int i = 0; i < 5; i++) {
        current->next_shelf = (warehouse_shelf_t *) csbrk(sizeof(warehouse_shelf_t));
        current = current->next_shelf;
    }

    current->next_shelf = NULL;

    // Now let's print everything again
    current = dummy_shelf;
    while(current != NULL) {
        printf("Size of this shelf: %ld\n", current->shelf_size);
        current = current->next_shelf;

    }



    printf("====================\n");

    // How to free a singly-linked list, starting at the end?
    // I'll be an absolute fiend and use recursion
    recursive_free(dummy_shelf);
    free(dummy_shelf);




    printf("All done!\n");
}