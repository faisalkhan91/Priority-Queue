#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

template<class ItemType>
struct TreeNode
{
    ItemType info;
    TreeNode * left;
    TreeNode * right;
};

template<class ItemType>
class BinarySearchTree
{
    private:
        TreeNode<ItemType> * root;
        void InsertNode(ItemType info, TreeNode<ItemType> *node);
        ItemType DequeueTree(TreeNode<ItemType> * node, TreeNode<ItemType> *parent);
        void DeleteBinarySearchTree(TreeNode<ItemType> *node);
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        void InsertNode(ItemType info);
        ItemType DequeueTree();
        void DeleteBinarySearchTree();
        void MakeEmpty()
        {
            root=NULL;
        }
        bool IsEmpty();
        //displaying the elements
        void Print();
        void TreePrint(TreeNode<ItemType> *root);
};

template<class ItemType>
void BinarySearchTree<ItemType>::Print()
{
    if(root!=NULL)
    {
        cout << "Printing Tree: " << endl;
        TreePrint(root);
    }
    else
    {
        cout << "End of Queue!" <<endl;
    }
}

template<class ItemType>
void BinarySearchTree<ItemType>::TreePrint(TreeNode<ItemType> *root)
{
    if (root != NULL)
    {
        TreePrint(root->right);
        cout<<root->info<<endl;
        TreePrint(root->left);
    }
}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
{
    root = NULL;
}

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
    DeleteBinarySearchTree();
}

template<class ItemType>
void BinarySearchTree<ItemType>::DeleteBinarySearchTree()
{
    DeleteBinarySearchTree(root);
}

template<class ItemType>
void BinarySearchTree<ItemType>::DeleteBinarySearchTree(TreeNode<ItemType> * node)
{
    if(node != NULL)
    {
        DeleteBinarySearchTree(node->left);
        DeleteBinarySearchTree(node->right);
        delete node;
    }
}

template<class ItemType>
void BinarySearchTree<ItemType>::InsertNode(ItemType info)
{
    if(root != NULL)
    {
        InsertNode(info,root);
    }
    else
    {
        root=new  TreeNode<ItemType>;
        root->info=info;
        root->left=NULL;
        root->right=NULL;
    }
}

//inserting element into the tree
template<class ItemType>
void BinarySearchTree<ItemType>::InsertNode(ItemType info, TreeNode<ItemType> * node)
{

    if(info < node->info)
    {
        if(node->left != NULL)
        {
            InsertNode(info, node->left);
        }
        else
        {
            node->left =new TreeNode<ItemType> ;
            node->left->info=info;
            node->left->left=NULL;
            node->left->right=NULL;
        }
    }
    else
    {
        if(node->right != NULL)
        {
            InsertNode(info, node->right);
        }
        else
        {
            node->right = new TreeNode<ItemType>;
            node->right->info=info;
            node->right->left=NULL;
            node->right->right=NULL;
        }
    }
}
//Removing the element with the highest priority
template<class ItemType>
ItemType BinarySearchTree<ItemType>::DequeueTree()
{
    ItemType info;
    if(root != NULL)
    {
        if(root->right != NULL)
        {
            info = DequeueTree(root->right, root);
        }
        else
        {
            info = root->info;
            if(root->left != NULL)
            {
                TreeNode <ItemType>* temp = root;
                root = root->left;
                delete temp;
            }
            else
            {
                delete root;
                root = NULL;
            }
        }
    }
    else
    {
        info = -1;
    }
    return info;
}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::DequeueTree(TreeNode<ItemType> *node, TreeNode<ItemType>* parent)
{
    ItemType info;
    if(node->right != NULL)
    {
        info = DequeueTree(node->right, node);
    }
    else
    {
        info = node->info;
        if(node->left != NULL)
        {
            parent->right = node->left;
        }
        else
        {
            parent->right = NULL;
        }
        delete node;
    }
    return info;
}

//to make tree empty
template<class ItemType>
bool BinarySearchTree<ItemType>::IsEmpty()
{
    bool isEmpty;
    if(root == NULL)
    {
        isEmpty = true;
    }
    else
    {
        isEmpty = false;
    }
    return isEmpty;
}

#endif // BINARYSEARCHTREE_H_INCLUDED
