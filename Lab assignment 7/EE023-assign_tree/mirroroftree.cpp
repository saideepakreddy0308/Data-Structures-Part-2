#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node* newnode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node*));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return(newnode);
}
void mirror(struct node *node)
{
    if(node==NULL)
    {
        return;
    }
    else
    {
        struct node* temp;
        mirror(node->left);
        mirror(node->right);
        //swap
        temp=node->left;
        node->left=node->right;
        node->right=temp;
    }
}

void inorder(struct node* node)
{
    if(node==NULL)
    {
        return;
    }
    inorder(node->left);
    printf("%d-",node->data);
    inorder(node->right);
    
}
int main()
{
    struct node *root=newnode(8);
    root->left=newnode(3);
    root->right=newnode(10);
    root->left->left=newnode(1);
    root->left->right=newnode(6);
    root->left->right->left=newnode(4);
    root->left->right->right=newnode(7);
    root->right->right=newnode(14);
    root->right->right->left=newnode(13);
    
    printf("inorder of given numbers \n");
    inorder(root);
    
    mirror(root);
    printf("\n inorder of mirror tree \n");
    inorder(root);
    
    return 0;
}

