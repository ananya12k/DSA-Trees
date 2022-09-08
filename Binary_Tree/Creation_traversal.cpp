#include <iostream>
#include <queue>
using namespace std;
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
void Level_order(TreeNode *root)
{
    if (root == NULL)
    {
        // cout << "Tree is empty" << endl;
        return;
    }
    queue<TreeNode *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        TreeNode *temp = Q.front();
        cout << temp->data;
        if (temp->left != NULL)
        {
            Q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            Q.push(temp->right);
        }
        Q.pop();
    }
}
void Inorder(TreeNode *root)
{
    if (root == NULL)
    {
        // cout << "Tree is empty" << endl;
        return;
    }
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
void Preorder(TreeNode *root)
{
    if (root == NULL)
    {
        // cout << "Tree is empty" << endl;
        return;
    }
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}
void Postorder(TreeNode *root)
{
    if (root == NULL)
    {
        // cout << "Tree is empty" << endl;
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}
void insertion(TreeNode *root, TreeNode *newnode)
{
    char option;
    cout << "Enter where do you want to insert Left or Right of " << root->data << endl;
    cin >> option;
    if (option == 'r')
    {
        if (root->right == NULL)
        {
            root->right = newnode;
        }
        else
        {
            insertion(root->right, newnode);
        }
    }
    else
    {
        if (root->left == NULL)
        {
            root->left = newnode;
        }
        else
        {
            insertion(root->left, newnode);
        }
    }
}
TreeNode *get_node()
{
    TreeNode *temp;
    temp = new TreeNode;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
int main()
{
    TreeNode *newnode, *root;
    root = NULL;
    char option;

    do
    {
        newnode = get_node();
        cout << "Enter the number that you want to insert " << endl;
        int x;
        cin >> x;
        newnode->data = x;
        if (root == NULL)

            root = newnode;
        else
            insertion(root, newnode);

        cout << "Do you want to enter element ? ";
        cin >> option;
    } while (option == 'y');
    cout << "Inorder Traversal" << endl;
    Inorder(root);
    cout << "\nPreorder Traversal" << endl;
    Preorder(root);
    cout << "\nPostorder Traversal" << endl;
    Postorder(root);
    return 0;
}