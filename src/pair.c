/* ======================================================== *
 *              Trabalho Prático 3 - AEDS III               *
 *                                                          *
 * @ Pedro Otávio Machado Ribeiro.                          *
 *                                                          *
 * pair.c - Define funções para manipulação de uma TAD      *
 * pair.                                                    *
 * ======================================================== */

#include <stdlib.h>
#include <pair.h>

/* abaixo seguem a estrutura e suas funções básicas */
/* o funcionamento das funções é trivial */

struct pair_t {
    int fi,
        se;
};

pair new_pair( int pub, int house ) {

    pair p = ( pair ) malloc ( sizeof(struct pair_t ) );

    if ( pub < house ) {
        p->fi = house;
        p->se = pub;
    }
    else {
        p->fi = pub;
        p->se = house;
    }

    return p;
}

void delete_pair( pair p ) {
    free(p);
}

int getFirst( pair p ) {
    return p->fi;
}

int getSecnd( pair p ) {
    return p->se;
}

/*
* Compara duas bandeirolas pelo termino.
*
* Parâmetros:
*   a - par que representa a bandeirola a
*   b - par que representa a bandeirola b
*
* Retorna:
*   * bool - verdadeiro se a termina antes de b, falso caso contrario
*/
bool compare( pair a, pair b ) {
    return a->fi < b->fi;
}

/*
* Retorna se a bandeirola a cruza com a b.
*
* Parâmetros:
*   a - par que representa a bandeirola a
*   b - par que representa a bandeirola b
*
* Retorna:
*   * bool - verdadeiro se cruza, falso caso contrario
*/
bool collides( pair a, pair b ) {

    int aEven, bEven, aOdd, bOdd;

    if ( a->fi % 2 ) {
        aEven = a->se;
        aOdd  = a->fi;
    }
    else {
        aEven = a->fi;
        aOdd  = a->se;
    }

    if ( b->fi % 2 ) {
        bEven = b->se;
        bOdd  = b->fi;
    }
    else {
        bEven = b->fi;
        bOdd  = b->se;
    }

    return !( (aEven > bEven && aOdd > bOdd) || (aEven < bEven && aOdd < bOdd) );
}
