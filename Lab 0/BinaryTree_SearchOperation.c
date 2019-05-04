/*
	@About
		C program to search element in a tree recursively.
		
	@Simple
	There is a basic Binary tree 
	
	      (60)					<====== This line is tree root
             /    \
            /      \
        (50)        (80)			<====== This are tree's branchs
        /   \       /   \
      (40) (55)   (75)  (90)			
      / \   /\    /\	  /\
    (0)(0) /  \	 (0)(0) (0)(0)		
         (52)(57) 					<====== This are tree's leaves
	      

    @Programmed by : Aadarsha Acharya
		
		
*/

#include <stdio.h>
#include <stdlib.h>


struct Tree
{
    int info;
    struct Tree *left;
    struct Tree *right;
};

typedef struct Tree Tree;

Tree *createNode(Tree *root, int item)
{
    if (root == NULL)
    {
        root = (Tree *)malloc(sizeof(Tree));
        root->info = item;
        root->left = root->right = NULL;
        return (root);
    }

    else if (root->info > item)
    {
        root->left = createNode(root->left, item);
        return root;
    }

    else
    {
        root->right = createNode(root->right, item);
        return root;
    }
}

void PreorderTraversal(Tree *root)
{

    if (root != NULL)
    {
        printf("%d\t", root->info);
        PreorderTraversal(root->left);
        PreorderTraversal(root->right);
    }

    return;
}

int search(Tree *root, int key)
{
    while (root != NULL)
    {
        if (key > root->info)
        {
            return search(root->right, key);
        }
        else if (key < root->info)
        {
            return search(root->left, key);
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    struct Tree *root;
    int flag =0, item;
    int key;
    int ch;

    root = NULL;

    printf("1. Enter in Binary Tree \n");
    printf("2. Search and Replace \n");
    printf("3. Exit \n");

    while (1)
    {
        printf("\n\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter new element : ");
            scanf("%d", &item);
            root = createNode(root, item);
            printf("Root item : %d", root->info);
            printf("\nPreoder traversal of binary tree is : ");
            PreorderTraversal(root);
            break;

        case 2:
            printf("Enter element to search : ");
            scanf("%d",&key);
            flag = search(root, key);
            if (flag)
            {
                printf("Key %d found in tree \n", key);
            }
            else
            {
                printf("Key %d not found in tree \n", key);
            }
           
            break;

        case 3:
            exit(1);

        default:
            break;
        }
    }

    return 0;
}