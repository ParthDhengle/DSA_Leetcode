class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        int ans=0;
        unordered_map<char,int>map={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        for(int i=0;i<n;i++){
            if(i+1<n and map[s[i]] < map[s[i+1]]){
                ans+=map[s[i+1]] - map[s[i]];
                i++;
            }else{
                ans+=map[s[i]];
            }
        }
        return ans;
    }
};