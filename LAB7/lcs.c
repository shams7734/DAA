#include<stdio.h>
#include<stdlib.h>


int max(int x,int y)
{
	return x>y?x:y;
}


void lcs(char *x,char *y,int m,int n)
{
	int i,j;
	int a[m+1][n+1];
	//create table 
	for(i = 0;i<=m;i++)
		for(j=0;j<=n;j++)
			{
				if(i==0||j==0)
					a[i][j] = 0;
				else if(x[i-1]==y[j-1] )
					a[i][j] =a[i-1][j-1]+1 ;

				else
					a[i][j] = max(a[i-1][j],a[i][j-1]);
			}

	//print table
	for(i = 0;i<=m;i++)
		{
			for(j=0;j<=n;j++)
				printf("%d  ",a[i][j]);
			printf("\n");
		}
	printf("longest c s has length of %d\n",a[m][n]);
	int l = a[m][n];
	char lcs[l+1];
	lcs[l] ='\0';

	i =m;j=n;
	//find lcs with help of table
	while(i>0&&j>0)
		{
			if(x[i-1]==y[j-1])
				{
					lcs[l-1] = x[i-1];
					i--;j--;l--;
					//printf("%c\t%c\n",lcs[l-1],x[i-1]);
				}
			else if(a[i-1][j]>a[i][j-1])
				i--;
			else j--;
				
		}
	printf("%s\n",lcs);
	
	

}

void main()
{
	char x[] = {'A','B','C','D','A','B'};
	char y[] = {'B','D','C','A','B'};
	int m = 6;int n = 6;
	printf("%d\n\n",max(2,10));
	
	lcs(x,y,m,n);
	
	//printf("lcs is %d\n",r);
}
