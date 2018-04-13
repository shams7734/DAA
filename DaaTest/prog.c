#include<stdio.h>
#include<stdlib.h>
struct node
{
	int val;
	struct node *left,*right;
}*root=NULL;

struct node *par,*ptr,*newnode,*temp;
	
int i,del,*a,j=1;

struct node insert(int val)
{
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->left=newnode->right=NULL;
	newnode->val=a[i];
	if(root==NULL)
	{
		root=newnode;
		return *root;
	}

	ptr=root;
	while(ptr!=NULL)
	{
		if(newnode->val < ptr->val)
		{
			par=ptr;
			ptr=ptr->left;
		}
		else
		{
			par=ptr;
			ptr=ptr->right;
		}	
	}

	if(newnode->val < par->val)
		par->left=newnode;

	else
		par->right=newnode;

	return *root;
}

  

void inorder(struct node *root)
{
    	if (root != NULL)
    	{
		inorder(root->left);
		printf("%d \n", root->val);
		inorder(root->right);
    	}
    	
}

void delete(int del)
{
	temp=root;
	
	while(temp!=NULL)
	{
		par=temp;
		if(temp->left !=NULL && temp->right!=NULL)
		{
			if (temp != NULL)
			{
				par=temp;
				inorder(temp->left);
				if(temp->val==del)
				{
				
					par->left=temp;
					free(temp);
				
				}
				inorder(temp->right);
			}
		}
	
		else if(temp->left == NULL && temp->right == NULL && temp->val ==del)
		{
			free(temp);
		}
	
		else if(temp->left==NULL&&temp->right !=NULL && temp->val==del )
		{
			par->right=temp->right;
		}
		
		else if(temp->left!=NULL&&temp->right ==NULL && temp->val==del )
		{
			par->left=temp->left;
		}
	}
}


void postorder(struct node *root)
{
    	if (root != NULL)
    	{
		inorder(root->left);
		inorder(root->right);
		printf(" %d \t", root->val);
    	}
}

void preorder(struct node *root)
{
    	if (root != NULL)
    	{
		inorder(root->left);
		inorder(root->right);
    	}
}

int main()
{
	int *t,n;
	printf("Enter the no of nodes\n");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));

	for(i=0;i<n;i++)
	{
		printf("Enter the value of node\n");
		scanf("%d",&a[i]);
	}

	for(i=0;i<n;i++)
	{
		insert(a[i]);
	}
	
	inorder(root);
	printf("enter the value you want to delete\n");
	scanf("%d",&del);
	delete(del);
	inorder(root);	
}




