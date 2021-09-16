#include<stdio.h>
#include<stdlib.h>
void insert(void);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
void mirror(struct node*);
int nodesum(struct node*);
int getlevel(struct node*,int,int);
int stage(struct node*,int);
struct node* deletion(struct node*,int);
struct node* minimum(struct node*);


struct node {
	int data;
	struct node* right=NULL;
	struct node* left=NULL;
}*root=NULL;
main(){
	int ch,b,x,y;
	while(1)
	{
	printf("1.insertion\n");
	printf("2.inorder \n");
	printf("3.preorder \n");
	printf("4.postorder \n");
	printf("5.mirror \n");
	printf("6.level of given node\n");
	printf("7.deletion \n");
	printf("enter the value of choice: \n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:	insert();
				break;
		case 2: inorder(root);
				break;
		case 3: preorder(root);
				break;
		case 4: postorder(root);
				break;
		case 5: mirror(root);
				break;
		case 6: printf("enter the value of node: \n");
				scanf("%d",&x);
       			printf("Level of %d is %d\n", x,stage(root,x)); 
				break;
		case 7: printf("enter the value of node: \n");
				scanf("%d",&y);
				deletion(root,y);
		default:printf("enter valid choice");
				break;
	}
}
}
void insert(void){
	struct node* temp,*r;
	int x;
	temp=(node*)malloc(sizeof(struct node));
	printf("enter the data: \n");
	scanf("%d",&temp->data);
	temp->right=NULL;
	temp->left=NULL;
	r=root;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node* now;
		now=root;
		struct node* parent=NULL;
		while(now)
		{
			parent=now;
			if(temp->data>now->data)
			{
				now=now->right;
			}
			else
			{
				now=now->left;
			}
		}
		if(temp->data>parent->data)
		{
			parent->right=temp;
		}
		else
		{
			parent->left=temp;
		}
	}
}

void inorder(struct node *first)
{
	if(first==NULL)
	return;
	inorder(first->left);
	printf("%d->",first->data);
	inorder(first->right);
}
void mirror(node* first)
{
	if(first)
	{
		mirror(first->left);
		mirror(first->right);
		node *swap=first->left;
		first->left=first->right;
		first->right=swap;
	}
	return ;
}
int nodesum(node* first)
{
	int l=0,r=0;
	if(first==NULL||(first->left==NULL && first->right==NULL))
	return 1;
	else
	{
		if(first->left!=NULL)
		 l=first->left->data;
		if(first->right!=NULL)
		 r=first->right->data;
		if((first->data==l+r)&&nodesum(first->left)&&nodesum(first->right))
		return 1;
		else
		return 0;
	}
}
void preorder(node *first)
{
	if(first==NULL)
	return;
	printf("%d->",first->data);
	preorder(first->left);
	preorder(first->right);
}

void postorder(node *first)
{
	if(first==NULL)
	return;
	postorder(first->left);
	postorder(first->right);
	printf("%d->",first->data);
}

int getlevel(node *first,int data,int l)
{
	if(first==NULL)
	return 0;
	if(first->data==data)
	return l;
	int level=getlevel(first->left,data,l+1);
	if(level!=0)
	 return level;
	level=getlevel(first->right,data,l+1);
    return level;
}

int stage(node *first,int data)
{
	return getlevel(first,data,1);
}

struct node* minimum(struct node *first)
{
    if(first == NULL)
        return NULL;
    else if(first->left != NULL)
        return minimum(first->left);
    return first;
}

struct node* deletion(struct node *first, int val)
{
    if(first==NULL)
        return NULL;
    if (val>first->data)
        first->right = deletion(first->right, val);
    else if(val<first->data)
        first->left = deletion(first->left, val);
    else
    {
        if(first->left==NULL && first->right==NULL)
        {
            free(first);
            return NULL;
        }
        else if(first->left==NULL || first->right==NULL)
        {
            struct node *temp;
            if(first->left==NULL)
                temp = first->right;
            else
                temp = first->left;
            free(first);
            return temp;
        }
        else
        {
            struct node *temp = minimum(first->right);
            first->data = temp->data;
            first->right = deletion(first->right, temp->data);
        }
    }
    return first;
}




