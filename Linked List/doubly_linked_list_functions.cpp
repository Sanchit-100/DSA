#include<iostream>
using namespace std;

class Node{
    
    public:
        int data;
        Node* next;
        Node* prev;
          
        Node(int val){
            data=val;
            next=NULL;
            prev=NULL;
        }
    
};


void printLL(Node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    
    cout<<"NULL"<<endl;
}

void revPrint(Node* head){
    while((head->next)!=NULL){
        head=head->next;
    }
    
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->prev;
    }
    
    cout<<"NULL"<<endl;
}

void ReverseDLL(Node* &head){
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    
    head=temp;
    
    while(temp!=NULL){
        Node* ptr=temp->prev;
        temp->prev=temp->next;
        temp->next=ptr;
        
        temp=temp->next;
    }

}

void insertSortedDLL(Node*& head, int data){
    Node* temp=head;
    Node* n=new Node(data);
    
    if((head->data)>data){
        head=n;
        n->next=temp;
        temp->prev=n;
        return;
    }
    while(temp->next!=NULL){
        if((temp->next->data)<data){
            temp=temp->next;
        }
        else break;
    }   
    
    Node* ptr=temp->next;
    
    temp->next=n;
    n->next=ptr;
    if(ptr!=NULL) ptr->prev=n;
    n->prev=temp;
    
    return;
}
void insertNode(Node* &head,int val){
    Node* n=new Node(val);
    
    if(head==NULL){
        head=n;
        return;
    }
    
    Node* temp=head;
    
    while((temp->next)!=NULL){
        temp=temp->next;
    }
    
    temp->next=n;
    n->prev=temp;
    return;
    
}

int main(){
    Node* head=NULL;
    
    insertNode(head,3);
    insertNode(head,5);
    insertNode(head,7);
    insertNode(head,10);
    printLL(head);

    insertSortedDLL(head,8);
    printLL(head);
    return 0;
}

