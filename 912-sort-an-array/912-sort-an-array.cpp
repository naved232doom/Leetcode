class Solution {
public:
    void merge(int lo,int mid,int hi,vector<int> &nums,vector<int> &tmp){
        int n=(int)(nums.size());
        //vector<int> tmp(n);
        int left=lo,right=mid+1;
        int it1=lo;
        while(left<=mid && right<=hi){
            if(nums[left]<=nums[right]){
                tmp[it1++]=nums[left++];
            }
            else{
                tmp[it1++]=nums[right++];
            }
        }
        while(left<=mid) tmp[it1++]=nums[left++];
        while(right<=hi) tmp[it1++]=nums[right++];
        
        for(int i=lo;i<=hi;++i) nums[i]=tmp[i];
    }
    void merge_sort(int lo,int hi,vector<int> &nums,vector<int> &tmp){
        if(lo>=hi) return;
        int mid=(lo+hi)/2;
        merge_sort(lo,mid,nums,tmp);
        merge_sort(mid+1,hi,nums,tmp);
        merge(lo,mid,hi,nums,tmp);
        
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> tmp(n);
        merge_sort(0,n-1,nums,tmp);
        return nums;
    }
};