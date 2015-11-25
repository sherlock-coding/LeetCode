/*
 * 232 Implement Queue using Stacks
 * Implement the following operations of a queue using stacks.
 *
 * push(x) -- Push element x to the back of queue.
 * pop() -- Removes the element from in front of queue.
 * peek() -- Get the front element.
 * empty() -- Return whether the queue is empty.
 * Notes:
 * You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
 * You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
 * */

#include <iostream>
#include <stack>

using namespace std;

class Queue {
public:
    void push(int x) 
    {
        sin.push(x);
    }

    void pop()
    {
        if (sout.empty()) {
            if (sin.empty())
                return;
            while (!sin.empty()) {
                sout.push(sin.top());
                sin.pop();
            }
        }

        sout.pop();
    }

    int peek() {
        if (sout.empty()) {
            if (sin.empty())
                return -1;
            while (!sin.empty()) {
                sout.push(sin.top());
                sin.pop();
            }
        }
        
        return sout.top();
    }

    bool empty() 
    {
        if (sin.empty() && sout.empty())
            return true;
        return false;
    }
private:
    stack<int> sin;
    stack<int> sout;
};

int main()
{
}
