struct Node{
    Node * link[26]={NULL};
    vector<string>comb;
};


class Solution {
public:
Node * root=new Node();

void add_prod(vector<string>&products){
    for(int i=0;i<products.size();i++){
        Node * node=root;
        string word=products[i];

        for(int j=0;j<word.size();j++){
            if(node->link[word[j]-'a']==NULL){
                node->link[word[j]-'a']=new Node;
            }
            node=node->link[word[j]-'a'];
            if(node->comb.size()<3){
                node->comb.push_back(word);
            }
        }  
    }
    return;
}


    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());

        add_prod(products);

        int n= searchWord.size();
        vector<vector<string>>ans(n);
        Node * node=root;

        for(int i=0;i<n;i++){
            if(node && node->link[searchWord[i] - 'a']){
                node=node->link[searchWord[i] - 'a'];
                ans[i]=(node->comb);
            }else{
                node=NULL;
                ans[i]={};
            }
        }
        return ans;
    }
};