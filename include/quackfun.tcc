/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 *  stacks and queues portion of the lab.
 */
#include<iostream>

namespace quackfun
{

/**
 * Sums items in a stack.
 * @param s A stack holding values to sum.
 * @return The sum of all the elements in the stack, leaving the original
 *  stack in the same state (unchanged).
 *
 * @note You may modify the stack as long as you restore it to its original
 * values.
 *
 * @note You may use only two local variables of type T in your function.
 * Note that this function is templatized on the stack's type, so stacks of
 * objects overloading the + operator can be summed.
 *
 * @note We are using the standard library stack in this problem. Its pop
 * function works a bit differently from the stack we built. Try searching
 * for "stl stack" to learn how to use it.
 *
 * @hint Think recursively!
 */
    
template <typename T>
T sum(std::stack<T>& s)
{
    if(s.empty())
    {
        return T{};
    }    
    auto t = s.top();
    s.pop();
    auto sum_ = sum(s);
    
    s.push(t);
    sum_ = sum_+ t;
    
    return sum_;       
   
    // Your code here
    
}

/**
 * Reverses even sized blocks of items in the queue. Blocks start at size
 * one and increase for each subsequent block.
 * @param q A queue of items to be scrambled
 *
 * @note Any "leftover" numbers should be handled as if their block was
 * complete.
 *
 * @note We are using the standard library queue in this problem. Its pop
 * function works a bit differently from the stack we built. Try searching
 * for "stl stack" to learn how to use it.
 *
 * @hint You'll want to make a local stack variable.
 */
template <typename T>
void scramble(std::queue<T>& q)
{
    std::stack<T> s;
    auto check = 1;                           // To check even sized blocks of elements.
    int count = 1;                            // To count the number of elements arranged.
    int length = q.size();                    // Getting the size of given queue.

    while(count <= length) {

        if(check % 2 != 0) {
            for(auto i = 1; i<= check; ++i) { // Arranging odd sized blocks of elements.
                q.push(q.front());
                q.pop();
                ++count;
            }   
        }

        else {
            for(int i = 1; i <= check; ++i)  // Placing even sized blocks of elements in a local stack variable and removing them from queue.
            {
                if(count <= length) {
                    s.push(q.front());
                    q.pop();
                    ++count;
                }
            }
            for(int j = 1; j <= check; ++j)  // Placing even sized block of elements in reverse order in the queue and emptying the stack variable.
            {                                
                if(!s.empty()) {
                    q.push(s.top());
                    s.pop();
                }
            }
        
        }
    ++check;
    }
}
/**
 * @return true if the parameter stack and queue contain only elements of
 * exactly the same values in exactly the same order; false, otherwise.
 *
 * @note You may assume the stack and queue contain the same number of items!
 *
 * @note There are restrictions for writing this function.
 * - Your function may not use any loops
 * - In your function you may only declare ONE local boolean variable to
 *   use in your return statement, and you may only declare TWO local
 *   variables of parametrized type T to use however you wish.
 *   No other local variables can be used.
 * - After execution of verify_same, the stack and queue must be unchanged. Be
 *   sure to comment your code VERY well.
 */

template <typename T>
bool verify_same(std::stack<T>& s, std::queue<T>& q)
{
bool retval = true;
    if(s.empty() || q.empty())
    {
        return retval;
    }
    auto s_top = s.top();
    s.pop();
    verify_same(s,q);

    if(q.front() == s_top) {
        q.push(q.front());
        s.push(s_top);
        q.pop();
    }
    else {
        s.push(s_top);
        retval = false;
    }
    return retval;
}

} 