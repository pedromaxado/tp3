#include <stdio.h>
#include <vector.h>
#include <gohorse.h>

#define GOHORSE 'b'
#define DYNAMIC 'd'
#define GREEDY  'g'

int main() {

    int nPubs;
    char solver;

    if ( scanf("%c", &solver) ) {
        if ( scanf("%d", &nPubs) ) {

            int i = nPubs,
                house,
                pub;

            vector pairs = new_vector();

            while ( i-- ) {
                scanf("%d %d", &pub, &house);

                add( pairs, new_pair( pub, house ) );
            }

            sort( pairs );

            switch ( solver ) {

                case GOHORSE:
                    printf("%d\n", go_horse_solver( pairs ));
                    break;

                case DYNAMIC:
                    break;

                case GREEDY:
                    break;

                default:
                    break;
            }

            for ( i = 0; i < nPubs; i++ )
                delete_pair( get(pairs, i) );

            delete_vector( pairs );
        }
    }

    return 0;
}
