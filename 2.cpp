class TrieNode {
	int count;
	TrieNode* arr[26];
}


TrieNode* getNode(){
	TrieNode* p = new TrieNode();
	p->count = 0;
	for(int i=0;i<26;i++)
		p->arr[i] = NULL;

	return p;
}

void insert(TrieNode* root, string s){
	for(int i=0;i<s.size();i++){
		int idx = s[i]-'a';
		if(root->arr[idx] == NULL) {
			root->arr[idx]  = getNode();
		root = root->arr[idx];
		root->count = root->count+1;
}