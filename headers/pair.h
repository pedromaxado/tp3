/* ======================================================== *
 *              Trabalho Prático 3 - AEDS III               *
 *                                                          *
 * @ Pedro Otávio Machado Ribeiro.                          *
 *                                                          *
 * pair.c - Define a estrutura de dados e cabeçalho de      *
 * funções relacionadas a manipulação de um TAD pair        *
 * implementado com uma estrutura simples.                  *
 * ======================================================== */

#ifndef PAIR_H_
#define PAIR_H_

#include <stdbool.h>

typedef struct pair_t* pair;

/* o que as funções abaixo fazem é sugerido pelo nome */

pair new_pair( int pub, int house );

void delete_pair( pair p );

int getPub( pair p );

int getHouse( pair p );

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
bool compare( pair a, pair b );

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
bool collides( pair a, pair b );

#endif
