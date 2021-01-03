/* 
prime-crunch, prime number benchmark
made by @ZephyrLabs
ltd. 2020-2021
*/

#include <stdio.h>
#include <time.h>

int main(){
        // main variables
        int flag, ceiling, compare;
        time_t start;
        time_t stop;
        // ~main variables

        // main code
        compare = 0;
        printf("\n################");
        printf("\n# prime-crunch #");
        printf("\n################\n");
        printf("\nenter the search limit: ");
        scanf("%d", &ceiling);

        start = time(NULL);

        for(int i = 1; i <= ceiling; i++){
                flag = 1;
                for (int j = 2; j <= i/2; j++){
                        if (i%j == 0){
                                flag = 0;
                                break;
                        }
                }

                if(flag == 1){
                        if(i > compare){
                                compare = i;
                        }
                }

        }
        stop = time(NULL);

        printf("last prime: %d", compare);
        int lapsed = stop - start;
        printf("\ntime elapsed: %d", lapsed);
        printf("\nclosing program..\n");
        // ~main code

        return(0);
}
