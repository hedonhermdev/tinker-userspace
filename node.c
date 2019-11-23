#include <stdlib.h>

#include "tmalloc.h"
#include "node.h"

node* newNode(int data)
{
#ifdef TINKER
    node *n = (node*) tmalloc(sizeof(node));
#else
    node *n = (node*) malloc(sizeof(node));
#endif
    if (n == NULL)
    {
        return NULL;
    }
    n->data = data;
    n->l_child = NULL;
    n->r_child = NULL;

    return n;
}


void deleteNode(node *n)
{
    n->parent = NULL;
#ifdef TINKER
    tfree(n);
#else
    free(n);
#endif
}

node* traverse(node* root)
{
    node *n = root;
    while(n->l_child || n->r_child)
    {
        // Randomly select a child
        if (rand() % 2)
        {
            if(n->r_child)
                n = n->r_child;
            else
                n = n->l_child;
        } else
        {
            if(n->l_child)
                n = n->l_child;
            else
                n = n->r_child;
        }
    }
    return n;
}

