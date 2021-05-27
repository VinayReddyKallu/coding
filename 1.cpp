// C++ program for printing vertical order of a given binary tree
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Structure for a binary tree node
struct Node
{
	int key;
	Node *left, *right;
};

// A utility function to create a new node
struct Node* newNode(int key)
{
	struct Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return node;
}

// The main function to print vertical order of a binary tree
// with the given root
void printVerticalOrder(Node* root){

    if(root == NULL) return;
    map<int,vector<int>>m;
    queue<pair<Node*,int>>q;
    q.push({root->key,0});
    while(!q.empty()){
        pair<Node*,int> pi = q.front();
        q.pop();
        Node* node = pi.first;
        int width = pi.second;
        m[width].push_back(root->key);
        if(node->left){
            q.push({node->left,width-1});

        }
        if(node->right){
            q.push({node->right,width+1});
        }
    }

    for(auto i : m){
        vector<int> k = i.second;
        for(int i=0;i<k.size();i++)
            cout<<k[i]<<" ";
        cout<<"\n";
    }

	
}

// Driver program to test above functions
int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);
	root->right->right->right = newNode(9);
	cout << "Vertical order traversal is n";
	printVerticalOrder(root);
	return 0;
}
