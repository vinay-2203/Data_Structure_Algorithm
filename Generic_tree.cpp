#include <iostream>
using namespace std;
#include <queue>
#include "tree.h"
#This fucntion is used to print the childnode with parentsnode
void printTree(Treenode<int> *root)
{
    cout << root->data << " : ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << " ";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

#This function is used to takeinput levelwise
Treenode<int> *takeinputlevelwise()
{
    int rootdata;
    cout << "Enter root data : " << endl;
    cin >> rootdata;
    Treenode<int> *root = new Treenode<int>(rootdata);
    queue<Treenode<int> *> pendingnodes;
    pendingnodes.push(root);
    while (pendingnodes.size() != 0)
    {
        Treenode<int> *front = pendingnodes.front();
        pendingnodes.pop();
        cout << "Enter the number of children of " << front->data << endl;
        int children;
        cin >> children;
        for (int i = 0; i < children; i++)
        {
            int childdata;
            cout << "Enter  the " << i << "th child of " << front->data << endl;
            cin >> childdata;
            Treenode<int> *child = new Treenode<int>(childdata);
            front->children.push_back(child);
            pendingnodes.push(child);
        }
    }
    return root;
}

#Ths function is used to print tree levelwise
void printTreelevelwise(Treenode<int> *root)
{
    queue<Treenode<int> *> pendingnodes;
    pendingnodes.push(root);
    Treenode<int> *front = pendingnodes.front();
    while (pendingnodes.size() != 0)
    {
        cout << front->data << " : ";
        int t = 0;
        int n = front->children.size();
        for (int j = 0; j < front->children.size(); j++)
        {
            pendingnodes.push(front->children[j]);
            cout << front->children[j]->data;
            if (j < front->children.size() - 1)
            {
                cout << ",";
            }
            t++;
        }
        pendingnodes.pop();
        front = pendingnodes.front();
        if (t == n)
        {
            cout << endl;
        }
    }
}

#This function is used to count the nodes

int countnodes(Treenode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += countnodes(root->children[i]);
    }
    return ans;
}

#This function is used to sum of all nodes value
int sumofnodes(Treenode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += sumofnodes(root->children[i]);
    }
    return ans;
}

#This function is used to return the max value in all node
int maxnodevalue(Treenode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int mx = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        mx = max(mx, maxnodevalue(root->children[i]));
    }
    return mx;
}

#This function is used to find node which has maximum value
Treenode<int> *maxnode(Treenode<int> *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    Treenode<int> *mx = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        Treenode<int>*newnode = maxnode(root->children[i]);
        if(mx->data < newnode->data && newnode != NULL){
            mx  = newnode;
        }
        maxnode(root->children[i]);
    }
    return mx;
}

#This functin is used to find the height of tree
int height(Treenode<int> *root)
{
    int ans1 = 1;
    int  h = 0;
    for(int i = 0; i < root->children.size();i++)
    {
        ans1 += height(root->children[i]);
        h = (ans1,height(root->children[i]));

    }
    return h;
}

int main()
{
    Treenode<int> *root = takeinputlevelwise();
    printTree(root);
    printTreelevelwise(root);
    int nodes = countnodes(root);
    cout << "Nodes : " << nodes << endl;
    int sum = sumofnodes(root);
    cout << "Sum of nodes : " << sum << endl;
    int maxvalue = maxnodevalue(root);
    cout << "Maximum Value : " << maxvalue << endl;
    Treenode<int> *mxnode = maxnode(root);
    cout << "Maxnode value : " << mxnode->data << endl;
    int h = height(root);
    cout << h << endl;
    return 0;
}
