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
    // Testing singly linked list
    SiList list;

    list.add(10);
    list.add(15);
    list.push(5);
    list.add(20);
    std::cout << "Length of list: " << list.length() << "\n";
    list.printList();

    std::cout << "Index 2: " << list.get(2) << "\n";

    list.insert(2, 18);
    list.printList();

    std::cout << "Deleting node" << "\n";
    list.deleteNode(1);
    list.printList();

    list.add(1);
    list.printList();


    // Testing doubly linked list
    std::cout << "\nTesting doubly linked list\n";
    DlList list2;

    list2.add(5);
    list2.add(10);
    list2.add(3);
    list2.printList();

    list2.push(20);
    list2.printList();

    list2.insert(1, 18);
    list2.printList();

    std::cout << "Length: " << list2.length() << "\n";

    std::cout << "Index 2: " << list2.get(2) << "\n";
    std::cout << "Index at 18: " << list2.getIndex(18) << "\n";

    list2.deleteNode(1);
    list2.printList();

    // Testing Stack
    std::cout << "\n" << "Testing Stack\n";
    Stack stack1;
    std::cout << "Is stack empty? " << stack1.isEmpty() << "\n";
    stack1.push(5);
    stack1.push(12);
    stack1.print();
    std::cout << "Is stack empty? " << stack1.isEmpty() << "\n";
    std::cout << "pop: " << stack1.pop() << "\n";
    stack1.push(20);
    stack1.print();

    // Testing Queue
    Queue q1;
    std::cout << "\n" << "Testing Queue\n";
    std::cout << "Is queue empty? " << q1.isEmpty() << "\n";
    q1.enqueue(5);
    q1.enqueue(12);
    q1.print();
    std::cout << "Is queue empty? " << q1.isEmpty() << "\n";
    std::cout << "dequeue: " << q1.dequeue() << "\n";
    q1.enqueue(20);
    q1.print();
}