#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertatend(node *&head, node *&tail, int data)
{
    if (head == NULL)
    {
        head = tail = new node(data);
    }
    else
    {
        node *n = new node(data);
        tail->next = n;
        tail = n;
    }
}


void printLL(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "NULL\n";
}

//////////////////////MERGE TWO SORTED LL///////////////////////////////
node *mergesortedll(node *h1, node *h2)
{

    if (!h2)
        return h1;
    if (!h1)
        return h2;


    node *nH = NULL;
    if (h1->data < h2->data)
    {
        nH = h1;
        nH->next = mergesortedll(h1->next, h2);
    }
    else
    {
        nH = h2;
        nH->next = mergesortedll(h1, h2->next);
    }
    return nH;
}

//////////////////////MERGE TWO SORTED LL///////////////////////////////

/////////////////////Middle of LL////////////////////////////////////
node *midll(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *slow = head;
    node *fast = head->next;

    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node *mergesort(node *head)
{
    // base case
    if (head == NULL or head->next == NULL)
        return head;
    // recursive case
    // 1. Divide LL
    node *m = midll(head);
    node *a = head;
    node *b = m->next;
    m->next = NULL;

    // 2. Sort
    a = mergesort(a);
    b = mergesort(b);

    // 3. Merge
    node *nH = mergesortedll(a, b);
    return nH;
}

int main()
{
    node *head = NULL, *tail = NULL;
    node *head1 = NULL, *tail1 = NULL;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int d;
        cin >> d;
        insertatend(head, tail, d);
    }

    head = mergesortedll(head, head1);
    head = mergesort(head);

    printLL(head);

    return 0;
}