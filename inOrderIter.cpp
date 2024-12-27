#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<stack>
#include<queue>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node *createTree(vector<int>& nodes)
{
    if(nodes.size() == 0 || nodes[0] == -1) return nullptr;

    Node *root = new Node;
    root->data = nodes[0];
    root->left = nullptr;
    root->right = nullptr;

    queue<Node *> Q;
    Q.push(root);
    int i = 1;

    while (i < nodes.size() && !Q.empty())
    {
        Node *temp = Q.front();
        Q.pop();

        if(i < nodes.size() && nodes[i] != -1)
        {
            temp->left = new Node;
            temp->left->data = nodes[i];
            Q.push(temp->left);
        }
        i++;

        if(i < nodes.size() && nodes[i] != -1)
        {
            temp->right = new Node;
            temp->right->data = nodes[i];
            Q.push(temp->right);
        }
        i++;
    }
    return root;
}

void inOrder(Node *root)
{
    if(!root) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

class Solution {
public:
    vector<int> inOrder(Node* root)
    {
        vector<int> ans;

        while (root)
        {
            if (!root->left) // Left Subtree DNE
            {
                ans.push_back(root->data);
                root = root->right;
            }
            
            else // Left Subtree Exists
            {
                Node *curr = root->left;

                while (curr->right && curr->right != root)
                {
                    curr = curr->right; // Moving to the rightmost pointer
                }
                
                if (!curr->right) // Link DNE
                {
                    curr->right = root;
                    root = root->left;
                }
                
                else // Link exists
                {
                    curr->right = nullptr;
                    ans.push_back(root->data);
                    root = root->right;
                }
            }
        }
        return ans;
    }
};

int main(){
    
    vector<int> n2 = {1, 2, 3, 4, 5};
    Node *root = createTree(n2);

    inOrder(root);
    cout << endl;

    Solution S;
    vector<int> ans = S.inOrder(root);
    for(auto i = ans.begin(); i != ans.end(); i++)
        cout << *i << " ";

    cout << endl;

    return 0;
}