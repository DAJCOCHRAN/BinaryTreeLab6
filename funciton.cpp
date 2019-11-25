#include"header.h"
//main funcitons
//initialize tree root in heap
TreeType::TreeType(){
    root = new TreeNode;
}
//destroy initial root
/*----------------------------------
Destructor for tree
------------------------------------*/
TreeType::~TreeType(){
    int count = 0;
    TreeNode * node = root->left;
    TreeNode * prev = nullptr;
    while(root->left != nullptr){
        if((node->left == nullptr) && (node->right == nullptr)){
            cout << node->Info << " Deleted!" << endl;
            prev = node->ancestor;
            if(prev->left == node){
                prev->left = nullptr;
            }
            else{
                prev->right = nullptr;
            }
            delete node;
            count++;
            node = root;
            cout<<"set back to root" << endl;
        }
        else if((node->left != nullptr) && (node->right == nullptr)){
            cout<<"skipped left"<<endl;
            node = node->left;
        }
        else if((node->left == nullptr) && (node->right != nullptr)){
            cout<<"skipped right"<<endl;
            node = node->right;
        }
        //priority of shifting left if left and right pointers are valid
        else if((node->left != nullptr) && (node->right != nullptr)){
            cout<<"skipped left"<<endl;
            node = node->left;
        }
        else{
            cout << "error" <<endl;
        }
    }
    cout << "left Tree cleared!" <<endl;
    node = root;
    while(root->right != nullptr){
        if((node->left == nullptr) && (node->right == nullptr)){
            cout << node->Info << " Deleted!" << endl;
            prev = node->ancestor;
            if(prev->left == node){
                prev->left = nullptr;
            }
            else{
                prev->right = nullptr;
            }
            delete node;
            count++;
            node = root;
            cout<<"set back to root" << endl;
        }
        else if((node->left != nullptr) && (node->right == nullptr)){
            cout<<"skipped left"<<endl;
            node = node->left;
        }
        else if((node->left == nullptr) && (node->right != nullptr)){
            cout<<"skipped right"<<endl;
            node = node->right;
        }
        //priority of shifting left if left and right pointers are valid
        else if((node->left != nullptr) && (node->right != nullptr)){
            cout<<"skipped left"<<endl;
            node = node->left;
        }
        else{
            cout << "error" <<endl;
        }
    }
    cout << "right Tree cleared!" <<endl;
    cout << "Root "<< root->Info << " deleted" << endl;
    delete root;
    count++;
    cout << count << " Nodes deleted from tree" << endl;
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

void TreeType::fillTree(string input, int ignore){ 
        static TreeNode * node = root;
        static TreeNode * prev = root;
        static int pos = 0;

        
        //our position is past the last character
        if(pos == input.length()){
        cout << "tree has been filled" <<endl;
            return;
        }
        //if position is on root position
        else if(pos == ignore){
            cout << "skipped root position" <<endl;
            pos++;
            fillTree(input, ignore);
        }
        //source node is greater than character and is a leaf --LEFT
        else if((node->Info > input[pos]) && (node->left == nullptr)){
            TreeNode * leftLeaf = new TreeNode;
            leftLeaf->Info = input[pos];
            node->left = leftLeaf;
            leftLeaf->ancestor = node;
            cout<<"------------PLACE LEAF LEFT-------------"<<endl;
            cout<<"Ancestor: " << leftLeaf->ancestor <<endl;
            cout<<"Address   " << leftLeaf <<endl;
            cout<<"Value     " << leftLeaf->Info <<endl;
            cout<<"left leaf: " << leftLeaf->left <<endl;
            cout<<"right leaf: "<< leftLeaf->right << endl;
            cout<<"-------------------------"<<endl;
            //prepare next recursion with new character
            prev = root;
            node = root;
            pos++;
            fillTree(input, ignore);
        }
        //source node is greater and is a branch --LEFT
        else if((node->Info > input[pos]) && (node->left != nullptr)){
            cout<< "----------BRANCH SKIPPING LEFT------------------"<<endl;
            cout<< "Ancestor: " << node->ancestor <<endl;
            cout<< "Address:  " << node << "is full" <<endl;
            cout<< "Value:  " << node->Info <<endl;
            cout<< "Skipping to the left: " << node->right <<endl;
            cout<< "Left address: " << node->left <<endl;
            cout<< "----------------------------"<<endl;
            prev = node;
            node = node->left;
            fillTree(input, ignore);
        }
        //source node is less/equal than character and is a leaf --RIGHT
        else if((node->Info <= input[pos]) && (node->right == nullptr)){
            TreeNode * rightLeaf = new TreeNode;
            rightLeaf->Info = input[pos];
            node->right = rightLeaf;
            rightLeaf->ancestor = node;
            cout<<"----------PLACE LEAF RIGHT---------------"<<endl;
            cout<<"Ancestor: " << rightLeaf->ancestor <<endl;
            cout<<"Address   " << rightLeaf <<endl;
            cout<<"Value     " << rightLeaf->Info <<endl;
            cout<<"left should be null" << rightLeaf->left <<endl;
            cout<<"right leaf should be null"<< rightLeaf->right << endl;
            cout<<"-------------------------"<<endl;
            //prepare next cycle with new character
            prev = root;
            node = root;
            pos++;
            fillTree(input, ignore);
        }
        //source node is less/equal and is a branch --RIGHT
        else if((node->Info <= input[pos]) && (node->right != nullptr)){
            cout<< "----------BRANCH SKIPPING RIGHT------------------"<<endl;
            cout<< "Node " << node << "is full" <<endl;
            cout<< "Ancestor: "<< node->ancestor <<endl;
            cout<< "Value: " << node->Info <<endl;
            cout<< "Skipping to the right: " << node->right <<endl;
            cout<< "Left address: " << node->left <<endl;
            cout<< "----------------------------"<<endl;
            prev = node;
            node = node->right;
            fillTree(input, ignore);
        }
        else{
            cout << "error" <<endl;
            return;
        }
    return;
}

string toUpper(string input){
    for (int i=0; i<input.length(); i++){
        input[i] = toupper(input[i]);
    }
    return input;
}

void TreeType::IsFullTree(TreeNode * &root, int requirement){
    cout<<requirement<<": requirement" << endl;
    static int count = 0;
    //base case when we find a node that is not a complete branch or not a leaf
    if(((root->left== nullptr)&&(root->right!=nullptr))||((root->left!= nullptr)&&(root->right==nullptr))){
        cout<<"Not a complete tree"<<endl;
        return;
    }
    //we find a leaf or complete branch
    if(((root->left == nullptr)&&(root->right == nullptr))||((root->left != nullptr) && (root->right != nullptr))){
        count++;
        cout<<count<<"The count of nodes found"<<endl;
    }
    cout<< root->Info <<endl;
    if(root->left != nullptr){
        IsFullTree(root->left, requirement);
    }
    if(root->right != nullptr){
        IsFullTree(root->right, requirement);
    }
    //once we reach the last node, we should be at the last null ptr of left/right and requirment should be count
    if((root->right == nullptr)||root->left == nullptr){
        if(count == requirement){
            cout<<"tree is complete" <<endl;
            return;
        } 
    }
}