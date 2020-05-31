#include<stdio.h>
#include<stdlib.h>
struct node
{

    int data;
    struct node *next;

}*first=NULL,*second=NULL,*third=NULL;
//CREATING A LINKED LIST
void create(int A[],int n)
{
    struct node *t, *last;
    int i;
    first =  (struct node*)malloc(sizeof(struct node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct  node*)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void create2(int B[],int n)
{
    struct node *t, *last;
    int i;
    second =  (struct node*)malloc(sizeof(struct node));
    second->data=B[0];
    second->next=NULL;
    last=second;
    for(i=1;i<n;i++)
    {
        t=(struct  node*)malloc(sizeof(struct node));
        t->data=B[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}


//DISPLAYING A LINKED LIST
void display(struct node*p)
{

    while(p!=NULL)
    {
        printf("%d--> ",p->data);
        p=p->next;
    }
}
//RECUSIVE FUNCTION FOR DISPLAYING LINKED LIST
void RDisplay(struct node *p)
 {
      if(p!=NULL)
  {
        printf("%d--> ",p->data);
        RDisplay(p->next);
  }
}
//COUNTING NUMBER OF NODES
int count_node(struct node *p)
{
    int count=0;
    while(p!=NULL)
    {
        p=p->next;
        count++;
    }

   // printf("\n\n NO OF NODES = %d\n\n",count);
    return count;
}
//SUM OF ELEMENTS OF LL
void sum_of_elements(struct node *p)
{
    int sum=0;
    while(p!=NULL)
    {

        sum=sum+p->data;
        p=p->next;
    }
    printf("SUM OF ELEMENTS = %d",sum);
}
//FIND MAXIMUM ELEMENT IN LL
void find_max(struct node *p)
{
    int max=p->data;
    struct node *q=p->next;
    while(q!=NULL)
    {
        if(q->data>max)
        {
            max=q->data;
        }
         q=q->next;
    }
    printf("\n \nMAX ELEMENTS = %d\n\n",max);

}
//SEARCHING FOR AN ELEMENT
void ele_search(struct node *p,int x)
{
    int count=0;
    while(p)
    {
        if(p->data==x)
        {
            printf("%d FOUND AT %d\n\n",x,(count+1));
            p=p->next;
            count++;
        }
        else{
            p=p->next;
            count++;
        }
    }
}
//INSERTION IN A LL
void insert(struct node *p,int key,int pos)
{
     if(pos < 0 || pos > count_node(p))
        return;
    struct node *q = (struct node *)malloc(sizeof(struct node));
    q->data=key;
    if(pos==0)
    {
        q->next=first;
        first=q;
    }
    else
    {
    int i;
    for(i=1;i<pos-1;i++)
    {
        p=p->next;
    }
    q->next=p->next;
    p->next=q;
}

}
void insert_last(int x)
{
    struct node *q=(struct node *)malloc(sizeof(struct node));
    struct node *last;
    q->data=x;
    q->next=NULL;
    if(first==NULL)
    {
        first=last=q;
    }
    else{
        last->next=q;
        last=q;
    }
}
//sorting of a linked list (bubbleSort)
void sortList() {

        struct node *current = first, *index = NULL;
        int temp;

        if(first == NULL) {
            return;
        }
        else {
            while(current != NULL) {
                index = current->next;

                while(index != NULL) {

                    if(current->data > index->data) {
                        temp = current->data;
                        current->data = index->data;
                        index->data = temp;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
    }
    //INSERTING IN A SORTED LINKED LIST
    void insertSorted(struct node *p,int value)
    {
        struct node *q=NULL;
        struct node *newNode = (struct node *)malloc(sizeof(struct node ));
        newNode->data=value;
        newNode->next=NULL;
        if(first==NULL)
        {
            first=newNode;
        }
        else{
            while(p && p->data<value)
            {
                q=p;
                p=p->next;
            }
            if(p==first)
            {
                newNode->next=first;
                first=newNode;
            }
            else{
            newNode->next=q->next;
            q->next=newNode;
        }
        }
    }
//DELETING FROM A LINKED LIST
void deleteNode(struct node *p,int pos)
{
    struct node *q=NULL;
    if(pos<=count_node(first))
    {
    if(pos==1)
    {
       first = first->next;
       int x=p->data;
        free(p);
        printf("\nDELETED VALUE =>%d\n",x);
    }
    else{
            int i;
    for(i=0;i<pos-1;i++)
    {
        q=p;
        p=p->next;
    }
    q->next=p->next;
    int y=p->data;

    free(p);
    printf("\nDELETED VALUE=>%d\n",y);
    }
    }
    else{
        printf("\nenter no is greater than the numberr of nodes in linked list\n");
    }
}
int checkSorted(struct node *p)
{
    int n=-32543;
   if(p==NULL)
   {
       printf("\n EMPTY LIST");
       return 0;
   }
   else{
     while(p)
     {
         if(p->data<n)
         {
           return 0;
         }
         n=p->data;
         p=p->next;
     }
     return 1;
   }
}
//RREMOVING DUPLICATES FROM  THE LINKED LIST
void removeDuplicate(struct node *p)
{
    while(p->next!=NULL)
    {
    struct node *q=p->next;
    struct node *r=p;
    while(q!=NULL)
        {
             if(p->data!=q->data)
               {            r=q;
                          q=q->next;
                }
                else
                {
                r->next=q->next;
                free(q);
                q=r->next;
                        }
        }
        if(p->next!=NULL)
            p=p->next;
    }
}
//REVERSING LINKED LIST
void reverseList(struct node *p)
{
    struct node *q,*r;
    q=NULL;
    r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
//concatination of two lists==>
void concat(struct node *p,struct node *q)
{
    third=p;
    while(p->next != NULL)
    {
        p=p->next;
    }
    p->next=q;
}
//MERGING TWO SORTED LISTS
void merge(struct node *p,struct node *q)
{
    struct node *last;
    if(p->data<q->data)
    {
        third=p;
        last=p;
        p=p->next;
        last->next=NULL;
    }
    else{
          third=q;
        last=q;
        q=q->next;
        last->next=NULL;
    }
    while(p&&q)
    {
        if(p->data<q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
}
int main()
{
    int A[]={2,4,6,8,10,12,14,16};
    int B[]={3,5,7,9,11,13,15,17};
    //int A[]={};
    create(A,8);
      create2(B,8);
    //display(first);
    //printf(" \n");
    //RDisplay(first);
   // printf(" \n");
    //count_node(first);
   // sum_of_elements(first);
    //find_max(first);
    //ele_search(first,40);
    //insert(first,100000,0);
    //insert_last(333333);
    //printf("%d",count_node(first));

    //printf("\n\n");
    //sortList();
    //insertSorted(first,35);
    //insertSorted(first,3);
   // int n;
    //printf("enter the node number u want to delete\t");
    //scanf("%d",&n);
    //deleteNode(first,n);
   /* if(checkSorted(first)==0)
    {
        printf("\nUNSORTED LIST\n");
    }
    else{
        printf("\nSORTED LIST\n");
    }*/
   // removeDuplicate(first);
   //reverseList(first);
   //display(first);
    //printf("\n\n");
   // display(second);
    // printf("\n\n");
    //concat(first,second);
    //display(third);
    //sortList();
    printf("\n\n");
    merge(first,second);
     display(third);
    return 0;
}
