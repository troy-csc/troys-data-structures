#ifndef TDSSLIB_H
#define TDSSLIB_H

/*
 *
 * HEADER FILE FOR
 * Troy's Library
 * for
 * Data Structures and Sorting Algorithms
 * in C++
 *
 */

#include <iostream>

/*
 *
 * Singly Linked List
 * 
 */
class List {
    // Node for singly linked list
    class Node {
        public:
            int data;
            Node *next;
    };

    // creates a new node with data
    Node* createNode(int data) {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        std::cout << "Created node with data: " << newNode->data << "\n";
        return newNode;
    }

    void append(Node *node, int data) {
        Node *newNode = createNode(data);
        while(node != NULL) {
            if(node->next == NULL) {
                node->next = newNode;
                break;
            }
            node = node->next;
        }
    }

    public:
        // Reference to head of list
        Node* head = NULL;

        /* create and add a node to list
         * O(n)
         */
        void add(int data) {
            if(head == NULL) {
                Node *newNode = createNode(data);
                head = newNode;
            }
            else {
                append(head, data);
            }
        }

        /*
         * Add node to the start of the list
         */
        void push(int data) {
            Node *newNode = createNode(data);
            newNode->next = head;
            head = newNode;
        }

        /*
         * Insert node after given node
         */
        void insert(int index, int data) {
            int curIndex = 0;
            Node *node = head;
            while(node != NULL) {
                if(curIndex == index) {
                    Node *newNode = createNode(data);
                    newNode->next = node->next;
                    node->next = newNode;
                    break;
                }
                curIndex++;
                node = node->next;
            }
        }

        /* returns length of list
         * O(n)
         */
        int length() {
            Node *node = head;
            int len = 0;
            while(node != NULL) {
                len++;
                node = node->next;
            }
            return len;
        }

        int get(int index) {
            int cur = 0;
            Node *node = head;
            while(node != NULL) {
                if(cur == index) {
                    return node->data;
                }
                cur++;
                node = node->next;
            }
            std::cout << "Index out of bounds.\n";
            return NULL;
        }

        int getIndex(int data) {
            int index = 0;
            Node *node = head;
            while(node != NULL) {
                if(node->data == data) {
                    return index;
                }
                index++;
                node = node->next;
            }
            std::cout << "Node does not exist.\n";
        }

        int getIndex(Node *gNode) {
            int index = 0;
            Node *node = head;
            while(node != NULL) {
                if(node == gNode) {
                    return index;
                }
                index++;
                node = node->next;
            }
            std::cout << "Node does not exist.\n";
        }

        /* prints list
         * O(n)
         */
        void printList() {
            std::cout << "List: ";
            Node *node = head;
            while(node != NULL) {
                std::cout << node->data << "\t";
                node = node->next;
            }
            std::cout << "\n";
        }
};

/*
 *
 * Doubly Linked List
 * 
 */

// Implementation


/*
 *
 * Stack
 * 
 */

// Implemetation


/*
 *
 * Queue
 * 
 */

// Implemetation


/*
 *
 * Binary Tree
 * 
 */

// Implemetation


/*
 *
 * Binary Search Tree
 * 
 */

// Implemetation


/*
 *
 * Heap
 * 
 */

// Implemetation


/*
 *
 * Hashing
 * 
 */

// Implemetation


/*
 *
 * Matrix
 * 
 */

// Implemetation


/*
 *
 * Graph
 * 
 */

// Implemetation


#endif
