// IterativeTreeTraversal.cpp 
//iterative inorder and preorder tree traversal
//iterative procedure needs stack .


#include <iostream>
#include<stack>
#include<queue>

using namespace std;


struct Node
{
    int data;
    struct Node* lc;
    struct Node* rc;
}* T1root =NULL;

queue<Node*> q;
stack<Node*> s;


struct Node* CreateNode(int);
struct Node* createTree(int);

//function definitions



void iterativeInorder(struct Node* root)
{
    while (root || !s.empty())
    {
        if (root)
        {
            s.push(root);
            root = root->lc;
        }
        else
        {
            root = s.top();
            cout << root->data << " ";
            s.pop();
            root = root->rc;
        }
    }
}



void iterativePreorder(struct Node* root)
{

    while (root || !s.empty())
    {

        if (root)
        {
            cout << root->data << " ";
            s.push(root);
            root = root->lc;
        }
        else
        {
            root = s.top();
            s.pop();
            root = root->rc;

        }


    }


}



struct Node* CreateNode(int x)
{
    struct Node* p = new Node;
    p->data = x;
    p->lc = NULL;
    p->rc = NULL;

    return p;

}

struct Node* createTree(int x)
{
    

    struct Node* root = CreateNode(x);

    q.push(root);

    struct Node* p = NULL;

    while (!q.empty())
    {
        p = q.front();

        cout << "left child of " << p->data << " : ";
        cin >> x;
        if (x != -1)
        {
            p->lc = CreateNode(x);
            q.push(p->lc);
        }
        cout << "right child of " << p->data << " :";
        cin >> x;
        if (x != -1)
        {
            p->rc = CreateNode(x);
            q.push(p->rc);
        }
        q.pop();
    }

    return root;
}




int main()
{
    T1root = createTree(5);
    iterativeInorder(T1root);
    cout << endl;
    iterativePreorder(T1root);

}
