class Solution {
public:
    void merge(vector<int> &nums, int l, int mid, int r){
        vector<int> copy;
        int left = l, right = mid+1;
        while(left<=mid && right<=r){
            if(nums[left]<=nums[right])
                copy.push_back(nums[left++]);
            else
                copy.push_back(nums[right++]);
        }
        while(left<=mid)
            copy.push_back(nums[left++]);
        while(right<=r)
            copy.push_back(nums[right++]);
        for(int i=l;i<=r;i++)
            nums[i]=copy[i-l];
    }
    void mergeSort(vector<int> &nums, int l, int r){
        if(l>=r)
            return;
        int mid = (l+r)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);
        merge(nums,l,mid,r);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};