class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> st;
        
       vector<string> mp= {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(auto &s:words){
            string here="";
            for(auto &c:s){
                int x=c-'a';
                here+=mp[x];
            }
            st.insert(here);
        }
        return (int)(st.size());
    }
};