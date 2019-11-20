#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tmalloc.h"
#include "node.h"

// Node of a binary tree.

typedef enum operation {
    GROW_LEFT,
    GROW_RIGHT,
    DELETE_SELF,
    NUM_OPS
} operation;


int main(int argc, char* argv[])
{
    int count = 0;
    // Which algorithm to use.
#ifdef TINKER
    init_tmalloc("first_fit_block_algo");
#endif

    // Seed random generator.
    srand(time(0));
    // Initialize root node.
    node *ROOT_NODE = newNode(0);
    // Loop till malloc fails.
    node *n = ROOT_NODE;
    while(1) {
        operation opt = rand() % NUM_OPS;
        node* temp_node = newNode(0);
        if (temp_node == NULL) break;

        switch(opt)
        {
            case 0:
                n->l_child = temp_node;
                break;

            case 1:
                n->r_child = temp_node;
                break;

            case 2:
                deleteNode(n);
                break;
        }
        n = traverse(ROOT_NODE);
        count++;
    }
    printf("Successful malloc calls: %d", count);
}

