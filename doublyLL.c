#include<stdio.h>
#include<stdlib.h>
struct node{
struct node *prev;
int data;
struct node *next;
}*first=NULL;
                                        /*CREATING A DOUBLY LINKED LIST*/

void create(int A[],int n)
{
    int i;
    struct node *t,*last;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}
                                    /*DISPLAYING THE LINKED LIST */
void display(struct node *p)
{
    while(p)
    {
        printf("<= %d =>",p->data);
        p=p->next;
    }
}
                                /*LENGTH OF THE LINKED LIST */
int count(struct node *p)
{
    int node=0;
    while(p)
    {
        node++;
        p=p->next;
    }
    return node;
}

                                /*  INSERTING A NEW NODE A LINKED LIST */
void insertNode(struct node *p,int index, int value)
{
    struct node *t;
    int i;
     t=(struct node *)malloc(sizeof(struct node));
     t->data=value;
    if(index<1||index>(count(first)+1))
        printf("OUT OF BOUND CAN NOT INSERT\n\n");
        //INSERTING AT THE LAST
    else if(index==(count(first)+1)){
            for(i=1;i<count(first);i++)
            {
                p=p->next;
            }
            p->next=t;
            t->next=NULL;
            t->prev=p;
    }
    //INSERTING AT FRONT
    else{
        if(index==1)
        {
            t->next=first;
            t->prev=NULL;
            first->prev=t;
            first=t;
        }
        else{
            for(i=1;i<index-1;i++)
                p=p->next;
            t->next=p->next;
            t->prev=p;
            p->next->prev=t;
            p->next=t;
        }
    }
}
                                /* DELETING NODE FROM THE LINKED LIST */
void deleteNode(struct node *p,int index)
{
    int x,i;

    if(index<1||index>(count(first)))
        printf("OUT OF BOUND CAN NOT INSERT\n\n");
    //DELETING FIRST NODE
    if(index==1)
    {
        if(first->next==NULL)
        {
            x=first->data;
            free(first);
            first=NULL;
             printf("\nDELETED VALUE=> %d\n",x);
        }
        else{
        x=first->data;
        first=first->next;
        first->prev=NULL;
        free(p);
        printf("\nDELETED VALUE=> %d\n",x);
       }
    }
    //DELETING LAST NODE
    else if(index==count(first))
    {
        for(i=1;i<count(first);i++)
        {
            p=p->next;
        }
        p->prev->next=NULL;
        x=p->data;
        free(p);
         printf("\nDELETED VALUE=> %d\n",x);
    }
    //DELETING MIDDLE NODES
    else{
        for(i=1;i<index;i++)
        {
            p=p->next;
        }
        p->prev->next=p->next;
        p->next->prev=p->prev;
        x=p->data;
        free(p);
        printf("\nDELETED VALUE=> %d\n",x);
    }
}
void reverseList(struct node *p)
{
    struct node *temp;
    while(p)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL)
             first=p;
    }
}

int main()
{
int A[]={1,2,3,4,5};
create(A,5);
printf("\nNO. OF NODES=> %d\n\n",count(first));
//insertNode(first,7,4343);
//deleteNode(first,1);
//reverseList(first);
display(first);
printf("\n");
}
