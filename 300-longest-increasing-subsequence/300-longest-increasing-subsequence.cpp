class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> len;
        len.push_back(nums[0]);
        for(int i=1;i<nums.size();++i){
            auto it=lower_bound(len.begin(),len.end(),nums[i]);
            if(it==len.end()){
                len.push_back(nums[i]);
            }
            else{
            auto idx=lower_bound(len.begin(),len.end(),nums[i])-len.begin();
                len[idx]=nums[i];
            }
        }
        
        return (int)len.size();
    }
};