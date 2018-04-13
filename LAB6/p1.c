#include<stdio.h>
#include<stdlib.h>
struct node
{
	int val;
	struct node *left,*right;
}*root=NULL;
FILE *fp;

struct node *par,*ptr,*newnode;
	
int i,*a,j=1;

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


int main()
{
	int *t,n;
	//fp=fopen("file2.txt","r");
	//fscanf(fp,"%d",&n);
	printf("Enter the no of nodes you want to enter\n");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	for(i=0;i<n;i++)
	{
		insert(a[i]);
	}
	
}



