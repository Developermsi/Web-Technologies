#include<stdio.h>
#include<stdlib.h>


struct lnode{
    int data;
    struct lnode* next; //self reference
};
typedef struct lnode node;

node* head=NULL;

void insertAtBegining(int val){
    node* newNode=(node*)malloc(sizeof(node));

    if(newNode==NULL){
        printf("out of memory\n");
        return;
    }

    newNode->data=val;
    if(head==NULL){
        newNode->next=NULL;
        head=newNode;
    }
    else{
        newNode->next=head;
        head = newNode;
    }
    printf("Inserted %d at the Begining ",val);
}

void display(){
    if (head==NULL){
        printf("List is empty\n");
        return;
    }
    node* temp = head;

    printf("Elements in the list are:\n");
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp = temp->next;
    }
}

void insertAtPosition(int pos,int val){
    node* newNode=(node*)malloc(sizeof(node));
    if(newNode==NULL){
        printf("out of Memory");
        return;
    }
    newNode->data=val;
    node* temp = head;
    for(int i=1;i<=pos-1;i++){
        temp=temp->next;
        if(temp==NULL){
           printf("Invalid position\n");
           return;
        }
    }
        newNode->next=temp->next;
        temp->next=newNode;

}

void deleteAtPosition(int pos){
    node* temp=head;
    node* prev;
    if(head==NULL){
        printf("List is empty");
        return;
    }
    if(pos==0){
        head=head->next;
        printf("Deleted %d",temp->data);
        free(temp);
        return;
    }
    for(int i=1;i<=pos;i++){
        prev = temp;
        temp=temp->next;
        if(temp==NULL){
            printf("Invalid position\n");
            return;
        }
    }
    prev ->next=temp->next;
    printf("Deleted %d",temp->data);
    free(temp);
    
}

void reverse(){
    node* prev = NULL;
    node* current = head;
    node* Next = head->next;

    while(current != NULL){
        Next=current->next;
        current->next=prev;
        prev=current;
        current=Next;
    }
    head=prev;
}


int main(){
    int choice,val,pos;

    while(1){

        printf("\n---------Linked List Menu---------\n");
        printf("1.Insert at Begining\n");
        printf("2.Display \n");
        printf("3.Insert specified pos \n");
        printf("4.Delete specified pos \n");
        printf("5.Reverse \n\n");
        printf("5.Exit\n\n");
        printf("\n-------------------------------\n");
        printf("Enter the choice:\t");
        scanf("%d",&choice);

    switch(choice) {

    case 1:
        printf("Enter the Value : ");
        scanf("%d",&val);
        insertAtBegining(val);
        break;
    
    case 2:
        display(val);
        break;

    case 3:
        printf("Enter the Position(start at 0) : ");
        scanf("%d",&pos);
        printf("Enter the Data : ");
        scanf("%d",&val);
        if(pos==0)
            insertAtBegining(val);
        else
            insertAtPosition(pos,val);
        break;

    case 4:
        printf("Enter the Position : ");
        scanf("%d",&pos);
        deleteAtPosition(pos);
        break;

    case 5:
        reverse();
        display();
    case 6:
        exit(0);

    default:
        printf("Invalid choice");
        break;
    }

    }
}
