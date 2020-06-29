/*
开两个栈helper和Queue来模拟队列，helper用来中转元素，Queue存放倒序（与元素入队顺序相反）的元素。
这样pop()的时候就相当于最先进入“队列”的元素出队。

举个例子：最开始有四个元素1, 2, 3, 4要入队，由于我们只有栈，我们希望在栈Queue中存放的顺序是4, 3, 2, 1(分别是栈底到栈顶），
这不，我们这好有一个helper么，于是把元素全都放到helper里，此时helper中从栈底到栈顶的元素分别是1, 2, 3, 4，这样可模拟不了“出队”，
于是再逐个将栈顶元素出栈，并压入Queue栈中，于是Queue中就存放4, 3, 2, 1（顺序为从栈底到栈顶），要出队只需要pop()一下就行了。

题目要求deleteHead（即出队）的时候，队列为空返回-1，我们只需要判断栈Queue是否为空即可。如果非空就直接pop()。

对于入队(appendTail)，要注意原来的栈Queue可能非空，所以入队前需要把Queue中所有的元素逐个弹出并压入helper中，

比如最开始的入队顺序如果是1, 2, 3, 4，Queue中元素顺序从栈底到栈顶为4, 3, 2, 1, 
逐个弹出压入到helper中后helper中从栈底到栈顶的元素分别为1, 2, 3, 4（就是最开始的入队顺序），
这时我们再把要添加（入队）的元素压入helper中，后面的操作就简单了，把helper中的所有元素弹出并压入栈Queue中。
*/


class CQueue {
stack<int> helper;
stack<int> Queue;
public:
    CQueue() {                                         //类的构造函数，不用管

    }
    
    void appendTail(int value) {
        while(!helper.empty()) {                       //先清空helper栈，再把Queue中的元素转移到helper中
            helper.pop();
        }
        while(!Queue.empty()) {
            int topElement = Queue.top();
            helper.push(topElement);
            Queue.pop();
        }
        helper.push(value);
        while(!helper.empty()) {
            int topElement = helper.top();
            Queue.push(topElement);
            helper.pop();
        }
    }
    
    int deleteHead() {
        if(Queue.empty()) {
            return -1;
        }
        int deletedElement = Queue.top();
        Queue.pop();
        return deletedElement;
    }
};
