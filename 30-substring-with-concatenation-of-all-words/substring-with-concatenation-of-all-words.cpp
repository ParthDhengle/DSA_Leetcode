class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=s.size();
        int word_len=words[0].size();
        int window=word_len * words.size();

        unordered_map<string,int>orgmap;

        for(int i=0;i<words.size();i++){
            orgmap[words[i]]++;
        }

        vector<int>ans;

        for(int offset=0;offset<word_len;offset++){
            unordered_map<string,int>currmap;
            int i=offset;
            int j=i;
            int count=0;
            
            while(i<=n-window and j+word_len<=n){
                string word=s.substr(j,word_len);
                if(orgmap.find(word)!=orgmap.end()){
                    currmap[word]++;
                    count+=word_len;
                    j+=word_len;
                    while(currmap[word]>orgmap[word]){
                        currmap[s.substr(i,word_len)]--;
                        i+=word_len;
                        count-=word_len;
                    }
                    if(count==window){
                        ans.push_back(i);
                        
                        currmap[s.substr(i,word_len)]--;
                        i+=word_len;
                        count-=word_len;

                    }
                }else{
                    currmap.clear();
                    count=0;
                    j+=word_len;
                    i=j;
                }
            }
        }
       
        
        return ans;
    }
};