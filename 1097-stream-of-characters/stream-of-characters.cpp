class StreamChecker {
public:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            for(int i=0; i<26;++i) {
                children[i] = nullptr;
            }
            isEnd = false;
        }
    };   

    TrieNode* root;
    deque<char> stream;
    int maxLength;

    StreamChecker(vector<string>& words) {
        maxLength = 200;
        root = new TrieNode();
        for (const string s: words) {
            insert(s);
        }
        
    }
    
    bool query(char letter) {
        if (stream.size() < maxLength) {
            stream.push_back(letter);    
        }
        else {
            stream.pop_front();
            stream.push_back(letter);
        }

        return find();

        
    }

private:
    void insert(string word) {

        TrieNode* curr = root;

        for(int i=word.size()-1; i>=0; i--) {
            char c = word[i];
            if(!curr->children[c-'a']) {
                curr->children[c-'a'] = new TrieNode();
            }

            curr = curr->children[c-'a'];
        }

        curr->isEnd = true;
    }

    bool find() {

        TrieNode* curr = root;

        for(auto it = stream.rbegin(); it!=stream.rend(); ++it) {
            char c = *it;

            if(!curr->children[c-'a']) return false;

            if (curr->children[c-'a']->isEnd ) return true;

            curr = curr->children[c-'a'];
        }

        return curr->isEnd;

    }
};


/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */