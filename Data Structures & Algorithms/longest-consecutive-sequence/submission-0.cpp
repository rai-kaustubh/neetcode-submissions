class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(auto num: nums){
            set.insert(num);
        }
        int _max=0;

        for(auto num:nums){
            int left=0, right=0;
            auto temp=set.find(num-1);

            while(temp!=set.end()){
                left++;
                auto temp2=*temp;
                set.erase(temp2);
                temp=set.find(temp2-1);
            }

            temp=set.find(num+1);

            while(temp!=set.end()){
                right++;
                auto temp2=*temp;
                set.erase(temp2);
                temp=set.find(temp2+1);
            }

            _max =max(_max, left+right+1);
        }

        return _max;
    }
};
