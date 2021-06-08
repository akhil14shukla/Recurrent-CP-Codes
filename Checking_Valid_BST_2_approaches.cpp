#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, n) for (int i = 0; i < n; i++)

// * Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

pair<pair<int, int>, bool> rec(TreeNode *root)          //using recursion
{
    int r1 = root->val, l1 = root->val;
    bool b1 = true;
    if (root->left != NULL)
    {
        pair<pair<int, int>, bool> l = rec(root->left);
        l1 = (l.first.first);
        b1 = b1 && l.second && root->val > root->left->val && root->val > l.first.second;
    }
    if (root->right != NULL)
    {
        pair<pair<int, int>, bool> r = rec(root->right);
        r1 = (r.first.second);
        b1 = b1 && r.second && root->val < root->right->val && root->val < r.first.first;
    }
    return {{l1, r1}, b1};
}

bool isValidBST(TreeNode *root)
{
    vector<int> pre;
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty())          //by checking the preorder, using loop
    {
        // pre.push_back(s.top()->val);
        TreeNode *curr = s.top();
        if (curr->left == NULL && curr->right == NULL)
        {
            pre.push_back(curr->val);
            s.pop();
            continue;
        }
        s.pop();
        if (curr->right != NULL)
        {
            s.push(curr->right);
        }
        TreeNode *t = new TreeNode(curr->val);
        s.push(t);
        if (curr->left != NULL)
        {
            s.push(curr->left);
        }
    }
    for (int i = 1; i < pre.size(); i++)
    {
        if (pre[i] <= pre[i - 1])
        {
            return false;
        }
    }
    return true; //rec(root).second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
