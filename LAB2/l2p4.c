#include<stdio.h>
#include<stdlib.h>
int main()
{
 FILE *fp;
 int *x;
 int i,j,k=0,n;
 fp=fopen("file4.txt","r");
 fscanf(fp,"%d",&n);
 int a[n];
 x = (int *)malloc((n+1)*sizeof(int));
 for(i=1;i<=n;i++)
 {
  fscanf(fp,"%d",&a[i]);
 }
 fclose(fp);
 fp=fopen("ans4.txt","w");
 for(i=1;i<=n;i++)
  {
   for(j=i+1;j<=n;j++)
    {
      if(a[i]>a[j])
       { 
        k++;
	fprintf(fp," %d inversion is (%d,%d)\n",k,a[i],a[j]);
       }
    }
  } 
 fprintf(fp," The total number of inversions are %d\n",k);
 fclose(fp);
 }     
        
      

