#include <stdlib.h>
#include "linkedListRef.h"

/*
 * Inserts the new key at the beginning of the list.
 * Returns 0 on success.
 * Return -1 if memory allocation fails.
 */
int LLInsertAtBeginning(LLElement **first, int key) {
    // TODO Implementation needed
    int r=0;
    LLElement * temp;
    temp = (LLElement *)malloc(sizeof(LLElement));
    if(temp != NULL) {
        temp->next = *first;
        temp->key = key;
        *first = temp;
    }
    else
        r=-1;
    return r;
}

/*
 * Inserts the new key at the end of the list.
 * Returns 0 on success.
 * Return -1 if memory allocation fails.
 */
int LLInsertAtEnd(LLElement **first, int key) {
    // TODO Implementation needed
    
    LLElement * new;
    LLElement ** temp;
    int r=0;
    int i=0;
    int size;
    size = LLSize (*first);
    if (first!=NULL){
        new=(LLElement*)malloc(sizeof(LLElement));
        new->key=key;
        temp=first;
        while (i<size){
        temp=&(*temp)->next;
        i++;
        }
        new->next=NULL;
        *temp=new;
    }
    else {
        r=-1;
    }
    return (r);

 
}

/*
 * Inserts the new key at the specified positon of the list.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns 0 on success.
 * Return -1 if memory allocation fails.
 */
int LLInsertAtPosition(LLElement **first, int key, int position) {
    // TODO Implementation needed
    LLElement * new;
    LLElement ** temp;
    int r=0;
    int i=0;
    if (first!=NULL){
        new=(LLElement*)malloc(sizeof(LLElement));
        new->key=key;
        temp=first;
        while (i<position){
            temp=&((*temp)->next);
            i++;
        }
        
        new->next=*temp;
        *temp=new;   
    }
    else {
        r=-1;
    }
    return (r);
}

/*
 * Returns the size of the list.
 */
int LLSize(LLElement *first) {
    // TODO Implementation needed
    LLElement * temp;
    int i=0;
    temp=first;
    while (temp!=NULL){
      temp=temp->next;  
      i++;
    }
    return (i);
    
}

/*
 * Gives the key at the specified position. * 
 * 
 * Returns 0 on success.
 * Returns -1 if there is no key at the specified position
 */ 
int LLGetKey(LLElement *first, int position, int *key) {
    // TODO Implementation needed
    
    int r=0;
    int i=0;
    while (i<position && first!=NULL){
        first=first->next;
        i++;
    }
    if (first!=NULL){
        *key=first->key;
        
    }
    else{
       r=-1;
    }
    return r;
}

/*
 * Gives the position of the first element, starting from startPosition, that
 * has the specified key.
 * 
 * Returns 0 on success.
 * Returns -1 if not found. 
 */ 
int LLFindKey(LLElement *first, int key, int startPosition, int *position) {
    // TODO Implementation needed
    int size=LLSize(first);
    int r=0;
    int c=0;
    int i=0;
    *position=-1;
    while (i<startPosition)
    {
        first=first->next;
        i++;
    }       
    while (first!=NULL && *position==-1)
    {   
        if (first->key == key){
            *position=i;
        }
    first=first->next;
    i++;
    }
    if (size==i)
        r=-1;
    return r;
    }

/*
 * Remove the first element of the list.
 * 
 * Returns 0 on success.
 * Returns -1 in csae of empty list.
 */
int LLRemoveFirst(LLElement **first) {
    // TODO Implementation needed
    int r=0;
    LLElement * temp;
    if(*first != NULL) {
        temp = *first;
        *first = (*first)->next;
        free(temp);
    }
    else{
     r=-1;   
    }
    return r;
  
}

/*
 * Remove the last element of the list.
 * 
 * Returns 0 on success.
 * Returns -1 in csae of empty list.
 */
int LLRemoveLast(LLElement **first) {
    // TODO Implementation needed
    int r=0;
    LLElement ** temp;
    if(*first!=NULL){
        temp=first;
        while((*temp)->next != NULL){
            temp = &((*temp)->next);
        }
        free(*temp);
        *temp = NULL;
    }
    else{
        r=-1;
    }
    return r;
}

/*
 * Remove the element at the specified position.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns 0 on success.
 * Returns -1 in case it does not exist any element at the specified position
 */
int LLRemoveAtPosition(LLElement **first, int position) {
    // TODO Implementation needed
    LLElement ** temp;
    LLElement * prox;
    
    int r=0;
    int i=0;
    
        temp=first;
        while(i<position && *temp!=NULL){
            temp=&((*temp)->next);
            i++;
        }
        if (*temp!=NULL){
            prox = (*temp)->next;
            
            if ((*temp)->next!=NULL){
                *temp=(*temp)->next;   
            }
        free(temp);
        }
        else{
         r=-1;
        }
        return r;
}

/*
 * Empties the list.
 * Returns 0 on success.
 * Return -1 in case of emtpy list. 
 */
int LLEmptyList(LLElement **first) {
    // TODO Implementation needed
    int size=LLSize(*first);
    int i=0;
    int r = 0;
    LLElement * temp;
    if(size!=0){
        while (i<size){
            temp = *first;
            *first = (*first)->next;
            free (temp);
            i++;
        }
    }
    else{
        r = -1;
    }
    return r;
}