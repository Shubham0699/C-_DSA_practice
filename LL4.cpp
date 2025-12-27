//this file is for doubly linkedlist 
#include<bits/stdc++.h>
using namespace std;

class node{

    public:

    int data;
    node* next;
    node* back;

    public:

    node(int data1, node* next1, node* back1){
        data=data1;
        next=next1;
        back=back1;
    }

    public:

    node(int data2){
        data=data2;
        next=nullptr;
        back=nullptr;
    }
};

node* arrayToLL(vector<int>&arr){
    node* head= new node(arr[0]);
    node* prev=head;

    for(int i=1;i<arr.size();i++){
        node* temp= new node(arr[i]);
        prev->next=temp;
        temp->back=prev;
        prev=prev->next;
        /*or we can write like
        prev=temp; cause temp is already assigned as prev's next */

    }
    return head;
}

node* removeheadDLL(node* head){
    if(head==NULL|| head->next==NULL) return NULL;

    node* prev=head;
    head=head->next;

    head->back=nullptr;
    prev->next=nullptr;
    
    delete prev;
    return head;
}

node* deletTail(node* head){
     if(!head|| !head->next) return NULL;
     node* tail=head;
     while(tail->next!= NULL){
        tail=tail->next;
     }
     node* prev=tail->back;
     prev->next=nullptr;
     tail->back=nullptr;
     delete tail;
     return head;
}

node* deletKnode(node* head, int k){
    node* temp=head;
    int cnt=0;
    while(temp){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }
    node* prev=temp->back;
    node* front= temp->next;
    if(prev==NULL && front ==NULL){
        delete temp;
        return NULL;
    }else if(prev==NULL){
        removeheadDLL(head);
    }else if(front == NULL){
        deletTail(head);
    }else{
        prev->next=front;
        front->back=prev;
        temp->back=temp->next=nullptr;
        delete (temp);
    }
    return head;

}


    void printDLL(node* head){
    while(head){

        cout<<head->data<<endl;
        head=head->next;
    }
}

int main(){
    vector<int>arr={2,1,4,5,7,9};
    node* head= arrayToLL(arr);
    cout<<"head of the doubly linkedlist is: "<<head->data<<endl;
    //cout<<"whole doubly LL:"<<endl;
    //printDLL(head);

    /*head=removeheadDLL(head);
    cout<<"new head:"<<head->data<<endl;
    
    head= deletTail(head);
    cout<<"head of the DLL whose tail is deleted:"<<head->data<<endl;
    printDLL(head);
    */

    head=deletKnode(head,3);
    cout<<"full LL after deleting kth node:"<<endl;
    printDLL(head);
}