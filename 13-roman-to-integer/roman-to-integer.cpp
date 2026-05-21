class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        int ans=0;
        unordered_map<char,int>map={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        for(int i=0;i<n;i++){
            if(s[i]=='I'){
                if(s[i+1]=='V'){
                    ans+=4;i++;
                }else if(s[i+1]=='X'){ans+=9;i++;}
                else{ans+=1;}
                continue;
            }else if(s[i]=='X'){
                if(s[i+1]=='L'){
                    ans+=40;i++;
                }else if(s[i+1]=='C'){ans+=90;i++;}
                else{ans+=10;}
                continue;
            }else if(s[i]=='C'){
                if(s[i+1]=='D'){
                    ans+=400;i++;
                }else if(s[i+1]=='M'){ans+=900;i++;}
                else{ans+=100;}
                continue;
            }else{
                ans+=map[s[i]];
            }
        }
        return ans;
    }
};