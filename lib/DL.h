#include "stdTypes.h"
#include "stdbool.h"
#include "../system/config.h"
#ifndef SL_H
#define SL_H

/****************************Data Type Declaration**************************************/

typedef struct Book{

    s8  bookName [MAX_BOOK_NAME_LENGTH+1]; //+1 due to the need of \0 at the end
    s8  authName [MAX_AUTH_NAME_LENGTH+1]; //+1 due to the need of \0 at the end
    u32 ID;
    f32 bookPrice;
} 
 ListEntry;

typedef struct Node
{
	ListEntry* data;
	struct Node* next;
    struct Node* prev;
}Node;

typedef struct List
{
	Node* head;
    Node* tail;
	int size;
}List;

// typedef enum 
// {
// 	false,
// 	true
// }bool;

/*******************************Macro Definition*****************************************/
#define NULL ((void *)0)

/************************Function Declaration******************************************/
void createList(List* pList);
int listSize(List* pList);
void insertSortedNode(List* pList,ListEntry* val);
void printList(List* pList);
bool deleteNode(List* pList,int ID);
void clearList(List* pList);
bool searchNode(List * pList,u32 ID);








#endif