class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        unordered_map<string, int> count;

        string word = "";
        for (char c : paragraph) {
            if (isalpha(c)) {
                word += tolower(c);
            } else if (!word.empty()) {
                count[word]++;
                word = "";
            }
        }
        if (!word.empty()) count[word]++;

        string result = "";
        int maxFreq = 0;
        for (auto &[w, freq] : count) {
            if (bannedSet.count(w) == 0 && freq > maxFreq) {
                maxFreq = freq;
                result = w;
            }
        }

        return result;
    }
};
