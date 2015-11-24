/*
 * 206 Reverse Linked List
 * Reverse a singly linked list.
 * */

#include <iostream>

using namespace std;

stuct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode * reveseList(ListNode * head) 
{
    ListNode * p = NULL;
    ListNode * q = head;
    ListNode * r;
    
    while (q) {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }

    return p;

    /*
     return reverseListRecursive(head, NULL);
     */
}

ListNode * reverseListRecursive(ListNode *head, ListNode *newhead)
{
    if (!head)
        return newhead;
    ListNode * r = head->next;
    head->next = newhead;
    return reverseListRecursive(r, head);
}

int main()
{

}
