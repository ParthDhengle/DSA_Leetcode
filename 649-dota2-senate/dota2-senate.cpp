class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>rq,dq;
        int n=senate.size();
        for(int i=0;i<n;i++){
            if(senate[i]=='R'){
                rq.push(i);
            }else{
                dq.push(i);
            }
        }

        while(!rq.empty() and !dq.empty()){
             if(rq.front()>dq.front()){
                rq.pop();
                dq.push(n);
                dq.pop();
             }else{
                dq.pop();
                rq.push(n);
                rq.pop();
             }
             n++;
        }
        if(rq.empty()){
            return "Dire";
        }
        return "Radiant";
    }
};