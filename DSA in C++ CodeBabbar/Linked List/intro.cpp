#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Linked List
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

void insertAtHead(Node *&head, int data)
{

    // new node create
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at last node
    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }

    // creating a node for data
    Node *nodeTOInsert = new Node(data);
    nodeTOInsert->next = temp->next;
    temp->next = nodeTOInsert;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void deleteNode(int position, Node *&head, Node *&tail)
{
    // Deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // check if list is empty
        if (head == NULL)
        {
            tail = NULL;
        }
        temp->next = NULL;
        // memory free
        delete temp;
    }

    else
    {
        // deleting any other node
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;

        // handling tail
        if (prev->next == NULL)
        {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}

int main()
{

    // Created a new node
    Node *node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;

    Node *head = node1;
    Node *tail = node1;
    print(head);

    // insertAtHead(head, 12);
    // print(head);

    insertAtTail(tail, 12);
    print(head);

    insertAtTail(tail, 15);
    print(head);

    insertAtPosition(head, tail, 4, 22);
    print(head);

    cout << endl;
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;

    deleteNode(1, head, tail);
    print(head);

    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;

    return 0;
}