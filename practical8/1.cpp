#include <iostream>
#include <queue>
using namespace std;
class Node {
public:
    int data;
    Node *right;
    Node *left;
    Node(int d) {
        data = d;
        right = NULL;
        left = NULL;
    }
    void preorder() {
        cout<<data<<" ";
        if(left!= NULL)
            left->preorder();
        if(right!= NULL)
            right->preorder();
    }
    void inorder() {
        if(left!= NULL)
            left->inorder();
        cout<<data<<" ";
        if (right != NULL)
            right->inorder();
    }
    void postorder() {
        if(left!= NULL)
            left->postorder();
        if(right!= NULL)
            right->postorder();
        cout<<data<< " ";
    }
};

void insert(Node* root, int value) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        if (current->left == NULL) {
            current->left = new Node(value);
            return;
        }
        else {
            q.push(current->left);
        }
        if (current->right == NULL) {
            current->right = new Node(value);
            return;
        }
        else {
            q.push(current->right);
        }
    }
}

void levelOrder(Node* root) {
    if (root == NULL)
        return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left != NULL)
            q.push(current->left);
        if (current->right != NULL)
            q.push(current->right);
    }
}
int main() {
    Node* root = new Node(5);
    insert(root,3);
    insert(root,7);
    insert(root,1);
    insert(root,9);
    cout<<"Inorder: ";
    root->inorder();
    cout<<endl;
    cout<<"Preorder: ";
    root->preorder();
    cout<<endl;
    cout<<"Postorder: ";
    root->postorder();
    cout<<endl;
    cout<<"Level Order: ";
    levelOrder(root);
    return 0;
}