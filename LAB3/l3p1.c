#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()

{
	FILE *fp;
	fp=fopen("file1.txt","r");
	int i,j,n,num=0,level=0,*a;
	float k;
	
	fscanf(fp,"%d",&n);
	k=( log(n)/log(2) )
	for(i=0;i<n;level++)
	{
		for(j=0;( j<( pow(2,level) ) && i<n );j++)
		{
			fscanf(fp,"%d",&a[i]);
			i++;
		}
		
	}
	fclose(fp);
	
	fp=fopen("ans1.txt","w");
	
	fprintf(fp,"\nThe height of tree is %.2f\n",k);
	fprintf(fp,"\nThe no.of levels of tree is %d\n",level-1);
	for(;level>=0;)	
	{
		num = num+( pow(2,(level-2)) ); 
		level--;
	}
	fprintf(fp,"\nThe number of elements in leaf node is %d",n-num);
	
	fclose(fp);		
}

