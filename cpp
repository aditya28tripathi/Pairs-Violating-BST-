class Solution {
    private:
       
  public:

  void inorder(Node* root,vector<int>&arr){
      if(root==NULL){
          return;
      }
       inorder(root->left,arr);
       arr.push_back(root->data);
       inorder(root->right,arr);
  }
    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root) {
        // your code goes here 
        vector<int>arr;
        inorder(root,arr);
        
        
vector<int>store(n);
for (int i = 0; i <n; i++)
{
    store[i]=arr[i];
}
sort(store.begin(),store.end());
int cnt=0;
// int sum=0;

for (int i = 0; i <n; i++)
{
    int lb=lower_bound(store.begin(),store.end(),arr[i])-store.begin();
    cnt+=lb;
    store.erase(store.begin()+lb);
    
}
// cout<<cnt;
return cnt;
    }
};
