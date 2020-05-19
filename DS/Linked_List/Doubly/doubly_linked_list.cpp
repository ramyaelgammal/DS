#include "doubly_linked_list.h"

DoublyList::DoublyList():head{nullptr}
{
}

Node* DoublyList::createNode(int x)
{
    Node *pnode;
    // create a list node
    pnode = new Node;
    pnode->data = x;
    pnode->next = nullptr;
    pnode->prev = nullptr;
    return pnode;
}

DoublyList::DoublyList(int A[], int size)
{
    int idx;
    Node *temp;
    head = createNode(A[0]);
    Node *tail = head;
    for (idx = 1; idx < size; idx++)
    {
        temp = createNode(A[idx]);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void DoublyList::Display()
{
    if(head == nullptr) return;
    Node* p =  head;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int DoublyList::count()
{
    int len = 0;
    if(head == nullptr) return 0;
    Node* p = head;
    while(p){
        len++;
        p = p->next;
    };
    return len;
}

/*
* insert at index pos
* indecies starts from index 0 [0,1,...,count-1]
*/
void DoublyList::insert(int pos, int key)
{
    Node* p=head, *t, *last=head;
    int i = 0;

    if(pos<0 || pos > count()) return;
    t = createNode(key);

    if (pos == 0)
    {
        if (head == nullptr)
        {
            head = t;
        }
        else
        {
            t->next = head;
            head->prev = t;
            head = t;
        }
    }
    else
    {
        if(head == nullptr) return;
        for(i=0; (i < pos-1); i++)
        {
            p=p->next;
        }
        t->next = p->next;
        if(p->next) p->next->prev = t;
        t->prev = p;
        p->next = t;
    }
}

// remove from index pos [0,1,.., count-1]
int DoublyList::remove(int pos)
{
    Node* p = head;
    int x;
    if(head == nullptr || pos >= count() || pos < 0) 
        return INT16_MIN;
    
    if(pos == 0)
    {
        p = head;
        head = head->next;
        if(head) head->prev = nullptr;
        x = p->data;
        delete(p);
    }
    else
    {
        for(int i=0; i <= pos-1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if(p->next) p->next->prev = p->prev;
        x = p->data;
        delete(p);
    }
    return x;
}

void DoublyList::reverse()
{
    Node* p = head;
    Node* t;
    if(p->next == nullptr) return;
    while(p!=nullptr) {
        t = p->prev;
        p->prev = p->next;
        p->next = t;
        p = p->prev;
    };
    head = t->prev;
}

bool DoublyList::isSorted()
{
    static Node* p = head;
    if((p == NULL)|| (p->next == NULL)) 
    {
        p = head; 
        return true;
    }
    else if(p ->data <= p ->next->data)
    {
        p = p->next;
        return isSorted();
    }
    else
    {
        p = head;
        return false;
    }
    return true;
}

int DoublyList::getMiddle()
{
    Node *p,*q;
    q = p = head;
    while(p)
    {
        p = p->next;
        if(p) p = p->next;
        if(p) q = q->next;
    }
    return q->data;
}