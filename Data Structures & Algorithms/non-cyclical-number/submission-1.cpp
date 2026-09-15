class Solution {
public:
    bool isHappy(int n) {
        int prev =n;
        int sum=0;
        unordered_set<int> st;
        
        while(1){
            int prevCopy =prev;
            while(prevCopy>0){
                int digit = prevCopy%10;
                prevCopy/=10;
                sum+=digit*digit;
            }

            if(sum==1) return true;
            if(st.count(sum)) return false;
            st.insert(sum);
            prev = sum;
            sum=0;
        }

        return false;
    }
};
