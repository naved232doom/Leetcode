class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=(int)(nums.size());
        bool ok=0;
        int l=-1,r=n;
        for(int i=n-1;i>=0;--i){
            for(int j=i-1;j>=0;--j){
                if(nums[j]<nums[i]){
                    if(min(j,i)>l){
                        l=min(j,i);
                        r=max(j,i);
                    }
                }
            }
            
        }
        if(l!=-1){
            swap(nums[l],nums[r]);
            sort(nums.begin()+l+1,nums.end());
            ok=1;
        }
        if(!ok){
            sort(nums.begin(),nums.end());
        }
    }
};