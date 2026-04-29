class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip=0;
        while((a | b )!= c){
            if((c & 1) ==1 and ((a&1)==0 and (b&1)==0)){
                flip+=1;
            }else if((c&1)==0){
                if((a&1)==1){
                    flip+=1;
                }
                if((b&1)==1){
                    flip+=1;
                }
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return flip;
    }
};