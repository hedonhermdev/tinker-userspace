#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tmalloc.h"
#include "node.h"

// Possible operations on a node of binary tree.
typedef enum operations {
    GROW_LEFT,
    GROW_RIGHT,
    DELETE_SELF,
    NUM_OPS
} operations;

int main(int argc, char* argv[])
{
    // Which algorithm to use.
    #ifdef TINKER
        init_tmalloc("first_fit_block_algo");
    #endif

    // Seed random generator.
    srand(atoi(argv[1]));

    // Count of malloc calls,
    int count = 0;

    // Initialize root node.
    struct node *ROOT_NODE = newNode(0);

    // Loop till malloc fails.
    struct node *n = ROOT_NODE;
    while(1) {

        int r = rand() % NUM_OPS;
        struct node* temp_node = newNode(0);

        // Exit if malloc failed to allocate memory.
        if (temp_node == NULL) break;

        switch(r) {
                case GROW_LEFT:
                    n->l_child = temp_node;
                    count++;
                    break;

                case GROW_RIGHT:
                    n->r_child = temp_node;
                    count++;
                    break;

                case DELETE_SELF:
                    deleteNode(n);
                    break;
            }
        n = traverse(ROOT_NODE);
    }
    printf("Successful malloc calls: %d", count);
    return 0;
}

