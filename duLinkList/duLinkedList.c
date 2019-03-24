#include<stdio.h>
#include<stdlib.h>
#include "../head/duLinkedList.h"

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
		*L=(DuLinkedList)malloc(sizeof(DuLNode));/*create the head node*/
		if(*L){							     /*check out if the head is created,return the success or error*/
		(*L)->next=NULL;
		(*L)->prior=NULL;
		return SUCCESS;
	}
	printf("Initialize error!");
	return ERROR;
	
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLinkedList p,s;
	p=*L;              /*make pointer p point the head node*/
	while(p){		   /*check out if the node exits while traversing*/
		s=p->next;	   
		free(p);       /*destroy the node pointed by p*/
		p=s;		   /*make pointer p point the next node*/
	}		
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	ElemType data2;
	if(!q){													/*check if the inserted node existed*/
		printf("The node don't exit,please create one"		/*create a new node if the node doesn't exist*/
			".\nTell me the data:");
		scanf("%d",&data2);
		q=(DuLinkedList)malloc(sizeof(DuLNode));
		q->data=data2;
	}
	q->prior=p->prior;									    /*make the pointer prior of q point the last node before p*/
	q->next=p;												/*make the next of q point to p*/
	if(p->prior)
		p->prior->next=q;										/*make the next of the node before p point q*/
	p->prior=q;												/*make the pointer prior of p point the node of q*/

	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	ElemType data;
	if(!q){													/*check if the inserted node existed*/
		printf("The node don't exit,please create one"		/*create a new node if the node doesn't exist*/
			".\nTell me the data:");
		scanf("%d",&data);
		q=(DuLinkedList)malloc(sizeof(DuLNode));
		q->data=data;
	}
	q->next=p->next;										/*make the pointer next of q point the next node after p*/
	q->prior=p;												/*make the prior of q point to the q*/
	if(p->next)
		p->next->prior=q;									/*make the prior of the node after point q*/
	p->next=q;												/*make the pointer next of p point the node of q*/

	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	DuLinkedList s;
	if(!p->next){								/*check if the node after p exists*/
		printf("There is no node after p!");
		return ERROR;
	}
	*e=p->next->data;							/*assign the value of the data to e*/
	s=p->next;
	p->next=p->next->next;						/*make the pointer next point of p the one after the node we want to delete*/
	free(s);									/* don't forget to destroy the node*/

	return SUCCESS;	
}
 
/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit 
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	DuLinkedList p;
	
	p=L->next;											/*treverse the list from the head node*/
	while(p){
		(*visit)(p->data);
		p=p->next;										/*use the next pointer to treverse the list*/
	}
}

