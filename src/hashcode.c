#include "hashcode.h"
#include <assert.h>

int lecture (const char *input,File_data *fd,Cache *tab_c,Video * dc,EndPoint * tab_ep,Request *tab_r)
{
	FILE *fichier = fopen(input,"r");
    assert(fichier!=NULL);
    
    //premiere ligne
    int n,nbv,nbep,nbrd,nbc,tc;
    n=fscanf(fichier,"%d %d %d %d %d",&nbv,&nbep,&nbrd,&nbc,&tc);
    if (n<=0)
    {
        perror("fscanf");
        printf("echec de la lecture\n");
        return -1;
    }
    
    fd->v = nbv;
    fd->e = nbep;
    fd->r = nbrd;
    fd->c = nbc;
    fd->x = tc;
    
    //printf("%d %d %d %d %d\n",nbv,nbep,nbrd,nbc,tc);
    
    //cache
    int i;
    
    //video
    int tv;
    dc = (Video *)malloc(nbv * sizeof(Video));
    for (i=0;i<nbv;i++)
    {
		n=fscanf(fichier,"%d",&tv);
		if (n<=0)
		{
			perror("fscanf");
			printf("echec de la lecture\n");
			return -1;
		}
		//printf("%d ",tv);
		init_video(dc,i,tv);
	}
	
	tab_c = (Cache *)malloc(nbc * sizeof(Cache));
	
	init_cache(tab_c,nbc,tc,nbv);
	//printf("\n");
	
	//EndPoint
	int ldc,nbcc,j;
	int idc,lc;
	tab_ep = (EndPoint *)malloc(nbep * sizeof(EndPoint));
	for(i=0;i<nbep;i++)
	{
		n=fscanf(fichier,"%d %d",&ldc,&nbcc);
		if (n<=0)
		{
			perror("fscanf");
			printf("echec de la lecture\n");
			return -1;
		}
		init_ep(tab_ep,i,ldc,nbcc);
		//printf("%d %d\n",ldc,nbcc);
		
		for(j=0;j<nbcc;j++)
		{
			n=fscanf(fichier,"%d %d",&idc,&lc);
			if (n<=0)
			{
				perror("fscanf");
				printf("echec de la lecture\n");
				return -1;
			}
			ajout_coupleCL(tab_ep[j],j,tab_c[idc],lc);
			//printf("%d %d\n",idc,lc);
		}
	}
	
	//Request
	int idv,idep,nbr;
	tab_r = (Request *)malloc(nbr * sizeof(Request));
	for(i=0;i<nbrd;i++)
	{
		n=fscanf(fichier,"%d %d %d",&idv,&idep,&nbr);
		if (n<=0)
		{
			perror("fscanf");
			printf("echec de la lecture\n");
			return -1;
		}
		//printf("%d %d %d\n",idv,idep,nbr);
		init_request(tab_r[i],idv,idep,nbr);
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


void init_cache(Cache *tab_c,int nbc,int tc,int nbv)
{
	int i;
	for(i=0;i<nbc;i++)
    {
		tab_c[i].id = i;
		tab_c[i].capacity = tc;
		tab_c[i].tab = (Video *)malloc(nbv * sizeof(Video));
	}
	return ;
}

void init_video(Video *dc, int id,int tv)
{
	dc[id].id= id;
	dc[id].length = tv;
	return ;

}

void init_ep(EndPoint *ep ,int id,int latence,int nbcc)
{
	ep[id].id = id ;
	ep[id].latence_datacenter = latence ;
	ep[id].tab = (CoupleCL *)malloc(nbcc * sizeof(CoupleCL));
	return ;
}

void ajout_coupleCL(EndPoint ep,int i,Cache idc,int lc)
{
	CoupleCL cl;
	cl.latence = lc;
	cl.cache = idc;
	ep.tab[i] =cl;
	return;
}

void init_request(Request r,int idv,int idep,int nbr)
{
	r.idVideo = idv;
	r.idEndpoint = idep;
	r.requests = nbr;
	return ;
}
void libere(Cache *tab_c,Video * dc,EndPoint * tab_ep,Request *tab_r)
{
	free(tab_c->tab);
	free(tab_c);
	free(dc);
	free(tab_ep->tab);
	free(tab_ep);
	free(tab_r);
	return;
}
