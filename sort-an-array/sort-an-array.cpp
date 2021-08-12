class Solution {
public:
        vector<int> MergeArray(vector<int> &left,vector<int> &right){
                int ln=(int)(left.size());
                int rn=(int)(right.size());
                int n=ln+rn;
                vector<int> ans;
                ans.resize(n);
                int l=0,r=0,i=0;
                while(l<ln&&r<rn){
                        if(left[l]<right[r]){
                             ans[i++]=left[l++];   
                        }
                        else{
                                ans[i++]=right[r++];
                        }
                }
                while(l<ln){
                        ans[i++]=left[l++];
                }
                while(r<rn){
                        ans[i++]=right[r++];
                }
                return ans;
        }
        vector<int> MergeSort(int lo,int hi,vector<int> &nums){
                if(lo==hi){
                        return {nums[lo]};
                }
                int mid=(lo+hi)/2;
                vector<int> left=MergeSort(lo,mid,nums);
                vector<int> right=MergeSort(mid+1,hi,nums);
                vector<int> mergedArray=MergeArray(left,right);
                return mergedArray;
        }
    vector<int> sortArray(vector<int>& nums) {
        int n=(int)(nums.size());
            if(n==1) return nums;
            
            return MergeSort(0,n-1,nums);
    }
};