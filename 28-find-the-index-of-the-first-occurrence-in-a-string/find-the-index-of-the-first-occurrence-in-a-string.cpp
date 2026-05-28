class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        for(int i=0;i<n;i++){
            int k=0; 
            while(k<m && haystack[i+k]==needle[k]){
                k++;
            }
            if(k==m){return i;}
        }
        return -1;
    }
};