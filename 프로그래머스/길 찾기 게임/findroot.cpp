#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(pair<int,vector<int>> a, pair<int,vector<int>> b) {
    if (a.second[1] > b.second[1]) return true;
    else if (a.second[1] == b.second[1]) return a.second[0] < b.second[0];
    else return false;
}
struct Tree {
    int data;
    int seq;
    Tree* left;
    Tree* right;
    Tree(int data,int seq) {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
        this->seq = seq;
    }
    void insert(int data, int seq) {
         if (this->data > data) {
             if (this->left == NULL) {
                 this->left = new Tree(data,seq);
                 return;
             }
             else this->left->insert(data,seq);
        }
        else {
             if (this->right == NULL) {
                 this->right = new Tree(data,seq);
                 return;
             }
            this->right->insert(data,seq);
        }
        return;
    }
    void findF(Tree * tree,vector<int>& arr) {
        if (tree != NULL) {
            arr.push_back(tree->seq);
            findF(tree->left, arr);
            findF(tree->right, arr);
        }
    }
    void findL(Tree* tree, vector<int>& arr) {
        if (tree != NULL) {
            findL(tree->left, arr);
            findL(tree->right, arr);
            arr.push_back(tree->seq);
        }
    }
};
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector< pair<int, vector<int>>>v;
    for (int i = 0; i < nodeinfo.size(); i++) {
        v.push_back(make_pair(i+1, nodeinfo[i]));
    }
    sort(v.begin(), v.end(), compare);
    Tree tree = Tree(v[0].second[0],v[0].first);
    for (int i = 1; i < nodeinfo.size(); i++) {
        tree.insert(v[i].second[0],v[i].first);
    }
    vector<int> arr1,arr2;
    tree.findF(&tree, arr1);
    tree.findL(&tree, arr2);
    answer.push_back(arr1);
    answer.push_back(arr2);
    return answer;
}
int main() {
    vector<vector<int>> v = {
        {5, 3},{11, 5},{13, 3},{3, 5},{6, 1},{1, 3},{8, 6},
        {7, 2},{2, 2} };
    vector<vector<int>> a = solution(v);
}