#include<iostream>
using namespace std;
class Node{
public:
int data;
Node *next;
Node(int val){
    data=val;
    next=NULL;
}
};

class MyStack{
    Node *top;
    int count;
    public:
    MyStack(){
        top=NULL;
        count=0;
    }
    void push(int x){
        Node* temp=new Node(x);
        temp->next=top;
        top=temp;
        count++;
    }
    int pop(){
        if(top==NULL){
            cout<<"Stack underflow";
            return -1;
        }
        Node *temp=top;
        top=top->next;
        int val=temp->data;
        count--;
        delete temp;
        return val;
    }
    int peek(){
        if(top==NULL){
            cout<<"Stack is empty";
            return -1;
        }
        return top->data;
    }
    int size(){
        return count;
    }

};
int main(){
    MyStack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<"Popped: "<<st.pop();
    cout<<"Top :"<<st.peek();

}