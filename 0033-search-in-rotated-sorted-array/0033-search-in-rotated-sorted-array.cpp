class Solution {
public:
    int search(vector<int>& arr, int target) {
        int left = 0;
        int right = (int)arr.size() - 1;
        while(left <= right){
            int mid = (left + right) >> 1;
            if(arr[mid] == target){
                return mid;
            }
            if(arr[left] <= arr[mid]){
                if(target >=arr[left] && target<=arr[mid]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }else{
                if(target >=arr[mid] && target<=arr[right]){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};