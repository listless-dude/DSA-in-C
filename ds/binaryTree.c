    #include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *left;
    struct Node *right;
};

void inorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ->", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(struct Node* root) {
    if (root == NULL) 
        return;
    printf("%d ->", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct Node* root) {
    if (root == NULL) 
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ->", root->data);
}


struct Node *createNode(int val)
{
    // first node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node *insertLeft(struct Node *root, int val)
{
    // create a node to the left
    root->left = createNode(val);
    return root->left;
}

struct Node *insertRight(struct Node *root, int val)
{
    // create a node to the right
    root->right = createNode(val);
    return root->right;
}
int main()
{
    struct Node *root = createNode(1);
    insertLeft(root, 2);
    insertRight(root, 3);
    insertLeft(root->left, 4);

    printf("\nInorder Traversal: \n");
    inorderTraversal(root);
    printf("\nPreorder Traversal: \n");
    preorderTraversal(root);
    printf("\nPostorder Traversal: \n");
    postorderTraversal(root);

    return 0;
}