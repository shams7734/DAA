#include<stdio.h>
#include<stdlib.h>
 int main()
{
 int a[5],b[4],c[3];
 int i,j,k,n,m,p;
 FILE *fp;
 int *x;
 fp=fopen("file1.txt","r");
 fscanf(fp,"%d",&n);
 x = (int *)malloc((n+1)*sizeof(int));
  for(i=1;i<=n;i++)
  {
   fscanf(fp,"%d",&a[i]);
  }
 fscanf(fp,"%d",&m);
 i++; 
   for(i=1;i<=m;i++)
  {
   fscanf(fp,"%d",&b[i]);
  }
 fscanf(fp,"%d",&p);
 i++;  
   for(i=1;i<=p;i++)
  {
   fscanf(fp,"%d",&c[i]);
  }
  fclose(fp); 
 

  fp=fopen("ans1.txt","w");
  j=0,k=0;
  for(i=1;i<=n && j<=m && k<=p;)
  {
	 if (a[i]==b[j] && b[j]==c[k])
	  {
		fprintf(fp,"%d\n",a[i]);
		i++,j++,k++;
	  }

 	else if (a[i]<b[j])
             i++;

	else if (b[j]<c[k])
             j++;

	else
             k++;
  } 
        
  fclose(fp); 
 } 
  
    
