#include<bits/stdc++.h>
using namespace std;

class BinaryTree
{
public:
    int data;
    BinaryTree* LeftChild;
    BinaryTree* RighChild;

    BinaryTree(int val)
    {
        data = val;
        LeftChild = NULL;
        RighChild = NULL;
    }

};

void specePrint(int lavel)
{
    for(int i = 0; i< lavel; i++)
    {
        cout<<"   ";
    }
}
void printTree(BinaryTree* root, int lavel)
{
    if(root == NULL)
    {
        return;
    }
    if(root->LeftChild == NULL && root->RighChild == NULL)
    {
        cout<<root->data<<endl;
        return;
    }
    else
    {
        cout<<endl;
        specePrint(lavel);
        cout<<"Root: "<<root->data<<endl;
    }

    if(root->LeftChild != NULL)
    {
        specePrint(lavel);
        cout<<"Left: ";
        printTree(root->LeftChild, lavel+1);
    }

    if(root->RighChild != NULL)
    {

        specePrint(lavel);
        cout<<"Right: ";
        printTree(root->RighChild, lavel+1);
    }


}
void inOrder(BinaryTree* root, string &chk){


     if(root == NULL)
        return;

    inOrder(root->LeftChild, chk);
    chk += to_string(root->data)+" ";
    inOrder(root->RighChild, chk);

}
void preOrder(BinaryTree* root, string &chk){

     if(root == NULL)
        return;

    chk += to_string(root->data);
    preOrder(root->LeftChild, chk);
    preOrder(root->RighChild, chk);

}

void postOrder(BinaryTree* root, string &chk){

     if(root == NULL)
        return;

    postOrder(root->LeftChild, chk);
    postOrder(root->RighChild, chk);
    chk += to_string(root->data);

}

int levelOrderTraversal(BinaryTree* root, string &chk, int k){

    if(root == NULL){
        return -1;
    }
    queue<BinaryTree*>q;
    q.push(root);
    q.push(NULL);
    int max = INT_MIN;
    int level = 0;
    while(!q.empty()){
        BinaryTree* checkNode = q.front();
        q.pop();

        if(checkNode != NULL){
            if(level == k){
                if(checkNode->data > max){
                    max = checkNode->data;
                }
            }
        }


        if(checkNode != NULL){
            chk+=to_string(checkNode->data);
            //cout<<checkNode->data<<" ";
            if(checkNode->LeftChild != NULL){
                q.push(checkNode->LeftChild);
            }
            if(checkNode->RighChild != NULL){
                q.push(checkNode->RighChild);
            }
        }
        else{
            if(!q.empty()){
                q.push(NULL);
                level++;
            }
        }
    }

    return max;

}
void printLeave(BinaryTree * root){
    if(root == NULL){
        return;
    }

    if(root->LeftChild == NULL && root->RighChild == NULL){
        cout<<root->data;
        return;
    }
    printLeave(root->LeftChild);
    printLeave(root->RighChild);


}

void printLbNonleaves(BinaryTree * root){
    if(root == NULL){
        return;
    }
    if(root->LeftChild != NULL){
        cout<<root->data;
        printLbNonleaves(root->LeftChild);
    }
   else if(root->RighChild != NULL){
        cout<<root->data;
        printLbNonleaves(root->RighChild);
    }

}

void printRbNonleaves(BinaryTree* root){
    if(root == NULL){
        return;
    }

    if(root->RighChild != NULL){
        cout<<root->data<<" ";
        printRbNonleaves(root->RighChild);
    }
    else if(root->LeftChild != NULL){
        cout<<root->data<<" ";
        printRbNonleaves(root->LeftChild);
    }
}

void boundaryOrderTraversal(BinaryTree* root){
    if(root == NULL){
        return;
    }
    cout<<root->data;

    printLbNonleaves(root->LeftChild);
    printLeave(root->LeftChild);
    printLeave(root->RighChild);
    printRbNonleaves(root->RighChild);




}

BinaryTree* insertionBST(BinaryTree * root, int val){
    BinaryTree* newNode = new BinaryTree(val);
    if(root == NULL){
        root = newNode;
        return root;
    }
    // value < root ->data
    if(val < root->data){
        root->LeftChild = insertionBST(root->LeftChild, val);
    }
    // value > root -> data
    else if(val > root->data){
        root->RighChild = insertionBST(root->RighChild, val);
    }
    return root;
}

BinaryTree* searchBST(BinaryTree * root, int val){
    if(root == NULL){
        return NULL;
    }
    if(root->data == val){
        cout<<root->data;
        return root;
    }
    else if(val < root->data){
        cout<<root->data<<"->";
        searchBST(root->LeftChild, val);
    }
    else{
        cout<<root->data<<"->";
        searchBST(root->RighChild, val);
    }
}

BinaryTree* inorderSucc(BinaryTree* root){
    BinaryTree* curr = root;
    while(curr->LeftChild != NULL){
        curr = curr->LeftChild;
    }
    return curr;
}

BinaryTree* deleteBST(BinaryTree* root , int value){
    if(value < root->data){
        root->LeftChild = deleteBST(root->LeftChild, value);
    }
    else if(value > root->data){
        root->RighChild = deleteBST(root->RighChild, value);
    }
    else{
      // implementation of 3 case
      if(root->LeftChild == NULL){
            BinaryTree* temp = root->RighChild;
            free(root);
            return temp;
      }
      else if(root->RighChild == NULL){
            BinaryTree* temp = root->LeftChild;
            free(root);
            return temp;
      }
      else{
          BinaryTree * temp = inorderSucc(root->RighChild);
          root->data = temp->data;
          root->RighChild = deleteBST(root->RighChild, temp->data);

      }
        return root;

    }

}

void zigZagTreeTraversal(BinaryTree* root){
   if (!root)
      return;
   stack<BinaryTree*> currentlevel;
   stack<BinaryTree*> nextlevel;
   currentlevel.push(root);
   bool LtR = true;
   while (!currentlevel.empty()) {
      BinaryTree* temp = currentlevel.top();
      currentlevel.pop();
      if (temp) {
         cout<<temp->data<<"\t";
         if (LtR) {
            if (temp->LeftChild)
               nextlevel.push(temp->LeftChild);
            if (temp->RighChild)
               nextlevel.push(temp->RighChild);
         }
         else {
            if (temp->RighChild)
               nextlevel.push(temp->RighChild);
            if (temp->LeftChild)
               nextlevel.push(temp->LeftChild);
         }
      }
      if (currentlevel.empty()) {
         LtR = !LtR;
         swap(currentlevel, nextlevel);
      }
   }
}

int main()
{

    int n;
    cin>>n;
    BinaryTree* root = NULL;
    for(int i = 0; i < n; i++){
        int val;
        cin>>val;
        root = insertionBST(root, val);
    }

//    string traversal = "";
//    inOrder(root, traversal);
//    cout<<traversal;

//    int key;
//    cin>>key;
//    searchBST(root, key);



    int delKey;
    cin>>delKey;
    deleteBST(root, delKey);

    string traversalafterdeletion = "";
    inOrder(root, traversalafterdeletion);
    cout<<traversalafterdeletion;

    zigZagTreeTraversal(root);

    return 0;
}
/*
9
11 5 9 43 34 1 2 7 21

*/

/*

5
1 2 3
2 4 5
3 -1 -1
4 -1 -1
5 -1 -1


*/


// g++ -o BinaryTreeImplementation.exe BinaryTreeImplementation.cpp

