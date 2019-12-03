#include"header.h"
//main funcitons
//initialize tree root in heap

string toUpper(string input){
    for (int i=0; i<input.length(); i++){
        input[i] = toupper(input[i]);
    }
    return input;
}

bool powerTwoCheck(int inputLength){
    int check = inputLength % 2;
    if (inputLength == 1){
        return true;
    }
    else if(check == 0){
        inputLength = inputLength / 2;
        powerTwoCheck(check);
    }
    else{
        return false;
    }
}

TreeType::TreeType(){
    root = new TreeNode;
}
/*----------------------------------
Destructor function for tree and its nodes
------------------------------------*/
void TreeType::DeleteTree(TreeNode * & node){ 
    if((node->left == nullptr) && (node->right == nullptr)){
        cout<<"leaf has been deleted!!" << endl;
        delete node;
        return;
    }
    else{
        if(node->left != nullptr){
            DeleteTree(node->left);
        }
        if(node->right != nullptr){
            DeleteTree(node->right);
        }
        if(node == root){
            cout<<"root has been deleted"<<endl;
            delete node;
        }
        else{
            cout<<"branch has been deleted"<<endl;
            delete node;
        }
    }
}

TreeNode * TreeType::getRoot(){
    TreeNode * myRoot = root;
    return root;
}

//set the root of our tree
//must return int for position to ignore
int TreeType::setRoot(string input){
    //searching mid alphabet lowercase first
    for(int i=0; i<input.length(); i++){
        if(input[i] > 'I' && input[i] < 'R'){
            root->Info = input[i];
            cout<<"Root Address: "<< root <<endl;
            cout << "Root Value: " << input[i] << " has been placed as root" <<endl;
            return i;
        }
    }
    //then upper
    for(int i=0; i<input.length(); i++){
        if(input[i] > 'Q'){
            root->Info = input[i];
            cout<<"Root Address: "<< root <<endl;
            cout << "Root Value: " << input[i] << " has been placed" <<endl;
            return i;
        }
    }
    //then lower
    for(int i=0; i<input.length(); i++){
        if(input[i] > 'A'){
            root->Info = input[i];
            cout<<"Root Address: "<< root <<endl;
            cout << "Root Value: " << input[i] << " has been placed" <<endl;
            return i;
        }
    }
    //then numeric
    for(int i=0; i<input.length(); i++){
        if(input[i] > '0'){
            root->Info = input[i];
            cout<<"Root Address: "<< root <<endl;
            cout << "Root Value: " << root->Info <<endl;
            return i;
        }
    }
    //then any other character
    root->Info = input[0]; 
    cout << "Root" << input[0] << " has been placed" <<endl;
    return 0;
}

void TreeType::fillTree(TreeNode * & node, string input, int ignore){

        cout<< "----------AT POSITION------------------"<<endl;
        cout<< "Ancestor: " << node->ancestor <<endl;
        cout<< "Address:  " << node <<endl;
        cout<< "Value:  " << node->Info <<endl;
        cout<< "Left address: " << node->left <<endl;
        cout<< "Right address: " << node->right <<endl;
        cout<< "-----------------------------------------"<<endl;
        
        static int pos = 0; 
        //our position is past the last character
        //if position is on root position
        if(pos == ignore){
            cout << "SKIPPED ROOT POSITION" <<endl;
            pos++;
            fillTree(node, input, ignore);
        }
        else if(pos == input.length()){
            cout<<"TREE HAS BEEN BUILT"<<endl;
            return;
        }
        //source node is greater than input character --LEFT
        else if((node->Info > input[pos]) && (node->left == nullptr)){
            TreeNode * leftLeaf = new TreeNode;
            leftLeaf->Info = input[pos];
            node->left = leftLeaf;
            leftLeaf->ancestor = node;
            cout<<"------------PLACED LEAF LEFT-------------"<<endl;
            cout<<"Ancestor:   " << leftLeaf->ancestor <<endl;
            cout<<"Address:    " << leftLeaf <<endl;
            cout<<"Value:      " << leftLeaf->Info <<endl;
            cout<<"left leaf:  " << leftLeaf->left <<endl;
            cout<<"right leaf: "<< leftLeaf->right << endl;
            cout<<"-----------------------------------------"<<endl;
            //prepare next recursion with new character
            pos++;
            while(node->ancestor != nullptr){
                node = node->ancestor;
            }
            fillTree(node, input, ignore);
        }
        //target node is greater than character and is a branch --LEFT
        else if((node->Info > input[pos]) && (node->left != nullptr)){
            cout<<"SKIPPED LEFT"<<endl;
            node = node->left;
            fillTree(node, input, ignore);
        }
        //target node is less/equal than character and is a leaf --RIGHT
        else if((node->Info <= input[pos]) && (node->right == nullptr)){
            TreeNode * rightLeaf = new TreeNode;
            rightLeaf->Info = input[pos];
            node->right = rightLeaf;
            rightLeaf->ancestor = node;
            cout<<"------------PLACED LEAF RIGHT-------------"<<endl;
            cout<<"Ancestor:   " << rightLeaf->ancestor <<endl;
            cout<<"Address:    " << rightLeaf <<endl;
            cout<<"Value:      " << rightLeaf->Info <<endl;
            cout<<"left leaf:  " << rightLeaf->left <<endl;
            cout<<"right leaf: "<< rightLeaf->right << endl;
            cout<<"-----------------------------------------"<<endl;
            //prepare next cycle with next position
            pos++;
            while(node->ancestor != nullptr){
                node = node->ancestor;
            }
            fillTree(node, input, ignore);
        }
        //source node is less/equal and is a branch --RIGHT
        else if((node->Info <= input[pos]) && (node->right != nullptr)){
            cout<<"SKIPPED RIGHT"<<endl;
            node = node->right;
            fillTree(node, input, ignore);
        }
        else{
            cout << "error" <<endl;
            return;
        }
    return;
}

void TreeType::fillTreeBalanced(TreeNode * &node, string input){
    
}

/*
Takes the Root and requirement length and 
*/
void TreeType::IsFullTree(TreeNode * &root, int requirement){
    //count of nodes, include the root
    static int nodeCount = 1;
    //base case when we find a node that is a incomplete branch
    if(((root->left== nullptr)&&(root->right!=nullptr))||((root->left!= nullptr)&&(root->right==nullptr))){
        cout<<"Not a complete tree"<<endl;
        return;
    }
    //we find a leaf
    if((root->left == nullptr)&&(root->right == nullptr)){
        nodeCount++;
        //This leaf is the last leaf found
        if(nodeCount == requirement){
            cout<<"This is a complete tree!!!"<<endl;
            return;
        }
    }
    //We find a branch
    if((root->left != nullptr) && (root->right != nullptr)){
        cout<<"Branch Found"<<endl;
        nodeCount++;
        IsFullTree(root->left, requirement);
        IsFullTree(root->right, requirement);
    }
    //once we reach the last node, we should be at the last null ptr of left/right and requirment should be count
}


int TreeType::getNodesAtLevel(TreeNode * &node, int level, ItemType * mainArr){ 
    static int currLvl = 0;
    static int NodeCount = 1;
    static int pos = 0;

    if(currLvl == level){
        NodeCount++;
        return NodeCount;
    }

    else if(currLvl != level){
        currLvl++;
        if(node->left != nullptr){
        getNodesAtLevel(node->left, level, mainArr);
        }
        if(node->right != nullptr){
            pos++;
        getNodesAtLevel(node->right, level, mainArr);
        }
    }
    
}

TreeNode * TreeType::getSmallest(TreeNode * & node){
    if((node->left == nullptr) && (node->right == nullptr)){
        return node;
    }
    else if(node->left != nullptr){
        getSmallest(node->left);
    }
    else if(node->right != nullptr){
        getSmallest(node->right);
    }
    else{
        cout<<"error"<<endl;
    }
}

void TreeType::printAncestor(TreeNode * &node, ItemType target){
    if(node->Info == target){
        cout<<"Target found, printing ancestors.."<<endl;
        while(node->ancestor != nullptr){
            node = node->ancestor;
            cout<<node->Info<< endl;
        }
    return;
    }
    else{
        if(node->left != nullptr){
            printAncestor(node->left, target);
        }
        if(node->right != nullptr){
            printAncestor(node->right, target);
        }
    }
}