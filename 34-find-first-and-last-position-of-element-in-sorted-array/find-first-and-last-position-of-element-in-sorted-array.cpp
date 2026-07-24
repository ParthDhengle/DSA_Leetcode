class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        int n=nums.size();

        int l=0;
        int r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]==target){
                ans={m,m};
                //search left
                int ll=l;
                int lr=m-1;
                int lm=m;
                if( lm>0 and nums[lm-1]==target){
                    while(ll<=lr){
                        lm=ll+(lr-ll)/2;
                        if(nums[lm]==target){
                            lr=lm-1;
                        }
                        else{
                            ll=lm+1;
                        }
                    }
                    ans[0]=ll;
                }
                

                //search right;
                int rl=m+1;
                int rr=r;
                int rm=m;
                if(rm<n-1 and nums[rm+1]==target){
                    while(rl<=rr){
                        rm=rl+(rr-rl)/2;
                        if(nums[rm]==target){
                            rl=rm+1;
                        }
                        else{
                            rr=rm-1;
                        }
                    }
                    ans[1]=rr;
                }
                break;
            }

            else if(nums[m]<target){
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return ans;
    }
};