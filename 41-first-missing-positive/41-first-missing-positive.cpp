class Solution {
        private:
        bool valid(int x,int n){
                return (x>=1&&x<=n);
        }
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=(int)(nums.size());
            for(int i=0;i<n;++i){
                    int x=nums[i];
                    if(!valid(x,n)) continue;
                    while(valid(nums[i],n)&&nums[nums[i]-1]!=nums[i]){
                            swap(nums[nums[i]-1],nums[i]);
                    }
            }
            for(int i=0;i<n;++i){
                    if(nums[i]!=i+1) return i+1;
            }
            return n+1;
    }
};