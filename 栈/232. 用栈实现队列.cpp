/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
 
 /*
 思路：重点在于实现push，用一个辅助栈helper。
 因为要把新元素放到栈底，所以入栈前把栈内所有元素转移到辅助栈中，
 新元素入栈后再把辅助栈中的元素弄回来。
 */
 
 
class MyQueue {
private:
    stack<int> s;
    stack<int> helper;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        int length = s.size();
        for(int i = 0; i < length; i++) {
            int temp = s.top();
            helper.push(temp);
            s.pop();
        }
        s.push(x);
        for(int i = 0; i < length; i++) {
            int temp = helper.top();
            s.push(temp);
            helper.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int frontElement = s.top();
        s.pop();
        return frontElement;
    }
    
    /** Get the front element. */
    int peek() {
        return s.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
};
