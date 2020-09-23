#include "SqList.h"

// Create a SqList
Status InitList(SqList * List){
	(*List).elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(!(*List).elem) exit(OVERFLOW);
	(*List).length = 0;
	(*List).listsize = LIST_INIT_SIZE;	
    return OK;
}

// Delete a SqList
Status DestroyList(SqList * List){
	if((*List).elem == NULL || List == NULL) return ERROR;
	free(List);
	(*List).elem = NULL;
	(*List).length = 0;
	(*List).listsize = 0;
	return OK;
}

// Clear a SqList
Status ClearList(SqList * List){
	if((*List).elem == NULL || List == NULL) return ERROR;
	(*List).length = 0;
	return OK;
}

// If SqList is EMPTY return TRUE, else return FALSE
Bool ListEmpty(SqList List){
	return List.length == 0 ? TRUE : FALSE; 
}

// Return SqList numbers of elements
int ListLength(SqList * List){
	return (*List).length;
}

// Return the i-th element
Status GetElem(SqList * List, int i, ElemType * e){
	if (i < 1 || i > (*List).length) return ERROR;
	*e = (*List).elem[i - 1];
	return OK;
}

// Return the first E element have the compare() relation
int LocateElem(SqList * List, ElemType e, Status(Compare)(ElemType,ElemType)){
	int i = 1; // Index
	ElemType* p = (*List).elem;
	if((*List).elem == NULL || List == NULL) return ERROR;
	while (i <= List->length && !Compare(*p++,e))
	{
		++i;
	}
	if(i <= List->length){
		return i;
	}else{
		return 0;
	}
}

// Retuen prior Element
Status PriorElem(SqList * List, ElemType cur_e, ElemType * pre_e){
	int i = 0; // Index
	if (List->elem == NULL || List->length< 2) return ERROR;
	while (i < List->length && List->elem[i] != cur_e) ++i;
	if (i >= List->length || i == 0) return ERROR;
	*pre_e = List->elem[i-1];
	return OK;
}

// Retuen next Element
Status NextElem(SqList * List, ElemType cur_e, ElemType * next_e){
	int i = 0;
	if (List->elem == NULL || List->length< 2) return ERROR;
	while (i < List->length && List->elem[i] != cur_e) ++i;
	if(i >= List->length-1) return ERROR;
	*next_e = List->elem[i+1];
	return OK;
}

// Insert Element
Status ListInsert(SqList * List, int i, ElemType e){
	ElemType * newbase;
	ElemType * p, * q;

	if(List == NULL || (*List).elem == NULL) return ERROR;

	if(i >= (*List).length || i < 1) return ERROR;

	if((*List).length >= (*List).listsize){
		newbase = (ElemType*)realloc((*List).elem, ((*List).listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) exit(OVERFLOW);
		(*List).elem = newbase;
		(*List).listsize += LISTINCREMENT;
	}
	q = &(*List).elem[i-1];
	
	for(p = &(*List).elem[(*List).length - 1]; p >= q; --p) *(p + 1) = *p;
	*q = e;
	(*List).length++;

	return OK;
}

// Delete Element & Retuen Delete Element
Status ListDelete(SqList * List, int i, ElemType * e){
	ElemType * p , * q;
	if(List == NULL || List->elem == NULL) return ERROR;
	if(i >= (*List).length || i < 1) return ERROR;
	p = &(*List).elem[i - 1];
	*e = *p;
	q = (*List).elem + (*List).length - 1;
	for(++p; p <= q; ++p) *(p - 1) = *p;
	(*List).length--;

	return OK;
}

// visit()
void ListTraverse(SqList * List, void(Visit)(ElemType)){
	for(int i = 0; i < List->length; i++) Visit(List->elem[i]);
}
