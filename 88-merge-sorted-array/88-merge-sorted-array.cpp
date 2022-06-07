class Solution {
public:
    void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
        int it1=0,it2=0;
        for(;it1<m&&it2<n;){
            if(arr1[it1]<arr2[it2]){
                arr1.push_back(arr1[it1]);
                it1++;
            }
            else{
                arr1.push_back(arr2[it2]);
                it2++;
            }
        }
        while(it1<m) arr1.push_back(arr1[it1++]);
        while(it2<n) arr1.push_back(arr2[it2++]);
        reverse(arr1.begin(),arr1.end());
        // remove last m+n elements
        for(int i=0;i<m+n;++i){
            assert(!arr1.empty());
            arr1.pop_back();
        }
        reverse(arr1.begin(),arr1.end());
    }
};