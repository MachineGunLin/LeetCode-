class Solution {
public:
    char firstUniqChar(string s) {
        if(s.size() == 0) {
            return ' ';
        }
        unordered_map<char, int> frequency;
        for(auto c : s) {
            frequency[c]++;
        }
        for(auto c : s) {
            if(frequency[c] == 1) {
                return c;
            }
        }
        return ' ';
    }
};
