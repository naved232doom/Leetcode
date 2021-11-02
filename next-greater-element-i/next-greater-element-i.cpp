class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
            int n1=(int)(nums1.size()),n2=(int)(nums2.size());
            int MAXN=0;
            for(int i=0;i<n2;++i){
                 MAXN=max(MAXN,nums2[i]);       
            }
            MAXN++;
            vector<int> A(MAXN,-1);
            for(int i=0;i<n2;++i){
                    for(int j=i;j<n2;++j){
                            if(nums2[j]>nums2[i]){
                                    A[nums2[i]]=nums2[j];
                                    break;
                            }
                    }
            }
            for(int i=0;i<n1;++i){
                    res.push_back(A[nums1[i]]);
            }
            return res;
    }
};