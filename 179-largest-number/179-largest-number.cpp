class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> w;
        for(int v:nums){
            w.push_back(to_string(v));
        }
       sort(w.begin(),w.end(),[](string a,string b){
           string p= a+b;
           string q=b+a;
           return p>q;
       });
        
       
         string ans="";
        for(auto cur:w){
            ans+=cur;
        }
        while((int)(ans.size())>1&&ans.front()=='0'){
            ans.erase(ans.begin());
        }
        return ans;
    }
};