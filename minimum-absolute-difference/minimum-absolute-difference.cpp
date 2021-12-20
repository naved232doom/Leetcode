class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
                sort(arr.begin(),arr.end());
            vector<vector<int>> ans;
            int n=(int)(arr.size());
            int minD=INT_MAX;
            for(int i=0;i<n-1;++i){
                    minD=min(minD,arr[i+1]-arr[i]);
            }
            int i=0,j=1;
            
            for(;i<n&&j<n;){
                    int dif=arr[j]-arr[i];
                    if(dif>minD){
                            i++;
                    }
                    else if(dif==minD||i==j){
                            if(dif==minD)
                            ans.push_back({arr[i],arr[j]});
                            j++;
                    }
            }
            return ans;
    }
};