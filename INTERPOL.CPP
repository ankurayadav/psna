#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
float fact(float,float) ;
void main()
{       float *py,*px;
	float h,x,x0;
	float sum=0,p;
	int i,j,m,n;
	clrscr();
	printf("Program for interpolation forward method :") ;
	printf("\nHow many values you want to enter :") ;
	scanf("%d",&m) ;
	px = (float *)malloc(m*sizeof(float));
	printf("\nEnter the values of x:\n") ;
	for(i=0; i<m ; i++)
	{	printf("Enter the value %d:",i+1) ;
		scanf("%f",&px[i]);
	}
	py =(float *)malloc(m*sizeof(float)) ;
	printf("\nEnter the values of y:\n") ;
	for(i=0; i<m ; i++)
	{	printf("Enter the value %d:",i+1) ;
		scanf("%f",&py[i]);
	}

	printf("\n\nEnter the value of x to calculate the y :");
	scanf("%f",&x) ;
	h = px[1]-px[0];
	x0 = px[0] ;
      //	printf("\n%0.2f %0.2f\n",x,x0) ;
	p  = (x-x0)/h ;
      //	printf("\nh :%f p :%.2f\n",h,p) ;
	sum = py[0] ;
	printf("\n      x :") ;
	for(i=0; i<m ; i++)
	{	printf("\t%.2f",px[i]) ;
	}
	n=m  ;
	printf("\n\n      y :") ;
	for(j=0;j<n;j++)
	{	printf("\t%.2f",py[j]) ;
	}

	for(j=0;j<m-1; j++)
	{       printf("\ndel(y)%d:",j) ;
		for(i=0; i<n-1; i++)
		{    py[i]=py[i+1]-py[i];
		     printf("\t%.2f",py[i]);
		}
		n=n-1;
		sum = sum + (fact(p,j+1)*py[0]) ;
	}
	printf("\n\nAnswer is :%f",sum) ;
	free(py) ;
	free(px)  ;
	getch();
}

float fact(float p, float j)
{       int i;
	float pro,fact=1;
	pro = p;
	for(i=1; i<j; i++)
	{  p = p-1;
	   pro = p*pro ;
	}
	for(i=j; i>=1; i--)
	{     fact= fact*i;
	}
	pro = pro/fact ;
	return pro;
}