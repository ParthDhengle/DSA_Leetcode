class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        for(string i:wordList){
            st.insert(i);
        }

        queue<string>q;
        q.push(beginWord);

        int n=beginWord.size();
        int count=1;

        string alpha="abcdefghijklmnopqrstuvwxyz";

        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                string curr=q.front();
                q.pop();

                if(curr==endWord)return count;
                
                for(int j=0;j<n;j++){
                    char original=curr[j];

                    for(char ch:alpha){
                        if(ch==original)continue;
                        curr[j]=ch;

                        if(st.find(curr)!=st.end()){
                            q.push(curr);
                            st.erase(curr);
                        }
                    }
                    curr[j]=original;
                }
            }
            count++;
        }
        return 0;
    }
};