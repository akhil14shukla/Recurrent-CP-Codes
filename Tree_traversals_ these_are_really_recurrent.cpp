#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, n) for (int i = 0; i < n; i++)

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int level_order(TreeNode *root)
{
    queue<TreeNode *> q1, q2;
    q1.push(root);
    int sum = 0;
    int flag = 1;
    while (!q1.empty() || !q2.empty())      // Level Order traversal of binary tree
    {
        if (flag)
        {
            while (!q1.empty())
            {
                int curr = q1.front()->val;
                temp += 10 * sum + curr;
                if (q1.front()->left != NULL)
                {
                    q2.push(q1.front()->left);
                }
                if (q1.front()->right != NULL)
                {
                    q2.push(q1.front()->right);
                }
                q1.pop();
            }
        }
        else
        {
            while (!q2.empty())
            {
                int curr = q2.front()->val;
                temp += 10 * sum + curr;
                if (q2.front()->left != NULL)
                {
                    q1.push(q2.front()->left);
                }
                if (q2.front()->right != NULL)
                {
                    q1.push(q2.front()->right);
                }
                q2.pop();
            }
        }
        flag = !flag;
    }
    return sum
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}