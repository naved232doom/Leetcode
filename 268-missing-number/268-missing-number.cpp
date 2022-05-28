class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n=(int)(arr.size());
        int ans=0;
        for(int i=0;i<n;++i){
            if(arr[i]==0) arr[i]=2*n;
        }
        for(int i=0;i<n;++i){
            int v=abs(arr[i]);
            if(v>n) v%=n;
            if(v>=0&&v<n){
                int u=arr[v];
                arr[v]=-u;
            }
        }
        bool n_pres=0;
        for(int i=0;i<n;++i){
            if(arr[i]==n) n_pres=1;
            if(arr[i]>0) return i; 
            
        }
        return n;
        // 3 0 1
        // -3 -0 1 
    }
};