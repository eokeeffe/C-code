/*Evan O'Keeffe
  10324289
  practical 18 question4
  
  the program has the relevant checks to make sur the memory is allocated properly 
*/
#include<stdio.h>
#include<stdlib.h>
#define ERROR printf("Memory allocation failed at line %d in file %s\r\n",__LINE__,__FILE__);
#define LINE printf("line=%d\r\n",__LINE__);

int main()
{
	int *a[10],*b[10],*d[10],i,j;
	
	for(i=0;i<10;i++)
	{
		a[i]=(int *)calloc(10,sizeof(int));
		if(a[i]==NULL){ERROR exit(0);}
		else
		{	
			printf("please enter value %d of 10 of matrix 1\r\n",i);
			scanf("%d%*c",a[i]);
		}
	}
	for(i=0;i<10;i++)
	{
		b[i]=(int *)calloc(10,sizeof(int));
		if(b[i]==NULL){ERROR exit(0);}
		else
		{	
			printf("please enter value %d of 10 of matrix 2\r\n",i);
			scanf("%d%*c",b[i]);
		}
	}
	printf("Result=\r\n");
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			d[i]=(int *)calloc(10,sizeof(int));
			if(d[i]==NULL){ERROR exit(0);}
			else
			{	
				*(d[i]+j)=*(a[i]+j)+*(b[i]+j);
				if(*(d[i]+j)!=0){printf("%d ",*(d[i]+j));}
			}
		}
	}
	return 0;
}