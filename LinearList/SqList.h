/*
 * SqList.h
 *
 * Create - 2020/09/23
 *
 * */

#ifndef SQLIST_H
#define SQLIST_H

#include "../Status.h"
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

// SqList Structure define
typedef struct{
    ElemType *elem;
    int length;
    int listsize;
}SqList;

// Create a SqList
Status InitList(SqList *);

// Delete a SqList
Status DestroyList(SqList *);

// Clear a SqList
Status ClearList(SqList *);

// If SqList is EMPTY return TRUE, else return FALSE
Bool ListEmpty(SqList *);

// Return SqList numbers of elements
int ListLength(SqList *);

// Return the i-th element
ElemType GetElem(SqList *, int, SqList *);

// Return the first E element have the compare() relation
int LocateElem(SqList *, int, int *);

// Retuen prior Element
SqList* PriorElem(SqList *, SqList *, SqList *);

// Retuen next Element
SqList* NextElem(SqList *, SqList *, SqList *);

// Insert Element
Status ListInsert(SqList *, int, SqList *);

// Delete Element & Retuen Delete Element
SqList* ListDelete(SqList *, int, SqList *);

// visit()
Status ListTraverse(SqList *);


#endif
