class countOccurance{
    /*
int main(){
    int tmp [] = {3,2,3,1,6,3,4,1,3,2,8,10,13,0,2,1,3,1,6,5,9,6,13,24,12,13,21,16,8};
    vector<int> case1 (tmp, tmp + sizeof(tmp)/sizeof(int));
    for(auto &i : case1) cout << i << " " ;
    cout << endl;
    case1 = countSort::toSort(case1);
    for(auto &i : case1) cout << i << " " ;
    cout << endl;
    cout << "Occurance: " << countOccurance::countNumOccurance(case1, 3) << endl;
    return 0;
}
    */
public:
    static int countNumOccurance(vector<int>& nums, int k){
        //with sorted array
        if(nums.size() == 1) return k == nums[0] ? 1 : 0;
        int lo = 0, hi = nums.size() - 1;
        int lowerEnd = -1, upperEnd = -1;
        int mid = (hi + lo) / 2 ;
        while(lo <= hi){
            if(nums[mid] < k) lo = mid + 1;
            else if(nums[mid] > k) hi = mid - 1;
            else{
               int counter = 1;
               int cur = mid;
               while(nums[++cur] == k) counter ++;
               while(nums[--mid] == k) counter ++;
               return counter;
            }
            mid = (hi + lo) / 2 ;
        }
        return 0;
    }
};
