class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int t) {
        vector<int> ans;
        int n=(int)(arr.size());
            int l=0;
            int r=n-1;
            while(l<n&&r>=0&&l<r){
                int sum_here=arr[l]+arr[r];
                if(sum_here==t){
                    return {l+1,r+1};
                }
                if(sum_here<t){
                    l++;
                }
                else r--;
            }
        return ans;
    }
};