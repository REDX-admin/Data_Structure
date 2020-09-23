#include "SqList.h"

// Create a SqList
Status InitList(SqList * List){
	(*List).elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(!List->elem) exit(OVERFLOW);
	List->length = 0;
	List->listsize = LIST_INIT_SIZE;	
    return OK;
}


