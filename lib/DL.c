

/*******************************Includes***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include "DL.h"


/***************************Function Definition******************************************/

void createList(List* pList)
{

	pList->head = NULL;
    pList -> tail = NULL;
	pList->size = 0;
}

int listSize(List* pList)
{
	return pList->size;
}


void insertSortedNode(List* pList,ListEntry* val){
  

  //Create node 
  Node* temp = (Node*)malloc(sizeof(Node));
  if(temp == NULL)
  {
	  printf("No Memory Available\n");
	  return;
  }
  
  //Initialize node
  temp->data = val;
  temp->next = NULL;
  temp->prev = NULL;
  
  if(pList -> size == 0){ //empty list
    pList-> head = temp;
    pList -> tail = temp;
  }
  else{
    Node* ptr = pList -> head;    
    while(ptr != NULL &&  val->ID > ptr -> data -> ID ){ //find the node with id greater than input ID or reach end of list
        ptr = ptr ->next;
    }
    if(ptr == NULL){ //insert at tail
        temp -> prev = pList -> tail;
        pList -> tail -> next = temp;
        pList -> tail = temp;
    }
    else if(ptr == pList -> head){ //insert at head
        temp -> next = pList -> head;
        pList -> head -> prev = temp;
        pList -> head = temp;
    }
    else{ 
        ptr -> prev -> next = temp;
        temp -> prev = ptr -> prev;
        temp -> next = ptr;
        ptr -> prev = temp;
    }

  }


  pList->size ++;  

}




void printList(List* pList)
{
	Node* temp = pList->head;
	while(temp!=NULL)
	{
        printf("-------------------------------------\n");
        printf("Book Name: %s\n", temp->data->bookName);
        printf("Author Name: %s\n", temp->data->authName);
        printf("Book ID: %u\n", temp->data->ID);
        printf("Book Price: %.2f$\n", temp->data->bookPrice);
        printf("-------------------------------------\n");
        temp = temp -> next;
	}
    printf("\n");
}


bool deleteNode(List* pList,u32 ID)
{
  Node* temp = pList->head;
  while(temp != NULL && temp -> data -> ID < ID ){
    temp = temp -> next;
  }
  if(temp == NULL){
    return false;
  }
  if(temp -> data -> ID > ID){
    return false;
  }
  else{
    if(pList -> size == 1){
        pList -> head = NULL;
        pList -> tail = NULL;
        free(temp);
    }
    else if(temp == pList -> head){
        pList -> head = pList -> head -> next;
        pList -> head -> prev = NULL;
        free(temp);
    }
    else if(temp == pList -> tail){
        pList -> tail = pList -> tail -> prev;
        pList -> tail -> next = NULL;
        free(temp); 
    }
    else{
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
        free(temp);
    }
  }

  pList->size--;
  return true;
}

void clearList(List* pList)
{
	Node*temp = pList->head;
	while(temp!=NULL)
	{
		temp = temp->next;
		free(pList->head);
		pList->head = temp;
		pList->size--;
	}
}

bool searchNode(List * pList,u32 ID)
{
   Node* temp = pList->head;
   while(temp!=NULL)
   {    if(temp->data->ID > ID)
            break;
	   	if(temp->data->ID == ID)
		   return true;
	   temp = temp->next;
   }   
   return false;
}