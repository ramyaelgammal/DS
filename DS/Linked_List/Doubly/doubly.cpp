#include <iostream>
#include "doubly_linked_list.h"
using namespace std;

void test1()
{
    int A[] = {10,15,20,30,90,42,75,16, 80};
    DoublyList dlist(A,sizeof(A)/sizeof(int));
    cout << std::boolalpha << dlist.isSorted()<<endl;

    // Display
    dlist.Display();
    cout << "Doubly List count: " << dlist.count() << endl;

    // Insert at tail
    cout << "Insert at Tail:\n";
    dlist.insert(dlist.count(),90);
    dlist.Display();

    // Insert at index 3
    cout << "Insert at index 3:\n";
    dlist.insert(3,101);
    dlist.Display();

   // Delete element 0 (head)
    cout << "\nDelete elem at index 0 [head]:\n";
    cout << "deleting: " << dlist.remove(0) << endl;
    dlist.Display();

    // Delete element 1
    cout << "\nDelete elem at index 1:\n";
    cout << "deleting: " << dlist.remove(1) << endl;
    dlist.Display();

    // Delete element last elem tail: its index count-1
    cout << "\nDelete elem at tail:\n";
    cout << "deleting: " << dlist.remove(dlist.count()-1) << endl;
    dlist.Display();

    cout << "\nReverse doubly list:\n";
    dlist.reverse();
    dlist.Display();

    cout << "\nGet Middle Element\n";
    cout << dlist.getMiddle() << endl;

}

void test2()
{

}
int main()
{
    test1();
    // test2();

   // cout<<"Hi\n\n"<<clist.count()<<endl;
    return 0;
}


