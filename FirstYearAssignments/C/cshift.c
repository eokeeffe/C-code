/*Evan O'Keeffe
  10324289
  This is a caesar shift encoder
  basically what happens is that a string of characters is read in
  then the characters are shifted by a n number of positions
  */
  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include<time.h>
#include<ctype.h>

void clear_screen(void);
void get_option(void);
void wait_for_user(void);
void caesarshifttest(const char *a,int n);		/*just checking for the arguement pass in the mock version*/
void caesarshift1(char a[200],int n);
char lower_case(char a[200]);					/*kept all the characters in the lowercase form when doing the wraparound for the shift*/
char sl[200];									/*the only global variable needed in the structure*/

void clear_screen(void)/*helped keep the screen nice and clean for the use*/
{
	int i;
	for(i=0;i<24;i++)
	printf("\n");
}

void get_option(void)
{
	char choice='\0',a[200];
	int i=0,n=0;
	int valid=0;
	
	while(n++!=200){a[n]='\0';}
	n=0;

	printf("please enter the string you wan to encode\r\n");
	gets(a);
	printf("how much do you want to shift by?\r\n");
	scanf("%d",&n);
	while(n<0||n>=26)
	{
	printf("how much do you want to shift by?\r\n");
	scanf("%d",&n);
	}
	printf("do you want to test the program first?\r\n");/*debug feature*/
	
	printf("(Y)es or (N)o\r\nor (Q)uit\r\n");
	choice=getch();

		if(choice=='Y'||choice=='y'){valid=1; caesarshifttest(a,n);}/*reason i didn't loop this was becuase it seemed unnecesary with the control limits*/
		if(choice=='N'||choice=='n'){valid=1; caesarshift1(a,n);}/*debug feature*/
		if(choice=='Q'||choice=='q'){valid=1; exit(0);}
		if(!valid)printf("Invalid option %c\n",choice);
		wait_for_user();
}

void wait_for_user(void)								/*added during the debug phase to check for internal errors*/
{
	char dummy[80];
	printf("\n\n Press Return to continue:");
	gets(dummy);
}

void caesarshifttest(const char *a,int n)			/*simple little test to see if the inputs are being read*/
{
	int b;
	printf("%s\r\n",a);								/*debug feature*/
	printf("the shift you want is %d \r\n",n);		/*debug feature*/
	
	b=strlen(a);									/*debug feature*/
	printf("lenght = %d\r\n",b);					/*debug feature*/
	
}

void caesarshift1(char a[200],int n)			/*actual routine for the encrytion*/
{
	char b[200];
	int  z=0,i=0;
	
	while(z++!=200){ b[z]='\0';}
	
	
	printf("caesarshift1 %s\r\n",a);				/*debug feature*/
	printf("the shift you want is %d \r\n",n);		/*debug feature*/
	
	lower_case(a);									/*returns all lowercase to sl[]*/
	
	printf("first stage complete\r\n");				/*debug feature*/
	printf("string converted to %s\r\n",sl);		/*debug feature*/
	
	while(sl[i]!='\0')
	{
		b[i]=sl[i]+n;
		if(b[i]>=123){b[i]=b[i]-26;}								/*pretty much the wraparound to stop charaters going above 122(z)*/		
		i++;
	}
	b[i]='\0';
	printf("encoding complete\r\n");
	printf("your string %s has now been encoded\r\n",sl);
	printf("your encoded string is %s\r\n",b);
}

char lower_case(char a[200])
{
	int buf=200;
	int i=0,len,c;
	
	while(i++!=buf){sl[i]='\0';}
	i=0;
	
	len=strlen(a);
	printf("the lenght is %d\r\n",len);			/*debug feature*/	
	
	while(a[i]!='\0')
	{	
		
		if(a[i]>='A'&&a[i]<='Z')
		{
			sl[i]=a[i]+32;
			printf("your word  %s \r\n has been changed to  %s \r\n",a,sl);			/*debug feature*/
		}
		else{sl[i]=a[i];}
		i++;
		if(a[i]<=1&&a[i]>=9){printf("you have entered numbers , please enter again\r\n");exit(0);}
	}
	
	printf("lowercase is %s\r\n",sl);					/*debug feature*/
	return (*sl);
}
void main()
{
	clear_screen();
	get_option();
}