package com.company;
class Solution {
    static class Node{
        Node[] arr;
        int count;
        Node(){
            this.arr = new Node[26];
        }
    }
    static class Trie{
        Node root;
        Trie(){
            this.root = new Node();
        }
        void insert(String s){
            Node tempNode = root;
            root.count++;
            for(int i=0; i<s.length();i++){
                if(tempNode.arr[s.charAt(i)-'a'] == null){
                    tempNode.arr[s.charAt(i)-'a'] = new Node();
                    tempNode = tempNode.arr[s.charAt(i)-'a'];
                    tempNode.count =1;
                }
                else{
                    tempNode = tempNode.arr[s.charAt(i)-'a'];
                    tempNode.count++;
                }
            }
        }
        int find(String s){
            Node tempNode = root;
            for(int i=0; i<s.length();i++){
                if(tempNode.count == 1) return i;
                else tempNode = tempNode.arr[s.charAt(i)-'a'];
            }
            return s.length();
        }
    }
    public int solution(String[] words) {
        Trie trie = new Trie ();
        for (String s : words) {
            trie.insert(s);
        }
        int answer = 0;
        for (int i = 0; i < words.length; i++) {
            answer += trie.find(words[i]);
        }
        return answer;
    }
}
public class Main {
    public static void main(String[] args) {
        Solution a = new Solution();
    }
}
