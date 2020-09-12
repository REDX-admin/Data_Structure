#include "ADT_List.h"

int InitList(int * list){
    list = (int*)malloc(LISTLEN * sizeof(int));
    if(!list) return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int DestroyList(int * list){
    return EXIT_SUCCESS;
}