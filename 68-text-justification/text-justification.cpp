class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n=words.size();
        int count=0;
        vector<string>ans;
        int i=0;

        while(i<n){
            int j=i;
            //check word lenght
            int lineLength=0;

            while(j<n and words[j].size() + lineLength + (j-i)<=maxWidth){
                lineLength+=words[j].size();
                j++;
            }
            string line="";
            int gaps=j-i-1;
            if(j==n or gaps==0){
                for(int k=i;k<j;k++){
                    line+=words[k];
                    if(k!=j-1){
                        line+=" ";
                    }
                }
                line+=string(maxWidth-line.size(),' ');
            }
            else{
                int totalSpace=maxWidth - lineLength;
                int evenSpace=totalSpace/(gaps);
                int extraSpace=totalSpace%(gaps);

                for(int k=i;k<j;k++){
                    line+=words[k];
                    if(k!=j-1){
                        int spaceToApply=evenSpace;
                        if(extraSpace>0){
                            spaceToApply++;
                            extraSpace--;
                        }
                        line+=string(spaceToApply,' ');
                    }
                }
            }
            ans.push_back(line);
            i=j;

        }
        return ans;
    }
};