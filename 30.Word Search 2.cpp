class Solution {
public:
   
    class Trie{
        
    public:
        unordered_map<char, Trie*> children;
        bool terminal = false;

        void insert(string word){
            Trie* node=this;
            for(char c : word){
                if(node->children.find(c)==node->children.end())
                    node->children[c]=new Trie();
                node=node->children[c];
            }
            node->terminal=true;
        }
    
        
    };
    
    void checkWord(vector<vector<char>>& board,Trie* t,int i,int j,string& s,vector<string>& result){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='.'){
            return;
        }
        
        if(t->children.find(board[i][j])==t->children.end()){ 
            return; 
        }else{
            t = t->children[board[i][j]];
        }
        
        s.push_back(board[i][j]);
        if(t->terminal){
            result.push_back(s);
            t->terminal = false;
        }
        char temp = board[i][j];
        board[i][j] = '.';
        
        checkWord(board,t,i,j-1,s,result);
        checkWord(board,t,i,j+1,s,result);
        checkWord(board,t,i-1,j,s,result);
        checkWord(board,t,i+1,j,s,result);
        
        s.pop_back();
        board[i][j] = temp;
        
    }
    
    vector<string> findWordsHelper(vector<vector<char>>& board, Trie* t){
        int n = board.size();
        int m = board[0].size();
        
        vector<string> result;
        string s;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                checkWord(board,t,i,j,s,result);
            }
        }
        return result;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* t = new Trie();
        for(auto i : words){
            t->insert(i);
        }
        return findWordsHelper(board,t);
    }
};
