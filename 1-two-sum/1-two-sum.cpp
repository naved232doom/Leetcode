class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = (int)(nums.size());
        vector<int> ans;
        //3 1 2 3 4 5 
        //
        map<int,int> mp;
        // 3->0
        // 1->1
        // 2->2
        //...
        // 5->5
        // 100 -> mp.end()
        // 4 => Xmp.end()
        // 292929292929493101 =>mp.end()
        // for(int i=0;i<len;++i){
        //     mp[nums[i]]=i;
        // }
        
        for(int i=0;i<len;++i){
           int num_here=nums[i];
            int need= target-num_here;
            if(mp.find(need)!=mp.end()){
                int val= mp[need];
                return {i,val};
                
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};