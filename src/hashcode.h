#ifndef __HASHCODE_H__
#define __HASHCODE_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct Video {
	int id;
	int length;
}Video;

typedef struct Cache {
	int id;
	int capacity;
	Video *tab;
}Cache;

typedef struct CoupleCL {
	int latence;
	Cache cache;
}CoupleCL;

typedef struct EndPoint {
	int id;
	CoupleCL *tab;
	int latence_datacenter;
}EndPoint;

typedef struct Request{
	int idVideo;
	int idEndpoint;
	int requests;
}Request;


typedef struct File_data{
    int v;
    int e;
    int r;
    int c;
    int x;
} File_data;

void init_cache(Cache *tab_c,int nbc,int tc,int nbv);
void init_video(Video *dc, int id,int tv);
void init_ep(EndPoint *ep ,int id,int latence,int nbcc);
void ajout_coupleCL(EndPoint ep,int i,Cache idc,int lc);
void init_request(Request r,int idv,int idep,int nbr);

int lecture(const char *input,File_data *fd,Cache *tab_c,Video * dc,EndPoint * tab_ep,Request *tab_r );
int ecriture(const char *input);
Cache min(CoupleCL * tab);

void libere(Cache *tab_c,Video * dc,EndPoint * tab_ep,Request *tab_r);

#endif
