#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *tree = NULL;

struct node *insert(struct node *);
void inorderTraversal(struct node *);
void preorderTraversal(struct node *);
void postorderTraversal(struct node *);

int main()
{
    int option = 0;
    
    while (option != 5)
    {
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                tree = insert(tree);
                break;
            case 2:
                if (tree == NULL)
                    printf("Tree is Empty");
                else 
                {
                    printf("Inorder: ");
                    inorderTraversal(tree);
                }
                printf("\n");
                break;
            case 3:
                if (tree == NULL)
                    printf("Tree is Empty");
                else 
                {
                    printf("Preorder: ");
                    preorderTraversal(tree);
                }
                printf("\n");
                break;
            case 4:
                if (tree == NULL)
                    printf("Tree is Empty");
                else
                {
                    printf("Postorder: ");
                    postorderTraversal(tree);
                }
                printf("\n");
                break;
            case 5:
                break;
        }
    }
    
    return 0;
}

struct node *insert(struct node *tree)
{
    int data;
    printf("Enter Data to Insert: ");
    scanf("%d", &data);
    struct node *ptr, *nodeptr, *ptr2;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    
    if (tree == NULL)
    {
        tree = ptr;
        tree->left = NULL;
        tree->right = NULL;
    }
    else
    {
        ptr2 = NULL;
        nodeptr = tree;
        while (nodeptr != NULL)
        {
            ptr2 = nodeptr;
            if (data < nodeptr->data)
                nodeptr = nodeptr->left;
            else
                nodeptr = nodeptr->right;
        }
        
        if (data < ptr2->data)
            ptr2->left = ptr;
        else
            ptr2->right = ptr;
    }
    return tree;
}

void preorderTraversal(struct node *tree)
{
    if (tree != NULL)
    {
        printf("%d ", tree->data);
        preorderTraversal(tree->left);
        preorderTraversal(tree->right);
    }
}

void inorderTraversal(struct node *tree)
{
    if (tree != NULL)
    {
        inorderTraversal(tree->left);
        printf("%d ", tree->data);
        inorderTraversal(tree->right);
    }
}

void postorderTraversal(struct node *tree)
{
    if (tree != NULL)
    {
        postorderTraversal(tree->left);
        postorderTraversal(tree->right);
        printf("%d ", tree->data);
    }
}