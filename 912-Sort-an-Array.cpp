class Solution {
public:
  int partitionIndex(vector<int>& nums , int low , int high){

int pivot = nums[low];

int i = low;
int j = high;


while(i < j){

 while(nums[i] <= pivot && i<high){
    i++;
 }
 while(nums[j] > pivot && j>low){
    j--;
 }

 if(i < j) swap(nums[i] , nums[j]);


}

swap(nums[j] , nums[low]);

return j;


  }

  void quicksort(vector<int>& nums , int low , int high){
      if(low < high){
        int partition = partitionIndex(nums, low , high);

        quicksort(nums , low , partition-1);
        quicksort(nums, partition+1, high);
      }

  }

    



    vector<int> sortArray(vector<int>& nums) {
          int n = nums.size();

           quicksort(nums, 0 , n-1);
           return nums;
    }
};