class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> f(3);
            int n=(int)(nums.size());
            for(int i=0;i<n;++i) f[nums[i]]++;
                vector<int> ans;
            for(int i=0;i<3;++i) for(int j=0;j<(int)(f[i]);++j) ans.push_back(i);
           nums=ans;
    }
};