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
};

int main(){
    vector<int> arr = {2,4,7,9};

    /* so here we are creating node dynamically first understand this
    we are doing new Node, so the node is getting created in heap and y is a pointer so 
    basically y points to the address where that node is created 
    so when we do cout<< y , we will get memory addres, to access the element
    we do, y->data;
    */
    Node* y= new Node{arr[0],nullptr};
    cout<<y<<endl;
    cout<<y->data<<endl;



    /*here basically we are creating x object not a pointer 
    so now x is a box which stores data and pointer(here its a nullptr)
    to access its data we will do, x.data
    */
    Node x = Node{arr[1],nullptr};
    cout<<x.data<<endl;
    
}