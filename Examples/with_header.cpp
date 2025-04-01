#include <iostream>
#include "linkedlist.hpp"

int main() {
    LinkedList<int> mylist;

    mylist.append(1);
    mylist.append(2);
    mylist.append(3);
    mylist.append(4);
    mylist.append(5);

    mylist.print();
}
