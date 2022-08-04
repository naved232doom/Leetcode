class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
       //  1  5 9
       // 10 11 12
       // 12 13 15
       // 13 13 16 
        int n=(matrix.size());
        set<array<int,3>> st;
        for(int i=0;i<n;++i){
            st.insert({matrix[i][0],i,0});
        }
        for(int i=0;i<k-1;++i){
            auto it= st.begin();
            auto cur=*it;
            int r=cur[1],c=cur[2];
            st.erase(st.begin());
            if(c+1==n) continue;
            c++;
            st.insert({matrix[r][c],r,c});
        }
        // 5 10 12
        // 9 10 12
        // 10 12
        // 11 12
        // 12 12
        // 12
        // 12 13
        auto ans=*(st.begin());
        return ans[0];
    }
};