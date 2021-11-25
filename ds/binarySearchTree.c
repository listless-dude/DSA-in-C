#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

// create a new node
struct node *newNode(int data)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

void inorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ->", root->data);
    inorderTraversal(root->right);
}

struct node *insert(struct node *node, int data)
{
    if (node == NULL)
        return newNode(data);
    
    if (data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);

    return node;
}

struct node *deleteNode(struct node *root, int data)
{
    if (root == NULL)
        return root;
    
}


int main()
{

    return 0;
}