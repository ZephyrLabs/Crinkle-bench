/*
mem-bench, measures memory bandwidth of RAM
made by @ZephyrLabs
ltd. 2021-2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <chrono>
#include <iostream>
#include <cstring>

int main_array_1[64000];
int main_array_2[64000];
int main_array_3[64000];
int main_array_4[64000];

int i = 0;
int j = 0;
int q = 0;

int main(){

        std::chrono::time_point<std::chrono::system_clock> start, stop;

        double data_size = 10.24;

        for(q = 0; q < 64000; q++){
                main_array_1[q] = rand() % 255;
        }

        for(q = 0; q < 64000; q++){
                main_array_2[q] = rand() % 255;
        }

        for(q = 0; q < 64000; q++){
                main_array_3[q] = rand() % 255;
        }

        printf("\nstarting..");

        start = std::chrono::system_clock::now();

        for(i = 0; i < 10000; i++ ){

            memcpy(main_array_4, main_array_3, sizeof(int)*64000);

            memcpy(main_array_3, main_array_2, sizeof(int)*64000);

            memcpy(main_array_2, main_array_1, sizeof(int)*64000);

            memcpy(main_array_1, main_array_4, sizeof(int)*64000);

        }

        stop = std::chrono::system_clock::now();

        printf("\n..stopping");

        std::chrono::duration<double> lapsed = stop - start;

        printf("\ntime taken: %f seconds\n", lapsed.count());

        float bandwidth = data_size / lapsed.count();

        printf("\nachieved bandwidth: %f GB/s\n", bandwidth);

}   
