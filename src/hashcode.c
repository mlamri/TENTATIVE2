#include "hashcode.h"
#include <assert.h>

int lecture (const char *input)
{
	FILE *fichier = fopen(input,"r");
    assert(fichier!=NULL);
    
    //premiere ligne
    int n,nbv,nbep,nbrd,nbc,tc;
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
    n=fscanf(fichier,"%d",&tc);
    if (n<=0)
    {
        perror("fscanf");
        printf("echec de la lecture\n");
        return -1;
    }
    
    printf("%d %d %d %d %d\n",nbv,nbep,nbrd,nbc,tc);
    
    //cache
    int i;
    //for(i=0;i<nbc;i++)
		//init_cache(i,tc);
    
    //video
    int tv;
    for (i=0;i<nbv;i++)
    {
		n=fscanf(fichier,"%d",&tv);
		if (n<=0)
		{
			perror("fscanf");
			printf("echec de la lecture\n");
			return -1;
		}
		printf("%d ",tv);
		//init_video(i,tv);
	}
	printf("\n");
	
	//EndPoint
	int ldc,nbcc,j;
	int idc,lc;
	for(i=0;i<nbep;i++)
	{
		n=fscanf(fichier,"%d",&ldc);
		if (n<=0)
		{
			perror("fscanf");
			printf("echec de la lecture\n");
			return -1;
		}
		n=fscanf(fichier,"%d",&nbcc);
		if (n<=0)
		{
			perror("fscanf");
			printf("echec de la lecture\n");
			return -1;
		}
		//init_ep(i,ldc);
		printf("%d %d\n",ldc,nbcc);
		
		for(j=0;j<nbcc;j++)
		{
			n=fscanf(fichier,"%d",&idc);
			if (n<=0)
			{
				perror("fscanf");
				printf("echec de la lecture\n");
				return -1;
			}
			n=fscanf(fichier,"%d",&lc);
			if (n<=0)
			{
				perror("fscanf");
				printf("echec de la lecture\n");
				return -1;
			}
			//ajout_couple(j,idc,lc);
			printf("%d %d\n",idc,lc);
		}
	}
	
	//Request
	int idv,idep,nbr;
	for(i=0;i<nbrd;i++)
	{
		n=fscanf(fichier,"%d",&idv);
		if (n<=0)
		{
			perror("fscanf");
			printf("echec de la lecture\n");
			return -1;
		}
		n=fscanf(fichier,"%d",&idep);
		if (n<=0)
		{
			perror("fscanf");
			printf("echec de la lecture\n");
			return -1;
		}
		n=fscanf(fichier,"%d",&nbr);
		if (n<=0)
		{
			perror("fscanf");
			printf("echec de la lecture\n");
			return -1;
		}
		printf("%d %d %d\n",idv,idep,nbr);
		//init_request(i,idv,idep,nbr);
	}
	
	n = fclose(fichier);
	if(n!=0)
	{
		perror("fclose");
		printf("echec de la fermeture du fichier\n");
		return -1;
	}
	return 0;
}
