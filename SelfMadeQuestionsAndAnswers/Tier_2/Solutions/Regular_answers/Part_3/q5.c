/*
	Tier 2 : Part 3	:	Question 5
*/
#include<stdio.h>

int main(int argc,char *argv[])
{
	FILE *FILE_HANDLE_1,*FILE_HANDLE_2,*fopen();
	
	FILE_HANDLE_1 = fopen(argv[1],"r" );
	
	if(FILE_HANDLE_1==NULL)
	{
		printf("Cannot open %s for reading\r\n",argv[1]);
		return 0;
	}
	else
		{
			int curly_right=0,curly_left=0,brace_right=0,brace_left=0;
			int single_quote=0,double_quote=0;
			int character_variable=0;
			
			while(character_variable!=EOF)
			{
				character_variable = getc(FILE_HANDLE_1);
				if(character_variable=='{'){	curly_right++;	}
				if(character_variable=='}'){	curly_left++;	}
				if(character_variable== 39){	single_quote++;	}
				if(character_variable=='"'){	double_quote++;	}
				if(character_variable=='('){	brace_right++;	}
				if(character_variable==')'){	brace_left++;	}
			}
			
			fclose(FILE_HANDLE_1);
			
			if(curly_right!=curly_left)
			{
				printf("Script cannot be compiled\r\n");
				printf("Script is missing a curly bracket\r\n");
			}
			if(brace_right!=brace_left)
			{
				printf("Script cannot be compiled\r\n");
				printf("Script is missing a brace\r\n");
			}
			if((single_quote%2)!=0)
			{
				printf("Script cannot be compiled\r\n");
				printf("Script is missing a single quote\r\n");
			}
			if((double_quote%2)!=0)
			{
				printf("Script cannot be compiled\r\n");
				printf("Script is missing a double quote\r\n");
			}
			
			if(curly_right!=curly_left&&brace_right!=brace_left&&(single_quote%2)==0&&(double_quote%2)==0)
			{
				printf("%s is ready to be compiled\r\n",argv[1]);
			}
		}
		
	
	return 0;
}