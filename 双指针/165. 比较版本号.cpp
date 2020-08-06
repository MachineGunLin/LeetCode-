/*
根据题意，用'.'划分出两个版本的每个子版本号，从左到右逐个比较即可，如果某个版本的子版本号个数比另一个多，则子版本较少的那个版本用0表示子版本，这样就可以一直比较两个版本的所有子版本了。

划分子版本可以用双指针，划分出的子版本存到一个数组中，都划分好后就得到两个分别存放两个版本的子版本的数组，然后对数组逐个进行比较，如果相等就往后，否则返回结果。

如果某个数组大于另一个数组，则较小的另一个数组剩下的部分用0和较大的数组的当前元素比较（表示剩下的子版本都是0），一直比较下去直到比较出大小或者两个数组都结束了，都结束了就返回0，说明两个版本号是相同的。
*/


class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        int i = 0;
        for(; i < version1.size(); ++i) {
            int j = i;
            while(j < version1.size() && version1[j] != '.') {            //双指针划分出子版本号，存放到数组v1中
                ++j;
            }
            string subVer = version1.substr(i, j - i);
            v1.push_back(atoi(subVer.c_str()));
            i = j;
        }
        for(i = 0; i <version2.size(); ++i) {
            int j = i;
            while(j < version2.size() && version2[j] != '.') {
                ++j;
            }
            string subVer = version2.substr(i, j - i);
            v2.push_back(atoi(subVer.c_str()));
            i = j;
        }
        for(int i = 0; i < min(v1.size(), v2.size()); ++i) {
            if(v1[i] > v2[i]) {
                return 1;
            } else if(v1[i] < v2[i]) {
                return -1;
            }
        }
        if(v1.size() < v2.size()) {
            for(int i = v1.size(); i < v2.size(); ++i) {
                if(0 < v2[i]) {                              //如果v1的大小小于v2的大小，则v1不足的部分用0和v2[i]比较，表示后面的子版本号都是0
                    return -1;
                }
            }
        }
        if(v1.size() > v2.size()) {
            for(int i = v2.size(); i < v1.size(); ++i) {
                if(v1[i] > 0) {
                    return 1;
                }
            }
        }
        return 0;
    }
};
