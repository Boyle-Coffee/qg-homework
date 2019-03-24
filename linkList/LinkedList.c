#include "../head/linkedList.h"
#include <stdlib.h>
#include <stdio.h>

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	*L=(LinkedList)malloc(sizeof(LNode));/*create the head node*/
	if(*L){						 /*check out if the head is created,return the success or error*/
		(*L)->next=NULL;
		return SUCCESS;
	}
	printf("Initialize error!");
	return ERROR;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LinkedList p,s;
	p=*L;              /*make pointer p point the head node*/
	while(p){		   /*check out if the node exits while traversing*/
		s=p->next;	   
		free(p);       /*destroy the node pointed by p*/
		p=s;		   /*make pointer p point the next node*/
	}		
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	ElemType data;
	if(!q){													/*check if the inserted node existed*/
		printf("The node don't exit,please create one"		/*create a new node if the node doesn't exist*/
			".\nTell me the data:");
		scanf("%d",&data);
		q=(LinkedList)malloc(sizeof(LNode));
		q->data=data;
	}
	q->next=p->next;										/*make the pointer next of q point the next node after p*/
	p->next=q;												/*make the pointer next of p point the node of q*/

	return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	LinkedList s;
	if(!p->next){								/*check if the node after p exists*/
		printf("There is no node after p!");
		return ERROR;
	}
	*e=p->next->data;							/*assign the value of the data to e*/
	s=p->next;
	p->next=p->next->next;						/*make the pointer next point of p the one after the node we want to delete*/
	free(s);								/* don't forget to destroy the node*/

	return SUCCESS;	
}
/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit 
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	LinkedList p;
	
	p=L->next;
	while(p){
		(*visit)(p->data);
		p=p->next;
	}
	
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e 
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	LinkedList p;
	
	p=L->next;
	while(p){							/*check if the node exists*/
		if(p->data==e){					/*if e is in the list,return SUCCESS*/
			puts("e is in the list");
			return SUCCESS;
		}
		p=p->next;
	}
	puts("e is not in the list");		/*if we can not find e after traversing,return ERROR*/ 
	
	return ERROR;
} 

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list 
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	LinkedList p,s,q;

	p=(*L)->next;
	if(!p){										/*if it is a empty linked list,return ERROR*/
		printf("These is no node in the list");
		return ERROR;
	}
	s=(*L)->next;							/*make s point the first node*/								/*make the first pointer point NULL to turn it into the final node*/
	while(s->next){
		p=s->next;				/*Begin from the second node, every node is inserted after the head node*/
		s->next=p->next;
		p->next=(*L)->next;
		(*L)->next=p;
		}
									/*the head point points to the first node*/
		
	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
/*There are two methods to solve the problems.
The first one if fast and slow pointer method(快慢指针法),
which means using a two-step point and a one-step point.
if two pointers meet each other,it is a loop list.
And the following is the second method.*/
Status IsLoopList(LinkedList L) {
	LinkedList p1,p2;
	int step1=0,step2=0;
	p1=p2=L;
	while(p2){		
		p2=p2->next;	/*every time,p2 walk one step and don't go back*/
		step2++;
		while(p1!=p2){ /*every time,p1 walk from the head node*/
			p1=p1->next;
			step1++;
		}
		if(step1!=step2){/*when p1 and p2 point to the same place,compare their steps*/
			printf("It is a loop list.");
			return SUCCESS;
		}
		p1=L;
		step1=0;
	}
	printf("It is not a loop list.");

	return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish 
 */
LNode* ReverseEvenList(LinkedList *L) {
	LinkedList p,q,s;
	
	q=*L;
	p=q->next;
	while(p){	/*here p points the one before the even node,q is befor q*/
		q->next=p->next;	/*to insert the even node between p and q*/
		s=p->next->next;	
		p->next->next=p;	
		p->next=s;			/*link the p node and the node after the even node*/
		q=p;
		p=p->next;
	}

	
	return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish 
 */
//fast and slow pointer method(快慢指针法)
LNode* FindMidNode(LinkedList *L) {
	LinkedList pfast,pslow;

	pfast=pslow=*L;
	while(pfast->next){
		if(pfast->next->next){
			pfast=pfast->next->next;
			pslow=pslow->next;
		}
		else{
			pfast=pfast->next;
		}
	}
	pslow=pslow->next;

	return pslow;
}
