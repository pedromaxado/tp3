#include <stdio.h>
#include <greedy.h>

int greedy( vector pairs ) {

    int i,
        fwdCount = 0,
        bwdCount = 0;

    vector combination = new_vector( size(pairs) );

    add(combination, get(pairs, 0));

    for ( i = 1; i < size(pairs); i++ )
        if ( !collides( get(pairs, i), get(combination, size(combination)-1) ) )
            add(combination, get(pairs, i));

    fwdCount = size(combination);

    clear(combination);

    add(combination, get(pairs, size(pairs)-1));

    for ( i = size(pairs)-2; i >= 0; i-- )
        if ( !collides( get(pairs, i), get(combination, size(combination)-1) ) )
            add(combination, get(pairs, i));

    bwdCount = size(combination);

    delete_vector(combination);

    return fwdCount > bwdCount ? fwdCount : bwdCount;
}

int greedy_solver( vector pairs ) {
    return greedy(pairs);
}
