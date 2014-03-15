//Program to compute qth root using Newton Ralphson method.
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
struct poly
{  int co;
   int power;
   struct poly *link;

}*start=NULL , *p,*temp=NULL;

struct poly *diff(struct poly *);
void solve();
void display(struct poly *) ;
float csum(float,struct  poly *) ;
void main()
{      int n,i ;
	clrscr();
	printf("To calculate qth root using Newton Ralphson method :\n") ;
	printf("\nEnter value of q to find qth root :")  ;
	scanf("%d",&n) ;
	//for(i=n; i>=0; i--)
	{       p = (struct poly*) malloc(sizeof(struct poly))  ;
		p->power =n;
	      //	printf("Enter the coefficient of x^%d :",i)  ;
		p->co=1;
		start = p;
		start->link = NULL;
		p = (struct poly*) malloc(sizeof(struct poly))  ;
		p->power =0;
		printf("Enter the number N:")  ;
		scanf("%d",&i) ;
		p->co=-i;
		start->link = p;
		(start->link)->link = NULL;

	}

	printf("\n\nThe polynomial entered is :\n\n\tf(x) :")   ;
	display(start);
	printf("\n");
       solve();
       free(p);
       getch();
}
void display(struct poly *temp)
{
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


}


void solve()
{       struct poly *d;
	float i=0,u=0 ,a,tm=0 ;
	float sum=0,sud=0,t=0,c=1,pr;
	int choice ;
	printf("Select your choice for calculation :\n") ;
 //	printf("1.Automatic :\n");
 //	printf("2.Manually :");
 //	scanf("%d",&choice);
	choice = 1;
	switch(choice)
	{  case 1:

			for(i=0;;i=i+c)
			{     //  temp=start;
			//	sum = 0;
				sum = csum(i,start) ;
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
	  printf("<->%.0f\n",u) ;
	   c=i+u;
	   c=c/2;
	  temp = start;
	  d = diff(temp);
	  printf("\nf'(x) :");
	  display(d) ;

	do
	{ //tm++;
	 pr = c;
	  sum=csum(c,start);
	  sud=csum(c,d);
	  c = c - (sum/sud);
	 //if((c-pr))0.0001)
	 // {break;}
	 }while((pr-c)>0.0001||(pr-c)<-0.0001);
	    printf("\n\nRoot is:%f",c) ;
	  tag:

}

float csum(float i,struct poly *temp)
{       float sum=0,a=0,po=0;
	for(;temp!=NULL;)
		{  if(((i==0)||(temp->co==0))&&(temp->power!=0))
		  { a=0;
		  }
		   else
		   {    if(temp->power==0)
			{po=1;
				a = (temp->co)*po;
				   sum = sum + a ;
				   break;
			}
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
struct poly *diff(struct poly *di)
{       int i;
	int n = di->power;
	struct poly *d=NULL;
	for(i=n; i>=1; i--)
	{       p = (struct poly*) malloc(sizeof(struct poly))  ;
		p->co =di->co*di->power ;
		p->power =di->power-1;
	      //	printf("Enter the coefficient of x^%d :",i)  ;
	     //	scanf("%d",&p->co);
		if(i==n)
		{  d = p;
		   p->link = NULL;
		}
		else
		{  temp=d;
			while(temp->link!=NULL)
			{   temp = temp->link ;
			}
		   temp->link = p ;
		   p->link = NULL;
		}
                di = di->link  ;
	}

	return d;
}