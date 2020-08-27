/*
暴力做法是维护一个数组，每次插入一个元素就对数组进行排序，然后通过有序数组寻找中位数就很简单了。
但是因为每次插入一个元素都要对数组进行排序，调整的时间代价太大了，超时。

我们可以用两个优先级队列，一个小根堆，一个大根堆分别存储大于等于和小于当前中位数的所有数。
且小根堆的大小总是和大根堆的大小相等，或者比大根堆的大小多一。如果插入一个元素时两个堆的大小不满足这个关系，就从一个堆里
弹出堆顶元素到另一个堆里。

这样，如果两个堆的大小相等时，说明元素个数是偶数，两个堆的堆顶元素就是中间的两个元素，我们返回这两个数的平均值即可。
如果小根堆的大小比大根堆的大小多1，说明元素个数是奇数，且小根堆的堆顶元素就是中位数。

这种做法，每次维护堆的时间是O(logn)，所以总的时间复杂度是O(nlogn)。
*/

class MedianFinder {
public:
    priority_queue<int> smaller;                        
    priority_queue<int, vector<int>, greater<int>> larger;

    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(smaller.empty() || num <= smaller.top()) {            
            smaller.push(num);
        } else {
            larger.push(num);
        }
        if(smaller.size() > larger.size() + 1) {
            int topElement = smaller.top();
            smaller.pop();
            larger.push(topElement);
        } else if(larger.size() > smaller.size()) {
            int topElement = larger.top();
            larger.pop();
            smaller.push(topElement);
        }
    }
    
    double findMedian() {
        if(smaller.size() == larger.size()) {
            return (smaller.top() + larger.top()) / 2.0;
        }
        return smaller.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
