#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i, n) for(int i = 0; i < n; i++)
#define sort(n) sort(n.begin(), n.end())
const int MOD = 1e9 + 7;
typedef long long ll;
#define alpha 26
using namespace std;
struct TrieNode {
	int wc;
	char data;
	TrieNode *children[alpha];
};
TrieNode *root;
class Trie {
   
   public:
   	 TrieNode* makenode(char c) {
   	 	TrieNode *newnode = new TrieNode;
   	 	newnode->data = c;
   	 	for(int i = 0; i < alpha; i++) 
   	 		newnode->children[i] = NULL;
        newnode->wc = 0;
        return newnode;
   	 }
   	 Trie() {
   	 	root = makenode('/');
   	 }
   	 void insert(string word) {
   	    TrieNode *curr = root;
   	    
   	    int index;
   	    for(int i = 0;  i < word.size(); i++) {
   	    	index = word[i]-'a';

   	    	// if there is no such char make node with that char 
   	    	if(curr->children[index] == NULL) 
                curr->children[index] = makenode(word[i]);
            //else there is, then go and go to next one
            //cout << curr->children[index]->data << " \n";
            curr->children[index]->wc += 1;
            curr = curr->children[index];
   	    }
   	    
   	 }
   	 bool search(string word) {
   	 	TrieNode * curr = root;
   	 	int index;
   	 	for(int i = 0; i < word.size(); i++) {
   	 		index = word[i] - 'a';
   	 		if(curr->children[index] == NULL || curr->children[index]->wc == 0) 
   	 			   return false;
   	 		curr = curr->children[index];
   	 	}
   	 	return true;
   	 }
};
int main() {
   
     Trie *trie = new Trie;
     trie->insert("baba");
     if(trie->search("babab")) 
     	cout << "searched word has been found in trie" << "\n";
     else 
     	cout << " no such word exists in trie" << "\n";

	return 0;
}
