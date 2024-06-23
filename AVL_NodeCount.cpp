///////////////////////Counting nodes while inserting like an AVL tree
#include<iostream>
using namespace std;
template <typename k, typename v>
class tree;
template <typename k, typename v>
class tnode
{
    k key;
    v value;
    int nodecount=0;
    tnode<k, v>* left, * right;
    friend class tree<k,v>;
};
template <typename k, typename v>
class tree
{
    tnode<k, v>* root =new tnode<k,v>;


    int getNodeCount(tnode<k, v>* node)
    {
        if (node != nullptr)
        {
            return node->nodecount;
        }
        else
        {
            return 0;
        }
    }
    void insert(tnode<k, v>*& r, tnode<k, v>* n)
    {
        if (r == nullptr)
        {
            r = n;
            r->nodecount++;
        }
        else if (r->left != nullptr && r->right != nullptr)
        {
            if (r->left->nodecount <= r->right->nodecount)
            {
                insert(r->left, n);
            }
            else if (r->left->nodecount > r->right->nodecount)
            {
                insert(r->right, n);
            }
        }

        else if (r->right == nullptr)
            insert(r->right, n);
        else if (r->left == nullptr)
            insert(r->left, n);

        r->nodecount = getNodeCount(r->left) + getNodeCount(r->right) + 1;
    }
public:


    tree()
    {
        root = nullptr;
    }
    void insert(k key, v value)
    {
        tnode<k, v>* n=new tnode<k,v> ;
        n->key = key;
        n->value = value;
        n->nodecount = 0;
        n->left = nullptr;
        n->right = nullptr;
        insert(root, n);
    }
    int getNodeCount()
    {
        return root->nodecount;
    }
};
int main()
{
    tree<int, int> t;
    t.insert(10, 14);
    t.insert(11, 12);
    t.insert(12, 16);
    t.insert(13, 10);
    cout << t.getNodeCount();
}