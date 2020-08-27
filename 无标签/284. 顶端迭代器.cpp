/*
这题给的类原型里PeekingIterator类公有继承自类Iterator，所以我们可以调用基类的next()和hasNext()方法。

虽然在class Iterator里只对next()和hasNext()方法做了声明，但是实际上类外肯定对这两个方法做了实现，所以我们
是可以直接调用Iterator::next()和Iterator::hasNext()来获取迭代器的下一个元素以及判断是否还存在下一个元素。

我们再来看子类PeekingIterator，这个类里我们要实现peek()、next()、hasNext()，还需要在构造函数里进行初始化。

先看peek()，因为返回值是int类型，是当前遍历到的元素的下一个元素，所以我们在类PeekingIterator里需要有一个int型
的data member - int cur，这里cur并不是我们已经迭代到的元素（而是我们迭代到的元素的下一个元素）。

再看hasNext()，我们需要在每一次迭代判断cur是不是最后一个元素，因此类PeekingIterator里还需要一个布尔变量记录cur
是不是最后一个元素，于是我们再声明一个变量bool isLast。

看一下具体的实现，构造函数里，一开始两个变量cur和isLast都没有初始化，构造函数里将isLast初始化为false。
因为一开始迭代器没指向任何元素，不过好在我们的cur是定义为当前元素的下一个元素，所以如果Iterator::hasNext()为真，
则将Iterator::next()的值赋值给cur,否则，说明没有元素了，把isLast赋值为真。

peek()函数需要返回下一个元素，由于这就是我们cur记录的就是下一个元素，所以直接return cur就可以了。

next()也返回下一个元素，但是调用了next()函数之后迭代器需要向后移动，所以我们用一个变量nextElement记录一下cur，
然后判断Iterator::hasNext()是否为真，如果为真，则cur = Iterator::next(); 否则，isLast = true;  这步是为了将cur
向后移动，返回的还是nextElement。对Iterator::hasNext()做判断的部分就是成员函数next()和成员函数peek()区别的地方。

hasNext()函数是判断当前元素后面是否还有元素，如果cur是最后一个元素，即isLast为true，则hasNext()为假，否则hasNext()为真。
所以这个函数里返回!isLast即可。
*/

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    int cur;
    bool isLast;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    isLast = false;
        if(Iterator::hasNext() == true) {
            cur = Iterator::next();
        } else {
            isLast = true;
        }
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return cur;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if(isLast == true) {
            return -1;
        }
        int nextElement = cur;
        if(Iterator::hasNext() == true) {
            cur = Iterator::next();
        } else {
            isLast = true;
        }
        return nextElement;
	}
	
	bool hasNext() const {
	    return !isLast;
	}
};
