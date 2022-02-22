class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        long long ans=0;
            int n=(int)(nums.size());
            map<long long ,long long> gcds;
            // for(int i=0;i<n;++i){
            //         gcds[__gcd(nums[i],k)]++;
            // }
            for(int i=0;i<n;++i){
                    long long gcd_1=__gcd(nums[i],k);
                    for(auto it2:gcds){
                            
                            long long gcd_2=it2.first;
                            if((gcd_1%k*gcd_2%k)%k==0) ans+=(it2.second);
                    }
                    gcds[gcd_1]++;
            }
            return ans;
    }
};