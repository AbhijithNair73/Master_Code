#include<iostream>
#include<unordered_set>
#define MAX 3
using namespace std;
struct Node
{
	int data;
	struct Node * next;
};

struct NodeMatrix
{
	int data;
	NodeMatrix* right, *down;
	NodeMatrix(int n)
	{
		data=n;
		right=NULL;
		down=NULL;
	}
};

void createSingleLinkedList(struct Node *&head)
{
	int input=0;
	head=new struct Node;
	cout<<"Enter the value for 1st element"<<endl;
	cin>>input;
	head->data=input;
	head->next=NULL;
}

void addAtEnd(struct Node * head)
{
	char op='Y';
	int input =0;
	while(op=='Y' || op =='y')
	{
		while(head->next!=NULL)
		{
			head=head->next;				// traverse head till last element. In this case 
											// we are not modifying the head so just taken 
											// as a ptr in fn argument and just modifying the next of last node which is dynamic so no problem
		}
		struct Node * temp = new struct Node;
		cout<<"enter input value"<<endl;
		cin>>input;
		temp->data=input;
		temp->next=NULL;
		head->next=temp;
		cout<<"Do you want to add another node at end then press 'y' else 'n'"<<endl;
		cin>>op;
	}
}

void addAtBeginning(struct Node *&head)
{
	char op='Y';
	int input =0;
	while(op=='Y' || op =='y')
	{
		struct Node * temp = new struct Node;
		cout<<"enter input value"<<endl;
		cin>>input;
		temp->data=input;
		temp->next=head;
		head=temp;
		cout<<"Do you want to add another node at beginning then press 'y' else 'n'"<<endl;
		cin>>op;
	}
}

void insertNodeAtPosition(int position, struct Node *&head,int input)
{
	int count=0;
    Node * ptr=head;
    if(position == 0)
    {
        Node * temp = new Node;
        temp->data=input;
        temp->next=head;
        head=temp;
        return;
    }
    while(ptr->next!=NULL)
    {
        count++;
        if(count==position)
        {
            Node * temp = new Node;
            temp->data=input;
            temp->next=ptr->next;
            ptr->next=temp;
            break;
        }
        ptr=ptr->next;
    }
}


void printSingleLinkedList(struct Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data << "   "; 
        node = node->next; 
    }
    cout<<endl; 
} 

void printSingleLinkedListRecursion(struct Node* node) 
{ 
	if(node==NULL)
		return;
    cout << node->data << "   "; 
    printSingleLinkedListRecursion(node->next);
} 

void reversePrintSingleLinkedListRecursion(struct Node* node) 
{ 
	if(node==NULL)
		return;
    reversePrintSingleLinkedListRecursion(node->next);
    cout << node->data << "   "; 
} 

void reverseLink(struct Node *& head)
{
	Node * prev = head;
	Node * current = head;
	Node * next = head;
	if(current -> next == NULL)
		return;
	while (next != NULL)
	{
		prev = current;
		current = next;
		next = current -> next;
		current -> next = prev;
	}
	head -> next = NULL;
	head = current;
}

int getCount(struct Node* head)
{
    int count=0;
    while(head)
    {
        head=head->next;
        count++;
    }
    return count;
}

bool deleteNodewithoutHead(Node* node_ptr) 
{ 
    // If the node to be deleted is the  
    // last node of linked list 
    if (node_ptr->next == NULL) 
    { 
        delete node_ptr; 
        // this will simply make the node_ptr NULL. 
        return false; 
    } 
      
    // if node to be deleted is the first or  
    // any node in between the linked list. 
    Node* temp = node_ptr->next; 
    node_ptr->data = temp->data; 
    node_ptr->next = temp->next; 
    delete temp; 
    return true;
} 

// Function to remove duplicates from the linked list
// root: root of the linked list
Node * removeDuplicates( Node *start) 
{
 // Hash to store seen values 
    unordered_set<int> seen; 
    bool notlastnode = false;
    /* Pick elements one by one */
    struct Node *curr = start; 
    struct Node *prev;
    while (curr != NULL) 
    { 
        // If current value is seen before 
        if (seen.find(curr->data) != seen.end()) 
        { 
           notlastnode = deleteNodewithoutHead(curr);
           if(!notlastnode)
           {
               prev->next=NULL;
               //cout<<"last node"<<endl;
                break;
           }
        } 
        else
        { 
           seen.insert(curr->data); 
           if(curr->next!=NULL)
           {
               prev=curr;
                curr=curr->next;
           }
           else
            break;
        } 
    } 
    return start;
}

Node* Merge(Node* head_A, Node* head_B)  
{  
   Node * head = head_A;
   while(head_A -> next != NULL)
   {
       head_A = head_A->next;
   }
   head_A -> next = head_B;
   return head;
}  

Node *rearrangeEvenOdd(Node *head)
{
    if(head == NULL)
    {
        return head;
    }
    Node * odd=head;
    Node * even=head->next;
    Node * mergepoint=head->next;
    if(even==NULL)
        return head;
    while(even->next!=NULL)
    {
        odd->next = even->next;
        odd=odd->next;
        even->next=odd->next;
        if(even->next!=NULL)
        even=even->next;
    }
    odd->next=mergepoint;
    return head;
}

int intersectPoint(Node* head1, Node* head2)
{
	 //Take two pointers for the heads of both the linked lists.
	//If one of them reaches the end earlier then use it by moving it to the beginning of the other list.
	// Once both of them go through reassigning they will be equidistance from the collision point.


	//https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/
    int count1=getCount(head1);
	int count2=getCount(head2);
	int count3=count1-count2;
	Node* ptr=head1;
	Node* ptr1=head2;
	if(count3 < 0)
	{
	    count3=-count3;
	    ptr=head2;
	    ptr1=head1;
	}
	count1=0;
	if(count3)
	{
	    while(count1!=count3)
	    {
	        count1++;
	        ptr=ptr->next;
	    }
	}
	while(ptr!=ptr1)
	{
	    ptr=ptr->next;
	    ptr1=ptr1->next;
	}
	return ptr->data;
}

bool has_cycle(Node* head) 
{
	// Floyd’s Cycle detection 
    Node* slowptr=head;
    Node* fastptr=head;
    while(slowptr!=NULL && fastptr!=NULL)
    {
        slowptr=slowptr->next;
        fastptr=fastptr->next;
        if(fastptr==NULL)
            return false;
        fastptr=fastptr->next;
        if(slowptr == fastptr)
            return true;
    }
    return false;

//This method is also dependent on Floyd’s Cycle detection algorithm.
/*
removing Loop important 

1. Detect Loop using Floyd’s Cycle detection algorithm and get the pointer to a loop node.
2. Count the number of nodes in loop. Let the count be k.
3. Fix one pointer to the head and another to a kth node from the head.
4. Move both pointers at the same pace, they will meet at loop starting node.
5. Get a pointer to the last node of the loop and make next of it as NULL.

*/

}

NodeMatrix* constructLinkedMatrix(int mat[MAX][MAX], int n)
{
    int i=0,j=0;
    NodeMatrix * ptr=NULL;
    NodeMatrix * head[n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
              
            NodeMatrix * temp = new NodeMatrix(mat[i][j]);
            if(j==0)
            {
                head[i]=temp;
                continue;
            }
            ptr=head[i];
            while(ptr->right!=NULL)
            {
                ptr=ptr->right;
            }
            ptr->right=temp;
        }
    }
    ptr=nullptr;
    for(i=0;i<n-1;i++)
    {
        ptr=head[i];
        NodeMatrix*tempo = head[i+1];
        while(ptr!=NULL)
        {
            ptr->down=tempo;
            ptr=ptr->right;
            tempo=tempo->right;
        }
    }
    return head[0];
}

int main()
{
	Node * root = nullptr;
	createSingleLinkedList(root);
	addAtEnd(root);
	//addAtBeginning(root);
	printSingleLinkedListRecursion(root);
	cout <<endl;
	/*insertNodeAtPosition(0,root,25);
	insertNodeAtPosition(1,root,5);
	insertNodeAtPosition(5,root,15);
	*/
	reversePrintSingleLinkedListRecursion(root);
	cout <<endl;
	cout<<endl<<"Reverse link: "<<endl;
	reverseLink(root);
	printSingleLinkedListRecursion(root);
	cout <<endl;
	int Darr[3][3]={1,2,3,4,5,6,7,8,9};
	NodeMatrix * ret;
	ret=constructLinkedMatrix(Darr,3);
	return 0;
}