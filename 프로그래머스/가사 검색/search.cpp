#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Trie {
    Trie* next[26];
    int count;
    Trie() : count(1) {
        memset(next, 0, sizeof(next));
    }
    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (next[i]) delete next[i];
        }
    }
    void insert(const char* key) {
        if (*key != '\0') {
            int cur = *key - 'a';
            if (next[cur] == NULL) {
                next[cur] = new Trie();
            }
            else {
                next[cur]->count += 1;
            }
            next[cur]->insert(key + 1);
        }
    }
    int find(const char* key) {
        int cur = *key - 'a';
        if (*key == '?') {
            int temp = 0;
            for (int i = 0; i < 26; i++) {
                if (next[i] != NULL) {
                    temp += next[i]->count;
                }
            }
            return temp;
        }
        if (next[cur] == NULL) return 0;
        if (*(key + 1) == '?') return next[cur]->count;
        return next[cur]->find(key + 1);
    }
};
Trie* root[10001];
Trie* reverseroot[10001];
vector<int> solution(vector<string> words, vector<string> queries) {
    int wsize = words.size();
    int qsize = queries.size();
    vector<int> answer(qsize,0);
    for (auto& w : words) {
        int cursize = w.size();
        const char* c = w.c_str();
        if (root[cursize] == NULL) root[cursize] = new Trie();
        root[cursize]->insert(c);
        string reword = w;
        reverse(reword.begin(), reword.end());
        const char* r = reword.c_str();
        if (reverseroot[cursize] == NULL) reverseroot[cursize] = new Trie();
        reverseroot[cursize]->insert(r);
    }
    int index = 0;
    for (auto& q : queries) {
        int cursize = q.size();
        if (q[cursize - 1] == '?') {
            const char* c = q.c_str();
            if (root[cursize] == NULL) {
                index += 1;
                continue;
            }
            else {
                answer[index] = root[cursize]->find(c);
            }
        }
        else {
            string rs = q;
            reverse(rs.begin(), rs.end());
            const char* rec = rs.c_str();
            if (reverseroot[cursize] == NULL) {
                index += 1;
                continue;
            }
            else answer[index] = reverseroot[cursize]->find(rec);
        }
        index += 1;
    }
    return answer;
}  
int main() {
    vector<int> a = solution({ "frodo", "front", "frost", "frozen", "frame", "kakao" }, { "fro??", "????o", "fr???", "fro???", "pro?" });
}