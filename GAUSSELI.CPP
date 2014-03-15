//Program to solve system of equations using gauss elimination
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void main()
{       float *p,m,d,ans;
	int n,i,g,j,l;
	clrscr();
	printf("Program to solve system of linear equation :") ;
	printf("\n\nEnter number of variables in the linear equation :");
	scanf("%d",&n) ;
	l=n*(n+1) ;
	p = (float *)malloc(sizeof(float)*l) ;
	printf("\nGive details of %d euations :",n);
	for(i=0;i<n;i++)
	{       printf("\n\nEnter equation :%d\n",i+1);
		for(j=0;j<(n+1);j++)
		{	if(j==n)
			{	printf("c%d :",i+1);
			}
			else
			{	printf("x%d :",j+1) ;
			}
			scanf("%f",&p[i*(n+1)+j]) ;
		}
		printf("\n") ;
		for(j=0;j<(n+1);j++)
		{	if(j==n)
			{	printf("\b\b = %0.2f",p[i*(n+1)+j]);
			}
			else
			{	printf("%0.2fx%d + ",p[i*(n+1)+j],j+1)  ;
			}
		}
	}
	printf("\n\nMatrix form is :\n\n\t\t") ;
	for(i=0;i<n;i++)
	{	for(j=0;j<(n+1);j++)
		{       if(j==n)
			{
				printf("|%0.2f\t",p[i*(n+1)+j]) ;
			}
			else
			{	printf("%0.2f\t",p[i*(n+1)+j]) ;
			}
		}
		printf("\n\t\t");
	}
	printf("\n\nMatrix created after Gauss Elimination Procedure :\n\n\t\t") ;
	for(i=0;i<n;i++)
	{       d=p[i*(n+1)+i];
	     //	printf("\nd=%f",d);
		for(g=i+1;g<(n+1);g++)
		{	m=p[g*(n+1)+i];
		      //	printf("\nm=%f",m) ;
			for(j=0;j<n+1;j++)
			{
				p[g*(n+1)+j]=p[g*(n+1)+j]-((m*p[i*(n+1)+j])/d) ;
		      //		printf("\np=%0.2f",p[g*(n+1)+j]);
			}
		}
	}
     //	printf("\n\nGauss Elimination Matrix after solving :\n") ;
	for(i=0;i<n;i++)
	{	for(j=0;j<(n+1);j++)
		{  	if(j==n)
			{
				printf("|%0.2f\t",p[i*(n+1)+j]) ;
			}
			else
			{	printf("%0.2f\t",p[i*(n+1)+j]) ;
			}
		}
		printf("\n\t\t");
	}
	printf("\n\nAnswers are :") ;
	for(i=0;i<n;i++)
	{       d=p[i*(n+1)+i];
	     //	printf("\nd=%f",d);
		for(g=i;g<(n+1);g++)
		{	p[i*(n+1)+g]/=d;
		}
	}

	for(i=n-1;i>=0;i--)
	{
		ans=0;
		for(j=i+1;j<(n+1);j++)
		{
			if(j==n)
			{	p[i*(n+1)+i]=p[i*(n+1)+j]-ans;
			}
			else
			{       ans = ans + (p[i*(n+1)+j]*p[j*(n+1)+j]) ;
			}
		}
		ans = p[i*(n+1)+i] ;
		printf("\n\n\tx%d = %0.2f",i+1,ans)  ;
	}
	getch();

}