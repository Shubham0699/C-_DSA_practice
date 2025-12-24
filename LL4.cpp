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
        prev=prev->next;
        /*or we can write like
        prev=temp; cause temp is already assigned as prev's next */

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
    cout<<"whole doubly LL:"<<endl;
    printDLL(head);
}