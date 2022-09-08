#include <iostream>
using namespace std;
class TreeNode
{
private:
    int data;
    TreeNode *left;
    TreeNode *right;

public:
    friend class Tree;
    TreeNode()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
};
class Tree
{
private:
    TreeNode *root;

public:
    Tree();
    void insertion(TreeNode *Root, TreeNode *newnode)
    {
        root=Root;
        newnode = new TreeNode();
        cout << "Enter the number that you want to insert" << endl;
        int x;
        cin >> x;
        newnode->data = x;
        char option;
        cout << "Enter where do you want to insert TreeNode. Left or Right" << endl;
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
};

Tree::Tree()
{
    root = NULL;
}

int main()
{
    Tree T1;
    TreeNode *Root, *newnode;

    cout << "Do you want to insert elements? " << endl;
    char option;
    cin >> option;
    if (option == 'y')
    {
        cout << "How many elements do you want to insert ?" << endl;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            T1.insertion(Root, newnode);
        }
    }

    return 0;
}