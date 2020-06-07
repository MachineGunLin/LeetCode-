/*
开一个数组记录访问记录，注意visit操作，会删除当前页面之后的访问记录，并且在当前页面之后添加一个新的记录。
回退操作至多回退到最初的页面records[0],前进操作至多前进到最新的（或者说最后的）页面records[records.size() - 1]
*/

class BrowserHistory {
public:
    vector<string> records;
    int current;
    BrowserHistory(string homepage) {
        records.push_back(homepage);
        current = 0;
    }
    
    void visit(string url) {
        records.erase(records.begin() + current + 1, records.end());  //题目说了visit操作跳转到url对应的页面，并且会把浏览历史前进的记录全部删除
        records.push_back(url);
        current++;      //跳转到url所指的页面，current相应+1
    }
    
    string back(int steps) {
        current = max(0, current - steps);    //回退操作至多回退到records[0],再往后就回退不了了
        return records[current];
    }
    
    string forward(int steps) {
        current = min((int)records.size() - 1, current + steps);    //前进操作至多前进到records[records.size() - 1]，再往前就前进不了了
        return records[current];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
