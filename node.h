#ifndef BTREE_HEADER_INCLUDED
#define BTREE_HEADER_INCLUDED

struct node {
    int data;
    struct node* l_child;
    struct node* r_child;
};


struct node* newNode(int data);

void deleteNode(struct node* n);

struct node* traverse(struct node* root);


#endif /* BTREE_HEADER_INCLUDED */

