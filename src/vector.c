/* ======================================================== *
 *              Trabalho Prático 0 - AEDS III               *
 *                                                          *
 * @ Pedro Otávio Machado Ribeiro.                          *
 *                                                          *
 * vector.c - Define funções para manipulação de uma TAD    *
 * vetor implementada com array de inteiros.                *
 * ======================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "vector.h"

#define INIT_CAPACITY 16

/*
* Struct da TAD encapsulada.
*
* Membros:
*   * capacity - inteiro que armazena o capacidade atual do vetor
*   * size     - inteiro que armazena o tamanho atual do vetor
*   * array    - Vetor em si que armazena os elementos do tipo int
*/
struct vector_t {

	int capacity;
	int size;

	type* array;
};

/*
* Aumenta o tamanho do array que contém os elementos.
*
* Parâmetros:
*   * v - vetor
*   * m - tamanho desejado do vetor
*/
void reserveVector( vector v, int m ) {

	if ( m > v->capacity ) {

		v->capacity = m;

		type* aux = malloc( sizeof( int ) * v->capacity );

		for ( int i = 0; i < v->size; i++ )
			aux[i] = v->array[i];

		free( v->array );

		v->array = aux;
	}
}

vector new_vector() {

	vector v = ( vector ) malloc ( sizeof( struct vector_t ) );

	v->size = 0;
	v->capacity = INIT_CAPACITY;

	v->array = ( type* ) malloc( INIT_CAPACITY * sizeof( type ) );

	return v;
}

void delete_vector( vector v ) {
	free(v->array);
	free(v);
}

void add( vector v, type k ) {

	if ( v->size == v->capacity )
		reserveVector( v, 2*v->capacity );

	v->array[v->size] = k;
	v->size++;
}

type get( vector v, int pos ) {

	type k = NULL;

	if ( pos < v->size )
		k = v->array[pos];

	return k;
}

void pop_back( vector v ) {
	v->size--;
}

int size( vector v ) {
	return v->size;
}

int capacity( vector v ) {
    return v->capacity;
}

bool isVectorEmpty( vector v ) {
	return v->size == 0;
}

void swap( type* a, type* b ) {
    type aux = *a;

    *a = *b;
    *b = aux;
}

int partition( type* vec, int p, int r ) {

    type pivot = vec[r];
    int i = p-1;

    for( int j = p; j <= r-1; j++ ) {
        if ( compare(vec[j], pivot) ) {
            i++;
            swap( &vec[i], &vec[j] );
        }
    }

    swap( &vec[i+1], &vec[r] );

    return i+1;
}

void quick_sort( type* vec, int p, int r ) {

    if ( p < r ) {
        int q = partition( vec, p, r );
        quick_sort( vec, p, q-1 );
        quick_sort( vec, q+1, r );
    }
}

void sort( vector v ) {
	quick_sort( v->array, 0, v->size-1 );
}
