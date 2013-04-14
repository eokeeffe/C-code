/*evan o'keeffe 10324289
	28/09/2010
	WAP read the radius of a circle and output its area
*/

#include<stdio.h>

main()
{ 
	float radius,pi,area;
	pi = 3.1417;
	
	printf("please enter the (radius) \r\n");
	scanf("%f",&radius);
	
	area = (radius*radius) * (pi);
	
	printf("the answer is %f\r\n",area);
	
	return 0;
}