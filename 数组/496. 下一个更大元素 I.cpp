class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(int i = 0; i < nums1.size(); i++) {
            int currentNum = nums1[i];
            for(int j = 0; j < nums2.size(); j++) {
                if(nums2[j] != currentNum) {
                    continue;
                } else{
                    int k;
                    for(k = j + 1; k < nums2.size(); k++) {
                        if(nums2[k] > currentNum) {
                            res.push_back(nums2[k]);
                            break;
                        }
                    }
                    if(k == nums2.size()) {
                        res.push_back(-1);
                    }
                }
            }
        }
        return res;
    }
};
