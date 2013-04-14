/*Evan o'Keeffe 10324289
	04/10/2010
	this program takes input variables and produces the period 
	of a satellite or planet,then it will ask if you want the answer in seconds,minutes,hours,days*/

	
	
#include<stdio.h>
#include<math.h>/*this library was needed for the exponent function in the gravity constant*/

	float period,periodsquared,radius,mass,answer,gravconstant,pi;		/*these variables are brought outside the main */
	float yes,no,line,line2,e;											/*function so that they become global variables*/
	float seconds,minutes,hours,days;
	char  reply;

main(argc,argv)
int argc;
char *argv[];	/*matrix contains what was contained on the cmd line*//*argc is the num of entries on the cmd line*/
{
	gravconstant=(6.67300);
	e= pow(10, -11);
	pi= (3.1417);
	
	while(argc-->0)
	printf("arguements %s\r\n",argv[argc]);
	
	printf("please input the (radius)\r\n");
	if(argc>1){
				radius=atof(argv[2]);
			  }
	else{
		scanf("%f",&radius);
		}
	printf("please input (mass)\r\n");
	scanf("%f",&mass);
	
	line  =(4*pi*pi*radius*radius*radius);
	line2 =(gravconstant*e*mass);
	printf("line=%6.6f\r\n line2=%6.6f\r\n",line,line2);

	printf("do you want the period in seconds,minutes,hours,days?\r\n");
	printf("a for seconds\r\n");
	printf("b for minutes\r\n");
	printf("c for hours \r\n");
	printf("d for days \r\n");
	printf("what is your reply\r\n\n");
	
	while(1){
			 reply=getchar();
			 if(reply=='a')break;
			 if(reply=='b')break;
			 if(reply=='c')break;
			 if(reply=='d')break;
			}
	/*printf("the reply was %c\r\n",reply);*/
	
	periodsquared =((line)/(line2));
	period = sqrtf(periodsquared);
	/*printf("the period is %6.6f\r\n",period);*/
	
	
				if (reply=='a'){
					/*period = sqrtf(periodsquared);*/
					seconds=period;
					printf("%6.6f seconds\r\n\n",seconds);}
				
				
				if (reply=='b'){
					/*period = sqrtf(periodsquared);*/
					minutes=(period/60);
					printf("%6.6f minutes\r\n\n",minutes);}
				
				
				if (reply=='c'){
					/*period = sqrtf(periodsquared);*/
					hours=(period/(360));
					printf("%6.6f hours\r\n\n",hours);}
				
				
				if (reply=='d'){
					/*period = sqrtf(periodsquared);*/
					days=(period/(360*24));
					printf("%6.6f days\r\n\n",days);}
}