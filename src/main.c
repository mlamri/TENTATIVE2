
#include "hashcode.h"

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		fprintf(stderr,"usage : %s arg \n",argv[0]);
		return -1;
	}
	lecture(argv[1]);
	
	//printf("Hello World !!!");
	return 0;
}
