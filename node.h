#ifndef BTREE_HEADER_INCLUDED
#define BTREE_HEADER_INCLUDED

#include <stdlib.h>

struct node {
    int data;
    struct node* l_child;
    struct node* r_child;
};


struct node* traverse_tree(struct node* root)
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
	
#endif /* BTREE_HEADER_INCLUDED */

