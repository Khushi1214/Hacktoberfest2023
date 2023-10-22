#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void insertAtBeg();
void insertAtend();
void insertAtmid();
void delAtbeg();
void delAtend();
void delAtmid();
struct node{
    int data;
    struct node* next;
};
struct node* head= NULL;
int main(){
    create();
    display();
    insertAtBeg();
    display();
    insertAtend();
    display();
    insertAtmid();
    display();
    delAtbeg();
    display();
    delAtend();
    display();
    delAtmid();
    display();

}
void create(){
    int data,ch;
    do{
    
    struct node* temp=NULL;
    struct node* ptr=NULL;
    temp=(struct  node*)malloc(sizeof(struct node));
    printf("enter the data for ll");
    scanf("%d",&data);
    temp->data=data;
    temp->next=NULL;
    
    if(head==NULL)
    {
        head=temp;
    }
    else{
    ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=temp;
    }
    printf("to insert more press 1 else other integer");
    scanf("%d",&ch);
    
    }
    while(ch==1);


}
void display(){
    struct node* temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        printf(" ");
        temp=temp->next;
    }
}
void insertAtBeg(){
    int data,ch;
    do{
    struct node* temp=NULL;
    
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nenter the data for inserting at beg");
    scanf("%d",&data);
    temp->data=data;
    temp->next=NULL;
    if(head==NULL){
        temp=head;
    }
    else{
        temp->next=head;
        head=temp;
    }
    printf("to insert more at beg press 1");
    scanf("%d",&ch);
    }
    while(ch==1);
}
void insertAtend(){
    int data,ch;
    do{
        struct node* temp= head;
        temp=(struct node*)malloc(sizeof(struct node));
        printf("\n enter the data for inserting at end");
        scanf("%d",&data);
        temp->data=data;
        temp->next=NULL;
        if(head==NULL)
        {
            temp=head;
        }
        else{
            struct node* tail=head;
            while(tail->next!=NULL){
                tail=tail->next;
            }
            tail->next=temp;
            tail=temp;
        }
        printf("to insert more at end press 1");
        scanf("%d",&ch);
    }
    while(ch==1);
}
void insertAtmid(){
    int data,ch,ele;
    do{
        struct node* temp=head;
        struct node* ptr= head;
        temp=(struct node*)malloc(sizeof(struct node));
        printf("\nenter the element after which u want 2 insert");
        scanf("%d",&ele);
        printf("\nenter the data for inserting after %d",ele);
        scanf("%d",&data);
        temp->data=data;
        temp->next=NULL;
        if(head==NULL){
            temp=head;
        }
        else{
            while(ptr->data!=ele){
                ptr=ptr->next;
            }
            temp->next=ptr->next;
            ptr->next=temp;
        }
        printf("\nto insert more at mid press 1");
        scanf("%d",&ch);
    }
    while(ch==1);
}
void delAtbeg(){
    int ch;
    do{
    struct node* temp=head;
    head=head->next;
    temp->next=NULL;
    free(temp);
    printf("\nto del more at beg press 1");
    scanf("%d",&ch);
}
while(ch==1);
}
void delAtend(){
    int ch;
    do{
        struct node* tail=head;
        while(tail->next->next!=NULL)
        {
            tail=tail->next;
        }
        struct node* ptr= tail->next;
        tail->next=NULL;
        free(ptr);
        printf("\nto del more at end press 1");
        scanf("%d",&ch);

    }
    while(ch==1);
}
void delAtmid(){
    int ch,ele;
    do{
        struct node* temp=head;
        printf("enter the element which you want to delete");
        scanf("%d",&ele);
        if(ele==head->data){
            delAtbeg();
        }
        else{
        while(temp->next->data!=ele){
            temp=temp->next;
        }
        struct node* ptr= temp->next;

        temp->next=ptr->next;
        ptr->next=NULL;
        free(ptr);
        printf("\n to del more at mid press 1");
        scanf("%d",&ch);}
    }
    while(ch==1);
}
