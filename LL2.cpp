//this one is for deletion and insertion:

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
    node(int data1){
        data=data1;
        next=nullptr;
    }

};

node* arraytoLL(vector<int> &arr){
    node* head = new node(arr[0]);
    node* mover=head;
    for(int i=1;i<arr.size();i++){
        node* temp = new node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

node* removehead(node* head){
    node* temp=head;
    head=head->next;
    delete temp;
    return head;
}

void printLL(node* head){
    node* temp=head;
    while(temp){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

node* deletek(node* head, int k){
    if(!head) return head;
    if(k==1){
        node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    int cnt=0;
     node* temp=head;
    node* prev= NULL;
    while(temp){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int> arr1={1,6,8,9,4};

    node* H = arraytoLL(arr1);
    cout<<"linkedlist's head:"<<H->data<<endl;

   /* cout<<"full linkedlist:"<<endl;
    printLL(H);

    node* h2 = removehead(H);
    cout<<"head after removing head:"<<h2->data<<endl;
    

    cout<<"linkedlist after removing the head:"<<endl;
    printLL(h2);
    */

    node* h3 = deletek(H,3);
    cout<<"whole LL after deletion at kth position:"<<endl;
    printLL(h3);
   
}