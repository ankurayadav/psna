//Program to compute root of a polynomial equation using bisection method.
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
struct poly
{  int co;
   int power;
   struct poly *link;

}*start=NULL , *p,*temp=NULL;

void solve();
float csum(float) ;
void main()
{      int n,i ;
	clrscr();
	printf("To calculate the roots of polynomial equation using bisection method :\n") ;
	printf("\nEnter the degree of the equation :")  ;
	scanf("%d",&n) ;
	for(i=n; i>=0; i--)
	{       p = (struct poly*) malloc(sizeof(struct poly))  ;
		p->power =i;
		printf("Enter the coefficient of x^%d :",i)  ;
		scanf("%d",&p->co);
		if(i==n)
		{  start = p;
		   start->link = NULL;
		}
		else
		{  temp=start;
			while(temp->link!=NULL)
			{   temp = temp->link ;
			}
		   temp->link = p ;
		   p->link = NULL;
		}
	}

	printf("\n\nThe polynomial entered is :\n\n\t")   ;
	temp=start;
	do
	{ if(temp->co!=0)
	  {  printf("%d",temp->co) ;
	    if(temp->power!=0)
	    {
		printf("x^%d",temp->power) ;
		printf(" + ") ;
	    }
	  }
		temp=temp->link;
	}while(temp!=NULL) ;
       printf("\n");
       solve();
       free(p);
       getch();
}


void solve()
{
	float i=0,u=0 ,a ;
	float sum=0,si=0,su=0,t=0,c=1;
	int choice ;
	printf("Select your choice for calculation :\n") ;
	printf("1.Automatic :\n");
	printf("2.Manually :");
	scanf("%d",&choice);
	switch(choice)
	{  case 1:

			for(i=0;;i=i+c)
			{     //  temp=start;
			//	sum = 0;
				sum = csum(i) ;
				printf("\nfor x=%.0f SUM is:%.4f",i,sum) ;

				if(sum<0)
				{  if(sum<t)
					{ c=1;		}
					if(t>0)
					{ break;}
				}
				else if(sum>0)
				{  if(sum>t)
					{ c=-1;		}
				   if(t<0)
				   { break;}
				}
				else
				 { break ;}
				if(i<-300||i>300)
				{ printf("\n\n!!!!Out of range!!!!")  ;
					exit(0); }
				t=sum  ;
			}
			if(sum==0)
			{  printf("\n\nRoot is :%.0f",i);
				goto tag;
			}
			else{
				if(u<i)
				{  u=i;
				   i=i+c;
				}
				else
				{  u=i+c;
				}
			} break;
	case 2:
		 printf("\nEnter the range :\n");
		 printf("Enter the limit 1:");
		 scanf("%f",&u);
		 printf("Enter the limit 2:");
		scanf("%f",&i);

			if(u<i)
		{        c=u;
			u=i;
			i=c;
		}
     }

	  printf("\n\nRange %.0f",i);
	  printf("<->%.0f",u) ;
	  si=csum(i);
	  //printf("\nc:%f",c);
	  su=csum(u);

	for(a=0;;a++)
	{  c=i+u;
	   c=c/2;
	  sum=csum(c);
	  //printf("\n%f",sum) ;
	  if(sum==0)
	  {break;}
	  if(su>si)
	  {   if(sum<0)
		{ i=c;
		}
	      if(sum>0)
	      {   u=c;
	      }
	  }
	  else
	  {   if(sum>0)
		{i=c;}
	      if(sum<0)
		{u=c;}
	  }
	  if((u-i)<0.0001)
	  {break;}
	  }
	    printf("\n\nRoot is:%f",c) ;
	  tag:

}

float csum(float i)
{       float sum=0,a=0,po=0;
	temp=start;
	for(;temp!=NULL;)
		{  if(((i==0)||(temp->co==0))&&(temp->power!=0))
		  { a=0;
		  }
		   else
		   {    if(temp->power==0)
			{po=1;}
			else
			{po  = pow(i,(temp->power)) ;}
			a = (temp->co)*po;
		   }

		    sum = sum + a ;
		    temp=temp->link;
		 //  printf("\n%f",a) ;
		 //  printf("\n%f",po) ;
		}




	 return sum;
}