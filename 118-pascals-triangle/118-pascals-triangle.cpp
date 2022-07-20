class Solution {
public:
    vector<vector<int>> generate(int n) {
        // 1 4 6 4 1
        // 1 5 10 10 5 1
        vector<vector<int>> ans;
        vector<int> prev(1,1);
        ans.push_back(prev);
        for(int i=2;i<=n;++i){
            vector<int> here(1,1);
            for(int j=1;j<prev.size();++j){
                here.push_back(prev[j]+prev[j-1]);
            }
            here.push_back(1);
            ans.push_back(here);
            prev=here;
        }
        return ans;
    }
};