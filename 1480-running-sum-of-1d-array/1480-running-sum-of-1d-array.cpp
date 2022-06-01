class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> pref(1,0);
        for(int v:nums){
            pref.push_back(pref.back()+v);
        }
        pref.erase(pref.begin());
        return pref;
    }
};