#include<iostream>
#include<queue>
#include <vector>
#include <unordered_map>
using namespace std;

struct Tree
{
	struct Tree * lchild;
	int data;
	struct Tree * rchild;
};
struct Tree * root = NULL;
void createTree()
{
	int input=0;
	Tree *p,*t;
	std::queue<Tree *> q;
	q.push(root);
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		cout<<"Enter Left child for "<<p->data<<endl;
		cin>>input;
		if(input != (-1))
		{
			t=new Tree;
			t->data=input;
			t->lchild=t->rchild=NULL;
			p->lchild=t;
			q.push(t);
		}
		cout<<"Enter Right child"<<p->data<<endl;
		cin>>input;
		if(input != (-1))
		{
			t=new Tree;
			t->data=input;
			t->lchild=t->rchild=NULL;
			p->rchild=t;
			q.push(t);
		}
	}

}


///////////////////////////////basic//////////////////////////////////////////////////////////////////////

// Function to print all nodes of a given level from left to right
bool printLevelRec(Tree* root1, int level)
{
	if (root1 == nullptr)
		return false;

	if (level == 1)
	{
		cout << root1->data << " ";
		// return true if at-least one node is present at given level
		return true;
	}

	bool left = printLevelRec(root1->lchild, level - 1);
	bool right = printLevelRec(root1->rchild, level - 1);

	return left || right;
}

// Function to print level order traversal of given binary tree
void levelOrderTraversalRec(Tree* root1)
{
	// start from level 1 -- till height of the tree
	int level = 1;

	// run till printLevel() returns false
	while (printLevelRec(root1, level))
	{
		level++;
		cout<<endl;
	}
}

///////////////////////////////////--------map--------///////////////////////////////////////////////
// traverse the tree in pre-order fashion and store nodes into the map
// corresponding to their level
void prelevelorder(Tree *root2, int level, auto &map)
{
	// base case: empty tree
	if (root2 == nullptr)
		return;

	// insert current node and its level into the map
	map[level].push_back(root2->data);

	// recur for left and right subtree by increasing level by 1
	prelevelorder(root2->lchild, level + 1, map);
	prelevelorder(root2->rchild, level + 1, map);
}

// Recursive function to print level order traversal of given binary tree
void levelOrderTraversal(Tree *root2)
{
	// create an empty map to store nodes between given levels
	unordered_map<int, vector<int>> map;

	// traverse the tree and insert its nodes into the map
	// corresponding to the their level
	prelevelorder(root2, 1, map);

	// iterate through the map and print all nodes between given levels
	for (int i = 1; map[i].size() > 0; i++)
	{
		cout << "Level " << i << ": ";
		for (int j: map[i])
			cout << j << " ";

		cout << endl;
	}
}

////////////////////////////////////////--------------Queue--------/////////////////////////////////////
// Function to print level order traversal of given binary tree
void levelOrderTraversalQue(Tree* root3)
{
	// create an empty queue and enqueue root node
	std::queue<Tree *> q;
	q.push(root3);

	// pointer to store current node
	Tree* curr = nullptr;

	// loop till queue is empty
	while (q.size())
	{
		// process each node in queue and enqueue their
		// non-empty left and right child to queue
		curr = q.front();
		q.pop();

		cout << curr->data << " ";

		if (curr->lchild)
		   q.push(curr->lchild);

		if (curr->rchild)
		   q.push(curr->rchild);
	}
}

int main()
{
	int input;
	root = new Tree;
	cout<<"Enter a root value"<<endl;
	cin>>input;
	root->data=input;
	root->lchild=root->rchild=NULL;
 	createTree();
 	cout<<"---------LevelOrder Rec------------"<<endl;
 	levelOrderTraversalRec(root);
 	cout<<"---------LevelOrder map Rec------------"<<endl;
 	levelOrderTraversal(root);
 	cout<<"---------LevelOrder Oueue------------"<<endl;
 	levelOrderTraversalQue(root);
	return 0;
}