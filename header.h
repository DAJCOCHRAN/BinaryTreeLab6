#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
typedef char ItemType;

/*struct Node{
    ItemType value;
    Node * next = nullptr;
};
*/
//place character inside of tree
struct List{
    ItemType value;
    List * next = nullptr;
};
struct TreeNode{
    ItemType Info;
    TreeNode * right = nullptr;
    TreeNode * left = nullptr;
    TreeNode * ancestor = nullptr;
    };

class TreeType{
    private:
        TreeNode * root;

    public:
    TreeType();
    void DeleteTree(TreeNode * & node);
    // select the root
    int setRoot(string input);
    //check the tree is full or not
    //get root of tree
    TreeNode * getRoot();
    void fillTreeBalanced(TreeNode * & node, string input);
    void fillTree(TreeNode * & root, string input, int ignore);
    void IsFullTree(TreeNode * &root, int requirement);
    //check if tree organization is correct
    void IsBST(const TreeNode &head);
    //get the count of all nodes in the tree
    void getLength(const TreeNode &head);
    //get number of nodes at current level
    int getNodesAtLevel(TreeNode * &node, int level, ItemType * mainArr);
    //prints ancestor of given node
    void printAncestor(TreeNode * &node, ItemType target);
    friend void charValue();

    TreeNode * getSmallest(TreeNode * & node);
};