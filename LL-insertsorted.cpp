#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*head=NULL;
void display(struct Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}
void create(int A[],int n){
    struct Node *t,*last;
    int i;
    head=new Node[sizeof(struct Node)];
    head->data=A[0];
    head->next=NULL;
    last=head;
    for(i=1;i<n;i++){
        t= new Node[sizeof(struct Node)];
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void sortedinsert(int x){
    struct Node *newnode=new Node[sizeof(struct Node)];
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL||x<head->data){
        newnode->next=head;
        head=newnode;
        return ;
    }
    struct Node *current=head;
    while(current!=NULL&&current->next->data<x){
        current=current->next;
    }
    newnode->next=current->next;
    current->next=newnode;

}
int main(){
    int A[]={1,3,5,7,8};
    create(A,5);
    cout << "Original Linked List: ";
    display(head);
    int elementToInsert;
    cout << "\nEnter the element to insert in the sorted list: ";
    cin >> elementToInsert;
    sortedinsert(elementToInsert);
    cout << "Updated Sorted Linked List: ";
    display(head);

    return 0;

}