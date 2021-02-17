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
class SiList {
    // Node for singly linked list
    class Node {
        public:
            int data;
            Node *next;
    };

    // Reference to head of list
    Node* head = NULL;

    // creates a new node with data
    Node* createNode(int data) {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        std::cout << "Created node with data: " << newNode->data << "\n";
        return newNode;
    }

    // add node to the end of a list
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

        // deletes node at the given index
        void deleteNode(int index) {
            int curIndex = 0;
            Node *node = head;
            Node *pNode = NULL;

            if(index == 0) {
                head = node->next;
                return;
            }

            while(node != NULL) {
                if(curIndex == index) {
                    pNode->next = node->next;
                }
                pNode = node;
                node = node->next;
                curIndex++;
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

        // Get the data value of a node at a given index
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

        // get the index of the first occurrance of a given data value
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

        // get the index of the given pointer to node
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
            std::cout << "List:\t";
            Node *node = head;
            while(node != NULL) {
                if(node->next == NULL) {
                    std::cout << node->data << "\n";
                }
                else {
                    std::cout << node->data << " -> ";
                }
                node = node->next;
            }
        }
};

/*
 *
 * Doubly Linked List
 * 
 */

class DlList {
    class Node {
        public:
            int data;
            Node *prev;
            Node *next;
    };

    Node *head = NULL;

    Node* createNode(int data) {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;
        return newNode;
    }

    void append(int data) {
        Node *newNode = createNode(data);
        Node *node = head;

        while(node != NULL) {
            if(node->next == NULL) {
                node->next = newNode;
                newNode->prev = node;
                break;
            }
            node = node->next;
        }
    }

    public:
        // Add node
        void add(int data) {
            if(head == NULL) {
                Node *newNode = createNode(data);
                head = newNode;
                newNode->prev = head;
            }
            else {
                append(data);
            }
        }

        // Push node
        void push(int data) {
            Node *newNode = createNode(data);
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        // Insert after given index
        void insert(int index, int data) {
            Node *node = head;
            for(int cIndex = 0; node != NULL; cIndex++) {
                if(cIndex == index) {
                    Node *newNode = createNode(data);
                    newNode->prev = node;
                    node->next->prev = newNode;
                    newNode->next = node->next;
                    node->next = newNode;
                }
                node = node->next;
            }
        }

        // Delete
        void deleteNode(int index) {
            Node *node = head;
            for(int i = 0; node != NULL; i++) {
                if(i == index) {
                    node->prev->next = node->next;
                    node->next->prev = node->prev;
                    node->next == NULL;
                    node->prev == NULL;
                }
                node = node->next;
            }
        }

        // Length
        int length() {
            Node *node = head;
            int len = 0;
            while(node != NULL) {
                len++;
                node = node->next;
            }
            return len;
        }

        // Get
        int get(int index) {
            Node *node = head;
            for(int i = 0; node != NULL; i++) {
                if(i == index) {
                    return node->data;
                }
                node = node->next;
            }
        }

        int getIndex(int data) {
            Node *node = head;
            for(int i = 0; node != NULL; i++) {
                if(node->data == data) {
                    return i;
                }
                node = node->next;
            }
        }

        int getIndex(Node *gNode) {
            Node *node = head;
            for(int i = 0; node != NULL; i++) {
                if(node == gNode) {
                    return i;
                }
                node = node->next;
            }
        }

        // Print
        void printList() {
            Node *node = head;

            std::cout << "List:\t";

            while(node != NULL) {
                if(node->next == NULL) {
                    std::cout << node->data << "\n";
                }
                else {
                    std::cout << node->data << " <-> ";
                }
                node = node->next;
            }
        }
};


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


/*
 *
 * Set
 * 
 */

// Implementation

#endif
