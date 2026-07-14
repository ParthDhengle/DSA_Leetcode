class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>st;
        for(string i: bank){
            st.insert(i);
        }

        if(st.find(endGene)==st.end())return -1;

        int count=0;
        queue<string>q;
        q.push(startGene);

        string gene="ACGT";

        while(!q.empty()){
            int iniSize=q.size();

            for(int i=0;i<iniSize;i++){
                string curr=q.front();
                q.pop();
                if(curr==endGene)return count;

                for(int k=0;k<curr.size();k++){
                    char original=curr[k];

                    for(char c:gene){
                        if(c==original)continue;
                        curr[k]=c;
                        if(st.find(curr)!=st.end()){
                            q.push(curr);
                            st.erase(curr);
                        }
                    }
                    curr[k]=original;
                }
            }
            count++;
        }
        return -1;
    }
};