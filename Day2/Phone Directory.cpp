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
        
        // bool search(string &word){
        //     Node* node = root;
        //     for(int i = 0; i < word.size(); i++){
        //         if(node->containsKey(word[i]) == false) return false;
        //         node = node->get(word[i]);
        //     }
        //     return node->flag;
        // }
        void collectWords(Node* node, string prefix, vector<string> &result){
            if(node->flag == true){
                result.push_back(prefix);
            }
            
            for(char ch = 'a'; ch <= 'z'; ch++){
                if(node->containsKey(ch)){
                    collectWords(node->get(ch), prefix + ch, result);
                }
            }
        }
        
        vector<string> getWordsWithPrefix(string &prefix){
            vector<string> result;
            Node* node = root;
            for(int i = 0; i < prefix.size(); i++){
                if(!node->containsKey(prefix[i])) return result;
                node = node->get(prefix[i]);
            }
            collectWords(node, prefix, result);
            return result;
        }
        
};
class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        Trie trie;
        for(int i = 0; i < n; i++){
            trie.insert(contact[i]);
        }
        
        vector<vector<string>> ans;
        
        for(int i = 1; i <= s.length(); i++){
            string prefix = s.substr(0, i);
            vector<string> matchedContacts = trie.getWordsWithPrefix(prefix);
            if(matchedContacts.size() == 0) matchedContacts.push_back("0");
            ans.push_back(matchedContacts);
        }
        
        return ans;
    }
};