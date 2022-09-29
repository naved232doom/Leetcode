class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> pref,suf;
        int n=(int)(arr.size());
        for(int i=0;i<n;++i){
            if(arr[i]<=x) pref.push_back(arr[i]);
            else suf.push_back(arr[i]);
        }
        reverse(suf.begin(),suf.end());
        vector<int> ans;
        for(int i=0;i<k;++i){
            if(pref.empty() && !suf.empty()){
                ans.push_back(suf.back());
                suf.pop_back();
                continue;
            }
            if(suf.empty() && !pref.empty()){
                ans.push_back(pref.back());
                pref.pop_back();
                continue;
            }
            auto pref_here=pref.back();
            auto suf_here=suf.back();
            if(abs(pref_here-x) <= abs(suf_here-x)){
                ans.push_back(pref.back());
                pref.pop_back();
            }
            else{
                ans.push_back(suf.back());
                suf.pop_back();                
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};