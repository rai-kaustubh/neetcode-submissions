class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int half = (nums1.size()+nums2.size())/2;
        if(nums1.size()>nums2.size()){
            swap(nums1, nums2);
        }

        int l=0, r=nums1.size();
        while(l<=r){
            int mid1 =l+((r-l)/2);
            int mid2= half-mid1;
            int left1 = mid1==0?INT_MIN:nums1[mid1-1];
            int left2 = mid2==0?INT_MIN:nums2[mid2-1];
            int right1 = mid1==(int)nums1.size()?INT_MAX:nums1[mid1];
            int right2 = mid2==(int)nums2.size()?INT_MAX:nums2[mid2];

            if(left1<=right2 && left2<=right1){
                if((nums1.size()+nums2.size())%2==0){
                    auto l_max = max(left1, left2);
                    auto r_min = min(right1, right2);
                    return ((double)l_max+r_min)/2;
                }
                return min(right1, right2);
                
            } else if(left1>right2){
                r=mid1-1;
            } else{
                l=mid1+1;
            }
            
        }
        return -1;


    }
};
/*
size
half = size/2
mid (smaller arr)
half-mid

Left_smaller
Left_bigger
Right_smaller
Right_bigger



*/