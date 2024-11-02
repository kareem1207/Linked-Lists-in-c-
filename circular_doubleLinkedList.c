#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next,*prev;
}node;
node *head,*tail,*ptr,*newNode;
int total_nodes;
void create(int n){
    for(int i =0 ; i<n;i++){
        newNode=malloc(sizeof(node));
        printf("Enter %d element : ",i+1);
        scanf("%d",&newNode->data);
    if(head==NULL){
        head=newNode;
        newNode->prev=newNode;
        }
    else{
        ptr->next=newNode;
        newNode->prev=ptr;
        }
    tail=newNode;
    ptr=newNode;
    ptr->next=head;
    head->prev=newNode;
}
}
void insert(int index){
    if(!head)
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
            head->prev=newNode;
            newNode->prev=tail;
            newNode->next=head;
            head=newNode;
            tail->next=head;
        }else if(index==total_nodes){
            ptr=ptr->next;
            ptr->next=newNode;
            newNode->prev=ptr;
            newNode->next=head;
            head->prev=newNode;
            tail=newNode;
        }else{
            ptr->next->prev=newNode;
            newNode->next=ptr->next;
            newNode->prev=ptr;
            ptr->next=newNode;
        }
        total_nodes+=1;
    }
}
void delete(int index){
    if(!head)
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
            ptr->next->prev=tail;
            tail->next=head;
        }else if(index==total_nodes){
            temp->next=head;
            head->prev=temp;
            tail=temp;
        }else{
            temp->next=ptr->next;
            ptr->next->prev=ptr->prev;
        }
            free(ptr);
        total_nodes-=1;
    }
}
void display(){
    ptr=head;
   do{
        printf("prev add:%p data:%d next add:%p current:%p\n",ptr->prev,ptr->data,ptr->next,ptr);
        ptr=ptr->next;
    } while(ptr!=head);
}
void main(){
    int choice,position;
    while(choice!=9){
        printf("Enter\n1:Create\n2:insert at beginning\n3:insert at certain position\n4:insert at end\n5:delete at beginning\n6:delete at certain position\n7:delete at end\n8:display\n9:exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter how many nodes you want to insert ");
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
            printf("At which position you want your data to be delete : ");
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