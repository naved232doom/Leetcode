class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int it1 = 0, it2 = 0;
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if(n1+n2 != n3) return false;
        queue<array<int, 2>> q;
        vector<vector<int>> vis(n1+1,vector<int>(n2+1));
        q.push({0, 0});
        vis[0][0]=1;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int idx3 = cur[0] + cur[1];
            // cout<<"cur[0]: "<<cur[0]<<endl;
            // cout<<"cur[1]: "<<cur[1]<<endl;
            if (cur[0] == n1 && cur[1] == n2) return true;
            if (cur[0] < n1 && s1[cur[0]] == s3[idx3]) {
                if(!vis[cur[0]+1][cur[1]]) {
                q.push({cur[0] + 1, cur[1]});
                vis[cur[0]+1][cur[1]]=1;
                    
                }
            }
            if (cur[1] < n2 && s2[cur[1]] == s3[idx3]) {
                if(!vis[cur[0]][cur[1]+1]) {
                q.push({cur[0], cur[1] + 1});
                vis[cur[0]][cur[1]+1]=1;
                    
                }
            }

        }

        return false;
    }
};