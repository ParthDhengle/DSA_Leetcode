class Solution {
public:
    string addBinary(string a, string b) {
        int n1=a.size();
        int n2=b.size();
        if(n2>n1)return addBinary(b,a);
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string ans;
        int carry=0;
        for(int i=0;i<n2;i++){
            int sum=carry+a[i]-'0'+b[i]-'0';
            if(sum<2){
                ans+=sum+'0';
                carry=0;
            }
            if(sum==2){
                ans+='0';
                carry=1;
            }if(sum==3){
                ans+='1';
                carry=1;
            }
        }
        for(int i=n2;i<n1;i++){
            int sum=a[i]-'0'+carry;
            if(sum<2){
                ans+=sum+'0';
                carry=0;
            }else if(sum==2){
                carry=1;
                ans+='0';
            }
        }
        if(carry){
            ans+='1';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};