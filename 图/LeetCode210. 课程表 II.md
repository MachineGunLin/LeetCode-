# LeetCode210. 课程表 II

![](https://img2020.cnblogs.com/blog/2078361/202008/2078361-20200813163948326-864247338.png)

这题和[LeetCode207. 课程表](https://www.cnblogs.com/linrj/p/13496153.html)一样，都是拓扑排序的模板题，只不过207题只需判断是否存在拓扑序列，
这题要返回拓扑序列。

只需要在BFS时在一个结果数组中记录每个入队的元素即可，最后判断数组大小是否和课程总数量numCourses相同，相同就返回我们记录的所有元素的入队顺序的数组res，
不相同就返回空数组。

关于拓扑排序，可以看一下上面那个链接里（207题）的步骤，207题搞定了，这题就稍微改一下就可以了。

代码如下：

```
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);                  //g表示课程关系之间的图，g[i]数组存放课程i的所有后继课程
        vector<int> inDegree(numCourses);                   //inDegree[i]表示课程i的入度（先修课程的数量）
        for(int i = 0; i < prerequisites.size(); ++i) {
            int course1 = prerequisites[i][0], course2 = prerequisites[i][1];      //这题的输入比较奇怪，prerequisties的第一门课是后继课程，第二门课才是先修课程，注意一下顺序
            g[course2].push_back(course1);                  //course2是course1的先修课程
            ++inDegree[course1];                            //course1的先修课程数量加一
        }
        vector<int> res;                              //存放拓扑序列
        queue<int> q;
        for(int i = 0; i < numCourses; ++i) {            //拓扑排序最开始把所有入度为0的节点入队
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        while(q.size()) {
            int curCourse = q.front();                  //队头元素出队，表示这门课程学完了
            q.pop();
            res.push_back(curCourse);
            for(int i = 0; i < g[curCourse].size(); ++i) {      //这门学习完的课程的所有后继课程的入度（先修课程数量）可以减一了
                --inDegree[g[curCourse][i]];
                if(inDegree[g[curCourse][i]] == 0) {            //如果入度减一之后为0，则入队
                    q.push(g[curCourse][i]);
                }
            }
        }
        if(res.size() != numCourses) {             //无法学习完所有课程，返回空数组
            return {};
        }
        return res;                              //存在一种包含所有课程的拓扑序列，则返回
    }
};
```