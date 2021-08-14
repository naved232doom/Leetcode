class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=(int)(nums.size());
        map<int,int> m;
            int sum=0;
            int ans=0;
            // 1-> 1
            // 2-> 1
            m[0]=1;
            for(int i=0;i<n;++i){
                    sum+=nums[i];
                    if(m.find(sum-k)!=m.end()){
                      ans+=m[sum-k];      
                    }
                    m[sum]++;
            }
            
            return ans;
                
    }
};