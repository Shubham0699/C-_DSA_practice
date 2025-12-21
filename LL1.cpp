#include <bits/stdc++.h>

using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data=data1;
        next=next1;

    }

    public:
    Node(int data2){
        data=data2;
        next= nullptr;

    }
};

/* 
now we will create array to linkedlist function
1. function will return linkedlist's head node 
2. function will take array by reference cause we are changing the array 
3.head pointer will always point to the first node of LL
4.then there will be mover pointer which will point to head
5.then we will iterate on array
6.there will be temp node pointer pointing at every index of array for every iteration
7.temp will always be mover's next and we will move forward mover
*/
 Node* arraytoLL(vector<int>&arr){
    Node* head= new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
 }



int main(){
    vector<int> arr1 = {2,4,7,9};

    /* so here we are creating node dynamically first understand this
    we are doing new Node, so the node is getting created in heap and y is a pointer so 
    basically y points to the address where that node is created 
    so when we do cout<< y , we will get memory addres, to access the element
    we do, y->data;
    */
    Node* y= new Node{arr1[0],nullptr};
    cout<<y<<endl;
    cout<<y->data<<endl;



    /*here basically we are creating x object not a pointer 
    so now x is a box which stores data and pointer(here its a nullptr)
    to access its data we will do, x.data
    */
    Node x = Node{arr1[1],nullptr};
    cout<<x.data<<endl;

    Node* H= arraytoLL(arr1);
    cout<<H->data<<endl;
    
}

/*
imp notes:
we are using struct but industry standards are, people use class
so whats the difference 
struct dont let us use oops concepts like encapsulation, abstraction etc 
class let us use that and and and.....
the members of class are private by default while that of struct are public 

so basically struct trusts us while class doesnt 
*/