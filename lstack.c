#include <stdio.h>
#include <stdlib.h>
struct stack{
	int data;
	struct stack *link;
};
struct stack *top=NULL;
void push(int data){
	struct stack *newnode=(struct stack*)malloc(sizeof(struct stack));
	if(!newnode){
		printf("heap overflow!!\n");
		return;
	}
	newnode->data=data;
	newnode->link=NULL;
	if(!top){
		top=newnode;	
	}
	else{
		newnode->link=top;
		top=newnode;
	}
}
int pop(){
	int del;
	if(!top){
		printf("Stack underflow!!\n");
		exit(0);
	}
	else{
		struct stack *temp=top;
		top=top->link;
		del=temp->data;
		free(temp);
	}
	return del;
}
void display(){
	struct stack *temp=top;
	while(temp){
		printf("%d",temp->data);
		if(temp->link){
			printf("-->");
		}
		temp=temp->link;
	}
}
void main(){
	int ch,x,del;
	while(1){
		printf("\n----------------------------------------------------------------------------------\n");
		printf("Enter your choice:\n1.Push\t2.Pop\t3.Display\t4.Exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter the element you want to push:\n");
				scanf("%d",&x);
				push(x);
				break;
			case 2:
				del=pop();
				printf("Deleted element is:%d\n",del);
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("You have entered a wrong choice:\n");
				break;
		}
	}
}
