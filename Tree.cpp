#include <iostream> 
#include <stack>
#include <vector>
using namespace std;
class BTSnode
{
public:
    int data;
    BTSnode* left;
    BTSnode* right;
    BTSnode() {
        left = NULL;
        right = NULL;
    }
    BTSnode(int data)
    {
        BTSnode* Node = new BTSnode();
        Node->data = data;
    }

    int size(BTSnode* node)
    {
        if (node == NULL)
            return 0;
        else
            return(size(node->left) + 1 + size(node->right));
    }
    int leaf(BTSnode* node)
    {
        if (node == NULL)
            return (1);
        else
            return(leaf(node->left) + leaf(node->right));

    }
    int count(BTSnode* node)
    {
        if (node == NULL)
        {
            return (0);
        }
        if (node->data % 2 == 1)
        {
            return( leaf(node->left) +1+ leaf(node->right));
        }
        else
            return(leaf(node->left) + leaf(node->right));

    }
    int maxDepth(BTSnode* node)
    {
        if (node == NULL)
            return 0;
        else
        {
            int lDepth = maxDepth(node->left);
            int rDepth = maxDepth(node->right);

            if (lDepth > rDepth)
             return(lDepth + 1);
            else 
            return(rDepth + 1);
        }
    }
    void binTreeToVec(BTSnode* node,vector<int>&tree)
    {
        
            tree.push_back(node->data);
            return( binTreeToVec(node->left,tree) , binTreeToVec(node->right,tree));
        
    }




    ///////
    int findmax(BTSnode* node) 
    {
        if (node == NULL)
            return (0);
        else if (node->left == nullptr && node->right != nullptr)
        {
            int far1 = findmax(node->left);
            int far2 = findmax(node->right);

            far2 = node->data - node->right->data;

            return(far2);
        }
        else if (node->left != nullptr && node->right == nullptr)
        {
            int far1 = findmax(node->left);
            int far2 = findmax(node->right);

            far1 = node->data - node->left->data;

            return(far1);
        }
        else if (node->left == nullptr && node->right == nullptr)
        {
            return(0);
        }
        else
        {
            int far1 = findmax(node->left);
            int far2 = findmax(node->right);

            far1 = node->data - node->left->data;
            far2 = node->data - node->right->data;
            if (far1 > far2) {
                return(far1);
            }
            else
                return(far2);
        }
    }

    ////////
};
int main()
{
    vector<int> g1;
    BTSnode* root;
    root = new BTSnode(1);
    root->left = new BTSnode(2);
    root->right = new BTSnode(3);
    root->left->left = new BTSnode(4);
    root->left->right = new BTSnode(5);
    cout << "Size of the tree is " << root->size(root)<<endl;
    cout << "number of leaf is " << root->leaf(root) << endl;
    cout << " number of odds is " << root->count(root) << endl;
    cout << " Height is  " << root->maxDepth(root) << endl;
    cout << "  maximum difference is " << root->findmax(root) << endl;

    return 0;
}