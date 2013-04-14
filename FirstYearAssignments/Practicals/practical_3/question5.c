/*Evan OKeeffe
  103242810
  question 5 practical 3 */
  
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

char result(int number);

int number;
char convert;

void main()
{
	int number;
	printf("Please enter the results you want converted here \r\n");
	scanf("%d",&number);
	if(number<0||number>100){printf("Number doesn't fit in this range , try between 0-100\r\n");}
	else
		{result(number);}
}
char result(int number)
{
	char convert;
	//printf("the number you entered was %d \r\n",number);
	switch (number)
	{
		case 100:
		case 99:
		case 98:
		case 97:
		case 96:
		case 95:
		case 94:
		case 93:
		case 92:
		case 91:
		case 90:{convert='A';break;}
		case 89:
		case 88:
		case 87:
		case 86:
		case 85:
		case 84:
		case 83:
		case 82:
		case 81:
		case 80:{convert='B';break;}
		case 79:
		case 78:
		case 77:
		case 76:
		case 75:
		case 74:
		case 73:
		case 72:
		case 71:
		case 70:{convert='C';break;}
		case 69:
		case 68:
		case 67:
		case 66:
		case 65:
		case 64:
		case 63:
		case 62:
		case 61:
		case 60:{convert='D';break;}
		case 59:
		case 58:
		case 57:
		case 56:
		case 55:
		case 54:
		case 53:
		case 52:
		case 51:
		case 50:{convert='E';break;}
		
		default:{convert='F';break;}
	}
	printf("your number was converted to a %c\r\n",convert);
	return convert;
}
		