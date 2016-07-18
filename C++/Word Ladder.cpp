class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        unordered_set<string> used;
        queue<string> qWords;
        queue<int> qDist;
        
        used.insert(beginWord);
        qWords.push(beginWord);
        qDist.push(1);
        
        while (qWords.size() > 0) {
            string word = qWords.front(); qWords.pop();
            int dist = qDist.front(); qDist.pop();
            if(word == endWord) return dist;
            
            for(int i = 0; i < word.size(); ++i) {
                char l = word[i];
                for(char c = 'a'; c <= 'z'; ++c) {
                    word[i] = c;
                    if (wordList.count(word) && !used.count(word) ) {
                        used.insert(word);
                        qWords.push(word);
                        qDist.push(dist+1);
                    }
                }
                word[i] = l;
            }
        }
        
        return 0;
    }
};
