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

void postOrder(Node *root)
{
    if(!root) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

class Solution{
    public:
    vector<int> postOrder(Node* root) 
    {
        vector<int> ans;

        while (root)
        {
            if (!root->right) // Right DNE
            {
                ans.push_back(root->data);
                root = root->left;
            }
            
            else // Right Exists
            {
                Node *curr = root->right;
                while(curr->left && curr->left != root) curr = curr->left;

                if (!curr->left) // Link DNE
                {
                    ans.push_back(root->data);
                    curr->left = root;
                    root = root->right;
                }
                
                else // Link Exists
                {
                    curr->left = nullptr;
                    root = root->left;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    vector<int> nodes = {1, 2, 3, -1, -1, 4, 5};
    Node *root = createTree(nodes);

    postOrder(root);
    cout << endl;

    Solution S;
    vector<int> ans = S.postOrder(root);
    for(auto i = ans.begin(); i != ans.end(); i++) cout << *i << " ";
    cout << endl;

    return 0;
}