class Solution {
public:
        typedef long long ll;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=(int)(points.size());
            vector<vector<int>> ans;
            vector<pair<ll,ll>> result;
            for(int i=0;i<n;++i){
                    ll d=(points[i][0])*(points[i][0])+points[i][1]*points[i][1];
                    result.push_back({d,i});    
            }
            sort(result.begin(),result.end());
            for(int i=0;i<k;++i){
                    ans.push_back(points[result[i].second]);
            }
            return ans;
    }
};