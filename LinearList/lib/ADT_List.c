#include "ADT_List.h"

int* InitList(){

    int* list = (int*)malloc(LISTLEN * sizeof(int));

    return list;
}

int ShowList(int* list){

    for(int i = 0; i < LISTLEN; i++)
	printf("%d\n",list[i]);

    return EXIT_SUCCESS;
}

int DestroyList(int * list){

    return EXIT_SUCCESS;
}
