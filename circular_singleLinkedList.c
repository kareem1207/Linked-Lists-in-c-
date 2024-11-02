#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node *head,*tail,*ptr,*newNode;
int total_nodes;
void create(int n){
    for(int i =0 ; i<n;i++){
        newNode=malloc(sizeof(node));
        printf("Enter %d element : ",i+1);
        scanf("%d",&newNode->data);
    if(head==NULL)
        head=newNode;
    else
        ptr->next=newNode;
    ptr=newNode;
    newNode->next=head;
    tail=newNode;
}
}
void insert(int index){
    if(head==NULL)
        create(1);
    else{
        ptr=head;
        newNode=malloc(sizeof(node));
        printf("Enter the data you want to insert : ");
        scanf("%d",&newNode->data);
        int index_dub=index;
        while(index_dub>2){
            ptr=ptr->next;
            index_dub--;
        }
        if(index==1){
           tail->next=newNode;
           newNode->next=head;
           head=newNode;
        }else if(index==total_nodes){
            tail->next=newNode;
            newNode->next=head;
            tail=newNode;
        }else{
            newNode->next=ptr->next;
            ptr->next=newNode;
        }
        total_nodes+=1;
    }
}
void delete(int index){
    if(head==NULL)
    printf("List is empty\n");
    else{
        ptr=head;
        node *temp;
        int index_dub=index;
        while(index_dub>1){
            temp=ptr;
            ptr=ptr->next;
            index_dub--;
        }
        if(index==1){
            head=ptr->next;
            tail->next=head;
            free(ptr);
        }else if(index==total_nodes){
            temp->next=head;
            tail=temp;
            free(ptr);
        }else{
            temp->next=ptr->next;
            free(ptr);
        }
        total_nodes-=1;
    }
}
void display(){
    ptr=head;
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}
void main(){
    int choice,position;
    while(choice!=9){
        printf("Enter\n1:Create\n2:insert at beginning\n3:insert at certain position\n4:insert at end\n5:delete at beginning\n6:delete at certain position\n7:delete at end\n8:display\n9:exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
            printf("Enter how many nodes you want : ");
            scanf("%d",&total_nodes);
            create(total_nodes);
            break;
            case 2:
            insert(1);
            break;
            case 3:
            printf("At which position you want your data to be inserted : ");
            scanf("%d",&position);
            insert(position);
            break;
            case 4:
            insert(total_nodes);
            break;
            case 5:
            delete(1);
            break;
            case 6:
            printf("At which position you want your data to be deleted : ");
            scanf("%d",&position);
            delete(position);
            break;
            case 7:
            delete(total_nodes);
            break;
            case 8:
            display();
            break;
            case 9:
            printf("Exited sucessfully");
            break;
            default:
            printf("Invalid choice");
            break;
        }
    }
}