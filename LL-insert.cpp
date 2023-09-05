#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*head=NULL;

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
void insertfront(int x){
    struct Node *newnode= new Node[sizeof(struct Node)];
    newnode->data=x;
    newnode->next=head;
    head=newnode;
}
void display(struct Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void insertatpos(int pos,int x){
    if(pos<0){
        cout<<"Invalid position "<<endl;
        return ;
    }
    struct Node *newnode=new Node[sizeof(struct Node)];
    newnode->data=x;
    if(pos==0){
        newnode->next=head;
        head=newnode;
        return;
    }
    struct Node *current=head;
    int count=0;
    while(current!=nullptr&&count<pos - 1){
        current=current->next;
        count++;
    }
    if(current==nullptr){
        cout<<"out of bounds"<<endl;
        return;
    }
    newnode->next=current->next;
    current->next=newnode;

}

int main(){
    int A[]={10,20,30,40,50};
    int position;
    create(A,5);
    cout<<"original linkedlist is : ";
    display(head);
    int element;
    cout<<"enter the element to insert :";
    cin>>element;
    cout << "Enter the position (0-based index) to insert at: ";
    cin >> position;
    insertatpos(position,element);
    cout<<"updated LinkedList : "<<endl;
    display(head);
    insertfront(element);
    cout<<"updated LinkedList : "<<endl;
    display(head);

    return 0;


}