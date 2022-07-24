class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=(int)(matrix.size());
        int m=(int)(matrix[0].size());
        int C = m-1, R = 0;
        while(C >=0 && R<n){
            if(matrix[R][C]== target) return true;
            if(matrix[R][C]>target){
                C--;
            }
            else {
                R++;
            }
        }
        return false;
    }
};