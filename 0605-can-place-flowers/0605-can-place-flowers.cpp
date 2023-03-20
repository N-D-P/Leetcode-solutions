class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        if(arr.size()==1 and arr[0]==0)
            n--;
        if(arr.size()>=2){
            if(arr[0]==0 and arr[1]==0) {
                n--;
                arr[0]=1;

            }
        }
        for(int i=1; i<arr.size()-1; i++) {
            if(arr[i-1]==0 and arr[i+1]==0 and arr[i]==0) {
                arr[i]=1;
                n--;
            }
        }
        if(arr.size() >=2 and arr[arr.size()-1]==0 and arr[arr.size()-2]==0)
            n--;
        
        return n<=0;
    }
};