#include <iostream>
using namespace std;

struct Node   
{
    int data;
    Node* prev;
    Node* next;
};

class DoublyList
{
private:
    void rDisp(const Node*  pnode);
    void _rDisp(const Node*  pnode);
    Node* getTail();
    Node *head;
public:
    DoublyList();
    DoublyList(int A[], int size);
    Node* createNode(int x);
    void rDisplay();
    void Display();
    int count();
    void insert(int pos, int key);
    int remove(int pos);
    void reverse();
    bool isSorted();
    int getMiddle();
};