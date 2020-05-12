/*
 * Doubly linked list structure with a tail for fast appends
 */

struct ListNode {
    int data;
    ListNode* next;
    ListNode* prev;
};


struct List {
    ListNode* head;
    ListNode* tail;
};


List* newList();
ListNode* newListNode(int data);


void append(List* list, int data);
void prepend(List* list, int data);


void insertAfter(ListNode* node, int data);
void insertBefore(ListNode* node, int data);


void printForward(List* list);
void printBackward(List* list);
