class Solution {
  private:
    void helper(int i, vector<int> &ds, vector<int> &arr, vector<vector<int>> &ans, 
    vector<int> &vis){
        if(i == arr.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int j = 0; j < arr.size(); j++){
            if(!vis[j]){
                if(j > 0 && arr[j] == arr[j - 1] && !vis[j-1]) continue;
                
                
                ds.push_back(arr[j]);
                vis[j] = 1;
                
                helper(i+1, ds, arr, ans, vis);
                
                vis[j] = 0;
                ds.pop_back();
            }
        }
    }
  
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> vis(n, 0);
        vector<int> ds;
        
        helper(0, ds, arr, ans, vis);
        return ans;
        
    }
};