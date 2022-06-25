class Solution {
public:
    bool checkPossibility(vector<int>& arr) {
        int cnt=0;
        int n=(int)(arr.size());
       vector<int> lis;
        for(int i=0;i<n;++i){
            if(lis.empty()) lis.push_back(arr[i]);
            else{
                auto it=upper_bound(lis.begin(),lis.end(),arr[i]);
                auto idx=upper_bound(lis.begin(),lis.end(),arr[i])-lis.begin();
                if(it==lis.end()){
                    lis.push_back(arr[i]);
                }
                else{
                    lis[idx]=arr[i];
                }
            }
        }
        int len=(int)(lis.size());
        return len>=n-1;
    }
};