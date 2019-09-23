#include <stdio.h>
#include <stdlib.h>
struct q{
    int data;
    struct q *link;
}*top=NULL,*tail=NULL;
void enq(int elem){
    struct q *newnode=(struct q*)malloc(sizeof(struct q));
    if(!newnode){
        printf("heap overflow!!\n");
        exit(0);
    }
    newnode->data=elem;
    if(!top){
        newnode->link=NULL;
        top=newnode;
        tail=newnode;
    }
    else{
        newnode->link=top;
        top=newnode;
    }
}
int deq(){
    int d;
    if(!top){
        printf("Empty!!\n");
        exit(0);
    }
    struct q *temp=tail;
    if(top == tail){
        d=top->data;
        free(top);
        top=tail=NULL;
    }
    else{
        struct q *temp=top,*tmp;
        while(temp->link!=tail){
                temp=temp->link;
        }
        d=tail->data;
        temp->link=NULL;
        free(tail);
        tail=temp;
    }
    return d;
}
void display(){
    if(!top){
        printf("Empty!!\n");
        return;
    }
    struct q *temp=top;
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
        printf("\n------------------------------------------------------------------------------\n");
        printf("Enter your choice:1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            printf("Enter the element to be enqueued:\n");
            scanf("%d",&x);
            enq(x);
            break;
        case 2:
            del=deq();
            printf("Element dequeued is :%d\n",del);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("you have entered a wrong choice!!!\n");
            break;
        }
    }
}
