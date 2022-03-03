class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        int n=(int)(arr.size());
            int ans=0;
            for(int i=0;i<n-1;++i){
                    int dif_here=arr[i+1]-arr[i];
                    int it=i;
                    while(it+1<n&&arr[it+1]-arr[it]==dif_here){
                            it++;
                    }
                    ans+=max(0,(it-i+1-3+1));
            }
            
            
            return ans;
    }
};