/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


/*
思路：题目是要实现一个除了可以push、pop、top以外还能得到当前栈内所有元素最小值的一个操作getMin。
然而栈只能访问栈顶元素，因此想到开两个栈。x_stack是元素栈，新元素都压入这个栈中；
另外一个辅助栈min_stack用来保存当前栈内元素的最小值，所以如果要getMin，就返回辅助栈的栈顶元素。
因为辅助栈存的是当前最小元素，所以当一个新元素入栈x_stack时，辅助栈也会将新元素与辅助栈当前栈顶元素
进行比较，得到一个新的最小值，再将这个新的最小值压入辅助栈中。
当元素要从x_stack出栈时，min_stack也弹出栈顶元素，这样就保证了min_stack栈顶元素就是当前的最小元素。
注意： 由于min_stack的入栈操作为min_stack.push(min(min_stack.top(), x));
所以构造函数中需要初始地做这么一个操作: min_stack.push(INT_MAX); 
*/

class MinStack {
private:
    stack<int> x_stack;
    stack<int> min_stack;
public:
    /** initialize your data structure here. */
    MinStack() {
        min_stack.push(INT_MAX);
    }

    void push(int x) {
        x_stack.push(x);
        min_stack.push(min(min_stack.top(), x));
    }
    
    void pop() {
        x_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return x_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
