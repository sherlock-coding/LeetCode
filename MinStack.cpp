/*
 * 155 Min Stack
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <stdexcept>

using namespace std;

class MinStack {
public:
    void push(int x) 
    {
        st.push_back(x);
        if (minx.second == 0 || x < minx.first) {
            minx.first = x;
            minx.second = 1;
        } else if (x == minx.first)
            minx.second += 1;
    }

    void pop()
    {
        if (!st.empty()) {
            int tmp = st.back();
            st.pop_back();
            if (st.empty()) {
                minx.second = 0;
                return;
            }
            if (tmp == minx.first) {
                minx.second -= 1;
                if (minx.second == 0) {
                    auto it = min_element(st.begin(), st.end());
                    minx.first = *it;
                    minx.second = 1;
                }
            }
        }
        else
            throw logic_error("stack is empty()");
    }

    int top() 
    {
        if (!st.empty())
            return st.back();
        throw logic_error("stack is empty");
    }

    int getMin() 
    {
        if (!st.empty())
            return minx.first;
        throw logic_error("stack is empty");
    }

private:
    vector<int> st;
    pair<int, size_t> minx;
};

int main()
{
    MinStack st;
    st.push(395);
    st.push(276);
    st.push(29);
    st.push(-482);
    st.pop();
    st.push(-108);
    st.push(-251);
    st.push(-439);
    st.push(370);
    st.pop();
    st.pop();
    cout << st.getMin() << endl;
}
