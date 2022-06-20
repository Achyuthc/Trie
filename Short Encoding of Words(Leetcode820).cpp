/*A valid encoding of an array of words is any reference string s and array of indices indices such that:

words.length == indices.length
The reference string s ends with the '#' character.
For each index indices[i], the substring of s starting from indices[i] and up to (but not including) the next '#' character is equal to words[i].
Given an array of words, return the length of the shortest reference string s possible of any valid encoding of words.*/

sort the vector based on size so that when building trie we see "time" before "me"
reverse each word like "emit" and "em"
insert each word into the trie,keep track of wordExist. if wordExist is false then add size+1 to lengthOf Reference.
return lengthOfReference
class Solution {
public:
    class Trie{
        public:
        Trie *next[26];
        
    };
    
    int lengthOfReference=0;
    Trie *root=new Trie();
    
    static bool comparator(string &a,string &b)
    {
        return a.size()>b.size();
    }
    void buildTrie(vector<string> &words)
    {
        Trie *nd=root;
        
        for(string &word:words)
        {
            reverse(word.begin(),word.end());
            nd=root;
            bool wordExist=true;
            
            for(char &c:word)
            {
                if(!nd->next[c-'a'])
                {
                    //cout<<word<<" ";
                    wordExist=wordExist&&false;
                    nd->next[c-'a']=new Trie();
                }
                nd=nd->next[c-'a'];
                
            }
            
            if(!wordExist)
                lengthOfReference+=word.size()+1;
            
        }
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),comparator);
        
        buildTrie(words);
        
        return lengthOfReference;
        
    }
};
