void getInorder(struct Node *root, vector<int> &arr){
    if(root == NULL) return;
    
    getInorder(root->left, arr);
    arr.push_back(root->data);
    getInorder(root->right, arr);
    
}

float findMedian(struct Node *root)
{
      //Code here
      vector<int> arr;
      getInorder(root, arr);
      int n = arr.size();
      float median;
      
      
      if(n % 2 == 1){
        median = arr[n/2]; 
      }
      else{
        median = ( float(arr[n/2]) + float(arr[(n/2) - 1]) ) / 2;  
      }
      
      return median;
}
