struct Node{
  Node* links[26];  
  bool flag = false;
  
  bool containsKey(char ch){
      return (links[ch - 'a'] != NULL);
  }
  
  Node* get(char ch){
      return links[ch - 'a'];
  }
  
  void put(char ch, Node* node){
      links[ch - 'a'] = node;
  }
};

class Trie{
  private:
        Node* root;
  public:
        Trie(){
            root = new Node();
        }
        
        void insert(string &word){
            Node* node = root;
            for(int i = 0; i < word.size(); i++){
                if(!node->containsKey(word[i])){
                    node->put(word[i], new Node());
                }
                node = node->get(word[i]);
            }
            node->flag = true;
        }
        
        bool search(string &word){
            Node* node = root;
            for(int i = 0; i < word.size(); i++){
                if(node->containsKey(word[i]) == false) return false;
                node = node->get(word[i]);
            }
            return node->flag;
        }
};
class Solution{
    private:
        bool helper(int i, string &A, Trie &trie){
            if (i == A.size()) return true; 
            for (int len = 1; i + len <= A.size(); len++) { 
                string prefix = A.substr(i, len);
                if (trie.search(prefix)) {
                    if (helper(i + len, A, trie)) return true;
                }
            }
            return false;
        }
    public:
    // A : given string to search
    // B : vector of available strings
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        Trie trie;
        for(auto it : B) trie.insert(it);
        
        return helper(0, A, trie);
    }
};