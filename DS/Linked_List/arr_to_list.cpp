// Linked List display

#include <iostream>
#include <limits.h>
#include <exception>      // std::exception
#include <system_error>

using namespace std;
typedef struct _Node {
    int data;
    _Node *next;
} tNode;

tNode *head = nullptr;
tNode *tail = nullptr;

tNode* createNode(int data) {
    tNode *node;
    // create a list node
    node = new tNode;
    node->data = data;
    node->next = nullptr;
    return node;
}

void ArrToList(tNode *&pbase, int A[], int size) {
    int idx;
    tNode *temp;
    pbase = createNode(A[0]);
    tail = pbase;
    for (idx = 1; idx < size; idx++) {
        temp = createNode(A[idx]);
        tail->next = temp;
        tail = temp;
    }
}

void dispList(const tNode *pNode) {
    while (pNode) {
        cout << pNode->data << " ";
        pNode = pNode->next;
    }
    cout << endl;
}

void rDispList(const tNode *pNode) {
    if (pNode) {
        cout << pNode->data << " ";
        rDispList(pNode->next);
    } else {
        cout << endl;
    }
}

int nodeCount(const tNode *pNode) {
    int count = 0;
    while (pNode) {
        count++;
        pNode = pNode->next;
    }
    return count;
}

int r1NodeCount(const tNode *pNode) {
    static int count = 0;
    if (pNode) {
        count++;
        r1NodeCount(pNode->next);
    }
    return count;
}

int r2NodeCount(const tNode *pNode) {
    if (pNode == nullptr)
        return 0;
    return r2NodeCount(pNode->next) + 1;
}

int listSum(const tNode *pNode) {
    int sum = 0;
    while (pNode) {
        sum += pNode->data;
        pNode = pNode->next;
    }
    return sum;
}

int r1ListSum(const tNode *pNode) {
    static int sum = 0;
    static int retSum;
    if (pNode != nullptr) {
        sum += (pNode->data);
        r1ListSum(pNode->next);
    } else {
        retSum = sum;
        sum = 0; // init it for subsequent calls
    }
    return retSum;
}

int r2ListSum(const tNode *pNode) {
    if (pNode != nullptr)
        return r2ListSum(pNode->next) + (pNode->data);
    else
        return 0;
}

int max(const tNode *pNode) {
    int max = 0;
    if (pNode) {
        max = pNode->data;
        pNode = pNode->next;
    }
    while (pNode != nullptr) {
        if (pNode->data > max)
            max = pNode->data;
        pNode = pNode->next;
    }
    return max;
}

int rMax(const tNode *pNode) {
    int x = 0;
    if (pNode == nullptr)
        return INT32_MIN;
    x = rMax(pNode->next);
    if (x > pNode->data)
        return x;
    else
        return pNode->data;
}

tNode* search(tNode *pNode, int key) {
    tNode *pPrevNode = nullptr;
    while (pNode != nullptr) {
        if (key == pNode->data) {
            if (pPrevNode == nullptr)
                break; // first node contain key
            pPrevNode->next = pNode->next; // Linear search bring to head the pnode
            pNode->next = head;
            head = pNode;
            if (head == tail)
                tail = pPrevNode;
            break;
        } else {
            pPrevNode = pNode;
            pNode = pNode->next;
        }
    }
    return pNode;
}

tNode* rSearch(tNode *pNode, int key) {
    if (pNode == nullptr)
        return nullptr;
    if (key == pNode->data)
        return pNode;
    return rSearch(pNode->next, key);
}

void insertAfter(tNode *&pBase, int pos, int val) // pos in LL starts from 0
        {
    tNode *pNode, *pCurr;
    pNode = createNode(val);

    if (pos < -1)
        return;
    else if (pos == 0) {
        pNode->next = pBase;
        pBase = pNode;
    } else {
        pCurr = pBase;
        for (int i = 0; (i < pos - 1) && (pCurr != nullptr); i++)
            pCurr = pCurr->next;
        if (pCurr) {
            pNode->next = pCurr->next;
            pCurr->next = pNode;
        }
    }
}

void insertLast(int x) {
    tNode *t = createNode(x);
    if (head == nullptr)
        head = tail = t;
    else {
        tail->next = t;
        tail = t;
    }
}

void insertSorted(int x) {
    tNode *pnode = head;
    tNode *t = createNode(x);
    if (head == nullptr)
        head = t;
    else if (x < head->data) {
        t->next = head;
        head = t;
    } else {
        while ((pnode->next) && (x > pnode->next->data)) {
            pnode = pnode->next;
        }
        t->next = pnode->next;
        pnode->next = t;
    }

}
void reset() {
    while (head) {
        tNode *temp = head;
        head = head->next;
        delete (temp);
    }
    tail = head;
}

int remove() {
    int x = 0;
    if (head != nullptr) {
        tNode *t = head;
        head = head->next;
        x = t->data;
        delete (t);
    }

    return x;
}

int remove(int pos) {
    int val = 0;
    if (pos <= 0)
        return val;
    if (pos == 1)
        remove();
    tNode *prev = nullptr;
    tNode *pnode = head;
    for (int i = 0; (i < pos - 1) && (pnode); i++) {
        prev = pnode;
        pnode = pnode->next;
    }
    if (pnode) {
        prev->next = pnode->next;
        val = pnode->data;
        delete (pnode);
    }
    return val;
}

bool isSorted() {
    if (head == nullptr)
        return false;
    else if (head->next == nullptr)
        return true;
    else {
        int x = head->data;
        tNode *pnode = head->next;
        while (pnode != nullptr) {
            if (x > pnode->data)
                return false;
            x = pnode->data;
            pnode = pnode->next;
        }
        return true;
    }
}

void delDuplicate() {
    if (head == nullptr)
        return;
    else if (head->next == nullptr)
        return;
    else {
        tNode *pnode = head->next;
        tNode *prev = head;
        while (pnode != nullptr) {
            if (prev->data != pnode->data) {
                prev = pnode;
                pnode = pnode->next;
            } else {
                prev->next = pnode->next;
                delete (pnode);
                pnode = prev->next;
            }

        }
    }
}

void reverse() {
    tNode *pnode = head;
    int count = nodeCount(head);
    // int A[count]={};
    int *A = new int[count - 1];
    int i = 0;
    while (pnode) {
        A[i++] = pnode->data;
        pnode = pnode->next;
    }
    pnode = head;
    i--;
    while (pnode) {
        pnode->data = A[i--];
        pnode = pnode->next;
    }
    delete[] A;
}

void revLinks() {
    tNode *r, *q, *p;
    p = head;
    q = nullptr;
    r = nullptr;

    while (p) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

void f(tNode *q, tNode *p) {
    if (p == nullptr) {
        head = q;
        return;
    }
    f(p, p->next);
    p->next = q;
}

void rRevLinks() {
    f(nullptr, head);
}

void f2(tNode *r, tNode *q, tNode *p) {
    if (p == nullptr) {
        head = q;
        q->next = r;
        return;
    }
    q->next = r;
    return f2(q, p, p->next);
}

void rRevLinks2() {
    f2(nullptr, head, head->next);
}

void concat(tNode *const f, tNode *const s) {
//    if (f == s)
//        return;
    tNode *p = f;
    while (p->next != nullptr) {
        p = p->next;
    }
    p->next = s;
}

tNode* merge(tNode *f, tNode *s) {

    if (f == s || (!f && !s))
        return nullptr;
    tNode *p = f, *q = s;
    tNode *out, *m = nullptr;

    if (p->data < q->data) {
        m = createNode(p->data);
        out = m;
        p = p->next;
    } else {
        m = createNode(q->data);
        out = m;
        q = q->next;
    }

    while (p && q) {
        if (p->data < q->data) {
            m->next = createNode(p->data);
            m = m->next;
            p = p->next;
        } else {
            m->next = createNode(q->data);
            m = m->next;
            q = q->next;
        }
    } // get out because either reached to end of p list or q list

    while (p) {
        m->next = createNode(p->data);
        p = p->next;
        m = m->next;
    }
    while (q) {
        m->next = createNode(q->data);
        q = q->next;
        m = m->next;
    }
    return out;
}

tNode* mergeLinks(tNode *p, tNode *q) {
    tNode *out;
    tNode *m = nullptr;
    if (p->data < q->data) {
        m = p;
        p = p->next;
        out = m;
    } else {
        m = q;
        q = q->next;
        out = m;
    }
    while (p && q) {
        if (p->data < q->data) {
            m->next = p;
            p = p->next;
            m = m->next;
        } else {
            m->next = q;
            q = q->next;
            m = m->next;
        }
    }
    if (p)
        m->next = p;
    if (q)
        m->next = q;

    return out;
}

bool isLoop(tNode* pnode)
{
    tNode* p,*q;
    p=q=pnode;
    while(p && q){
        p = p->next;
        q = q->next;
        if(q) q = q->next;
        if(p==q) break;
    }
    if(p==q) return true;
    return false;
    
}

int main() {
    int Arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    ArrToList(head, Arr, sizeof(Arr) / sizeof(int));
    dispList(head);
    cout << "recursively display List: \n";
    rDispList(head);

    cout << "\nNumber of Nodes: " << nodeCount(head);
    cout << "\n[Recursively] rNumber of Nodes: " << r2NodeCount(head);

    cout << "\nSum: " << listSum(head);
    cout << "\n[Recursively] rSum: " << r2ListSum(head) << " ... again: "
            << r1ListSum(head);

    cout << "\nMax: " << max(head);
    cout << "\n[Recusively] rMax: " << rMax(head);
    tNode *p;
    cout << boolalpha;

    // p=search(root, 7); cout << "\nSearch(7), is '7' in the list: " << (p==nullptr? "NO": "YES") << endl;
    dispList(head);

    p = search(head, 1);
    cout << "\nSearch(1), is '1' in the list: " << (p == nullptr ? "NO" : "YES")
            << endl;
    dispList(head);

    p = search(head, 10);
    cout << "\nSearch(5), is '10' in the list: "
            << (p == nullptr ? "NO" : "YES") << endl;
    dispList(head);
    cout << "\ndisplay last: " << tail->data << endl;

    p = rSearch(head, 15);
    cout << "\n[Recursively] rSearch(15), is '15' in the list: "
            << (p == nullptr ? "NO" : "YES") << endl;
    dispList(head);

    p = rSearch(head, 10);
    cout << "\n[Recursively] rSearch(10), is '10' in the list: "
            << (p == nullptr ? "NO" : "YES") << endl;
    dispList(head);

    cout << "\nTry Insertion: \n";
    insertAfter(head, 1, 99);
    rDispList(head);

    reset();
    insertLast(9);
    insertLast(2);
    cout << "\nDisplay After Reset: ";
    rDispList(head);

    //create new list
    cout << "\nCreate new list using insert method: \n";
    tNode *root2 = 0;

    insertAfter(root2, 0, 4);
    dispList(root2);
    insertAfter(root2, 0, 3);
    dispList(root2);

    cout << "\nsorted list: \n";
    int Arr2[] = { 10, 20, 30, 40, 50, 60 };
    ArrToList(head, Arr2, sizeof(Arr2) / sizeof(int));
    insertSorted(4);
    insertSorted(34);
    dispList(head);

    cout << "\nTest Remove head: \n";
    remove();
    dispList(head);

    cout << "\nTest Remove node num 3: " << remove(3) << endl;
    dispList(head);

    cout << "\ncheck sorted?: " << isSorted() << endl;
    cout << "\nInsert 100 after elem #3: ";
    insertAfter(head, 0, 100);
    dispList(head);
    cout << "check sorted?: " << isSorted() << endl;
    //reset();

    cout << "\nsorted list with duplicated: \n";
    int Arr3[] = { 10, 10, 10, 10, 20, 20, 30, 30, 40, 50, 50, 50, 50, 60, 60 };
    ArrToList(head, Arr3, sizeof(Arr3) / sizeof(int));
    dispList(head);
    delDuplicate();
    dispList(head);

    cout << "\nReverse List: \n";
    //rRevLinks2();
    //reverse();
    rRevLinks();
    dispList(head);
    rRevLinks2();

    cout << "\nconcatenate these two lists: \n";
    dispList(head);
    dispList(root2);

    concat(head, root2);
    dispList(head);

    reset();
    cout << "\nMerge two lists:\n";
    int Arr4[] = { 2, 4, 8, 11 };
    ArrToList(head, Arr4, sizeof(Arr4) / sizeof(int));
    dispList(head);

    tNode *root3;
    int Arr5[] = { 5, 10, 7, 3 };
    ArrToList(root3, Arr5, sizeof(Arr5) / sizeof(int));
    dispList(root3);
    dispList(merge(head, root3));
    cout << "still input lists the same: \n";
    dispList(head);
    dispList(root3);

    cout << "\nMerge two lists with their links: \n";
    dispList(mergeLinks(head, root3));
    cout << "Input lists changed: \n";
    dispList(head);
    dispList(root3);
 
    cout << "\nforcing a loop, concat head with itself:\n";
    //dispList(head);
    cout << "\nBefore concat: does head has a loop? "<<isLoop(head);
    concat(head, head);
    cout << "\nafter concat: does head has a loop? "<<isLoop(root3);

    return 0;
}
