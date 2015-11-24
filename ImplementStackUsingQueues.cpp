/*
 * 225 Implement Stack using Queues
 * Implement the following operations of a stack using queues.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 * Notes:
 * You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
 * Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
 * You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
 * */

#include <iostream>
#include <queue>

using namespace std;

class Stack {
public:
    void push(int x) 
    {
        q.push(x);
        back = x;
    }

    void pop()
    {
        if (q.empty())
            return;
        int sz = q.size();
        for (int i = 0; i < sz - 1; ++i) {
            if ( i == sz -2)
                back = q.front();
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }

    int top() 
    {
        if (q.empty())
            return -1;
        return back;

    }

    bool empty()
    {
        return q.empty();
    }

private:
    queue<int> q;
    int back;
};

int main()
{

}
