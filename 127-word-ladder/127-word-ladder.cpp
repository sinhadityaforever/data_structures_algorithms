class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        while(!q.empty()){
            auto top  = q.front();
            q.pop();
            string word = top.first;
            int size = top.second;
            if(word==endWord) return size;
            
            for(int i=0; i<word.length(); i++){
                string originalWord = word;
                for(char ch = 'a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word, size+1});
                    }
                }
                word=originalWord;
            }
            
        }
        return 0;
    }
};