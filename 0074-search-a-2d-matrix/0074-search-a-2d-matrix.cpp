class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)     {
        if(matrix.size()==0) return false;
        int r=matrix.size(),c=matrix[0].size();
        int low=0,high=(r*c)-1,mid;
        
        while(low<=high)
        {
            mid = (high+low)/2;
            if(matrix[mid/c][mid%c] == target)
                return true;
            else if(matrix[mid/c][mid%c] < target)
                low = mid+1;
            else 
                high = mid-1;
        }
        return false;
    }
};