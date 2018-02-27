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

typedef struct Couple {
	int latence;
	Cache cache;
}Couple;

typedef struct EndPoint {
	int id;
	Couple *tab;
	int latence_datacenter;
}EndPoint;

int init_video(int id, int length);
int init_cache(int id, int length);
int init_ep(int id, int length);

int lecture(const char *input);
int ecriture(const char *input);
Cache min(Couple * tab);

#endif
