#include<stdio.h>
#include<stdlib.h>
main()
{
 FILE *fp;
 int *a,n,temp,i,j;
 fp=fopen("input.txt","r");
 fscanf(fp,"%d",&n);
 a=(int*)malloc((n+1)*sizeof(int));
 for(i=1;i<=n;i++)
 {
   fscanf(fp,"%d",&a[i]);
 }
 fclose(fp);
 for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
     {
      if(a[j]>a[j+1])
       {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
       }
     }
  }
 fp=fopen("out.txt","w");
 for(i=1;i<=n;i++)
 {
  fprintf(fp,"%d\n",a[i]);
 }
 fclose(fp);
}       
        
