#include <stdlib.h>

#include "tmalloc.h"
#include "node.h"


struct node* newNode(int data)
{
    #ifdef TINKER
        struct node *n = (struct node*) tmalloc(sizeof(struct node));
    #else
        struct node *n = (struct node*) malloc(sizeof(struct node));
    #endif

    if (n == NULL) return NULL; // Return null pointer if malloc failed.

    n->data = data;
    n->l_child = NULL;
    n->r_child = NULL;

    return n;
}

void deleteNode(struct node *n)
{
    #ifdef TINKER
        tfree(n);
    #else
        free(n);
    #endif
}

struct node* traverse(struct node* root)
{
    struct node *n = root;
    while(n->l_child || n->r_child)
    {
        // Randomly select a child
        if (rand() % 2) {
            if(n->r_child)
                n = n->r_child;
            else
                n = n->l_child;
        } else {
            if(n->l_child)
                n = n->l_child;
            else
                n = n->r_child;
        }
    }
    return n;
}

