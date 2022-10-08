/*
// This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).

Time Complexity:O(1)
Space Complexity:O(1)

*/
#include <iostream>
#include <stack>

using namespace std;

void push(stack<int> &s, int a);
bool isFull(stack<int> &s, int n);
bool isEmpty(stack<int> &s);
int pop(stack<int> &s);
int getMax(stack<int> &s);

stack<int> s;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a;
        cin >> n;
        while (!isEmpty(s))
        {
            pop(s);
        }
        while (!isFull(s, n))
        {
            cin >> a;
            push(s, a);
        }
        cout << getMax(s) << endl;
    }
}
// } Driver Code Ends

int maximum;
void push(stack<int> &s, int a)
{

    // checking whether my stack is empty
    if (s.size() == 0)
    {
        maximum = a;
        s.push(a);
    }
    // then will check which one is maximum and then insert it into the stack
    else
    {

        maximum = max(a, maximum);
        s.push(a);
    }
}

bool isFull(stack<int> &s, int n)
{

    if (s.size() == n)
        return true;
    else
        return false;
}

bool isEmpty(stack<int> &s)
{

    if (s.size() == 0)
        return true;
    else
        return false;
}
int pop(stack<int> &s)
{

    if (!s.empty())
    {
        int popElement = s.top();
        s.pop();
        return popElement;
    }
    return -1;
}

int getMax(stack<int> &s)
{

    return maximum;
}