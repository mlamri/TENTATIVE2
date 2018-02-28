
#include "hashcode.h"

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		fprintf(stderr,"usage : %s arg \n",argv[0]);
		return -1;
	}
	Video *datacenter =NULL;
	Cache *tab_cache =NULL;
	EndPoint *tab_ep = NULL;
	Request * tab_rd =NULL;
	
	lecture(argv[1]);
	
	//printf("Hello World !!!");
	return 0;
}
