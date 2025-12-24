//this one is for insertion

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    public:

    node(int data1, node* next1){
        data=data1;
        next=next1;
    }

    public:

    node(int data2){
        data=data2;
        next=nullptr;
    }
};

node* arrayToLL(vector<int> &arr){
    node* head = new node(arr[0]);
    node* mover=head;
    for(int i=1;i<arr.size();i++){
        node* temp= new node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

/*
this one is for insertion at head 
so its simple, basically we are just creating new node 
with the next pointer pointing at existing head and data will be given value
*/

node* insertathead(node* head, int val){
    return new node(val,head);
}

void printLL(node* head){
    node* temp =head;
    while(temp){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

 node* insertAttail(node* head, int val){
   if(head==NULL) return new node(val);

   node* temp=head;

   while(temp->next != NULL){
    temp=temp->next;
   }

   temp->next= new node(val);

   return head;
}

int main(){
    vector<int>arr={1,4,3,5,7,8};
    node* H = arrayToLL(arr);
    cout<<"head of the LL:"<<H->data<<endl;
    
   /*H = insertathead(H,10);
    cout<<"head of newly created LL:"<<H->data<<endl;

    cout<<"updated LL is:"<<endl;
    printLL(H);
    */
    
    H=insertAttail(H,27);
    cout<<"insertion at tail:"<<endl;
    printLL(H);


}

