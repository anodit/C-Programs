#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coef,expo;
    struct node* next;
};

struct node* insertpoly(struct node* thead,int c,int e);
struct node* append(struct node* thead,int c,int e);
struct node* polyaddition(struct node* p1thead,struct node* p2thead);
void display(struct node* thead);

void main()
{
    int a,b,n,i;
    struct node* p1head,* p2head,* p3head;
    p1head=p2head=NULL;

    printf("\n\t\t\t\t\t*******************************");
    printf("\n\t\t\t\t\t| ADDITION OF TWO POLYNOMIALS |");
    printf("\n\t\t\t\t\t*******************************\n");
    printf("\n\t\tGeneral polynomial expression :->  a0x^n + a1x^(n-1) + a3x^(n-3) + ...... + a(n-1)x + an\n");
    printf("\n\tEnter the no. of terms for first polynomial ->  ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("\n\tEnter the coefficient of %d term : ",i);
        scanf("%d",&a);
        printf("\n\tEnter the exponent of %d term : ",i);
        scanf("%d",&b);
        p1head=insertpoly(p1head,a,b);
    }

    printf("\n\tEnter the no. of terms for second polynomial -> ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("\n\tEnter the coefficient of %d term : ",i);
        scanf("%d",&a);
        printf("\n\tEnter the exponent of %d term : ",i);
        scanf("%d",&b);
        p2head=insertpoly(p2head,a,b);
    }

    p3head=polyaddition(p1head,p2head);
    printf("\n\tFirst polynomial in descending power of x :-> ");
    display(p1head);
    printf("\n\n\tSecond polynomial in descending power of x :->");
    display(p2head);
    printf("\n\n\tThe sum of the two (First + Second) polynomials is :-> ");
    display(p3head);
}

struct node* append(struct node* thead,int c,int e)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coef=c;
    newnode->expo=e;
    if(thead==NULL){
    return newnode;
    }
    struct node* trav=thead;
    while(trav->next!=NULL)
        trav=trav->next;
    trav->next=newnode;
    newnode->next=NULL;
    return thead;
}

struct node* insertpoly(struct node* thead,int c,int e)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coef=c;
    newnode->expo=e;
    if(thead==NULL){
        newnode->next=NULL;
        return newnode;
    }
    struct node* prev,* curr;
    prev=curr=thead;
    while(curr!=NULL && curr->expo>e){
        prev=curr;
        curr=curr->next;
    }
    if(curr==thead){
        newnode->next=curr;
        return newnode;
    }
    else if(curr==NULL){
        prev->next=newnode;
        newnode->next=NULL;
    }
    else{
        newnode->next=curr;
        prev->next=newnode;
    }
    return thead;
}

struct node* polyaddition(struct node* p1thead,struct node* p2thead)
{
    struct node* ans=NULL;
    struct node* t1,* t2;
    t1=p1thead;
    t2=p2thead;
    while(t1!=NULL && t2!=NULL){
        if(t1->expo > t2->expo){
            ans=append(ans,t1->coef,t1->expo);
            t1=t1->next;
        }
        else if(t1->expo < t2->expo){
            ans=append(ans,t2->coef,t2->expo);
            t2=t2->next;
        }
        else{
            ans=append(ans,(t1->coef)+(t2->coef),t1->expo);
            t1=t1->next;
            t2=t2->next;
        }
    }

    while(t1!=NULL){
        ans=append(ans,t1->coef,t1->expo);
        t1=t1->next;
    }

    while(t2!=NULL){
        ans=append(ans,t2->coef,t2->expo);
        t2=t2->next;
    }
    return ans;
}

void display(struct node* thead)
{
    struct node* temp=thead;
    if(temp==NULL){
        printf("\nEmpty..");
    }
    else{
        while(temp->next!=NULL){
            printf(" %dx^%d +",temp->coef,temp->expo);
            temp=temp->next;
        }
       printf(" %dx^%d ",temp->coef,temp->expo);
    }
}
