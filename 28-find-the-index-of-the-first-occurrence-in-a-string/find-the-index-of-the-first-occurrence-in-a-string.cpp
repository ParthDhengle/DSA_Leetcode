class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        int k=0;
        for(int i=0;i<n;i++){
            k=0; 
            while(k<m and haystack[i+k]==needle[k]){
                k++;
            }
            if(k==m){return i;}
            
        }
        return -1;
    }
};