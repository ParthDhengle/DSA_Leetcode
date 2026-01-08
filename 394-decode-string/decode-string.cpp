class Solution {
public:
    pair<int,string> recursion(int i,string s){
        string number="";
        while(isdigit(s[i])){
            number+=s[i];
            i++;
        }
        i++;
        string new_string="";
        while(s[i]!=']'){
            if(!isdigit(s[i])){
                new_string+=s[i];
            }
            else{
                auto result=recursion(i,s);
                i=result.first;
                new_string+=result.second;
            }
            i++;
        }
        string expanded="";
        for(int i=0;i<stoi(number);i++){
            expanded+=new_string;
        }
        return {i, expanded};
    }
    string decodeString(string s) {
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            if(!isdigit(s[i])){
                ans+=s[i];
            }else{
                auto results=recursion(i,s);
                i=results.first;
                ans+=results.second;
            }
        }
        return ans;
    }
};