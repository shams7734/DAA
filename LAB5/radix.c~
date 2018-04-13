#include<stdio.h>
#include<stdlib.h>

int *a,i,j,k=0,n,m,count=0,val1=0;

struct node
{
	int val;
	struct node *p;
};

struct node *head[10],*temp,*temp1;

void max(int a[])
{
	m=a[0];
	for(i=1;i<8;i++)
	{
		if(a[i]>m)
			m=a[i];
	}
	
	while( !( m<10 && m>=0 ) )
	{
		m=m/10;
		count++;
	}
	
}

void radix(int a[])
{
	
	for(i=0;i<8;i++)
	{
		val1=a[i];
		for(j=0;j<count;j++)
		{
			val1=val1/10;
		}
		
		
		temp1=head[val1];
		
		if(temp1->p==NULL)
		{
			
			temp=(struct node *)malloc(sizeof(struct node));
			temp->val=a[i];
			temp->p=NULL;
			temp1->p=temp;
			
		}
		
		else
		{
			temp=(struct node *)malloc(sizeof(struct node));
			temp->val=a[i];
			temp->p=NULL;
			while(temp1->p!=NULL)
				temp1=temp1->p;
			
			temp1->p=temp;
			
		}			
	}
	
}


int main()
{

	FILE *fp;
	fp=fopen("file3.txt","r");
	fscanf(fp,"%d",&n);	
	a=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&a[i]);
	}
	fclose(fp);	
	
	char *ch;
	for(i=0;i<10 && k<10;i++)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->val=k;
		temp->p=NULL;
		head[i]=temp;
		k++;
	}	
	ch="The sorted array is : ";
	
	max(a);
	radix(a);
	
	fp=fopen("radix1.txt","w");
	
	printf("%s\n",ch);
	for(i=0;i<10;i++)
	{
		temp1=head[i];
		
		while(temp1->p!=NULL)
		{
			printf("%d\t",temp1->val);
			temp1=temp1->p;
		}
		
		printf("%d\n",temp1->val);
	}
	
	fclose(fp);
	
}
