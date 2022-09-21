#include<iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node *right;
    bool leftThread=true;
    bool rightThread=true;
};


void insert(node *root, node *n)
{
    cout<<"Where to insert on l/r of"<<root->data;
    char c;
    cin>>c;
    if(c=='r')
    {
        if(root->right==NULL)
        {
            root->right=n;
            root->rightThread=false;
        }
        else
            insert(root->right,n);
    }
    else{
        if(root->left==NULL)
        {
            root->left=n;
            root->rightThread=false;
        }
        else
            insert(root->right,n);
    }
}

/*

node * search(node *root,int x)
{
    node * temp=root;
    while(!temp->rightThread && !temp->leftThread)
    {
        if(temp->data==x)
        {
            cout<<x<<" is present";
            return temp;
        }

        else if(temp->data>x)
            temp=temp->left;
        else
            temp=temp->right;
    }
    return NULL;
}
int InorderSucc(node * currentnode,node* root)
{

node* temp=currentnode->right;
if(!currentnode->rightThread)
while(!temp->leftThread)
temp=temp->left;
currentnode=temp;
if(currentnode==root)
return 0;
else
return currentnode->data;
}

*/
int main()
{
    node *root,*n;
    root=NULL;
    char ans;
    do{
        n=new node();
        cout<<"Enter integer";
        cin>>n->data;
        if(root==NULL)
            root=n;
        else
            insert(root,n);
        cout<<"Do you want to insert another element?";
        cin>>ans;
    }while(ans=='y');
    return 0;
}