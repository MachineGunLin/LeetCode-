/*
遍历一遍糖果数组获得最大糖果数量mostCandies。
然后再遍历一遍计算candies[i] + extraCandies 是否大于等于 mostCandies，
是就true，不是就false咯。
*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int mostCandies = 0;
        for(auto candy : candies) {
            mostCandies = max(mostCandies, candy);
        }
        for(int i = 0; i < candies.size(); i++) {
            if(candies[i] + extraCandies >= mostCandies) {
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }
        return res;
    }
};
