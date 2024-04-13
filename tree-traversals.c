#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *right;
    struct node *left;
};
struct node *root;
struct node *newnode(int item)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}
void inorder(struct node *temp)
{
    if (temp == NULL)
    {
        return;
    }
    inorder(temp->left);
    printf("%d ", temp->data);
    inorder(temp->right);
}
void preorder(struct node *temp)
{
    if(temp == NULL)
    {
        return ;
    }
    printf("%d ",temp->data);
    preorder(temp->left);
    preorder(temp->right);
}
void postorder(struct node *temp)
{
    if(temp == NULL)
    {
        return ;
    }
    postorder(temp->left);
    postorder(temp->right);
    printf("%d ",temp->data);

}
void main()
{
    // manual creattion of the binary treee
    root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);
    // traversals
    // inorder traversal
    printf("Inorder traversal of the above binary tree\n");
    inorder(root);
    printf("\nPreorder traversal of the above binary tree\n");
    preorder(root);
    printf("\nPostorder traversal of the above binary tree\n");
    postorder(root);
    getch();
}
