#include <iostream>
#include "circular_linked_list.h"
using namespace std;

int main()
{
    system("color %");

    int A[] = {2,3,4,5,6};
    CircLnkdLst clist(A,5);
    // Display
    clist.rDisplay();

    // Insert at head
    cout << "delete head\n";
    clist.insert(0,9);
    clist.Display();

    // Insert at tail
    cout << "Insert at Tail:\n";
    clist.insert(clist.count(),9);
    clist.Display();

    // Insert at index 3
    cout << "Insert at index 3:\n";
    clist.insert(1,10);
    clist.Display();

    // Delete element 0 (head)
    cout << "\nDelete elem at index 0 [head]:\n";
    cout << "deleting: " << clist.remove(0) << endl;
    clist.Display();

    // Delete element 1
    cout << "\nDelete elem at index 1:\n";
    cout << "deleting: " << clist.remove(1) << endl;
    clist.Display();

    // Delete element last elem tail: its index count-1
    cout << "\nDelete elem at tail:\n";
    cout << "deleting: " << clist.remove(clist.count()-1) << endl;
    clist.Display();

   // cout<<"Hi\n\n"<<clist.count()<<endl;
    return 0;
}


