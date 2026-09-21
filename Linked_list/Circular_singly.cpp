#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Insert at beginning
void insertBeginning(Node *&head, int x)
{
    Node *newNode = new Node;
    newNode->data = x;

    // Empty list
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node *temp = head;

    // Go to last node
    while (temp->next != head)
    {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Insert at end
void insertEnd(Node *&head, int x)
{
    Node *newNode = new Node;
    newNode->data = x;

    // Empty list
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

// Insert at a specific position
void insertPosition(Node *&head, int x, int pos)
{
    if (pos <= 0)
    {
        cout << "Invalid position\n";
        return;
    }

    if (pos == 1)
    {
        insertBeginning(head, x);
        return;
    }

    if (head == NULL)
    {
        cout << "Invalid position\n";
        return;
    }

    Node *temp = head;

    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;

        if (temp == head)
        {
            cout << "Invalid position\n";
            return;
        }
    }

    Node *newNode = new Node;
    newNode->data = x;

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from beginning
void deleteBeginning(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    // Only one node
    if (head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;

    // Find last node
    while (temp->next != head)
    {
        temp = temp->next;
    }
    Node *del = head;
    head = head->next;
    temp->next = head;
    delete del;
}

// Delete from end
void deleteEnd(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    // Only one node
    if (head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }
    Node *temp = head;
    // Find second-last node
    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    Node *del = temp->next;
    temp->next = head;
    delete del;
}

// Delete a specific value
void deleteValue(Node *&head, int x)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    // If head contains value
    if (head->data == x)
    {
        deleteBeginning(head);
        return;
    }

    Node *temp = head;
    while (temp->next != head && temp->next->data != x)
    {
        temp = temp->next;
    }

    // Value not found
    if (temp->next == head)
    {
        cout << "Value not found\n";
        return;
    }
    Node *del = temp->next;
    temp->next = del->next;
    delete del;
}

// Search
void search(Node *head, int x)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node *temp = head;
    int pos = 1;
    do
    {
        if (temp->data == x)
        {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    cout << "Not found\n";
}

// Count nodes
int countNodes(Node *head)
{
    if (head == NULL)
        return 0;
    int count = 0;
    Node *temp = head;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

// Display
void display(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
// Update value
void update(Node *head, int oldValue, int newValue)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    Node *temp = head;
    do
    {
        if (temp->data == oldValue)
        {
            temp->data = newValue;
            cout << "Updated successfully\n";
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "Value not found\n";
}
// Reverse circular linked list
void reverseList(Node *&head)
{
    if (head == NULL || head->next == head)
        return;

    Node *prev = NULL;
    Node *curr = head;
    Node *next;
    Node *last = head;
    while (last->next != head)
    {
        last = last->next;
    }
    do
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

    } while (curr != head);
    head->next = prev;
    head = prev;
}

// Main
int main()
{
    Node *head = NULL;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);

    cout << "Original list: ";
    display(head);

    insertBeginning(head, 5);

    cout << "After inserting at beginning: ";
    display(head);

    insertPosition(head, 15, 3);

    cout << "After inserting at position 3: ";
    display(head);

    deleteBeginning(head);

    cout << "After deleting beginning: ";
    display(head);

    deleteEnd(head);

    cout << "After deleting end: ";
    display(head);

    deleteValue(head, 15);

    cout << "After deleting 15: ";
    display(head);
    search(head, 20);
    cout << "Number of nodes: "
         << countNodes(head) << endl;
    update(head, 20, 200);
    cout << "After update: ";
    display(head);
    reverseList(head);
    cout << "After reverse: ";
    display(head);
    return 0;
}