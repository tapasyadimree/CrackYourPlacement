struct Node{
    Node* links[26];
    bool endFlag = false;

    bool containsChild(char ch){
        return (links[ch - 'a'] != NULL);
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
};

class WordDictionary {
private: 
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsChild(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->endFlag = true;
    }
    
    bool search(string word) {
        return helper(0, word, root);
    }

    bool helper(int i, string word, Node* node){
        if(i == word.size()){
            return node->endFlag;
        }

        if(word[i] != '.'){
            int ch = word[i];
            if(node->containsChild(ch) != NULL &&
                helper(i + 1, word, node->get(ch))) return true;
        }
        else{
            for(Node* child : node->links){
                if(child != NULL && helper(i+1, word, child)) return true;
            }
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */