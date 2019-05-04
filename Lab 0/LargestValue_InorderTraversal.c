/*
 * C Program for finding the largest node
 * in a Binary Search Tree using  Inorder Traversal 
 */
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *left, *right;
};


struct node *createnode(int key)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return(newnode);
}


void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf(" %d ",root->info);
        inorder(root->right);
    }
}


void largest(struct node *root)
{
    while (root != NULL && root->right != NULL)
    {
        root = root->right;
    }
    printf("\nLargest value is %d\n", root->info);
}


/*
 * Main Function
 */
int main()
{

    /* Creating first Tree. */
    struct node *newnode = createnode(25);
    newnode->left = createnode(17);
    newnode->right = createnode(35);
    newnode->left->left = createnode(13);
    newnode->left->right = createnode(19);
    newnode->right->left = createnode(27);
    newnode->right->right = createnode(55);
    /* Sample Tree 1:
     *               25
     *             /    \
     *            17     35
     *           / \     / \
     *         13  19   27 55
     */
    printf("Inorder traversal of tree 1 :");
    inorder(newnode);
    largest(newnode);

    return 0;
}