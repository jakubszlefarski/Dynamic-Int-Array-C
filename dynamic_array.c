#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdarg.h>

typedef struct IntArray
{
    int *array;
    int size;
};



void printarray(int len, int *array){
    if (len != 0){
        printf("array:\n[");
        for (int i = 0; i < len; i++){
            if (i != len -1){
                printf("%d, ", array[i]);

            }
            else{
                printf("%d", array[i]);
            }
            // printf("%d\n", *array);
            // array++;
        }
        printf("]\n");

    }
    else{
        printf("user didn't provide any data\n");
    }
}

int sumarray(int len, int *array){
    int tempsum = 0;
    for(int p = 0; p < len; p++){
        tempsum+= array[p];
    }
    printf("the sum of array equals %d", tempsum);
    return tempsum;

}

int append(int len, int *array){

}


int main(){

    //init
    int turn = 0; //liczba elementów
    
    // itt
    int *array = NULL;
    // if (array == NULL){
    //     printf("realloc error\n");
    //     return 1;        
    // }



    char buffer[32];
    int input;
    // int turn = 1;
    while(1){
        // if (turn > 0){
        //     int *temp = realloc(array, sizeof(int) * turn);
        //     if (temp == NULL){
        //         printf("realloc error\n");
        //         return 1;
        //     }

        //     array = temp; //podmiana przez adresy!

        // }

        int *temp = realloc(array, sizeof(int) * turn);
        array = temp; //podmiana przez adresy!
        printf("enter %d number (or q to quit)\n>", turn + 1);

        
        if (fgets(buffer, sizeof(buffer), stdin) != NULL){ //takes input
            if (buffer[0] == 'Q' || buffer[0] == 'q'){
                printf("your array is complete\n");
                break;
            }

            if (sscanf(buffer, "%d", &input) == 1){
                printf("succes\n");
               
                array[turn] = input;
                
                // else{}

            }
            else{
                printf("error\n");
            }  


        }
        turn++;

    }
    
    printarray(turn, array);
    sumarray(turn, array);




    free(array);
    return 0;

    //nie kompiluje sie
}