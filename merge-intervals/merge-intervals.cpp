class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
            vector<vector<int>> ans;
            int n=(int)(intervals.size());
            int lb=intervals[0][0],rb=intervals[0][1];
            for(int i=1;i<n;++i){
                    int nl=intervals[i][0],nr=intervals[i][1];
                    if(nl<=rb){
                            rb=max(rb,nr);
                    }
                    else{
                            vector<int> cur;
                            cur.push_back(lb);
                            cur.push_back(rb);
                            ans.push_back(cur);
                            lb=nl,rb=nr;
                    }
            }
             vector<int> cur;
                            cur.push_back(lb);
                            cur.push_back(rb);
                            ans.push_back(cur);
                            
            
            return ans;
    }
};