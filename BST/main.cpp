#include "/Users/swassow/Downloads/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
#define ll long long
vi ara;
struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* root=NULL;
Node* GetNewNode(int data)
{
    Node* NewNode=new Node();
    NewNode->data=data;
    NewNode->left=NewNode->right=NULL;
    return NewNode;
}
Node* insert(Node* root,int data)
{
    if(root==NULL)
        root=GetNewNode(data);
    else if(data<=root->data)
        root->left=insert(root->left, data);
    else
        root->right=insert(root->right, data);
    return root;
}
bool Search(Node* root,int data)
{
    if(root==NULL)
        return false;
    else if (root->data==data)
        return true;
    else if(data<=root->data)
        return Search(root->left,data);
    else
        return Search(root->right, data);
}
int findMin(Node* root)
{
    if(root==NULL)
    {
        cout<<"Tree is empty!";
        return -1;
    }
    else if(root->left==NULL)
        return root->data;
    return findMin(root->left);
}
int findMax(Node* root)
{
    if(root==NULL)
    {
        cout<<"Tree is empty!";
        return -1;
    }
    else if(root->right==NULL)
        return root->data;
    return findMax(root->right);
}
int findHeight(Node* root)
{
    if(root==NULL)
        return -1;
    return max(findHeight(root->left),findHeight(root->right))+1;
}
void bfs(Node *root)
{
    queue<Node*> Q;
    if(root==NULL)
        return;
    Q.push(root);
    while (!Q.empty()) {
        Node* crr=Q.front();
        Q.pop();
        cout<<crr->data<<" ";
        if(crr->left!=NULL)
        Q.push(crr->left);
        if(crr->right!=NULL)
        Q.push(crr->right);
    }
    cout<<endl;
}
void preOrder(Node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node* root)
{
    ara.clear();
    if(root==NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    ara.pb(root->data);
    inOrder(root->right);
}
void postOrder(Node* root)
{
    if(root==NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
bool isBST(Node* root)
{
    inOrder(root);
    for(int i=1;i<ara.size();i++)
    {
        if(ara[i]<ara[i-1])
            return false;
    }
    return true;
    
}
int main()
{
    root=insert(root,10);
    root=insert(root,11);
    root=insert(root,12);
    root=insert(root,9);
    root=insert(root,8);
    root=insert(root,7);
    root=insert(root,6);
    if(Search(root,9)==true)
        cout<<"Found!"<<endl;
    else
        cout<<"Not Found!"<<endl;
    cout<<findMin(root)<<endl;
    cout<<findMax(root)<<endl;
    cout<<findHeight(root)<<endl;
    bfs(root);
    inOrder(root);
    cout<<endl;
    if(isBST(root))
        cout<<"Yes!"<<endl;
    else
        cout<<"No!"<<endl;
    
}
