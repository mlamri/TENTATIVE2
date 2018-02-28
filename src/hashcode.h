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

int init_video(int id, int length);
int init_cache(int id, int length);
int init_ep(int id, int length);

int lecture(const char *input,File_data *fd,Cache *tab_c,Video * dc,EndPoint * tab_ep,Request *tab_r );
int ecriture(const char *input);
Cache min(Couple * tab);


#endif
