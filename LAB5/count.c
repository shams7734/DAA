#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	fp=fopen("file1.txt","r");
	int *a,b[50],c[10],i,j,k,n;
	printf("The range of numbers in file is (0,9)\n");
	k=9;
	fscanf(fp,"%d",&n);
	a=(int*)malloc((n+1)*sizeof(int));
	for(i=0;i<n;i++)
	{	
			fscanf(fp,"%d",&a[i]);
	}
	
	for(i=0;i<=k;i++)
		c[i]=0;
		
	for(j=0;j<n;j++)
		c[a[j]]=c[a[j]]+1;
		
	for(i=1;i<=k;i++)
		c[i]=c[i] + c[i-1];
		
	for(j=n-1;j>=0;j--)
	{
		b[c[a[j]]] = a[j];
		c[a[j]]=c[a[j]]-1;
	}
	fclose(fp);
	
	fp=fopen("ans1.txt","w");
	for(i=1;i<=n;i++)
		fprintf(fp,"%d\n",b[i]);
	fclose(fp);
	
}
