#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
}*head;
                         /*CREATING A CIRCULAR LINKED LIST */
void create(int A[],int n)
{
    int i;
    struct node *t,*last;
    head=(struct node *)malloc(sizeof(struct node));
    head->data=A[0];
    head->next=head;
    last=head;
    for(i=1;i<n;i++)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=A[i];
        last->next=t;
        last=t;
        last->next=head;

    }
}
                                        /*DISPLAYING THE CIRCULAR LINKED LIST   */
void display(struct node *p)
{
    do{
        printf("%d->",p->data);
        p=p->next;
    }
    while(p!=head);
}
int count(struct node *p)
{
    int num=0;
    do{
        num++;
        p=p->next;
    }while(p!=head);
    return num;
}
                                    /*INSERTION IN A CIRCULAR LINKED LIST */
void insertIn(struct node *p,int pos,int value)
{
    int i;
    if(pos<0||pos>count(head))
    {
        printf("\n ENTER WITH IN THE LIMIT\n");
    }

         if(pos==0){
                 struct node *t=(struct node *)malloc(sizeof(struct node));
                 t->data=value;

                 if(count(head)==0)
        {
            head=t;
            head->next=head;
        }
           while(p->next!=head) {
                p=p->next;
            }
            p->next=t;
            t->next=head;
            head=t;
        }
        else{
            for(i=1;i<pos-1;i++)
            {
                p=p->next;

            }
            struct node *t=(struct node *)malloc(sizeof(struct node));
             t->data=value;
            t->next=p->next;
            p->next=t;
        }
}

void removeNode(struct node *p,int index)
{
     int i;
    if(index<1||index>count(head))
    {
        printf("\n ENTER WITH IN THE LIMIT\n");
    }
     if(index==1)
    {
         while(p->next!=head);
        {
            p=p->next;
        }
        int x=head->data;
        if(head==p){
            free(head);
            printf("\nREMOVED NUMBER=> %d\n",x);
            head=NULL;
        }
        else{
        p->next=head->next;
        free(head);
        head=p->next;
        printf("\nREMOVED NUMBER=> %d\n",x);

           }
    }
    else{
        struct node *q=NULL;
        for(i=1;i<index;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        int x=p->data;
        free(p);
        printf("\nREMOVED NUMBER=> %d\n",x);
    }

}
int main()
{
    int A[]={1,2,3,4,5,6};
    create(A,6);
   // insertIn(head,2,11111);
    removeNode(head,1);
   printf("\n\n");
    display(head);
    printf("\n\n");
    return 0;
}
