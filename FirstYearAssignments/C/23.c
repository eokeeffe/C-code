/*euros to dollar converter*/
#include<stdio.h>
float answer1,answer2;
float euros,dollars;
char  yes,no,way;
main()

{
   
	
	printf("do you want to convert euros to dollars or the other way?\r\n");
	printf("please type y for euros to dollars or n for dollars to euros\r\n");
	way=getchar();
	yes='y';
	no='n';
	while(1){	
			
			 if(way==yes){float euro,dollar;
						  printf("please enter euro value\r\n");
						  scanf("%f",&euro);
						  dollar=(0.725227);
						  answer1=(euro/dollar);
						  printf("the answer is %f dollars\r\n",answer1);break;
						 }
			 if(way==no){float euro,dollar;
						 printf("please enter value in dollar\r\n");
			             scanf("%f",&dollar);
						 euro=(1.37937);
						 answer2=(dollar/euro);
						 printf("the answer in euro is %f dollars\r\n",answer2);break;
						 }
		    }
}