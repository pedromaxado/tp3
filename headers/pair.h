#ifndef PAIR_H_
#define PAIR_H_

#include <stdbool.h>

typedef struct pair_t* pair;

pair new_pair( int pub, int house );

void delete_pair( pair p );

int getPub( pair p );

int getHouse( pair p );

bool compare( pair a, pair b );

bool collides( pair a, pair b );

#endif
