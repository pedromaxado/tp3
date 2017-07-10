/* ======================================================== *
 *              Trabalho Prático 3 - AEDS III               *
 *                                                          *
 * @ Pedro Otávio Machado Ribeiro.                          *
 *                                                          *
 * gohorse.c - Define a função responsável por solucionar   *
 * o probema por meio de programação dinâmica.              *
 * ======================================================== */

#include <gohorse.h>
#include <vector.h>

/*
* Soluciona o problema em si por meio de
* força bruta.
*
* Parâmetro:
*   * pairs - vetor de bandeirolas
*
* Retorna:
*   * int - número máximo de bandeirolas que não se cruzam
*/
void go_horse( vector pairs, vector combinations, int count, int *max ) {

    // ao chegar no fim, checa se o numero de bandeirolas
    // eh maior que o máximo até então encontrado
    if ( count == size(pairs) ) {
        if ( size(combinations) > *max )
            *max = size(combinations);

        return;
    }

    // nao adiciona uma aresta
    go_horse( pairs, combinations, count+1, max );

    // se a aresta atual nao se cruza com a ultima aresta adicionada
    // ela eh adicionada na combinação
    if ( !collides( get(pairs, count), get(combinations, size(combinations)-1) ) ) {
        add( combinations, get(pairs, count) );
        go_horse( pairs, combinations, count+1, max );
        pop_back( combinations );
    }
}

int go_horse_solver( vector pairs ) {

    int max = 0;

    // vetor para armazenar uma possível combinação de bandeirolas
    vector combinations = new_vector( size(pairs) + 1 );
    add( combinations, new_pair(-1, -1) );

    // chama o cavalo
    go_horse( pairs, combinations, 0, &max );

    delete_pair( get(combinations, 0) );
    delete_vector( combinations );

    return max-1;
}
