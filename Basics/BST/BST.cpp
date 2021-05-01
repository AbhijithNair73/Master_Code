#include<iostream>
using namespace std;
struct Btree
{
	int data;
	Btree * lchild;
	Btree * rchild;
};

Btree * globalroot=nullptr;

void Insert(Btree * &root,int key)
{
	Btree * p = root;
	Btree * q = nullptr;

	if(root == nullptr)
	{
		root = new(Btree);
		root->data = key;
		root -> lchild = root -> rchild = nullptr;
		return;
	}
	else
	{
		while(p != nullptr)
		{
			q=p;
			if(p->data == key)
			{
				cout<<"Error data already present in tree"<<endl;
				return;
			}
			else if(key > p->data)
			{
				p=p->rchild;
			}
			else
			{
				p=p->lchild;
			}
		}
		Btree * newtree = new Btree;
		newtree->data = key;
		newtree->lchild = newtree->rchild = nullptr;
		if(key > q->data)
		{
			q->rchild = newtree;
		}
		else
		{
			q->lchild = newtree;
		}

	}
}

void Inorder( Btree * localRoot)
{
	if(localRoot)
	{
		Inorder(localRoot -> lchild);
		cout<<" "<< localRoot->data << " ";
		Inorder(localRoot -> rchild);
	}
	return;
}

Btree * RSearch(Btree* root , int key)
{
	Btree * p = root;
	if(p==nullptr)
	{
		return nullptr;
	}
	if(p->data == key)
	{
		return p;
	}
	else if(key > p->data)
	{
		return RSearch(p->rchild,key);
	}
	else
	{
		return RSearch(p->lchild,key);
	}
}

bool isLeafNode(Btree * Node)
{
	return (Node->lchild == nullptr && Node->rchild == nullptr);
}

int RcountNodes(Btree * Node)
{
	int x,y;
	if(Node != nullptr)
	{
		x = RcountNodes(Node -> lchild);
		y = RcountNodes(Node -> rchild);
		return x+y+1;
	} 
	else
		return 0;
}

int RSumofallNodes(Btree * Node)
{
	int x,y;
	if(Node != nullptr)
	{
		x = RSumofallNodes(Node -> lchild);
		y = RSumofallNodes(Node -> rchild);
		return x+y+Node->data;
	} 
	else
		return 0;
}

int RcountLeafNodes(Btree * Node)
{
	int x,y;
	if(Node != nullptr)
	{
		x = RcountLeafNodes(Node -> lchild);
		y = RcountLeafNodes(Node -> rchild);
		if(Node -> lchild ==nullptr && Node -> rchild ==nullptr)
			return x+y+1;
		else
			return x+y;
	} 
	else
		return 0;
}

int Rheight(Btree * Node)
{
	int x,y;
	if(Node != nullptr)
	{
		x = Rheight(Node -> lchild);
		y = Rheight(Node -> rchild);
		if(x>y)
			return x+1;
		else
			return y+1;
	} 
	else
		return 0;
}

Btree * inpreOrder(Btree * leftchild)
{
	while(leftchild && leftchild->rchild != nullptr)
	{
		leftchild=leftchild->rchild;
	}
	return leftchild;
}

Btree * insubOrder(Btree * rightchild)
{
	while(rightchild && rightchild->lchild != nullptr)
	{
		rightchild=rightchild->lchild;
	}
	return rightchild;
}

Btree * minValueNode(Btree* node)
{
    Btree * current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->lchild != NULL)
        current = current->lchild;
 
    return current;
}

Btree * deleteNode(Btree * root, int key)
{
	if (root == nullptr)
	{
        return root;
	}
	if(root->lchild == nullptr && root->rchild==nullptr)
	{
		if(root == globalroot)
			globalroot == nullptr;
		delete root;
		return NULL;
	}
	if(key < root->data)
	{
		root->lchild=deleteNode(root->lchild,key);
	}
	else if(key > root->data)
	{
		root->rchild=deleteNode(root->rchild,key);
	}
	else
	{
		if (Rheight(root->lchild) > Rheight(root->rchild))
        {
        	Btree *temp = inpreOrder(root->lchild);
        	root->data = temp->data;
        	root->lchild = deleteNode(root->lchild,temp->data);
		}
		else
		{
			Btree *temp = insubOrder(root->rchild);
        	root->data = temp->data;
        	root->rchild = deleteNode(root->rchild,temp->data);
		}
	}
	return root;
}

int main()
{
	Btree * root = nullptr;
	Insert(root, 10);
	globalroot = root;
	Insert(root, 40);
	Insert(root, 30);
	Insert(root, 90);
	Insert(root, 70);
	Insert(root, 25);
	//Insert(root, 10);
	Inorder(root);
	Btree * found = RSearch(root, 90);
	if(found)
		cout<<"Found data = "<<found->data<<endl;
	else
		cout<<"Not found"<<endl;
	deleteNode(root,10);
	cout << " Root " << root << "  Globalroot "<<globalroot<<endl;
	Inorder(root);
	return 0;
}