class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=(int)(intervals.size());
            vector<vector<int>> ans;
            sort(intervals.begin(),intervals.end(),[](vector<int> &A,vector<int> &B){
                    return A[0]<B[0];
            });
           int cur_interval_start=intervals[0][0],cur_interval_end=intervals[0][1];
           for(int i=1;i<n;++i){
                int interval_start=intervals[i][0],interval_end=intervals[i][1];
                if(cur_interval_end>=interval_start){
                        cur_interval_end=max(cur_interval_end,interval_end);
                        cur_interval_start=min(cur_interval_start,interval_start);
                }
                    else{
                            ans.push_back({cur_interval_start,cur_interval_end});
                            cur_interval_start=interval_start;
                            cur_interval_end=interval_end;
                    }
            }
            
            ans.push_back({cur_interval_start,cur_interval_end});
            return ans;
    }
};