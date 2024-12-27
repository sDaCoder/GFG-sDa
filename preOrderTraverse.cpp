// https://www.geeksforgeeks.org/problems/preorder-traversal/1
// https://www.geeksforgeeks.org/problems/inorder-traversal/1
// https://www.geeksforgeeks.org/problems/postorder-traversal/1
#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<stack>
#include<stdlib.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *left, *right;
    ListNode() : val(0), left(nullptr), right(nullptr) {}
    ListNode(int x) : val(x), left(nullptr), right(nullptr) {}
    ListNode(int x, ListNode *left) : val(x), left(left) {}
    ListNode(int x, ListNode *left, ListNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
    // Function to return a list containing the preorder traversal of the tree.
    void traverse(ListNode* root, vector<int>& ans)
    {
        if (root == nullptr) return;
        ans.push_back(root->val);
        traverse(root->left, ans);
        traverse(root->right, ans);
    }
    
    vector<int> preorder(ListNode* root) {
        // write code here
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }
};

ListNode *createTree()
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

    ListNode *temp = new ListNode(x);

    cout << "Enter the node left to " << x << "(-1 returns NULL): ";
    temp->left = createTree();

    cout << "Enter the node right to " << x << "(-1 returns NULL): ";
    temp->right = createTree();

    return temp;
}

int main(){
    system("cls");
    
    ListNode *root = nullptr;
    root = createTree();

    Solution S;

    vector<int> ans = S.preorder(root);
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";


    
    return 0;
}