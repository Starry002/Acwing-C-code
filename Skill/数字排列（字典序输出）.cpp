//����һ�����֣����ܰ����ظ����֣�����������е����з�ʽ��

//���ݷ�Χ
//�������鳤�� [0,6]��

//����
//���룺[1,2,3]

//�����
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
         }while (next_permutation(nums.begin(),nums.end()));	//ʹ��next_permutation�����ֵ����е���һ������
         return res;
    }
};

