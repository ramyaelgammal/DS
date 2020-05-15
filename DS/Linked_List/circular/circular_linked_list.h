#include <iostream>
using namespace std;

struct Node   
{
    int data;
    Node* next;
};

class CircLnkdLst
{
private:
    Node *head;
    void rDisp(const Node*  pnode);
    void _rDisp(const Node*  pnode);
    Node* getTail();
public:
    CircLnkdLst();
    CircLnkdLst(int A[], int size);
    Node* createNode(int x);
    void rDisplay();
    void Display();
    int count();
    void insert(int pos, int key);
    int remove(int pos);
};
