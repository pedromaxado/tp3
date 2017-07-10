#include <stdio.h>
#include <greedy.h>

/*
* Soluciona o problema em si por meio de
* guloso.
*
* Parâmetro:
*   * pairs - vetor de bandeirolas
*
* Retorna:
*   * int - número máximo de bandeirolas que não se cruzam
*/
int greedy( vector pairs ) {

    int i,
        fwdCount = 0,
        bwdCount = 0;

    // vetor para armazenar combinação
    vector combination = new_vector( size(pairs) );

    // assume primeiro como otimo
    add(combination, get(pairs, 0));

    // pega todos os proximos que não se colidem em sequencia
    for ( i = 1; i < size(pairs); i++ )
        if ( !collides( get(pairs, i), get(combination, size(combination)-1) ) )
            add(combination, get(pairs, i));

    fwdCount = size(combination);

    clear(combination);

    // assume o ultimo como verdade
    add(combination, get(pairs, size(pairs)-1));

    // faz a mesma coisa só que ao contrário
    for ( i = size(pairs)-2; i >= 0; i-- )
        if ( !collides( get(pairs, i), get(combination, size(combination)-1) ) )
            add(combination, get(pairs, i));

    bwdCount = size(combination);

    delete_vector(combination);

    // retorna o tamanho da maior combinação encontrada
    return fwdCount > bwdCount ? fwdCount : bwdCount;
}

int greedy_solver( vector pairs ) {
    return greedy(pairs);
}
