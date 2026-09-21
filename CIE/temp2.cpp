#include <iostream>
#include <string>
using namespace std;
struct Node
{
    int id;
    int priority;
    Node* prev;
    Node* next;
};
class TicketSystem
{
private:
    Node* head;
    Node* tail;
    Node* current;
    int totalLinkModifications;
public:
    TicketSystem()
    {
        head = NULL;
        tail = NULL;
        current = NULL;
        totalLinkModifications = 0;
    }
    Node* findTicket(int id)
    {
        Node* temp = head;

        while (temp != NULL)
        {
            if (temp->id == id)
                return temp;

            temp = temp->next;
        }
        return NULL;
    }

    void newTicket(int id, int priority)
    {
        int modifications = 0;
        if (findTicket(id) != NULL)
        {
            cout << "Invalid: Ticket_ID already exists." << endl;
            cout << "Link modifications: 0" << endl;
            return;
        }
        Node* newNode = new Node;
        newNode->id = id;
        newNode->priority = priority;
        newNode->prev = NULL;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            current = newNode;
            cout << "Ticket added." << endl;
            cout << "Link modifications: "
                 << modifications << endl;

            return;
        }
        Node* temp = head;

        while (temp != NULL &&
               temp->priority >= priority)
        {
            temp = temp->next;
        }
        if (temp == head)
        {
            newNode->next = head;
            modifications++;
            head->prev = newNode;
            modifications++;
            head = newNode;
        }

        // Insert at end
        else if (temp == NULL)
        {
            newNode->prev = tail;
            modifications++;
            tail->next = newNode;
            modifications++;

            tail = newNode;
        }

        else
        {
            Node* before = temp->prev;
            newNode->next = temp;
            modifications++;
            newNode->prev = before;
            modifications++;
            before->next = newNode;
            modifications++;
            temp->prev = newNode;
            modifications++;
        }
        totalLinkModifications += modifications;
        cout << "Ticket added." << endl;
        cout << "Link modifications: "
             << modifications << endl;
    }
    void nextTicket()
    {
        if (current == NULL)
        {
            cout << "No current ticket." << endl;
            return;
        }
        if (current->next == NULL)
        {
            cout << "Already at the last ticket." << endl;
            return;
        }
        current = current->next;
        cout << "Current ticket: "
             << current->id
             << " Priority: "
             << current->priority << endl;
    }
    void previousTicket()
    {
        if (current == NULL)
        {
            cout << "No current ticket." << endl;
            return;
        }

        if (current->prev == NULL)
        {
            cout << "Already at the first ticket." << endl;
            return;
        }
        current = current->prev;
        cout << "Current ticket: "<< current->id<< " Priority: "<< current->priority << endl;
    }
    void resolveTicket(int id)
    {
        int modifications = 0;
        Node* temp = findTicket(id);
        if (temp == NULL)
        {
            cout << "Invalid Ticket_ID." << endl;
            cout << "Link modifications: 0" << endl;
            return;
        }
        if (temp == current)
        {
            if (temp->next != NULL)
                current = temp->next;
            else
                current = temp->prev;
        }
        if (temp == head && temp == tail)
        {
            head = NULL;
            tail = NULL;
            current = NULL;
            delete temp;
            cout << "Ticket resolved!" << endl;
            cout << "Link modification: "<< modifications << endl;
            return;
        }
        if (temp == head)
        {
            head = temp->next;
            head->prev = NULL;
            modifications++;
            delete temp;
            totalLinkModifications += modifications;
            cout << "Ticket resolved." << endl;
            cout << "Link modifications: "<< modifications << endl;
            return;
        }
        if (temp == tail)
        {
            tail = temp->prev;
            tail->next = NULL;
            modifications++;
            delete temp;
            totalLinkModifications += modifications;
            cout << "Ticket resolved!" << endl;
            cout << "Link modification: "<< modifications << endl;
            return;
        }

        // Middle node
        Node* before = temp->prev;
        Node* after = temp->next;
        before->next = after;
        modifications++;
        after->prev = before;
        modifications++;
        delete temp;
        totalLinkModifications += modifications;
        cout << "Ticket resolved." << endl;
        cout << "Link modifications: "
             << modifications << endl;
    }
    void changePriority(int id, int newPriority)
    {
        int modifications = 0;
        Node* temp = findTicket(id);
        if (temp == NULL)
        {
            cout << "Invalid Ticket_ID." << endl;
            cout << "Link modifications: 0" << endl;
            return;
        }
        int oldPriority = temp->priority;      
        if (oldPriority == newPriority)
        {
            temp->priority = newPriority;
            cout << "Priority unchanged." << endl;
            cout << "Link modifications: 0" << endl;
            return;
        }

        bool wasCurrent = (temp == current);
        if (temp == head && temp == tail)
        {
            head = NULL;
            tail = NULL;
            current = NULL;
        }
        else if (temp == head)
        {
            head = temp->next;
            head->prev = NULL;
            modifications++;
        }
        else if (temp == tail)
        {
            tail = temp->prev;
            tail->next = NULL;
            modifications++;
        }
        else
        {
            Node* before = temp->prev;
            Node* after = temp->next;

            before->next = after;
            modifications++;
            after->prev = before;
            modifications++;
        }
    temp->priority = newPriority;

        temp->prev = NULL;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            tail = temp;
            current = temp;
        }
        else
        {
            Node* position = head;
            while (position != NULL &&
                   position->priority >= newPriority)
            {
                position = position->next;
            }
            if (position == head)
            {
                temp->next = head;
                modifications++;
                head->prev = temp;
                modifications++;
                head = temp;
            }

            else if (position == NULL)
            {
                temp->prev = tail;
                modifications++;
                tail->next = temp;
                modifications++;
                tail = temp;
            }
            else
            {
                Node* before = position->prev;
                temp->next = position;
                modifications++;
                temp->prev = before;
                modifications++;
                before->next = temp;
                modifications++;
                position->prev = temp;
                modifications++;
            }

            if (wasCurrent)
                current = temp;
        }
        totalLinkModifications += modifications;
        cout << "Priority changed and ticket repositioned."<< endl;
        cout << "Link modifications: "<< modifications << endl;
    }
    void show()
    {
        if (head == NULL)
        {
            cout << "No active tickets." << endl;
            return;
        }
        Node* temp = head;
        cout << "\nActive Tickets:" << endl;
        while (temp != NULL)
        {
            cout << "Ticket_ID: "
                 << temp->id
                 << " Priority: "
                 << temp->priority << endl;
            temp = temp->next;
        }
    }

    void showReverse()
    {
        if (tail == NULL)
        {
            cout << "No active tickets." << endl;
            return;
        }
        Node* temp = tail;
        cout << "\nActive Tickets (Reverse):" << endl;
        while (temp != NULL)
        {
            cout << "Ticket_ID: "
                 << temp->id
                 << " Priority: "
                 << temp->priority << endl;

            temp = temp->prev;
        }
    }
    void showCurrent()
    {
        if (current == NULL)
        {
            cout << "No current ticket." << endl;
            return;
        }

        cout << "Current Ticket_ID: "
             << current->id
             << " Priority: "
             << current->priority << endl;
    }

    void showTotalModifications()
    {
        cout << "\nTotal link modifications: "
             << totalLinkModifications << endl;
    }
    ~TicketSystem()
    {
        Node* temp = head;
        while (temp != NULL)
        {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};
int main()
{
    TicketSystem system;
    string command;
    cout << "Technical Support Ticket Navigator" << endl;
    cout << "Enter commands. Type END to finish." << endl;
    while (true)
    {
        cout << "\n> ";
        cin >> command;
        if (command == "NEW")
        {
            int id, priority;
            cin >> id >> priority;
            if (priority < 1 || priority > 5)
            {
                cout << "Invalid priority. "
                     << "Priority must be between 1 and 5."
                     << endl;
                continue;
            }
            system.newTicket(id, priority);
        }
        else if (command == "NEXT")
        {
            system.nextTicket();
        }
        else if (command == "PREVIOUS")
        {
            system.previousTicket();
        }
        else if (command == "RESOLVE")
        {
            int id;
            cin >> id;
            system.resolveTicket(id);
        }
        else if (command == "CHANGE")
        {
            int id, newPriority;
            cin >> id >> newPriority;
            if (newPriority < 1 || newPriority > 5)
            {
                cout << "Invalid priority. "
                     << "Priority must be between 1 and 5."
                     << endl;
                continue;
            }
            system.changePriority(id, newPriority);
        }
        else if (command == "SHOW")
        {
            system.show();
        }
        else if (command == "SHOW_REVERSE")
        {
            system.showReverse();
        }
        else if (command == "CURRENT")
        {
            system.showCurrent();
        }
        else if (command == "END")
        {
            break;
        }
        else
        {
            cout << "Invalid command." << endl;
        }
    }
    system.showTotalModifications();
    return 0;
}