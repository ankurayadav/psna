#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void main()
{       float *py,*px;
	float h,x,x0;
	float sum=0,p=1;
	int i,j,m,n;
	clrscr();
	printf("Program for langrange's interpolation method :") ;
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
	for(i=0;i<m;i++)
	{       p=1;
		for(j=0;j<m;j++)
		{    if(i!=j)
		     {	p=(p*(x-px[j]))/(px[i]-px[j])  ;
		     // printf("(%.0f-%.0f)/(%.0f-%.0f), ",x,px[j],px[i],px[j]) ;
		    //  printf("%.4f * ",p) ;
		     }
		}
		p=p*py[i];
	      //	printf("|*%0.f",py[i]);
	      //	printf(" = %f\n",p);
		sum=sum+p;
	}
	printf("\n\nAnswer is :%f",sum) ;
	free(py) ;
	free(px)  ;
	getch();
}
