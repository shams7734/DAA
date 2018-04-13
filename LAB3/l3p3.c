#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	float i,j,k,n,a,b,c;
	float d;
	printf("\n");
	printf("The general form of Master's Method is T(n) = aT(n/b) + F(n)\n");
	printf("Value of a must be >=1 and value of b must be > 1\n");
	printf("Here F(n) is n^c\n");
	printf("Enter the values of a,b,c\n");
	scanf("%f %f %f",&a,&b,&c);
	d=( log(a)/log(b) );
	
	printf("case1: n^(log(a)/log(b)) > n^c)\n");
	printf("case3: n^(log(a)/log(b)) < n^c)\n");
	printf("case2: n^(log(a)/log(b)) = n^c)\n");
	
	if(!(a>=1) || !(b>1))
	{
		printf("Invalid values . Please enter correct values.\n");
		exit(0);
	}
		
	
	
	if( d > c)
	{
		printf("\n");
		printf("case1 is applicable\n");
		printf("Complexity is order of O(n^%.2f)\n",d);
	}
	
	else if( d < c)
	{
		printf("\n");
		printf("case3 is applicable\n");
		printf("Complexity is order of O(n^%.2f)\n",c);
	}
	
	else if( d == c)
	{
		printf("\n");
		printf("case2 is applicable\n");
		printf("Complexity is order of O(log(n)*n^(%.2f))\n",c);
	}
	
}
