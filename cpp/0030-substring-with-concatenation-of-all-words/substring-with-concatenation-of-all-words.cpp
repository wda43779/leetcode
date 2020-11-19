class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        
        int wordLen = words[0].size();
        int wordsLen = wordLen * words.size();
        
        int wordsHash = 0;
        for (auto &word : words) {
            for (auto &ch : word) {
                wordsHash += ch;
            }
        }
        
        unordered_multiset<string> wordsSet(words.begin(), words.end());
        
        int curHash = 0;
        for (int i = 0; i < wordsLen; i++) {
            curHash += s[i];
        }
        for (int i = 0; i < s.size() - wordsLen + 1; i++) {
            if (curHash == wordsHash) { // check with hash
                // check with set
                unordered_multiset<string> guess;
                for (int j = i; j < i + wordsLen; j+= wordLen) {
                    guess.insert(s.substr(j, wordLen));
                }
                if (guess == wordsSet) {
                    res.push_back(i);
                }
            }
            curHash -= s[i];
            curHash += s[i + wordsLen];
        }
        
        return res;
    }
};
