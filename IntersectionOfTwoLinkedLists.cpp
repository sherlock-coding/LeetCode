/*
 * 160 Intersection of Two Linked Lists
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 * Notes:
 *
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 * */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int length(ListNode *head)
{
    int len = 0;
    while (head) {
        ++len;
        head = head->next;
    }

    return len;
}

ListNode * getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (!headA || !headB)
        return NULL;

    int lena = length(headA);
    int lenb = length(headB);
    while (lena > lenb) {
        headA = headA->next;
        --lena;
    }
    while ( lena < lenb) {
        headB = headB->next;
        --lenb;
    }

    while (headA && headB) {
        if (headA == headB)
            return headA;
        else {
            headA = headA->next;
            headB = headB->next;
        }
    }

    return NULL;
}

int main()
{
    ListNode *headA = new ListNode(1);
    ListNode *headB = new ListNode(1);

    ListNode *ret = getIntersectionNode(headA, headB);
}
