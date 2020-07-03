/*
这题是要实现Linux里的类似pwd命令的功能，给出一串绝对地址，绝对地址里每两个"/"之间可能含有"."，".."，"",/等，
这些特殊情况都需要判断。

思路是，遍历path字符串，对于每两个"/"之间的字符串temp，根据字符串内容考虑是否要压入一个额外的string数组strs中。
strs中元素的顺序就是最终路径的各个目录的顺序，只需要用"/"把所有目录（或者说是文件名）连接起来即可。

1. 如果temp是""或者"."**("."在Linux中表示当前目录)**，则跳过，不需要压入strs数组中。

2. 如果temp是".."**(".."在Linux中表示上一级目录）**且strs数组非空，则弹出strs数组最后的元素（表示返回到上一级目录），
为什么要判断非空呢？因为可能当前目录已经是根目录了，根目录再往上还是根目录，所以这里要特判一下。

3. 否则如果temp不是".."的话，就把temp压入strs数组中。为什么要判断temp不是".."呢？因为有可能出现temp是".."且strs数组为空，
如果没有这个判断，这会把".."压入数组中，最终的路径里就出现了".."，这样就比较尴尬了hh，所以只有temp不是".."的时候我们才认为
是一个有效的目录（文件）。

读取path字符串后需要根据'/'作为分隔符分割出'/'之间的字符串，这里用了stringstream。

要特别注意如果res为空（即strs数组为空），则返回一个"/"。
*/

class Solution {
public:
    string simplifyPath(string path) {
        stringstream is(path);
        string res, temp;
        vector<string> strs;
        while(getline(is, temp, '/')) {
            if(temp == "" || temp == ".") {
                continue;
            } else if(temp == ".." && !strs.empty()) {
                strs.pop_back();
            } else if(temp != ".."){
                strs.push_back(temp);
            }
        }
        for(auto str : strs) {
            res += '/' + str;
        }
        if(res.empty()) {
            res = "/";
        }
        return res;
    }
};

/*
还有一种写法是不用stringstream，直接遍历path按照字符判断两个"/"之间的字符串。

首先需要判断path的末尾是否是'/',如果不是'/'，需要加上'/'（因为我们需要'/'作为分隔符，如果
结尾没有'/'就会造成无法判断）。

然后遍历path，如果当前字符不是'/'，就把字符加入一个字符串变量name中，name表示两个'/'之间的字符串。

如果当前字符是'/'，就需要判断name属于那种情况了，如果name是".."，这时就需要不断删除res的末尾字符，
直到删了两个'/'。

其他情况，只要name不是空字符串或者"."，就可以更新res了， res += '/' + name;

代码如下：
*/

class Solution {
public:
    string simplifyPath(string path) {
        string res, name;
        if(path.back() != '/') {
            path += '/';
        }   
        for(auto c : path) {
            if(c != '/') {
                name += c;
            } else {
                if(name == "..") {
                    while(!res.empty() && res.back() != '/') {
                        res.pop_back();
                    }
                    if(!res.empty()) {
                        res.pop_back();
                    }
                } else if(name != "" && name != ".") {
                    res += '/' + name;
                }
                name.clear();
            }
        }
        if(res.empty()) {
            res = "/";
        }
        return res;
    }
};
