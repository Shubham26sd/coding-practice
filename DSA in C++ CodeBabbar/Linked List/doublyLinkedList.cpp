#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data " << value << endl;
    }
};

// traversing a linked list
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// gives length of linked list
int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void insertAtHead(Node *&head, Node *&tail, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {

        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&head, Node *&tail, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at last position
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }

    // creating a node for d
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(int position, Node *&head, Node *&tail)
{
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if (curr->next == NULL)
        {
            curr->prev = NULL;
            tail = prev;
            prev->next = NULL;
            delete curr;
            return;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next->prev = prev;
        curr->next = NULL;
        delete (curr);
    }
}

int main()
{
    Node *node1 = new Node(10);
    Node *tail = NULL;
    Node *head = NULL;

    print(head);
    cout << getLength(head) << endl;

    insertAtHead(head, tail, 11);
    print(head);

    insertAtHead(head, tail, 13);
    print(head);

    insertAtHead(head, tail, 8);
    print(head);

    insertAtTail(head, tail, 25);
    print(head);

    insertAtPosition(head, tail, 2, 100);
    print(head);

    insertAtPosition(head, tail, 1, 101);
    print(head);

    // cout << "Head : " << head->data << endl;
    // cout << "Tail : " << tail->data << endl;
    insertAtPosition(head, tail, 7, 102);
    print(head);
    // cout << "Head : " << head->data << endl;
    // cout << "Tail : " << tail->data << endl;

    deleteNode(6, head, tail);
    print(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;
}