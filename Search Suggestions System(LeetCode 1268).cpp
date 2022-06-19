/*You are given an array of strings products and a string searchWord.

Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return a list of lists of the suggested products after each character of searchWord is typed.*/

class Solution {
public:
    class Trie{
        
        public:
        Trie *next[26];
        priority_queue<int> index;
  };
    
    Trie *root;
    vector<vector<string>> ans;
    
    static bool comp(string &a,string &b)
    {
        int mi=min((int)a.size(),(int)b.size());
        
        for(int i=0;i<mi;i++)
        {
            if(a[i]==b[i])
                continue;
            else return a[i]<b[i];
        }
        
        return a.size()<b.size();
    }
    
    void buildTrie(vector<string>& products)
    {
        Trie *nd;
        root=new Trie();
        int index=0;
        
        for(string s:products)
        {
            nd=root;
            
            for(int i=0;i<s.size();i++)
            {
                if(!nd->next[s[i]-'a'])
                    nd->next[s[i]-'a']=new Trie();
                nd=nd->next[s[i]-'a'];
                nd->index.push(index);
                if(nd->index.size()>3)
                    nd->index.pop();
            }
            
            index++;
        }
    }
    
    void addAnswer(string &searchWord,vector<string> &products)
    {
        Trie *nd=root;
        int index=0;
        
        for(char c:searchWord)
        {
            
            if(!nd->next[c-'a'])
            {
                for(index=index;index<searchWord.size();index++)
                    ans.push_back({});
                return ;
            }
            
            nd=nd->next[c-'a'];
            vector<string> v;
            
            while(!nd->index.empty())
            {
                v.push_back(products[nd->index.top()]);
                nd->index.pop();
            }
            
            reverse(v.begin(),v.end());
            ans.push_back(v);
            
            index++;
        }
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        sort(products.begin(),products.end(),comp);
        
        buildTrie(products);
        
        addAnswer(searchWord,products);
        
        return ans;
        
        
        
}
};
