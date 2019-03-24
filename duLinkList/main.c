#include <stdio.h>
#include "../head/dulinkedList.h"
#include <stdlib.h>
#include "duLinkedList.c" 
int getInt();
void print(int);
int main()
{
	DuLinkedList L,p,q;
	int data2,location,i,num=0;
	char c,choice;

	if(InitList_DuL(&L))							/*create the linkedlist and check if it is created*/
		puts("The list is created");
	else{
		puts("Error!");
		return 0;
	}
	p=L;
	printf("Please enter the data to initialize the linked list:"		
		"(not number to stop)\n");
	while(scanf("%d",&data2)){											/*get the data ,if scanf returns 0 ,stop the loop*/ 
		while(getchar()!='\n')
			continue;
		q=(DuLinkedList)malloc(sizeof(DuLNode));						/*create the new node*/
		if(!q){															/*check if the new node is created*/
			printf("Error!Click a to try again");
			c=getchar();
			if(c!='a'){
				DestroyList_DuL(&L);
					return(0);
			}
			continue;	
		}
	
		q->data=data2;					/*assign the data of new node*/
		InsertAfterList_DuL(p, q);		/*link the new node with the linkedlist*/
		p=p->next;
		num++;
	}
	while(getchar()!='\n')
		continue;
	while(1){
		puts("Please choose your operation:");		/*let user choose the operation of list*/
		puts("A.insert      B.delete");
		puts("C.print       D.destroy");
		choice=getchar();
		while(getchar()!='\n')		/*modification:discard the extra enter*/
			continue;
		switch(choice){					/*use the switch to judge the choice*/
		case 'A':printf("Please enter the data:");		/*get the number and location to insert the node*/
			data2=getInt();
			printf("Please enter the location:");
			location=getInt();
			while (location<=0||location>num+1){				/*chat if the location is right*/
				printf("the location is wrong.Please enter again:");
				location=getInt();
			}
			q=(DuLinkedList)malloc(sizeof(DuLNode));
			q->data=data2;
			if(location==1)
			{
				InsertAfterList_DuL(L,q);
			}
			else{
				p=L;
				for(i=1;i<=location-1;i++)
					p=p->next;
				InsertAfterList_DuL(p,q);
			}
			num++;
			break;
		case 'B':if(num!=0){
					printf("please tell me the location:");	/*get the location to delete the node*/
					location=getInt();
					while (location<=0||location>num){							/*check if the location is right*/
						printf("the location is wrong.Please enter again:");
						location=getInt();
					}
					if(location==1)
						DeleteList_DuL(L,&data2);
					else{	
						p=L;
						for(i=1;i<=location-1;i++)
						p=p->next;
						DeleteList_DuL(p,&data2);
					}
					printf("OK!The data deleted is %d",data2);
					num--;
					break;
				 }
				else
					puts("The list is empty!");			/*modification:check if the list is empty*/
				break;
		case 'C':TraverseList_DuL(L,&print);
				printf("\nthe number of nodes is %d",num);		/*print the data and number*/
				break;
		case 'D':DestroyList_DuL(&L);			/*destroy the list*/
				printf("The list is destroyed.Done!\n");
				return 0;
				break;
		default:printf("The choice you entered is wrong!please try again!");	/*modification:dispose the error enter*/
		}
		printf("\nq to quit\n");
		c=getchar();
		if(c=='q')			/*enter q to stop the loop*/
			break;
		getchar();
	}
	DestroyList_DuL(&L);	/*destroy the list*/
	printf("Done!\n");

	return 0;
}

int getInt()
{
	char ch;
	int input;
	while(scanf("%d",&input)!=1)
	{
		while((ch=getchar())!='\n')
			putchar(ch);
		printf(" is not an integer.\nPlease enter an ingeter:");
	}
	return input;
}

void print(int e){
	printf("%d  ",e);
}
