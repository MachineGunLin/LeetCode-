/*
这题是拓扑排序的模板题。

先看一下拓扑排序的步骤：

（1）遍历存放所有点之间的依赖关系的数组（这题是prerequisities数组），统计所有入度为0的节点，即没有任何先修课程的课程。

（2）有一个队列存放所有的点（入队顺序表示学习课程的顺序），将所有入度为0的节点入队。
      然后进行BFS，不断取出队列中的队头元素，并且更新这个点的所有后继节点（这里队头元素是所有入度为0的节点，表示已经学习过的课程，
      则这门课的所有后继课程的先修课程数量减一，也就是学了一门先修课程），然后判断减一之后，后继课程们是否已经没有了先修课程（入度是否为0），
      如果入度为0，就把这门课加入到队列中。当然，每取出一门课程，我们都有一个计数变量cnt加一，表示已经修过多少门课程。

（3）重复第（2）步，直到队列为空，这时判断一下修过的课程数量cnt是否和课程总数numCourses，如果是，说明存在一种拓扑序列，可以学习完所有课程。
如果不相等，说明不存在。

具体实现上，由于需要一个图存放所有课程之间的学习关系，所以我们开一个二维数组g存放每门课和它的后继课程，一个大小为numCourses的一维数组inDrgree
存放所有课程的先修课程（入度）。
最开始先遍历prerequisities数组，由于prerequisities数组中给的关系是先给后继课程，再给前驱课程，所以存放到g数组的时候要注意一下顺序，前驱课程在前，
后继课程在后。
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);                  //存放图的每条边，第二维的第一个数是先修课程，第二个数是后继课程                  
        vector<int> inDegree(numCourses);                   //存放所有课程的先修课程的数量
        for(int i = 0; i < prerequisites.size(); ++i) {
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);      //注意一下prerequisites数组中的顺序
            ++inDegree[prerequisites[i][0]];
        }
        queue<int> q;
        for(int i = 0; i < numCourses; ++i) {
            if(inDegree[i] == 0) {                              //如果某门课没有先修课程或者所有的先修课程都修过了，则我们可以学习这门课程，把这门课加入到队列中
                q.push(i);
            }
        }
        int cnt = 0;                                           //cnt变量计算我们学习过了多少门课程
        while(q.size()) {
            int curCourse = q.front();
            q.pop();
            ++cnt;
            for(auto &course : g[curCourse]) {                  //对于刚学习完的课程curCourse，更新他的所有后继课程的入度（减一），如果减一后入度为0，则加入队列中
                --inDegree[course];
                if(inDegree[course] == 0) {
                    q.push(course);
                }
            }
        }
        return cnt == numCourses;                              //如果可以学习完所有课程，则拓扑排序成功
    }
};
