//Declaration:  char *strerror(int errnum); 
//Return:       returns error message associated with the errnum. 

#include<string.h>
#include<stdio.h>

int main(void){
  printf(strerror(10));
}
