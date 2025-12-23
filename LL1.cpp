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

 /*
 1.now to find length we will just take a cnt variable initalizingat 0 
 and after every traversal its ciunt is going to be increased 
 so basically cnt 0 till cnt n
 2.n being the size of ll
 */

int lengthofLL(Node* head){
    int cnt=0;

        /*for traversal 
    1. first and foremost rule of linkedlist is never mess with head so 
    we will keep one pointer at head which will traverse furthure 
    2. then we will use loop using traversal pointer
    3. and then just printing data of the pointer 
     */

     Node* temp=head;
     while(temp){
        
        cnt++;
        temp=temp->next;
        
     }
     return cnt;
}

int chekifPresent(Node* head, int val){
    Node* temp= head;
    while(temp){
        if(temp->data==val) return 1;
        temp=temp->next;
    }
    return 0;
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
    cout<<"head of linkedlist converted from array: "<<H->data<<endl;

    int count= lengthofLL(H);
    cout<<"lengt of LL: "<<count<<endl;

    int n= chekifPresent(H,0);
    cout<<"output of if present: "<<n<<endl;

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