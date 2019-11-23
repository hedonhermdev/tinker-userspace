typedef struct node {
    int data;
    struct node* parent;
    struct node* l_child;
    struct node* r_child;
} node;

node* newNode(int data);
void deleteNode(node *n);
node* traverse(node* root);


