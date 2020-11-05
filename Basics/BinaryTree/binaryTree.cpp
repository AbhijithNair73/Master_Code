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

void preOrderPrintingRec(Tree * p)
{
	if(p)
	{
		cout<<"Data: "<<p->data<<endl;
		preOrderPrintingRec(p->lchild);
		preOrderPrintingRec(p->rchild);
	}
	return;
}

void inOrderPrintingRec(Tree * p)
{
	if(p)
	{
		inOrderPrintingRec(p->lchild);
		cout<<"Data: "<<p->data<<endl;
		inOrderPrintingRec(p->rchild);
	}
	return;
}

void postOrderPrintingRec(Tree * p)
{
	if(p)
	{
		postOrderPrintingRec(p->lchild);
		postOrderPrintingRec(p->rchild);
		cout<<"Data: "<<p->data<<endl;
	}
	return;
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
 	cout<<"---------preOrder------------"<<endl;
 	preOrderPrintingRec(root);
 	cout<<"---------postOrder------------"<<endl;
 	postOrderPrintingRec(root);
 	cout<<"---------InOrder------------"<<endl;
 	inOrderPrintingRec(root);
 	cout<<"---------LevelOrder------------"<<endl;
	return 0;
}