#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
struct Trie {
    Trie* next[26];
    int count = 1;
    int layer;
    Trie(int layer) {
        memset(next, 0, sizeof(next));
        this->layer = layer;
    }
    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (next[i]) delete next[i];
        }
    }
    void insert(const char* words) {
        if (*words != '\0') {
            int cur = *words - 'a';
            if (next[cur] == NULL) next[cur] = new Trie(this->layer + 1);
            else next[cur]->count += 1;
            next[cur]->insert(words + 1);
        }
    }
    int find(const char* words, int size, int total) {
        int cur = *words - 'a';
        if (size == total) return next[cur]->layer;
        int nextlayer = *(words + 1) - 'a';
        if (next[cur]->count == 1) return next[cur]->layer;
        else if (next[cur]->next[nextlayer]->count == 1) return next[cur]->next[nextlayer]->layer;
        return next[cur]->find(words + 1, size + 1, total);
    }
};

int solution(vector<string> words) {

    int answer = 0;
    Trie tree(0);
    for (auto& w : words) {
        const char* c = w.c_str();
        tree.insert(c);
    }
    for (auto& w : words) {
        const char* c = w.c_str();
        answer += tree.find(c, 1, strlen(c));
    }
    return answer;

}