// Implementing quick sort using middle element as the pivot element


#include<stdio.h>
#include<stdlib.h>
	
int i,j,x,p,r,q,n,temp,*m,mid,count=0;
int a[50];

void quicksort(int a[],int p,int r)
{

int partition(int a[],int p,int r)
{
	mid=(p+r)/2;
	temp=a[r];
	a[r]=a[mid];
	a[mid]=temp;
	count++;
	x=a[r];
	i=p-1;
	for(j=p;j<=(r-1);j++)
	{
		if(a[j]<=x)
		{
			i=i+1;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			count++;
		}
	}

	temp=a[i+1];
	a[i+1]=a[r];
	a[r]=temp;
	count++;
	return (i+1);
}
	if(p<r)
	{
		q=partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}



}
int main()
{
	FILE *fp;
	char *ch;
	ch="The Sorted array is : ";
	fp=fopen("file1.txt","r");
	fscanf(fp,"%d",&n);
	m=(int *)malloc(n*sizeof(int));
	//mid=n/2;
	for(i=0;i<n;i++)
		fscanf(fp,"%d",&a[i]);
	p=0;r=7;
	quicksort(a,p,r);
	fclose(fp);
	fp=fopen("ans3.txt","w");
	fprintf(fp,"%s \t",ch);
	for(i=0;i<8;i++)
		fprintf(fp,"%d\t",a[i]);
	fprintf(fp,"\n \nThe no. of swaps are : \t%d\t ",count);
	fclose(fp);
}
