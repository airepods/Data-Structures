#include <iostream>
#include <string>
#include <vector>

using namespace std;

static bool flag = false;

bool is_operator(string c)
{
    if(c == "+" || c == "-" || c == "*" || c == "/")
        return true;
    else
        return false;
}

class Btree
{
    private:
        Btree* left;
        Btree* right;
        string value;
    public:
        Btree()
        {}
        void insert(Btree*&, string);
        void postOrder(Btree*);
};

void Btree::insert(Btree*& root, string value)
{   
    if(root == nullptr)
    {
        root = new Btree();
        root->value = value;
        flag = true;
        return;
    }
    else
    {
        if(is_operator(root->value))
        {
            insert(root->right, value);
            if(flag)
                return;

            insert(root->left, value);
        }
        
        if(!is_operator(root->value))
            return;
    }
}

void Btree::postOrder(Btree* root)
{
    if(root->left == nullptr && root->right == nullptr)
    {
        cout<<root->value<<" ";
        return;
    }
    if(root->left != nullptr)
        postOrder(root->left);
    if(root->right != nullptr)
        postOrder(root->right);
    cout<<root->value<<" ";
}


int main()
{
    Btree* root = nullptr;
    Btree tree;

    string c;
    vector<string> expression;

    cout<<"Enter an expression in postfix form"<<endl;

    cin>>c;
    expression.push_back(c);
    while(c != ">")
    {
        cin>>c;
        if(c == " " || c == ">")
            continue;
        expression.push_back(c);
    }

    for(auto i = expression.rbegin(); i != expression.rend(); ++i)
    {
        if(*i == " ")
            continue;
        tree.insert(root, *i);
        flag = false;
    }

    tree.postOrder(root);

    /*tree.insert(root, '+');
    flag = false;
    tree.insert(root, '/');
    flag = false;
    tree.insert(root, '8');
    flag = false;
    tree.insert(root, '3');
    flag = false;
    tree.insert(root, '*');
    flag = false;
    tree.insert(root, '6');
    flag = false;
    tree.insert(root, '2');

    tree.postOrder(root);*/


    return 0;
}