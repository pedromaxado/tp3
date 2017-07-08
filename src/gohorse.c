#include <stdio.h>
#include <stdbool.h>
#include <gohorse.h>
#include <stdlib.h>
#include <string.h>
#include <vector.h>

void go_horse( vector pairs, vector combinations, int count, long int *max ) {

    if ( count == size(pairs) ) {
        if ( size(combinations) > *max )
            *max = size(combinations);

        return;
    }

    go_horse( pairs, combinations, count+1, max );

    if ( !collides( get(pairs, count), get(combinations, size(combinations)-1) ) ) {
        add( combinations, get(pairs, count) );
        go_horse( pairs, combinations, count+1, max );
        pop_back( combinations );
    }
}

int go_horse_solver( vector pairs ) {

    long int max = 0;

    vector combinations = new_vector();
    add( combinations, new_pair(-1, -1) );

    go_horse( pairs, combinations, 0, &max );

    delete_pair( get(combinations, 0) );
    delete_vector( combinations );

    return max-1;
}
