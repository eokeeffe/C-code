/***************************************************************************/
#define MAXlist 100
//my string data-type
struct string
{
	char array[MAXlist];//set the max string length to 100
};
struct string list[MAXlist];//create an array of 100 structs called array 

//global variables
int NumofElements;//keep track of the number of filenames there are
int NumofFiles;   //keep track of the total number of relevant files i.e first character is a number

//my functions
int find();//find the entry that has the shortest name with
		   //beginning character being [0->9] and print it
int readinFiles();	//read file names into the struct from the pipe
int initialize(int d);//initialize the global variables and debug setting,d is 1 for debug mode 0 for normal mode

//my debugging functions
int currentGlobals();//get the current values of all global variables 
int printList();//print the struct array, debugging function

//debugging variables
int debug;	//set this to 1 to activate the debugging printing