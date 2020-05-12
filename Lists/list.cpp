#include <iostream>
#include "list.hpp"


ListNode* newListNode(int data) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    node->next = nullptr;
    node->prev = nullptr;
}


List* newList() {
    List* list = (List*)malloc(sizeof(List));
    list->head = nullptr;
    list->tail = nullptr;
}


void prepend(List* list, int data) {
    if(!list) {
        std::cerr << "list is not initialized\n";
        return;
    }

    ListNode* newNode = newListNode(data);

    if(!list->head) {
        list->head = list->tail = newNode;
    }
    else {
        newNode->next = list->head; // forward link
        list->head->prev = newNode; // backward link
        list->head = newNode;
    }
}


void append(List* list, int data) {
    if(!list) {
        std::cerr << "list is not initialized\n";
        return;
    }

    ListNode* newNode = newListNode(data);

    if(!list->head) {
        list->head = list->tail = newNode;
    }
    else {
        newNode->prev = list->tail; // backward link
        list->tail->next = newNode; // forward link
        list->tail = newNode;
    }
}


void insertBefore(ListNode* node, int data) {
    ListNode* newNode = newListNode(data);

    // link the new node with the previous node
    node->prev->next = newNode;
    newNode->prev = node->prev;

    // link the new node with the current node
    node->prev = newNode;
    newNode->next = node;
}


void insertAfter(ListNode* node, int data) {
    ListNode* newNode = newListNode(data);

    // link the new node with the next node
    node->next->prev = newNode;
    newNode->next = node->next;

    // link the new node with the current node
    node->next = newNode;
    newNode->prev = node;
}


void printForward(List* list) {
    if(!list || !list->head) {
        std::cerr << "trying to print an empty list\n";
        return;
    }

    ListNode* walker = list->head;
    while(walker) {
        std::cout << walker->data << " ";
        walker = walker->next;
    }
    std::cout << "\n";
}


void printBackward(List* list) {
    if(!list || !list->tail) {
        std::cerr << "trying to print an empty list\n";
        return;
    }

    ListNode* walker = list->tail;
    while(walker) {
        std::cout << walker->data << " ";
        walker = walker->prev;
    }
    std::cout << "\n";
}
