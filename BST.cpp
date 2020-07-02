#include <iostream>

using namespace std;

class Btree
{
    private:
        Btree* left;
        Btree* right;
        int value;
    public:
        Btree()
        {}
        void insert(Btree*&, int);
};

void Btree::insert(Btree*& root, int value)
{
    if(root == nullptr)
    {
        root = new Btree();
        root->value = value;
    }
    else
    {
        if(value < root->value)
            insert(root->left, value);
        if(value > root->value)
            insert(root->right, value);
    }
}


int main()
{
    Btree* root = nullptr;
    Btree tree;

    tree.insert(root, 15);
    tree.insert(root, 10);
    tree.insert(root, 20);


    return 0;
}
