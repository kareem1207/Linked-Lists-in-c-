#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next,*prev;
}node;
node *head,*ptr,*newNode;
int total_nodes;
void create(int n){
    for(int i =0 ; i<n;i++){
        newNode=malloc(sizeof(node));
        printf("Enter %d element : ",i+1);
        scanf("%d",&newNode->data);
    if(head==NULL){
        head=newNode;
        head->prev=NULL;
        }
    else{
        ptr->next=newNode;
        newNode->prev=ptr;
        }
    ptr=newNode;
    ptr->next=NULL;
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
            head->prev=newNode;
            newNode->prev=NULL;
            newNode->next=head;
            head=newNode;
        }else if(index==total_nodes){
            ptr=ptr->next;
            ptr->next=newNode;
            newNode->prev=ptr;
            newNode->next=NULL;
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
            ptr->next->prev=NULL;
            ptr->next=NULL;
            free(ptr);
        }else if(index==total_nodes){
            temp->next=NULL;
            ptr->prev=NULL;
            free(ptr);
        }else{
            temp->next=ptr->next;
            ptr->next->prev=ptr->prev;
            free(ptr);
        }
        total_nodes-=1;
    }
}
void display(){
    ptr=head;
    while(ptr){
        printf("prev add:%p data:%d next add:%p\n",ptr->prev,ptr->data,ptr->next);
        ptr=ptr->next;
    }
}
void main() {
    int choice = 0,position;
    while (choice != 9) {
        printf("\n 1:Create\n 2:Insert At Beginning\n 3:Insert At Position\n 4:Insert At End\n 5:Delete At Beginning\n 6:Delete At Position\n 7:Delete At End\n 8:Display List\n 9:Exit\n Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter number of elements: ");
            scanf("%d", &total_nodes);
            create(total_nodes);
            break;
        case 2:
            insert(1);
            break;
        case 3:
            printf("Enter position to insert: ");
            scanf("%d", &position);
            insert(position);
            break;
        case 4:
            insert(total_nodes);
            break;
        case 5:
            delete(1);
            break;
        case 6:
            printf("Enter the position to be deleted: ");
            scanf("%d", &position);
            delete(position);
            break;
        case 7:
            delete(total_nodes);
            break;
        case 8:
            display();
            break;  
        case 9:
            printf("Exited Successfully");
            break;
        default:
            printf("Invalid Input");
            break;
        }
    }
}