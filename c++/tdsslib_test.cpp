/*
 *
 * Test file for
 * 
 * Troy's Library
 * for
 * Data Structures and Sorting Algorithms
 * in C++
 *
 */

#include <iostream>
#include "tdsslib.h"

int main() {
    List list;

    list.add(10);
    list.add(15);
    list.push(5);
    list.add(20);
    std::cout << "Length of list: " << list.length() << "\n";
    list.printList();

    std::cout << "Index 2: " << list.get(2) << "\n";

    list.insert(2, 18);
    list.printList();
}