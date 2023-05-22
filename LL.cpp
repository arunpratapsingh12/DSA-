#include <iostream>
#include <map>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructure
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory freed for this node " << value;
    }
};

void insertAthead(Node *&head, int d)
{
    // create the node
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insetAtTail(Node *&tail, int d)
{
    // create a new node
    Node *temp = new Node(d);

    tail->next = temp;
    tail = tail->next;
}

void insertAtspecific(Node *&tail, Node *&head, int d, int position)
{
    // insert at start

    if (position == 1)
    {
        insertAthead(head, d);
        return;
    }

    // tell us head;

    Node *temp = head;
    int cont = 1;

    while (cont < position - 1)
    {
        temp = temp->next;
        cont++;
    }

    // insert at end updating tail

    if (temp->next == NULL)
    {
        insetAtTail(tail, d);
    }

    // create a node
    Node *inserTonode = new Node(d);

    inserTonode->next = temp->next;
    temp->next = inserTonode;
}

// delete a node

void deleteAnode(Node *&head, int position)
{
    // starting node delete
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL; // remove the pointer to the next value 53min lec 44 dsa love babbar
        delete temp;
    }
    else
    { // delete a specific position

        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;

        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next; // remove the point of a node
        curr->next = NULL;       // remove the pointer to the next element of the delete node
        delete curr;
    }
}

void Print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// is LL is circular or not

bool iscircular(Node *&tail)
{
    // empty case

    if (tail == NULL)
    {
        return true;
    }

    // if ll has greater than 1 node

    Node *temp = tail->next;

    while (temp != NULL && temp != tail)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        return false;
    }

    if (temp == tail)
    {
        return true;
    }
}

// detect the cycle using map TC & SC o(n)

bool detectcycle(Node *head)
{
    if (head == NULL)
    {
        return false;
    }

    map<Node *, bool> visited;
    Node *temp = head;

    while (temp != NULL)
    {
        // loop present
        if (visited[temp] == true)
        {
            cout << "loop At position" << temp->data << endl;
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

// floyed detect cycle algo using map TC & SC o(n)

bool floyed(Node *head)
{

    if (head == NULL)
    {
        return false;
    }

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    // create a new node
    Node *node1 = new Node(10);
    //    cout<< node1->data <<endl;
    //    cout<< node1->next <<endl;

    // head pointed to node1

    Node *head = node1;
    Node *tail = node1;
    //  Print(head);
    insertAthead(head, 23);
    //  Print(head);

    insetAtTail(tail, 12);
    //     Print(head);
    insetAtTail(tail, 112);

    tail->next = head->next;

    cout << head->data << endl;
    cout << tail->data << endl;

    //           Print(head);

    if (floyed(head))
    {
        cout << "cycle present" << endl;
    }
    else
    {

        cout << "cycle not present" << endl;
    }

    //
    //     insertAtspecific(tail,head,13,4);
    //
    // Print(head);
    //    insertAtspecific(tail,head,13,1);
    //    Print(head);
    //    insertAtspecific(tail,head,13,7);
    //    Print(head);
    //
    //    deleteAnode(head,1);
    //      Print(head);
    //
    //
    //      if(iscircular)
    //{
    //    cout<<"it is a circular LL"<<endl;
    //}else{
    //    cout<<"it is not a  circular LL"<<endl;
    //
    //
    //}

    return 0;
}
