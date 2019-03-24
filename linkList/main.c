#include <stdio.h>
#include "../head/linkedList.h"
#include <stdlib.h>
#include "LinkedList.c" 
int getInt();
void print(int);
int main()
{
	LinkedList L,p,q;
	int data2,location,i,num=0;
	char c,choice;

	if(InitList(&L))							/*create the linkedlist and check if it is created*/
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
		q=(LinkedList)malloc(sizeof(LNode));						/*create the new node*/
		if(!q){														/*check if the new node is created*/
			printf("Error!Click a to try again");
			c=getchar();
			if(c!='a'){
				DestroyList(&L);
					return(0);
			}
			continue;	
		}
		q->data=data2;					/*assign the data of new node*/
		InsertList(p, q);		/*link the new node with the linkedlist*/
		p=p->next;
		num++;
	}
	while(getchar()!='\n')		
		continue;
	while(1){
		puts("Please choose your operation:");
		puts("A.insert      B.delete");
		puts("C.print       D.destroy");
		puts("E.search      F.reverse");
		puts("G.reverse the even");
		puts("H.find the middle data");
		choice=getchar();
		while(getchar()!='\n')		/*modification:discard the extra enter*/
			continue;
		switch(choice){
		case 'A':printf("Please enter the data:");
			data2=getInt();
			printf("Please enter the location:");
			location=getInt();
			while (location<=0||location>num+1){				/*modification:chat if the location is right*/
				printf("the location is wrong.Please enter again:");
				location=getInt();
			}
			q=(LinkedList)malloc(sizeof(LNode));
			q->data=data2;
			if(location==1)
			{
				InsertList(L,q);
			}
			else{
				p=L;
				for(i=1;i<=location-1;i++)
					p=p->next;
				InsertList(p,q);
			}
			num++;
			break;
		case 'B':if(num!=0){
					printf("please tell me the location:");	/*get the location to delete the node*/
					location=getInt();
					while (location<=0||location>num){							/*modification:check if the location is right*/
						printf("the location is wrong.Please enter again:");
						location=getInt();
					}
					if(location==1)
						DeleteList(L,&data2);
					else{	
						p=L;
						for(i=1;i<=location-1;i++)
						p=p->next;
						DeleteList(p,&data2);
					}
					printf("OK!The data deleted is %d",data2);
					num--;
				 }
				else
					puts("The list is empty!");			/*modification:check if the list is empty*/
				break;
		case 'C':TraverseList(L,&print);	/*print the data and number*/
				printf("\nthe number of nodes is %d",num);
				break;
		case 'D':DestroyList(&L);			/*destroy the list*/
				printf("The list is destroyed.Done!");
				return 0;
				break;
		case 'E':printf("Please enter a data:");
				data2=getInt();
				if(SearchList(L,data2))
					printf("The data is in list");
				else
					printf("The data is not in list");
				break;
		case 'F':ReverseList(&L);
				printf("The list is reversed!");
				 break;
		case 'G':if(num%2==0){
					ReverseEvenList(&L);
					printf("The even numbers of the list is reversed!");
				 }
				else
					printf("The list can not be reversed for its number is not even number");
				 break;
		case 'H':p=FindMidNode(&L);
				printf("the data of the middle one is %d",p->data);
				break;
		default:printf("The choice you entered is wrong!please try again!");	/*modification:dispose the error enter*/
		}
		printf("\nq to quit\n");
	
		c=getchar();
		if(c=='q')			/*enter q to stop the loop*/
			break;
		getchar();
	}
	DestroyList(&L);	/*destroy the list*/
	printf("Done!");

	return 0;
}

int getInt()	//this is a function to check the number input
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

void print(int e){	//to print the data
	printf("%d  ",e);
}
