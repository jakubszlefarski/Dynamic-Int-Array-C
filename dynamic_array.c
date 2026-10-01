#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdarg.h>

typedef struct 
{
    int *data;
    int size;
} IntArray;

enum OPERATION{
    QUIT,
    SUM,
    APPEND,
    POP,
    SORT,
    UNDEFINED
};

int inttoenum(int intinput){
     
    switch (intinput)
    {
    case 1:
        return QUIT;
    case 2:
        return SUM;
    case 3:
        return APPEND;
    case 4:
        return POP;
    case 5:
        return SORT;    
    default:
        return UNDEFINED;
    }
}
void printarray(IntArray array){
    if (array.size != 0){
        printf("array:\n[");
        for (int i = 0; i < array.size; i++){
            if (i != array.size -1){
                printf("%d, ", array.data[i]);

            }
            else{
                printf("%d", array.data[i]);
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

int sumarray(IntArray array){
    int tempsum = 0;
    for(int p = 0; p < array.size; p++){
        tempsum+= array.data[p];
    }
    printf("the sum of array equals %d", tempsum);
    return  tempsum;

}

void swap(IntArray *array, int currentindex){ //via indexes
    int a = currentindex;
    int b = a + 1;
    int temp = array->data[a];
    array->data[a] = array->data[b];
    array->data[b] = temp;

}

void sortarray(IntArray *array){
    int len = array->size;
    for (int n = 0; n < len; n++){
        int swapped = 0;
        for (int i = 0; i < len; i++){
            // int swapped = 0;
            if (i+1<=len && array->data[i] > array->data[i+1]){
                swap(array, i);
                swapped = 1;
            }


        }
        if (swapped == 0){
        break;
        }
    }
    
}

enum OPERATION useroplogic(int intinput, IntArray *intarray){
    enum OPERATION tempaction = inttoenum(intinput);
    switch (tempaction)
    {
    case QUIT:
        printf("shutting down. . .\n");
        break;
    case SUM:
        sumarray(*intarray); 
        break;
    case APPEND:
        /* code */
        break;
    case POP:
        /* code */
        break;
    case SORT:
        sortarray(intarray); //bubble sort
        printf("sorted ");
        printarray(*intarray);
        break;
    case UNDEFINED:
        /* code */
        break;
        
        default:
        printf("error\n");
        break;
    }
    
    
    
    
    
}


void getuserop(IntArray array){
    while(1){
    char buff[100];
    int intinput = 0;
    printf("array operations: \n1.quit\n2.sum\n3.append\n4.pop\n5.sort\n>");
    if(fgets(buff, sizeof(buff), stdin) != NULL){
        if (sscanf(buff, "%d", &intinput) == 1){
            useroplogic(intinput, &array);
            break;
        }
        else{
            printf("provide valid op!");
        }
    }
    }

}




// int append(int array.size, int *array){
//     ;
// }


int main(){

    //init
    
    IntArray array = {NULL, 0};
    // itt
    // int *array = NULL;

    // if (array == NULL){
    //     printf("realloc error\n");
    //     return 1;        
    // }



    char buffer[32];
    int input;
    // int array.size = 1;
    while(1){
        // if (array.size > 0){
        //     int *temp = realloc(array, sizeof(int) * array.size);
        //     if (temp == NULL){
        //         printf("realloc error\n");
        //         returne 1;
        //     }

        //     array = temp; //podmiana przez adresy!

        // }

        int *temp = realloc(array.data, sizeof(int) * array.size + 1);
        array.data = temp; //podmiana przez adresy!
        printf("enter %d number (or q to quit)\n>", array.size + 1);

        
        if (fgets(buffer, sizeof(buffer), stdin) != NULL){ //takes input
            if (buffer[0] == 'Q' || buffer[0] == 'q'){
                printf("your array is complete\n");
                break;
            }

            if (sscanf(buffer, "%d", &input) == 1){
                printf("succes\n");
               
                array.data[array.size] = input;
                
                // else{}

            }
            else{
                printf("error, provide valid integer\n");
                array.size--;
            }  


        }
        array.size++;

    }
    printarray(array);
    getuserop(array);
    // printarray(array);
    // sumarray(array);




    free(array.data);
    return 0;

    //musi automatycznie wyluskiwac metadane ze struktur
    //dodac podstawowe operacje na listach z pythona
}