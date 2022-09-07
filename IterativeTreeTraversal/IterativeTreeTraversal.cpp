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
stack<Node*> hs;




struct Node* CreateNode(int);
struct Node* createTree(int);


void iterativeInorder(struct Node* );
void iterativePreorder(struct Node* );
void iterativePostorder(struct Node* );


//function definitions

void iterativeLevelOrder(struct Node* root)
{
    q.push(root);

    while (!q.empty())
    {
        if (root->lc)
            q.push(root->lc);
        if (root->rc)
            q.push(root->rc);

        cout << q.front()->data << " ";
        q.pop();
        if(!q.empty())root = q.front();
    }

}


void iterativePostorder(struct Node* root)
{ 
   
    while(root )
    {
        hs.push(root);
        if (root->lc)
            s.push(root->lc);
        if (root->rc)
            s.push(root->rc);
        if (!s.empty())
        {
            root = s.top();
            s.pop();
        }
        else
            root = NULL;
    }

    while (!hs.empty())
    {
        cout << hs.top()->data << " ";
        hs.pop();
    }

}

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
    cout << endl;
    iterativePostorder(T1root);
    cout << endl;
    iterativeLevelOrder(T1root);

}
