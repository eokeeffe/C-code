/***************************************************************************/
#define MAXlist 100
//my string data-type
struct string
{
	char array[MAXlist];
};
struct string list[MAXlist];//create an array of structs called array

//global variables
int NumofElements;//keep track of the number of filenames there are
int NumofFiles;

//my functions
int find();//find the entry that has the needed shortest name with
		   //beginning character being [0->9]
int directorySize();//get the total number of elements in the directory
int readinFiles();	//read file names into the struct
int initialize(int d);//initialize the global variables,d is 1 for debug mode

//my debugging functions
int currentGlobals();//get the current values of global variables
int printList();//print the struct array, debugging function

//debugging variables
int debug;