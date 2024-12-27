#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<stack>
#include<stdlib.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left) : val(x), left(left), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

Node *createTree()
{
    int x;
    static bool first = true;
    
    if (first)
    {
        first = false;
        cout << "Enter the value of the node(-1 returns NULL): ";
    }

    cin >> x;
    if(x == -1) return nullptr;

    Node *temp = new Node(x);

    cout << "Enter the node left to " << x << "(-1 returns NULL): ";
    temp->left = createTree();

    cout << "Enter the node right to " << x << "(-1 returns NULL): ";
    temp->right = createTree();

    return temp;
}

void Leaves(Node *root, int &count)
{
    if(root == nullptr) return;

    if(!root->left && !root->right) count++;
    Leaves(root->left, count);
    Leaves(root->right, count);
}

void nonLeaves(Node *root, int &count)
{
    if(root == nullptr) return;

    if(root->left || root->right) count++;
    nonLeaves(root->left, count);
    nonLeaves(root->right, count);
}

int main(){
    system("cls");

    Node *root = nullptr;
    root = createTree();

    int countL = 0, countNL = 0;
    Leaves(root, countL);
    nonLeaves(root, countNL);
    cout << "Leaf nodes: " << countL << endl;
    cout << "Non-leaf nodes: " << countNL << endl;
    
    return 0;
}