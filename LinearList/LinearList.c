#include "lib/ADT_List.h"


int main(){
    int* newarray;
    InitList(newarray);
    for (int i = 0; i < LISTLEN; i++){
        newarray[i] = i;
    }
    for (int i = 0; i < LISTLEN; i++)
    {
        printf("newarray[%d]: %d\n",i,newarray[i]);
    }
    
    return EXIT_SUCCESS;
}