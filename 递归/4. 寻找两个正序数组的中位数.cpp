/*
这题思路是递归，假设两个数组的大小分别是 n 和 m， 我们要寻找的中位数下标 k 就是 (n + m ) / 2
我们先判断 nums1[k / 2] 和 nums2[k / 2] （这里实际上是 k - k / 2，当 k 是偶数时, k - k / 2 和 k / 2相等，
当 k 是奇数时，k - k / 2比 k/ 2 多一，这里为了讨论方便，直接比较 nums1[k / 2] 和 nums2[k / 2]，
(1) 如果 nums1[k / 2] < nums2[k / 2] ，则nums1[k / 2]小于中位数，因为num1[k / 2]的前面部分和nums2[k / 2]的
前面部分加起来正好为k，但是nums1[k / 2]更小，所以nums1[k / 2]的前面 k / 2部分可以删去，然后我们在num1 剩下的部分
和nums2里找第 k - (k / 2)个数就是中位数了。
(2) 如果 nums1[k / 2] > nums2[k / 2]，那么同理，我们砍掉 nums2的前面 k / 2个元素，然后在nums2的剩下部分和nums1
里面找第 k - (k / 2) 个元素就是中位数了。
(3) 如果 nums1[k / 2] == nums2[k / 2],那么直接就找到中位数了(nums1[k / 2] 或 nums2[k / 2])。
通过上面递归的每次减少 k / 2 个元素，时间复杂度降到了 O(log(n + m))，符合题目要求（如果合并两个数组再排序，时间复杂度是O(nlogn)，超时)。
这题需要画图好理解，我画在PDF里了。
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if(total % 2 == 0) {                                            //当两个数组的元素个数和为偶数时
            int left = find(nums1, 0, nums2, 0, total / 2);
            int right = find(nums1, 0, nums2, 0, total / 2 + 1);
            return (left + right) / 2.0;                                //中位数为中间两个元素的平均值。注意返回值是double，所以这里要除以2.0
        } else {
            return find(nums1, 0, nums2, 0, total / 2 + 1);             //如果元素个数和为奇数，则直接返回中间的数，就是中位数
        }
    }
    int find(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {       //i，j是两个数组的起始位置，返回值是两个数组中第k小的数
        if(nums1.size() - i > nums2.size() - j) {                       //我们假设nums1是元素个数较小的那个数组
            return find(nums2, j, nums1, i, k);                         //如果nums1元素个数大于nums2元素个数，就需要把两个数组对调一下
        }
        if(k == 1) {                                                    //如果要找的数是第一个数(k == 1)，递归边界，特判一下
            if(nums1.size() == i) {                                     //因为nums1是较短的数组，所以nums1有可能为空
                return nums2[j];                                        //如果nums1为空，则直接返回nums2的第一个元素
            } else {
                return min(nums1[i], nums2[j]);                          //否则返回两个数组的第一个元素中较小的那一个
            }
        }
        if(nums1.size() == i) {                                          //特判，如果nums1为空
            return nums2[j + k - 1];                                     //则直接返回nums2中的第k个元素
        }
        int si = min(int(nums1.size()), i + k / 2), sj = j + k - k / 2;  //si, sj分别表示nums1和nums2的“第 k / 2个元素”
        //这里要注意两点，第一点是nums1中i + k / 2有可能越界（因为nums1较短），所以需要对nums1.size()和i + k / 2取min，因为nums1.size()的返回值是size_t,所以需要强制类型转换为int
        //第二点是si不是j + k / 2，而是j + k - k / 2，因为当k是奇数时k - k / 2和 k / 2是不相等的
        if(nums1[si - 1] > nums2[sj - 1]) {                     //nums1[si - 1]大于nums2[sj - 1], 砍掉nums2的前"k / 2"个元素(sj - j个）
            return find(nums1, i, nums2, sj, k - (sj - j));     //在新的两个数组中寻找第k - (sj - j)个元素，sj - j是被砍掉的元素的个数。 注意nums2的下标从sj开始
        } else {                                                //nums1[si - 1]小于nums2[sj - 1], 砍掉nums1的前"k / 2"个元素(si - i个）
            return find(nums1, si, nums2, j, k - (si - i));     //在新的两个数组中寻找第k - (si - i)个元素，si - i是被砍掉的元素的个数。 注意nums1的下标从si开始
        }
    }
};
