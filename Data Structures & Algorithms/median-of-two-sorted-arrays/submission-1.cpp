class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            swap(nums1, nums2);
        }

        int l=0, r = nums1.size(), half = (nums1.size()+nums2.size())/2;
        while(1){
            int p1 = l+(r-l)/2;
            int p2 = half-p1;

            int l1 = p1>0?nums1[p1-1]:INT_MIN;
            int l2 = p2>0?nums2[p2-1]:INT_MIN;
            int r1 = p1<nums1.size()?nums1[p1]:INT_MAX;
            int r2 = p2<nums2.size()?nums2[p2]:INT_MAX;
            
            if(l1<=r2 && l2<=r1){
                if((nums1.size()+nums2.size())%2==0){
                    return (double) (max(l1,l2)+min(r1,r2))/2.0;
                } else{
                    return min(r1,r2);
                }
            }

            if(l1>r2){
                r=p1-1;
            } else {
                l=p1+1;
            }
        }
        return -1;
    }
};
/*
nums1 = [1,2,3,4]
nums2 = [5,6,7,8,9] 


mid1, mid2;


*/
