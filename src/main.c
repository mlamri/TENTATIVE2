
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
	Request *tab_rd =NULL;
	
	File_data fd;
	
	lecture(argv[1],&fd,tab_cache,datacenter,tab_ep,tab_rd);

	libere(tab_cache,datacenter,tab_ep,tab_rd);
	
	//printf("Hello World !!!");
	exit(EXIT_SUCCESS);
}
