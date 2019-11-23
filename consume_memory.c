#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tmalloc.h"
#include "node.h"

// Node of a binary tree.

typedef enum operation {
    GROW_LEFT,
    GROW_RIGHT,
    GROW_BOTH,
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
        node* temp_node;
        if (temp_node == NULL) break;

        switch(opt)
        {
            case GROW_LEFT:
                temp_node = newNode(0);
                n->l_child = temp_node;
                temp_node->parent = n;
                count++;
                break;

            case GROW_RIGHT:
                temp_node = newNode(0);
                temp_node->parent = n;
                n->r_child = temp_node;
                count++;
                break;

            case GROW_BOTH:
                temp_node = newNode(0);
                n->l_child = temp_node;
                temp_node->parent = n;
                temp_node = newNode(0);
                n->r_child = newNode(0);
                temp_node->parent = n;
                count += 2;  

            case DELETE_SELF:
                deleteNode(n);
                break;
        }
        n = traverse(ROOT_NODE);
    }
    printf("Successfully called memory allocation function %d times.", count);
}

