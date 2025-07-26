/*
Word sense disambiguation is the problem of determining which sense a word takes on in a particular setting, if that word has multiple meanings. For example, in the sentence "I went to get money from the bank", bank probably means the place where people deposit money, not the land beside a river or lake.

Suppose you are given a list of meanings for several words, formatted like so:

```
{
    "word_1": ["meaning one", "meaning two", ...],
    ...
    "word_n": ["meaning one", "meaning two", ...]
}
```

Given a sentence, most of whose words are contained in the meaning list above, create an algorithm that determines the likely sense of each possibly ambiguous word.
*/
#include <bits/stdc++.h>
using namespace std;

// Lowercase & split on non-alphanumerics.
vector<string> tokenize(const string &s) {
    vector<string> tokens;
    string cur;
    for (char c : s) {
        if (isalnum(c)) {
            cur += tolower(c);
        } else if (!cur.empty()) {
            tokens.push_back(cur);
            cur.clear();
        }
    }
    if (!cur.empty()) tokens.push_back(cur);
    return tokens;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // // 1) Read dictionary
    // int N;
    // cin >> N;
    // unordered_map<string, vector<string>> dict;
    // unordered_map<string, vector<vector<string>>> dictTokens;
    // for (int i = 0; i < N; ++i) {
    //     string word;
    //     cin >> word;
    //     int S;
    //     cin >> S;
    //     cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //     vector<string> senses(S);
    //     vector<vector<string>> tokDefs(S);
    //     for (int j = 0; j < S; ++j) {
    //         getline(cin, senses[j]);
    //         tokDefs[j] = tokenize(senses[j]);
    //     }
    //     // normalize key
    //     for (auto &c : word) c = tolower(c);
    //     dict[word] = move(senses);
    //     dictTokens[word] = move(tokDefs);
    // }

    // // 2) Read & tokenize sentence
    // string line;
    // getline(cin, line);
    // auto sent = tokenize(line);

    // Sample Inputs: (Above are inputs through input stream)
    vector<pair<string, vector<string>>> sampleDict = {
        {"bank",
         {"place where people deposit money", "land beside a river or lake"}}};
    string sentence = "I went to get money from the bank";

    // 1) Build dict + tokenized definitions
    unordered_map<string, vector<string>> dict;
    unordered_map<string, vector<vector<string>>> dictTokens;
    for (auto &entry : sampleDict) {
        string w = entry.first;
        // normalize key to lowercase
        for (auto &c : w) c = tolower(c);
        dict[w] = entry.second;

        vector<vector<string>> toks;
        for (auto &def : entry.second) toks.push_back(tokenize(def));
        dictTokens[w] = move(toks);
    }

    // 2) Tokenize the sentence
    auto sent = tokenize(sentence);
    unordered_set<string> seen;
    // 3) Disambiguate each ambiguous word once
    for (auto &w : sent) {
        if (dict.count(w) && dict[w].size() > 1 && !seen.count(w)) {
            seen.insert(w);
            // build context = all other tokens
            unordered_set<string> ctx;
            for (auto &x : sent)
                if (x != w) ctx.insert(x);

            // pick sense with maximum overlap
            int bestSense = 0, bestScore = -1;
            auto &defs = dictTokens[w];
            for (int i = 0; i < (int)defs.size(); ++i) {
                int score = 0;
                for (auto &t : defs[i])
                    if (ctx.count(t)) ++score;
                if (score > bestScore) {
                    bestScore = score;
                    bestSense = i;
                }
            }

            // 4) Output
            cout << w << " -> " << dict[w][bestSense] << "\n";
        }
    }

    return 0;
}
// Dictionary:
//   bank → ["financial institution", "river edge"]

// Sentence:
//   I went to get money from the bank

// Tokenized sentence = ["i","went","to","get","money","from","the","bank"]

// For “bank”:
//   Context = {i, went, to, get, money, from, the}
//   Overlap with “financial institution” = 0
//   Overlap with “river edge” = 0
//   → tie → picks the first sense (“financial institution”), which is correct here by intuition.

// ---

// #### Possible Extensions

// - **Extended Lesk**: include definitions of surrounding words.
// - **WordNet‐based**: use gloss overlaps + related synsets.
// - **Embedding methods**: compute cosine similarity between sense‐embeddings and context vector.

// But for many dictionary‐based tasks, this simple overlap heuristic already works surprisingly well.
