class TrieNode {
public: 
    TrieNode* children[10];

    TrieNode(){
        for(int i = 0;i < 10;i++){
            children[i] = nullptr;
        }
    }
};

class Trie { 
private:
    TrieNode* root;
public: 
    Trie(){
        root = new TrieNode();
    }

    // Insert all the prefix of the num into Trie
    void insert(int num){
        TrieNode* node = root;
        string numStr = to_string(num);

        for(char ch: numStr){
            int idx = ch - '0';
            if(node->children[idx] == nullptr){
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
    }

    // Search the largest prefix present in Trie for num and return the length
    int search(int num){
        TrieNode* node = root;
        string numStr = to_string(num);
        int length = 0;

        for(char ch: numStr){
            int idx = ch - '0';
            if(node->children[idx] != nullptr){
                length++;
                node = node->children[idx];
            }
            else break;
        }

        return length;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;

        for(int num: arr1){
            trie.insert(num);
        } 

        int ans = 0;

        for(int num: arr2){
            ans = max(ans, trie.search(num));
        }

        return ans;
    }
};