#include "array.h"

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

        }
        printf("]\n");

    }
    else{
        printf("user didn't provide any data\n");
    }
}

void sumarray(IntArray array){
    int tempsum = 0;
    for(int p = 0; p < array.size; p++){
        tempsum+= array.data[p];
    }
    printf("the sum of array equals %d\n", tempsum);

}

void pushpull(IntArray *array, int index, int value, enum MODE mode){
    // int len = array->size;
    if(mode == INSERT){
        if (index < 0) index = 0;
        if (index > array->size) index = array->size;

        int *temp = realloc(array->data, sizeof(int) * (array->size + 1));
        if (temp != NULL){
            array->data = temp;
            for(int i = array->size; i > index; i--){
                array->data[i] = array->data[i-1];
                
                
            }
            array->data[index] = value;
            array->size++;
        }
        else{
            printf("realloc erorr");
        }

    }
    else if(mode == DELETE){
        for(int i = index; i < array->size; i++){
           array->data[i] = array->data[i+1];    
        }
        array->size--;
    }
    else{
        printf("mode invalid");
    }

}

void append(IntArray *array, struct Args *args){
    int *temp = realloc(array->data, sizeof(int) * (array->size + 1));
    if (temp != NULL){
        array->data = temp;
        int tempindex = (args->index == -1? array->size : args->index);
        printf("%d %d", args->index, args->value);
        if (args->index == -1){
            array->size++;
            array->data[tempindex] = args->value; 
        }
        else{
            pushpull(array, tempindex, args->value, INSERT);
        }

    }
    else{
        printf("realloc error");
    }
    


}

void pop(IntArray *array, struct Args *args){
    
    if(args->index == -1){
        array->size--;
        
    }
    else{
        //make index safe
        if (args->index > array->size) args->index = array->size;
        if (args->index < 0) args->index = 0;

        pushpull(array, args->index, args->value, DELETE);
        

    }

    
    
}


//sorting
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
            if (i+1<len && array->data[i] > array->data[i+1]){
                swap(array, i);
                swapped = 1;
            }


        }
        if (swapped == 0){
        break;
        }
    }
    
}

struct Args* getargs(enum MODE mode, IntArray *array){
    char buff[100];
    if(mode == INSERT){
        printf("provide number and index, for example:\n1 1(or just one number to append)\n>");
        while(1){
            if (fgets(buff, sizeof(buff), stdin) != NULL){
                struct Args tempargs = {0, -1};
                struct Args *r = (struct Args *)malloc(sizeof(struct Args));
                // printf("inserting %d to %d index ...", tempargs.value, tempargs.index);
                if(r == NULL){
                    printf("malloc error");
                    return NULL;
                }
                int a = sscanf(buff, "%d %d", &tempargs.value, &tempargs.index);
                r->index = tempargs.index;
                r->value = tempargs.value;
                if (a == 2 || a == 1){
                    return r;
                }
            
                else{
                    free(r);
                    printf("use valid arguments\n");
                    return NULL;
                }
            }
            
        }
    }
    else if(mode == DELETE){
        printf("provide index of which element you want to delete\n(p for standard pop)\n>");
        while (1){
            if (fgets(buff, sizeof(buff), stdin) != NULL){
                struct Args tempargs = {0, -1};//value doesnt matter for this op
                struct Args *r = (struct Args *)malloc(sizeof(struct Args));
                // printf("inserting %d to %d index ...", tempargs.value, tempargs.index);
                if(r == NULL){
                    printf("malloc error");
                    return NULL;
                }
                if(buff[0] == 'P' || buff[0] == 'p'){
                    r->index = array->size;
                    return r;
                }
                int a = sscanf(buff, "%d", &tempargs.index);
                r->index = tempargs.index;
                if (a == 1){
                    return r;
                }
                    
                else{
                    free(r);
                    printf("use valid arguments\n");
                }
            }
        }
    }
    else{
        printf("invalid mode");
    } 
   

}