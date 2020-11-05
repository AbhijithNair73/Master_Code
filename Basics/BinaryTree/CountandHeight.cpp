#include<iostream>
#include<queue>
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
		cout<<"Enter lchild child for "<<p->data<<endl;
		cin>>input;
		if(input != (-1))
		{
			t=new Tree;
			t->data=input;
			t->lchild=t->rchild=NULL;
			p->lchild=t;
			q.push(t);
		}
		cout<<"Enter rchild child"<<p->data<<endl;
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



/////////////////////////////////-----------height----------------//////////////////////////////////////////
// Recursive function to calculate height of given binary tree
int height(Tree* root5)
{
	int x=0,y=0;
	// Base case: empty tree has height 0
	if (root5 != nullptr)
	{
		x=height(root5->lchild);
		y=height(root5->rchild);
		if(x>y)
			return x+1;
		else
			return y+1;
	}
	else
		return 0;

	// recur for lchild and rchild subtree and consider maximum depth
	// **** return 1 + max(height(root5->lchild), height(root5->rchild));
}

/////////////////////////////------------------nonrec height-------------------////////////////////
// Iterative function to calculate height of given binary tree
// by doing level order traversal of the tree
typedef struct heightCount
{
	int height;
	int count;
}hgtCnt;

hgtCnt heightnonRec(Tree *root6)
{
	hgtCnt loc;
	loc.height=0;
	loc.count=1;
	// empty tree has height 0
	if (root6 == nullptr)
		return loc;

	// create an empty queue and enqueue root Tree
	std::queue<Tree*> qu;
	qu.push(root6);

	Tree* front = nullptr;

	// loop till queue is empty
	while (!qu.empty())
	{
		// calculate number of nodes in current level
		int size = qu.size();

		// process each Tree of current level and enqueue their
		// non-empty lchild and rchild child to queue
		while (size--)
		{
		   front = qu.front();
		   qu.pop();

		   if (front->lchild)
		   {
				qu.push(front->lchild);
				loc.count++;
		   }

		   if (front->rchild)
		   {
				qu.push(front->rchild);
				loc.count++;
		   }
		}

		// increment height by 1 for each level
		loc.height++;
	}

	return loc;
}



/*
==============================    Count all nodes ======================================================
*/
int countNodeRec(Tree * rooot)
{
	int x=0,y=0;
	if(rooot != nullptr)
	{
		x=countNodeRec(rooot->lchild);
		y=countNodeRec(rooot->rchild);
		return x+y+1;
	}
	return 0;
}



int TotalNodeValue (Tree * rooot)
{
	int x=0,y=0;
	if(rooot != nullptr)
	{
		x=TotalNodeValue(rooot->lchild);
		y=TotalNodeValue(rooot->rchild);
		return rooot -> data + x + y ;
	}
	return 0;
}

void TreeSum(Tree *rooot, int& sum){ 
    if (!rooot) 
        return; 
  
    // add root data to sum if  
    // root is a leaf node 
   // if (!root->lchild && !root->rchild) 
    sum += rooot->data; 

    // propagate recursively in lchild 
    // and rchild subtree 
    TreeSum(rooot->lchild, sum); 
    TreeSum(rooot->rchild, sum); 
} 

int sumLeaf(Tree* rooot)
{
    	int x=0,y=0;
	if(rooot != nullptr)
	{
	    if(rooot->lchild == NULL && rooot->rchild == NULL)
	    {
		x=sumLeaf(rooot->lchild);
		y=sumLeaf(rooot->rchild);
		return rooot -> data + x + y ;
	    }
	    else{
	    x=sumLeaf(rooot->lchild);
		y=sumLeaf(rooot->rchild);
		return x+y;
	    }
	}
	return 0;
}
void TreeMax(Tree *rooot, int& max){ 
    if (!rooot) 
        return; 
  
    // add root data to sum if  
    // root is a leaf node 
   // if (!root->lchild && !root->rchild) 
    if(max < rooot->data)
    	max=rooot->data;	 

    // propagate recursively in lchild 
    // and rchild subtree 
    TreeMax(rooot->lchild, max); 
    TreeMax(rooot->rchild, max); 
} 

int maxNodeValue(Tree * rooot)
{
	int x=0,y=0;
	int maxim = 0;
	int res=0;
	if(rooot != nullptr)
	{
		
		x=maxNodeValue(rooot->lchild);
		y=maxNodeValue(rooot->rchild);
		maxim=rooot->data;
		if(x > maxim)
			maxim = x;
		if(y > maxim)
			maxim = y;
		return maxim;
	}
	return 0;
}

int main()
{
	int input;
	int sum=0;
	int max=0;
	root = new Tree;
	cout<<"Enter a root value"<<endl;
	cin>>input;
	root->data=input;
	root->lchild=root->rchild=NULL;
 	createTree();
 	hgtCnt result;
 	result = heightnonRec(root);
 	TreeMax(root,max);
 	TreeSum(root,sum);
 	
 	cout<<"Height non rec is "<<result.height<<endl;
 	cout<<"count non rec is "<<result.count<<endl;
 	cout<<"Height rec is "<<height(root)<<endl;
 	cout<<"Total sum is "<<sum<<endl;
 	cout<<"total node value is"<<TotalNodeValue(root)<<endl;
 	cout<<"Total number of node is "<<countNodeRec(root)<<endl;
 	cout<<"Max node is "<<max<<endl;
 	cout<<"Max node exp val is "<<maxNodeValue(root)<<endl;
	return 0;
}