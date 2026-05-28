class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        int k=0;
        for(int i=0;i<n;i++){
            // cout<<"i : "<<i<<" k: "<<k<<endl;
            if(haystack[i]==needle[0]){
                int j=i;
                k=0;
                
                while(j<n and k<m){
                    
                    if(haystack[j]==needle[k]){
                        
                        j++;
                        k++;
                    }else{
                        break;
                    }
                }
                if(k==m){return i;}
            }
        }
        return -1;
    }
};