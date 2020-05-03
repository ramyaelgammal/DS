// Linked List display

#include <iostream>
using namespace std;
typedef struct _Node {
    int data;
    _Node *next;
} tNode;

tNode* createNode(int data)
{
    tNode* node;
    // create a list node
    node = new tNode;
    node->data = data;
    node->next = nullptr;
    return node;
}
tNode* ArrToList(int A[], int size)
{
    int idx;
    tNode *temp, *root, *last;
    root = createNode(A[0]);
    last = root;
    for (idx=1; idx<size; idx++ ){
        temp = createNode(A[idx]);
        last->next = temp;
        last = temp;
    }
    return root;
}

void dispList(tNode* const root)
{
    tNode* pNode = root;
    while(pNode){
        cout << pNode->data << " ";
        pNode = pNode->next;
    }
    cout<<endl;
}

void rDispList(tNode* pNode)
{
    if(pNode){
        cout << pNode->data << " ";
        rDispList(pNode->next);
    }
}
int main() {
    int Arr[] = {1,2,3,4,5,6};
    tNode *const root = ArrToList(Arr, sizeof(Arr)/sizeof(int));
    dispList(root);
    cout << "recursively display List: \n";
    rDispList(root);
    return 0;
}
