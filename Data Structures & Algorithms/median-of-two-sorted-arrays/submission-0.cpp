class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = {static_cast<int>(nums1.size())};
        int n = {static_cast<int>(nums2.size())};

        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int totalLength {m + n};
        int half {(m + n + 1) / 2};
        
        int low = 0, high = m;
        while (low <= high) {
            int x = low + (high - low) / 2;
            int y = half - x;

            int a_left = (x==0) ? INT_MIN : nums1[x-1];
            int a_right = (x==m) ? INT_MAX : nums1[x];
            int b_left = (y == 0) ? INT_MIN : nums2[y-1];
            int b_right = (y == n) ? INT_MAX : nums2[y];
            if (a_left <= b_right && b_left <= a_right) {
                if (totalLength % 2 == 0) {
                    return (max(a_left, b_left) + min(a_right, b_right)) / 2.0;
                }
                else {
                    return max(a_left, b_left);
                }
            }

            else if (a_left > b_right) {
                high = x - 1;
            }
            else {
                low = x + 1;
            }
        }
        return -1;
        
    }
};
