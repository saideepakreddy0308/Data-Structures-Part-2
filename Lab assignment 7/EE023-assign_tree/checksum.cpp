#include <stdio.h> 
#include <stdlib.h> 

struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 

int height(struct node*);
void levelorder(struct node*,int);
void print(struct node*);


int sum(struct node* temp) 
{ 
  int l=0,r=0; 
  if(temp==NULL||(temp->left==NULL&&temp->right==NULL)) 
    return 1; 
  else
  { 
    if(temp->left!=NULL) 
      l=temp->left->data; 
    if(temp->right!=NULL) 
      r=temp->right->data; 
    if((temp->data==l+r)&&sum(temp->left)&&sum(temp->right)) 
      return 1; 
    else
      return 0; 
  } 
} 
  
struct node* newfirst(int data) 
{ 
  struct node* temp=(struct node*)malloc(sizeof(struct node)); 
  temp->data=data; 
  temp->left=NULL; 
  temp->right=NULL; 
  return(temp); 
} 

int height(node* temp) {
    if (!temp)
        return 0;
    else{
        int lh=height(temp->left);
        int rh=height(temp->right);
        if (lh>=rh)
            return lh+1;
        else
            return rh+1;
    }
}
 
void levelorder(node* temp, int level) {
    if (!temp)
        return;
    if (level==0) {
        printf("%d-> ",temp->data);
    }
    else {
        levelorder(temp->left,level-1);
        levelorder(temp->right,level-1);
    }
 
}
 
void print(node* temp) {
    if (!temp)
        return;
    int h=height(temp);
    for (int i=0;i<h;i++){
        levelorder(temp,i);
        printf("\n");
    }
}

int main() 
{ 
  struct node *root =newfirst(13); 
  root->left         =newfirst(8); 
  root->right        =newfirst(5); 
  root->left->left   =newfirst(2); 
  root->left->right  =newfirst(6); 
  root->right->left  =newfirst(5); 
  
  int ch;
  while(1)
  {
  	printf("1.check over the sum property either T or F\n");
  	printf("2.level order9 \n");
  	printf("enter the choice:\n");
  	scanf("%d",&ch);
  	switch(ch)
  	{
  	case 1:	if(sum(root)) 
    		printf("1 \n"); 
  			else
    		printf("0 \n"); 
    		break;
    case 2: print(root);
    		break;
	}
  }
  
  return 0; 
} 
