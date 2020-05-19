#include <iostream>
#include "circular_linked_list.h"
using namespace std;

CircLnkdLst::CircLnkdLst() : head{nullptr}
{
}

CircLnkdLst::CircLnkdLst(int A[], int size)
{
    int idx;
    Node *temp;
    head = createNode(A[0]);
    Node *tail = head;
    for (idx = 1; idx < size; idx++)
    {
        temp = createNode(A[idx]);
        tail->next = temp;
        tail = temp;
    }
    tail->next = head; // now circular
}

Node *CircLnkdLst::createNode(int x)
{
    Node *pnode;
    // create a list node
    pnode = new Node;
    pnode->data = x;
    pnode->next = nullptr;
    return pnode;
}

void CircLnkdLst::rDisplay()
{
    rDisp(head);
    cout << endl;
}

void CircLnkdLst::_rDisp(const Node *pnode)
{

    cout << pnode->data << " ";
    if (pnode->next != head)
        _rDisp(pnode->next);
}

void CircLnkdLst::rDisp(const Node *pnode)
{
    static int flag = 0;
    if (pnode != head || flag == 0)
    {
        flag = 1;
        cout << pnode->data << " ";
        rDisp(pnode->next);
    }
    flag = 0;
}
Node* CircLnkdLst::getTail()
{
    Node* last = head;
    while(last->next != head) last = last->next;
    return last;
}
void CircLnkdLst::Display()
{
    if(head == nullptr) return;
    Node *pnode = head;
    do
    {
        cout << pnode->data << " ";
        pnode = pnode->next;
    } while (pnode != head);
    cout << endl;
}

int CircLnkdLst::count()
{
    int i = 0;
    if(head == nullptr) return 0;
    Node* p = head;
    do{
        i++;
        p = p->next;
    }while(p != head);
    return i;
}
/*
* insert at index pos
* indecies starts from index 0 [0,1,...,count-1]
*/
void CircLnkdLst::insert(int pos, int key)
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
            t->next = head;
        }
        else
        {
            last = getTail();
            t->next = head;
            last->next = t;
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
        t = createNode(key);
        t->next = p->next;
        p->next = t;
    }
}
// remove from index pos [0,1,.., count-1]
int CircLnkdLst::remove(int pos)
{
    Node* p = head, *q = nullptr;
    int x;
    Node* last = getTail();
    if(head == nullptr || pos >= count() || pos < 0) 
        return INT16_MIN;
    
    if(pos == 0)
    {
        p = head;
        last->next = head->next;
        head = head->next;
        x = p->data;
        delete(p);
    }
    else
    {
        for(int i=0; i <= pos-1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete(p);
    }
    return x;
}