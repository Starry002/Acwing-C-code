//输入一组数字（可能包含重复数字），输出其所有的排列方式。

//数据范围
//输入数组长度 [0,6]。

//样例
//输入：[1,2,3]

//输出：
//      [
//        [1,2,3],
//        [1,3,2],
//        [2,1,3],
//        [2,3,1],
//        [3,1,2],
//        [3,2,1]
//      ]

class Solution {
public:
    vector<vector<int>> permutation(vector<int>& nums) {
         sort(nums.begin(),nums.end());
         vector<vector<int>> res;
         do{
             res.push_back(nums);
         }while (next_permutation(nums.begin(),nums.end()));	//使用next_permutation生成字典序中的下一个排列
         return res;
    }
};

