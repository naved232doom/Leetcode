class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),[](vector<int> &a,vector<int> &b){
                return a[1]<b[1];
        });
                
                int ans=1;
            int lb=p[0][1];
            int n=(int)(p.size());
            for(int i=1;i<n;++i){
                    int leftbound=p[i][0];
                    if(lb>=leftbound){
                            continue;
                    }
                    else{
                            ans++;
                            lb=p[i][1];
                    }
            }
            return ans;
    }
};