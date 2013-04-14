/*Evan O'Keeffe
  10324289
  practical8 question2
*/

union ans
{
	int ians;
	float fans;
	double dans;
};
typedef struct 
{
	union ans answer;
	char flag;
	int a,b;
}name;
name x,y;