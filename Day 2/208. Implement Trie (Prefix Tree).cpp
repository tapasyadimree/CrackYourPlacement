struct Node{
    Node *links[26];
    bool flag = false;

    //kya is character se koi trie node linked h ?
    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    //trie node ke is character se link kardo ek new trie node ko
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    //trie node ke is character se konsi trie node linked h vo return krdo
    Node* get(char ch){
        return links[ch - 'a'];
    }

    //is node ka flag ko true mark krdo, end of the word aa gaya
    void setEnd(){
        flag =  true;
    }

    //kya ye node end of the word h ? matlab kya iska flag true h ?
    bool isEnd(){
        return flag;
    }
};

class Trie {
private: Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }

        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0; i < prefix.size(); i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */