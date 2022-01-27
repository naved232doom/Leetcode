class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans=0;
        int n=target;    
        while(maxDoubles&&target){
                if(target%2){
                        ans++;
                        target--;
                }
                else{
                        target/=2;
                        ans++;
                        maxDoubles--;
                }
        }
            // 9 1 2
            // 8 1 3
            // 4 0 4
            
            ans+=(target-1);
            return ans;
    }
};