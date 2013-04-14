#include <stdio.h>
 
typedef struct __address{
    int house_number;
    char street[50]; 
    int zip_code;
    char country[20];
 
} address;
 
void main()
{
 
    printf("size of int is %d byte(s)\n",sizeof(int));
    printf("size of unsigned int is %d byte(s)\n",sizeof(unsigned int));
    printf("size of short is %d byte(s)\n",sizeof(short));
    printf("size of unsigned short is %d byte(s)\n",sizeof(unsigned short));
    printf("size of long is %d byte(s)\n",sizeof(long));
 
    printf("size of char is %d byte(s)\n",sizeof(char));
 
    printf("size of float is %d byte(s)\n",sizeof(float));
    printf("size of double is %d byte(s)\n",sizeof(double));
 
    printf("size of address is %d byte(s)\n",sizeof(address));
}