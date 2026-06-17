class Solution {
public:
    string simplifyPath(string path) {
        vector<string>arr;
        int n=path.size();

        for(int i=0;i<n;i++){
            string curr="";
            if(path[i]=='/')continue;
            while(i<n and path[i]!='/'){
                curr+=path[i];
                i++;
            }
            if(curr==".")continue;
            if(curr==".."){
                if(arr.size()>0){
                    arr.pop_back();
                }
                continue;
            }
            arr.push_back(curr);
        }
        string ans="";
        for(auto i : arr){
            ans+="/"+i;
        }
        if(ans.size()==0)return "/";
        return ans;
    }
};