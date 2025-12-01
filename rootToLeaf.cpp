  

  #include<bits/stdc++.h>
  using namespace std;

   class TreeNode{
     
       public:

       int val;
       TreeNode* left;
       TreeNode* right;

       TreeNode(int val){
         
          this -> val = val;
          this -> left = NULL;
          this -> right = NULL;
       }
   };

   bool getPath(TreeNode* root , vector<int>&ans , int target){
      
       if(root == NULL) return false;

       ans.push_back(root -> val);

       if(root -> val == target) return true;

       if( getPath(root -> left , ans , target) || getPath(root -> right , ans , target)) return true;

       ans.pop_back();

       return false;

   }


   vector<int> hasPath(TreeNode* root , int target){
     
       vector<int> ans;

       if(root == NULL) return ans;

       getPath(root,ans ,target);

       return ans;
   }




  int main(){

    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> left -> left = new TreeNode(3);
    root -> left -> right = new TreeNode(5);
    root -> right = new TreeNode(4);
    root -> right -> left = new TreeNode(6);
    root -> right -> right = new TreeNode(8);


   vector<int> ans = hasPath(root , 8);

   for(auto x : ans) cout<<x;
     
      
  }