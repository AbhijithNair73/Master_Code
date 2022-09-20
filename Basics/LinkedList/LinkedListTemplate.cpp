/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
template <class T>
class Node
{
    T var;
    Node * next;
public:
    Node(){
        next = nullptr;
        var = 0;
    }
    Node(T _var)
    {
        var = _var;
        next = nullptr;
    }
    T getVar() const {return var;}
    void setVar(T _var)
    {
        var = _var;
    }
    Node * getNext() const {return next;}
    void setNext(Node * temp)
    {
        next = temp;
    }
    ~Node(){}
    static Node<T>* createNode(Node<T>* root, T arg)
    {
        if(root == nullptr)
        {
            Node<T> * temp = new Node<T>(arg);
            root = temp;
            temp = NULL;
            return root;
        }
        Node<T>* local = root;
        while(local->getNext()!=nullptr)
        {
            local = local->getNext();
        }
        Node<T> * temp = new Node<T>(arg);
        local->setNext(temp);
        return root;
    }
    
    static void printNode(Node<T> * root)
    {
        Node<T> * temp = root;
        while(temp)
        {
            cout<<temp->getVar()<<endl;
            temp = temp->getNext();
        }
    }
};

// template <class T1>
// Node<T1>* createNode(Node<T1>* root, T1 arg)
// {
//     if(root == nullptr)
//     {
//         Node<T1> * temp = new Node<T1>(arg);
//         root = temp;
//         temp = NULL;
//         return root;
//     }
//     Node<T1>* local = root;
//     while(local->getNext()!=nullptr)
//     {
//         local = local->getNext();
//     }
//     Node<T1> * temp = new Node<T1>(arg);
//     local->setNext(temp);
//     return root;
// }

// template <class T1>
// void printNode(Node<T1> * root)
// {
//     Node<T1> * temp = root;
//     while(temp)
//     {
//         cout<<temp->getVar()<<endl;
//         temp = temp->getNext();
//     }
// }
    

int main()
{
    Node<char>* root = nullptr;
    // root = createNode<char>(root,'c');
    // root = createNode<char>(root,'d');
    // root = createNode<char>(root,'e');
    // root = createNode<char>(root,'f');
    
    root = Node<char>::createNode(root,'c');
    root = Node<char>::createNode(root,'d');
    root = Node<char>::createNode(root,'e');
    root = Node<char>::createNode(root,'f');
    Node<char>::printNode(root);
    
    return 0;
}