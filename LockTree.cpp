#include <bits/stdc++.h>
using namespace std;

class narytree {
public:
	bool isLock;
	bool isLockable;
	int userLocked ;
	narytree* parent;
	vector<narytree*> children;
	unordered_map<int,unordered_set<narytree*>>childLocks;
	narytree()
	{
		isLock = false;
		isLockable = true;
		parent = NULL;
		userLocked = -1;
	}
	narytree(narytree* parent)
	{
		isLock = false;
		isLockable = true;
		this->parent = parent;
		userLocked = -1;
	}
};

// bool isLock(narytree* node) { return node->isLock; }

bool Lock(narytree* node,int user)
{
	if (node->isLockable == false)
		return false;

	narytree* T = node;
	bool flag = false;
	while (T != NULL) {
		if (T->isLock == true) {
			flag = true;
			break;
		}
		T = T->parent;
	}
	if (flag)
		return false;
	else {
		node->isLock = true;
		node->userLocked = user;
		T = node;
		// marking isLockable as false for ancestor nodes.
		while (T != NULL) {
			T->isLockable = false;
			T->childLocks[user].insert(node);
			T = T->parent;
		}
	}
	return true;
}

bool unLock(narytree* node,int currUser)
{
	if (node->isLock == false)
		return false;
	int user = node->userLocked;
	if(user != currUser) return false;
	narytree* T = node;
	node->isLock = false;
	// cout<<user<<endl;
	node->userLocked = -1;
	// marking isLoackable as true for ancestor nodes.
	while (T != NULL) {
		T->isLockable = true;
		T->childLocks[user].erase(node);
		if(T->childLocks[user].size() == 0) T->childLocks.erase(user);
		T = T->parent;
	}
	return true;
}

bool upgrade(narytree* UpgradeNode,int user){
	int size = UpgradeNode->childLocks.size();
	cout<<"Size"<<size;
	// for(auto i : UpgradeNode->childLocks){
	// 	cout<<i.first<<endl;
	// }

	if(UpgradeNode -> isLock ) return false;
	
	if(size==1 && UpgradeNode->childLocks.find(user)!= UpgradeNode->childLocks.end()){
		unordered_set<narytree*> s1 = UpgradeNode->childLocks[user];
		for(auto it = s1.begin(); it != s1.end(); ++it){
			narytree* node = *it;
			node->isLock = false;
			node->userLocked = -1;
			narytree* T = node;
			while (T != NULL) {
				T->isLockable = true;
				T->childLocks[user].erase(node);
				if(T->childLocks[user].size() == 0) T->childLocks.erase(user);
				T = T->parent;
			}	
		}
		UpgradeNode->isLock = true;
		UpgradeNode->userLocked = user;
		narytree* T = UpgradeNode;
		// marking isLockable as false for ancestor nodes.
		while (T != NULL) {
			T->isLockable = true;
			T->childLocks[user].insert(UpgradeNode);
			T = T->parent;
		}
		return true;
	}
	else{
		// cout<<"here"<<"\n";
		return false;
	}

	// else if(size == 0){
	// 	UpgradeNode->isLock = true;
	// 	UpgradeNode->userLocked = user;
	// 	narytree* T = UpgradeNode;
	// 	// marking isLockable as false for ancestor nodes.
	// 	while (T != NULL) {
	// 		T->isLockable = false;
	// 		T->childLocks[user].insert(UpgradeNode);
	// 		T = T->parent;
	// 	}
	// 	return true;
	// }
	
		

}



int main()
{
	// Creating N-Array Tree
	// narytree* World = new narytree();

	// narytree* Asia = new narytree(World);
	// narytree* Africa = new narytree(World);

	// World->children.push_back(Asia);
	// World->children.push_back(Africa);
	
	// unordered_set<narytree*> k;

	// narytree* China = new narytree(World->children[0]);
	// World->children[0]->children.push_back(China);
	
	// narytree* India = new narytree(World->children[0]);
	// World->children[0]->children.push_back(India);

	// narytree* SouthAfrica = new narytree(World->children[1]);
	// World->children[1]->children.push_back(SouthAfrica);

	// narytree* Egypt = new narytree(World->children[1]);
	// World->children[1]->children.push_back(Egypt);

	// cout<<Lock(World,9)<<endl;
	// cout<<Lock(India,9)<<endl;
	// cout<<unLock(World,9)<<endl;
	// cout<<upgrade(World,9)<<endl;
	// cout<<Lock(China,9)<<endl;
	// cout<<upgrade(Asia,9)<<endl;
	// cout<<Lock(Egypt,8)<<endl;	
	// cout<<upgrade(Africa,8)<<endl;
	// cout<<upgrade(World,8)<<endl;
	// cout<<India->isLock<<"\n";
	// cout<<"Printing"<<endl;
	// unordered_set<narytree*> k = World->childLocks[9];
	// 	for (auto it = k.begin(); it != k.end(); ++it)
	// 		 cout << ' ' << (*it)->isLock;
	
	// cout<<endl;
	// cout<<"Printing"<<endl;
	
	// cout<<"Printing"<<endl;

	//  = World->childLocks[9];
	// 	for (auto it = k.begin(); it != k.end(); ++it)
	// 		 cout << ' ' << (*it)->isLock;
	
	// cout<<endl;
	// cout<<"Printing"<<endl;
	// cout<<China->isLock<<"\n";

	

	// cout<<"Printing"<<endl;
	// k= World->childLocks[9];
	// 	for (auto it = k.begin(); it != k.end(); ++it)
	// 		 cout << ' ' << (*it)->isLock;
	// cout<<endl;
	// cout<<"Printing"<<endl;
	// cout<<unLock(India,9)<<endl;

	// cout<<"size of world"<<World->childLocks.size()<<endl;
	
      

	
	// cout<<"Printing"<<endl;
	// k= World->childLocks[9];
	// 	for (auto it = k.begin(); it != k.end(); ++it)
	// 		 cout << ' ' << (*it)->isLock;
	// cout<<endl;
	// cout<<"Printing"<<endl;


	

	// cout<<"Printing"<<endl;
	// k= World->childLocks[8];
	// 	for (auto it = k.begin(); it != k.end(); ++it)
	// 		 cout << ' ' << (*it)->isLock;
	// cout<<endl;
	// cout<<"Printing"<<endl;

	// cout<<World->childLocks.size();
	int n,m,Queries;
	cin>>n>>m;
	map<string,narytree*>input;
	queue<narytree*>q;
	string s;
	cin>>s;
	narytree *root = new narytree();
	input[s] = root;
	q.push(root);
	while(!q.empty() && n-1>0) {
		narytree* p=q.front();
		q.pop();
		for(int i=0;i<m;i++){
			cin>>s;
			narytree *ch= new narytree(p);
			p->children.push_back(ch);
			q.push(ch);
			input[s] = ch;
			n--;
			if(n==0)
				break;
		}

	}

    // cout<<upgrade(input["india"],9)<<endl;
	// cout<<upgrade(input["world"],9)<<endl;
	// cout<<Lock(input["india"],9)<<endl;
	// cout<<unLock(input["world"],9)<<endl;
	// cout<<upgrade(input["world"],9)<<endl;
	// cout<<Lock(input["china"],9)<<endl;
	// cout<<upgrade(input["asia"],9)<<endl;
	// cout<<Lock(input["egypt"],8)<<endl;	
	// cout<<upgrade(input["africa"],8)<<endl;
	// cout<<upgrade(input["world"],8)<<endl;

	cout<<Lock(input["j"],1);
	cout<<Lock(input["h"],1);
	cout<<upgrade(input["a"],2);
	cout<<upgrade(input["a"],1);
	// cout<<unLock(input["h"],1);
	// cout<<unLock(input["a"],1);
	// cout<<Lock(input["k"],1);
	// cout<<Lock(input["m"],1);
	// cout<<upgrade(input["d"],1);
	// cout<<Lock(input["e"],1);
	// cout<<Lock(input["d"],1);
	// cout<<upgrade(input["a"],1);
	// cout<<Lock(input["a"],1);
	return 0;
}
