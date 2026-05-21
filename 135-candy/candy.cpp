class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int j=n-1;
        vector<int>candy(n,1);
        for(int i=0;i<n;i++){
            if(i==0 ){
                candy[i]=max(candy[i],1);
                candy[j]=max(candy[j],1);
                j--;
                continue;
            }
            if(ratings[i]>ratings[i-1]){candy[i]=max(candy[i-1]+1,candy[i]);}
            if(ratings[j]>ratings[j+1]){candy[j]=max(candy[j+1]+1,candy[j]);}
            j--;
        }
        int ans=0;
        for(int i:candy){
            ans+=i;
        }
        return ans;
    }
};