#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tmalloc.h"

// Node of a binary tree.

typedef struct node {
	int data;
	struct node* l_child;
	struct node* r_child;
} node;


node* newNode(int data);
void deleteNode(node *n);
node* traverse(node* root);

int count = 0;

int main(int argc, char* argv[])
{
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
		int r = rand() % 3;
		
		switch(r)
			{
				case 0:
					n->l_child = newNode(0);
					count++;
				break;
			
				case 1:
					n->r_child = newNode(0);
					count++;
				break;
				
				case 2:
					n->l_child = newNode(0);
					n->r_child = newNode(0);
					count+=2;
				break;	

				case 3:
					deleteNode(n);
				break;
			}
		n = traverse(ROOT_NODE);
	}
}



node* newNode(int data)
{
#ifdef TINKER
	node *n = (node*) tmalloc(sizeof(node));
#else 
	node *n = (node*) malloc(sizeof(node));
#endif
	if (n == NULL)
	{
		printf("Number of successful malloc calls: %d", count);
		exit(0);
	}	
	n->data = data;
	n->l_child = NULL;
	n->r_child = NULL;

	return n;
}

void deleteNode(node *n)
{
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

