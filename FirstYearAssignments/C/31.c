/*EVAN O'KEEFFE 10324289*/
/*	05/10/2010			*/
/*	this program is for finding the force of gravity,centripetal,conservation of momentum,moments(90degrees is taken as angle),coulombic*/
/*	the program uses the if statement to then ask for the needed variables then read out the answer */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
char one,yes,no,right,y,n,show;

float main()
{
	printf("which force do you need to find?\r\n");
	printf("a=gravity\r\n");
	printf("b=centripetal acceleration\r\n");
	printf("c=conservation of momentum\r\n");
	printf("d=torque\r\n");
	printf("e=coulombic\r\n");
	printf("which one?\r\n");
	/*while(1){
			 one=getchar();
			 if(one=='a')break;
			 if(one=='b')break;
			 if(one=='c')break;
			 if(one=='d')break;
			 if(one=='e')break;*/
			
	/*printf("you have chosen %c,is this right?,type y for yes and n for no\r\n",one);*/
	one=getchar();
	if(one=='a'){
				float mass1,mass2,distance;
				float distancesquared,universalgravityconstant,force,answer;
				float line1,line2,e;
				
				printf("please enter the mass1\r\n");
				scanf("%f",&mass1);
				printf("please enter the mass2\r\n");
				scanf("%f",&mass2);
				printf("please enter the distance between the two bodies\r\n");
				scanf("%f",&distance);
				
				distancesquared=(distance*distance);
				universalgravityconstant=(6.67300);
				e=pow(10, -11);
				line1=(universalgravityconstant*e*mass1*mass2);
				line2=(distancesquared);
				answer=(line1/line2);
				
				printf("the answer is %fnewtons\r\n",answer);
				}
	if(one=='b'){
					float mass,v,vsquared,r,answer;
					float line1,line2;
					
					printf("please input the mass\r\n");
					scanf("%f",&mass);
					printf("please input the 'v' value\r\n");
					scanf("%f",&v);
					printf("please input the 'r' value\r\n");
					scanf("%f",&r);
					
					vsquared=(v*v);
					line1=(mass*vsquared);
					line2=(r);
					answer=(line1/line2);
					
					printf("the answer is %f newtons/radians/s\r\n",answer);
				}
	if(one=='c'){
					float mass1,mass2,u1,u2,v,answer,line1,line2;
					printf("please enter the mass1\r\n");
					scanf("%f",&mass1);
					printf("please enter the value for mass2\r\n");
					scanf("%f",&mass2);
					printf("Please enter the initial velocity for body1(u1)\r\n");
					scanf("%f",&u1);
					printf("please enter the velocity for body2(u2)\r\n");
					scanf("%f",&u2);
					printf("please enter the final velocity(v)\r\n");
					scanf("%f",&v);
					printf("do you want to show if they are conserved\r\n, p for prove s for  show \r\n?");
					show=getchar();
					line1=((mass1)*u1)+((mass2)*u2);
					line2=(((mass1)+((mass2))*v));
					
						if(show ='p'){	if ((line1==line2)){printf("the answer of line1\r\n and line2 is true\r\n");}
									
										if (line1!=line2){printf("the answer of line1%f\r\n and line2%f is false\r\n");}
									};
				        if(show='s'){ printf("the answer for 1=%f\r\n and 2=%f\r\n",line1,line2);
								  }
				}
	if(one=='d'){
				float torque,force,distance;
				printf("please enter the force\r\n");
				scanf("%f",&force);
				printf("please enter the perpendicular distance\r\n");
				scanf("%f",&distance);
				torque=(force*distance);
				printf("your answer is %f N/m\r\n\n",torque);
				}
	if(one=='e'){
					float v,q,f;
					printf("please enter the charge q\r\n");
					scanf("%f",&q);
					printf("please enter the voltage v\r\n");
					scanf("%f",&v);
					f=(q/v);
					printf("the answer is %f coulombs\r\n",f);
				}
				 
	
}