#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node *right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }

    void insert(Node* root,int value){
        if(value<root->data){
            if(root->left==NULL){
                root->left=new Node(value);
            }
            else{
                insert(root->left,value);
            }
        }
        if(value>root->data){
            if(root->right==NULL){
                root->right=new Node(value);
            }
            else{
                insert(root->right,value);
            }
        }
    }
    void inorder() {
        if (left != NULL)
            left->inorder();

        cout << data << " ";

        if (right != NULL)
            right->inorder();
    }
};
int main(){
    Node* root=new Node(5);
    root->insert(root,6);
    root->insert(root,2);
    root->insert(root,10);
    root->insert(root,3);
    cout<<"Inorder Traversal: ";
    root->inorder(); 
}