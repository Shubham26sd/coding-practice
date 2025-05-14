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
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with value " << value << endl;
    }
};

void insertNode(Node *&tail, int element, int d)
{
    // assuming that the element is present in the list

    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
        return;
    }
    else
    {
        // non empty list
        // assuming that the element is present in the list

        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }

        // element found -> curr is representing element wala node
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *&tail)
{
    Node *temp = tail;

    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

void deleteNode(Node *&tail, int value)
{
    // empty list
    if (tail == NULL)
    {
        cout << "List is empty, please check again" << endl;
        return;
    }
    else
    {
        // non-empty
        // assuming that "value" is present in the list

        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        // 1 Node linked list
        if (curr == prev)
        {
            tail = NULL;
        }

        // >=2 Node linked list
        if (tail == curr)
        {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}

bool isCircular(Node *head)
{
    // empty list
    if (head == NULL)
    {
        return true;
    }
    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        return true;
    }

    return false;
}

int main()
{
    Node *tail = NULL;
    Node *node1 = new Node(10);

    // empty list me insert krre hai
    insertNode(tail, 5, 3);

    insertNode(tail, 3, 5);

    insertNode(tail, 5, 7);

    insertNode(tail, 7, 9);
    insertNode(tail, 5, 6);

    insertNode(tail, 9, 10);

    insertNode(tail, 3, 4);
    print(tail);

    if (isCircular(tail))
    {
        cout << "Linked list is circular" << endl;
    }
    else
    {
        cout << "Linked list is not circular" << endl;
    }
}
