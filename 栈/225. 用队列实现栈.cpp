/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
 
/*
思路：top可以直接返回队列的front, empty可以直接返回队列是否empty。
pop可以直接获取队首元素，再把队首元素出队，然后返回队首元素。
所以重点在于实现push操作。
一个新元素要push时，把队列中的所有元素按照先进先出的顺序重新入队（当然是在新元素之后）即可。
*/
 
class MyStack {
private:
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        int length = q.size();
        q.push(x);
        for(int i = 0; i < length; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int topElement = q.front();
        q.pop();
        return topElement;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};
