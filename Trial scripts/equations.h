/*equations header file to calculate
  the magnetic fields , induction and others
  16/06/2011
*/
#include<iostream>
#include<cmath>
class equations
{
	
	public:
			void initialize(int MATE);
			//math functions
			float inductance(float radius,float number_of_turns);
			float resistance(float voltage,float current);
			float capacitance(float charge,float voltage);
			float current_heat(float current,float resistance);
			//infographics functions
			int info_screen();
			int values(int a);
			//variables
			float radius;
			float charge;
			float current;
			float mhenry;
			float cap;
			float resis;
			float voltage;
			float turns;
			

}var;

void equations::initialize(int MATE)
{
	radius=0.0;
	charge=0.0;
	current=0.0;
	mhenry=0.0;
	cap=0.0;
	resis=0.0;
	voltage=0.0;
	turns=0.0;
	std::cout<<"Variables initialized\r\n";
	
	values(1);
}

int equations::values(int a)
{
	std::cout<<"Please enter values for each heading\r\nIf value is unknown please enter 0\r\n\n";
	std::cout<<"Please enter for radius of coil\r\n";
	while(!(std::cin >> radius))
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout<<"Please enter a valid input\r\n";
    }
	std::cout<<"Please enter the number of turns in the coil\r\n";
	while(!(std::cin >> turns))
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout<<"Please enter a valid input\r\n";
    }
	std::cout<<"Please enter for charge\r\n";
	while(!(std::cin >> charge))
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout<<"Please enter a valid input\r\n";
    }
	std::cout<<"Please enter value for current being used\r\n";
	while(!(std::cin >> current))
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout<<"Please enter a valid input\r\n";
    }
	std::cout<<"please enter the magnetic field in micro-henries\r\n";
	while(!(std::cin >> mhenry))
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout<<"Please enter a valid input\r\n";
    }
	std::cout<<"please enter the capacitance value\r\n";
	while(!(std::cin >> cap))
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout<<"Please enter a valid input\r\n";
    }
	std::cout<<"please enter the resistance value\r\n";
	while(!(std::cin >> resis))
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout<<"Please enter a valid input\r\n";
    }
	std::cout<<"please enter the voltage\r\n";
	while(!(std::cin >> voltage))
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout<<"Please enter a valid input\r\n";
    }
	
	equations::info_screen();
	return 0;
}

int equations::info_screen()
{
	std::cout<<"\t radius of coil "<< radius <<"\r\n";
	std::cout<<"\t number of turns in the coil " << turns << "\r\n";
	std::cout<<"\t capacitor charge "<< charge <<"\r\n";
	std::cout<<"\t current being used "<< current <<"\r\n";
	std::cout<<"\t magnetic field in micro-henries "<< mhenry <<"\r\n";
	std::cout<<"\t capacitance value "<< cap <<"\r\n";
	std::cout<<"\t resistance value "<< resis <<"\r\n";
	std::cout<<"\t voltage "<< voltage <<"\r\n";
	return 0;
}