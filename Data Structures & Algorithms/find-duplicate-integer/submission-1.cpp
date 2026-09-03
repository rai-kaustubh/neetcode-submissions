class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int slow = arr[0];
        int fast = arr[arr[0]];

        while(slow!=fast){
            fast = arr[arr[fast]];
            slow = arr[slow];
        }
        fast = 0;
        while(fast!=slow){
            fast = arr[fast];
            slow = arr[slow];
        }
        return slow;
    }
};
