/* ======================================================== *
 *              Trabalho Prático 3 - AEDS III               *
 *                                                          *
 * @ Pedro Otávio Machado Ribeiro.                          *
 *                                                          *
 * dp.c - Define a função responsável por solucionar o      *
 * probema por meio de programação dinâmica.                *
 * ======================================================== */

#include <stdlib.h>
#include <dp.h>

/*
* Soluciona o problema em si por meio de
* programação dinâmica.
*
* Parâmetro:
*   * pairs - vetor de bandeirolas
*
* Retorna:
*   * int - número máximo de bandeirolas que não se cruzam
*/
int dynamic( vector pairs ) {

    int i, j,
        max = 1,
        *dp = ( int* ) malloc( size(pairs)*sizeof(int) );

    // inicializa a pd com 1, representando assim o menor conjunto
    // que se pode formar com uma bandeirola
    for ( i = 0; i < size(pairs); i++ )
        dp[i] = 1;

    // para cada bandeirola
    for ( i = 1; i < size(pairs); i++ ) {
        pair ref = get(pairs, i);

        // procura a ultima que nao cruza e verifica se o tamanho da subsolução
        // é maior que a atual
        for ( j = i-1; j >= 0; j-- ) {
            if ( !collides( ref, get(pairs, j) ) && dp[i] < dp[j] + 1 ) {
                dp[i] = dp[j] + 1;

                if ( dp[j] == max )
                    break;
            }
        }

        if ( dp[i] > max )
            max = dp[i];
    }

    free(dp);

    return max;
}

int dp_solver( vector pairs ) {
    return dynamic( pairs );
}
