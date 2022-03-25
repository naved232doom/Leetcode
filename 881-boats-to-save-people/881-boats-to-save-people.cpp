class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans=0;
        sort(people.begin(),people.end());
        int n=(int)(people.size());
        for(int i=0,j=n-1;i<=j;){
            int wt_here=people[i]+people[j];
            if(wt_here<=limit){
                i++;
                j--;
                ans++;
            }
            else{
                j--;
                ans++;
            }
        }
        
        return ans;
    }
};