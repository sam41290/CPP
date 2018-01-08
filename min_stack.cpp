/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack {
public:
    /** initialize your data structure here. */
    
    vector<int> stack;
    map<int,int> min_map;
    int stack_top;
    int min;
    
    MinStack() {
        stack_top = -1;
        min = INT_MAX;
    }
    
    void push(int x) {
        stack_top++;
        stack.push_back(x);
        if(x < min)
        {
            min = x;
        }
        min_map.insert(pair<int,int>(stack_top,min));
        
    }
    
    void pop() {
        
        min_map.erase(stack_top);
        stack.pop_back();
        stack_top--;
        if(stack_top < 0)
            min=INT_MAX;
        else
            min=getMin();
        
    }
    
    int top() {
        return stack[stack_top];
    }
    
    int getMin() {
        map<int,int> :: iterator itr;
        cout<<"top:"<<stack_top<<"\n";
        cout<<"top val:"<<stack[stack_top]<<"\n";
        itr=min_map.find(stack_top);
        return itr->second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
