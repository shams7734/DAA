// Implementing bucket sort 

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int n,i,j;
float *a,k=0;
	
struct node
{
	float val;
	struct node *p;
};

struct node *head[10],*temp,*b[10];


void bucket(float a[])
{

	struct node *temp1;
	for(i=0;i<10;i++)
	{
		
		b[(int)(floor(10*a[i]))]=head[(int)(floor(10*a[i]))];
		if(b[(int)(floor(10*a[i]))]->p==NULL)
		{
			temp=(struct node *)malloc(sizeof(struct node));
			temp->val=a[i];
			temp->p=NULL;
			b[(int)(floor(10*a[i]))]->p=temp;
		}
		
		else
		{
			temp=(struct node *)malloc(sizeof(struct node));
			temp->val=a[i];
			temp->p=NULL;
			
			temp1=b[(int)(floor(10*a[i]))];
			b[(int)(floor(10*a[i]))]=b[(int)(floor(10*a[i]))]->p;	
			while(b[(int)(floor(10*a[i]))] !=NULL )
			{
				if(temp->val < b[(int)(floor(10*a[i]))]->val)
				{
					temp->p=b[(int)(floor(10*a[i]))];
					temp1->p=temp;	
					break;
				}
			
				else 
				{
					temp1=b[(int)(floor(10*a[i]))];
					b[(int)(floor(10*a[i]))]=b[(int)(floor(10*a[i]))]->p;
				}
				
			}
			
			if(temp1->p ==NULL)
			{
				temp1->p=temp;
			}
		}
	}
	
	

}

int main()
{
	char *ch;
	FILE *fp;
	fp=fopen("file2.txt","r");
	fscanf(fp,"%d",&n);	
	a=(float*)malloc(n*sizeof(float));
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%f",&a[i]);
	}
	fclose(fp);
	
	ch="NULL";
	
	for(i=0;i<n && k<n;i++)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->val=k;
		temp->p=NULL;
		head[i]=temp;
		b[i]=head[i];
		k++;
	}

	bucket(a);
	fp=fopen("bucket1.txt","w");
	for(i=0;i<n;i++)
	{
		b[i]=head[i];
		fprintf(fp,"The bucket %d is:\t",i);
		if(b[i]->p==NULL)
			fprintf(fp,"%s\t\n",ch);
		else
		{
			b[i]=b[i]->p;
			while(b[i]->p!=NULL)
			{
				fprintf(fp,"%.2f\t",b[i]->val);
				b[i]=b[i]->p;
			}
			fprintf(fp,"%.2f\t",b[i]->val);
			fprintf(fp,"%s\n",ch);
			
		}
	}
	fclose(fp);
	
}
