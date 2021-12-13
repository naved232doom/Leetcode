class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
     // BRUTE FORCE
            int n=(int)(words.size());
            vector<int> avL(26);
            for(char c:letters) avL[c-'a']++;
            int ans=0;
            for(int mask=0;mask<(1<<n);++mask){
                        bool possible=1;
                        auto avltmp=avL;
                    int cur=0;
                        for(int i=0;i<n;++i){
                                if(mask&(1<<i)){
                                        for(int j=0;j<words[i].length();++j){
                                                int charHere=words[i][j]-'a';
                                                if(avltmp[charHere]<=0){
                                                        possible=0;
                                                }
                                                avltmp[charHere]--;
                                                cur+=score[charHere];
                                        }
                                }
                        }
                    if(possible) ans=max(ans,cur);
            }
            return ans;
    }
};