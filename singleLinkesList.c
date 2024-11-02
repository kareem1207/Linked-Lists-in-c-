#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node *head,*prev,*newNode,*ptr;
int total_nodes=0;
void create(int nodes_count){
    head=NULL;  
    for(int i=0;i<nodes_count;i++){
    newNode=malloc(sizeof(node));
    printf("Enter %d element data: ",i+1);
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    if(head==NULL)
    head=newNode;
    else
    prev->next=newNode;
    prev=newNode;
    }
}
void display(){
    if(head==NULL)
    printf("List is empty");
    else{ 
        ptr=head;
        while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->next;
    }
    printf("\n");
    }
}
void insert(int index){
    if(head==NULL)
    create(1);
    else{
        ptr=head;
        prev=head;
        int index_dub=index-1;
        while(index_dub>=2 ){
            prev=prev->next;
            index_dub--;
        }
        newNode=malloc(sizeof(node));
        printf("Enter your data: ");
        scanf("%d",&newNode->data);
        if(index==1){
            head=newNode;
            newNode->next=ptr;
        }
        else if(index==total_nodes){
            prev=prev->next;
            prev->next=newNode;
            newNode->next=NULL;
        }
        else{
            newNode->next=prev->next;
            prev->next=newNode;
        }
    }
                total_nodes+=1;
}
void delete(int index){
if(head==NULL) 
printf("The list is empty!\nCan't delete any element");
else{
ptr=head;
        int index_dub=index-1;
        while(index_dub>=1 ){
            prev=ptr;
            ptr=ptr->next;
            index_dub--;
        }
        if(index==1){
            head=ptr->next;
            free(ptr);
        }
        else if(index==total_nodes){
            prev->next=NULL;
            free(ptr);
        }
        else{
            prev->next=ptr->next;
            ptr->next=NULL;
            free(ptr);
        }
            total_nodes-=1;
}
}
void main(){
    int choice,position;
    while(choice!=9){
        printf("Enter\n1--->Create\n2--->insert at beginning\n3--->insert at certain position\n4--->insert at end\n5--->delete at beginning\n6--->delete at certain position\n7--->delete at end\n8--->display\n9--->exit\n");
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