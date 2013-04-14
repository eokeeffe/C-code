/*Evan O'Keeffe
  10324289
  practical6 question5
*/
int funct1(char a, char b);
int funct2(char *pa, char *pb);
main( )
{
	char a = 'X' ;
	char b = 'Y' ;
	int i,j;
	
	i = funct1(a, b);
	printf("a=%c b=%c\n", a, b);
	. . . . .
	j = funct2(&a, &b);
	printf("a=%c b=%c\n", a, b) ;
}
int funct1(char c1 , char c2)
{
c1 = 'P';
c2 = 'Q';

return ((c1 < c2) ? cl:c2);
}
int funct2(char *c1, char *c2)
{
*c1 = 'P';
*c2 = 'Q';

return ((*cl==*c2) ? *c1:*c2);
}

(a) Within main,what value is assigned to i? 
80
(b) What value is assigned to j?
81
(c) What values are displayed by the first printf statement?
a=X , b=Y
(d) What values are displayed by the second printf  statement?
a=X , b=Y