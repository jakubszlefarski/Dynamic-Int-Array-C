#include "array.h"

enum OPERATION useroplogic(int intinput, IntArray *intarray){
    enum OPERATION tempaction = inttoenum(intinput);
    switch (tempaction)
    {
    case QUIT:
        printf("shutting down. . .\n");
        return QUIT;

    case SUM:
        sumarray(*intarray); 
        return SUM;
    case APPEND:
        //getting args
        struct Args* argsptr = getargs(INSERT, intarray);
        append(intarray, argsptr);
        printf("\n");
        printarray(*intarray);
        free(argsptr);
        return APPEND;
    case POP:
        argsptr = getargs(DELETE, intarray);
        pop(intarray, argsptr);
        printarray(*intarray);
        free(argsptr);
        return POP;
    case SORT:
        sortarray(intarray); //bubble sort
        printf("sorted ");
        printarray(*intarray);
        return SORT;
    default:
        printf("error: undefined behavior\n");
        return UNDEFINED;
    }
    
    
    
    
    
}


enum OPERATION getuserop(IntArray array){
    while(1){
    char buff[100];
    int intinput = 0;
    printf("array operations: \n1.quit\n2.sum\n3.append\n4.pop\n5.sort\n>");
    if(fgets(buff, sizeof(buff), stdin) != NULL){
        if (sscanf(buff, "%d", &intinput) == 1){
            enum OPERATION op = useroplogic(intinput, &array);
            return op;
        }
        else{
            printf("provide valid op!");
        }
    }
    }

}


int main(){

    
    IntArray array = {NULL, 0};

    char buffer[32];
    int input;

    while(1){


        int *temp = realloc(array.data, sizeof(int) * (array.size + 1));
        if(temp == NULL) {
            printf("realoc error"); 
            break;
        }
        array.data = temp; //change through memory adresses
        printf("enter %d number (or q to quit)\n>", array.size + 1);

        
        if (fgets(buffer, sizeof(buffer), stdin) != NULL){ //takes input
            if (buffer[0] == 'Q' || buffer[0] == 'q'){
                printf("your array is complete\n");
                break;
            }

            if (sscanf(buffer, "%d", &input) == 1){
                printf("succes\n");
            
                array.data[array.size] = input;
                array.size++;

            }
            else{
                printf("error, provide valid integer\n");
           
            }  

        }

    }
    printarray(array);
    enum OPERATION userop = UNDEFINED;
    while (userop != QUIT)
    {
        userop = getuserop(array);
    }
    
    free(array.data);
    return 0;

}