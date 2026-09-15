class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;

        for(int i=digits.size()-1;i>=0;i--){
            digits[i]+=carry;
            if(digits[i]>=10){
                carry = digits[i]/10;
                digits[i] = digits[i]%10;
            } else carry=0;
        }

        if(carry){
            vector<int> ans(digits.size()+1);
            ans[0] = (carry);
            copy(digits.begin(), digits.end(), ans.begin()+1);
            return ans;
        }
        return digits;
    }
};
