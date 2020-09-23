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
Status GetElem(SqList *, int, ElemType *);

// Return the first E element have the compare() relation
int LocateElem(SqList *, ElemType, Status(Compare)(ElemType,ElemType));

// Retuen prior Element
Status PriorElem(SqList *, ElemType, ElemType *);

// Retuen next Element
Status NextElem(SqList *, ElemType, ElemType *);

// Insert Element
Status ListInsert(SqList *, int, ElemType);

// Delete Element & Retuen Delete Element
Status ListDelete(SqList *, int, ElemType *);

// visit()
void ListTraverse(SqList *, void(Visit)(ElemType));


#endif
