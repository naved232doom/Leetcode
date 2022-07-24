class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = (int)(matrix.size());
        int m = (int)(matrix[0].size());
        int lr = 0, rr = n;
        while (lr < rr) {
            int mid = (lr + rr) / 2;
            if (target <= matrix[mid].back() && target >= matrix[mid].front()) {
                int lc = 0, rc = m;
                while (lc < rc) {
                    int midc = (lc + rc) / 2;
                    int valc = matrix[mid][midc];
                    if (valc == target) return true;
                    else if (valc < target) {
                        lc = midc + 1;
                    }
                    else {
                        rc = midc;
                    }
                }
                return false;
            }
            else if (target > matrix[mid].back()) {
                lr = mid + 1;
            }
            else {
                rr = mid;
            }
        }
        return false;
    }
};