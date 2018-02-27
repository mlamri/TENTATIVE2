#include "hashcode.h"

int lecture (const char *input)
{
	FILE *fichier = fopen(nom,"r");
    assert(fichier!=NULL);
    
    int nbv,nbep,nbrd,nbc,tc;
    n=fscanf(fichier,"%d",&nbv);
    if (n<=0)
    {
        perror("fscanf");
        printf("echec de la lecture\n");
        return -1;
    }
    n=fscanf(fichier,"%d",&nbep);
    if (n<=0)
    {
        perror("fscanf");
        printf("echec de la lecture\n");
        return -1;
    }
    n=fscanf(fichier,"%d",&nbrd);
    if (n<=0)
    {
        perror("fscanf");
        printf("echec de la lecture\n");
        return -1;
    }
    n=fscanf(fichier,"%d",&nbc);
    if (n<=0)
    {
        perror("fscanf");
        printf("echec de la lecture\n");
        return -1;
    }
    n=fscanf(fichier,"%d",&nbtc);
    if (n<=0)
    {
        perror("fscanf");
        printf("echec de la lecture\n");
        return -1;
    }
	return 0;
}
