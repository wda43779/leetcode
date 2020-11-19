#include <vector>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        auto A = nums1.size() <= nums2.size() ? nums1 : nums2;
        auto B = nums1.size() <= nums2.size() ? nums2 : nums1;
        int m = A.size(), n = B.size();

        int l = 0, r = m;
        int i, j;
        while (l <= r)
        {
            i = (l + r) / 2;
            j = (m + n + 1) / 2 - i;

            if (i < m && B[j - 1] > A[i])
                l = i + 1;
            else if (i > 0 && A[i - 1] > B[j])
                r = i - 1;
            else
            {
                int leftMax;
                if (i == 0)
                    leftMax = B[j - 1];
                else if (j == 0)
                    leftMax = A[i - 1];
                else
                    leftMax = max(A[i - 1], B[j - 1]);

                if ((m + n) % 2 == 1)
                    return leftMax;
                else
                {
                    int rightMin;
                    if (i == m)
                        rightMin = B[j];
                    else if (j == n)
                        rightMin = A[i];
                    else
                        rightMin = min(A[i], B[j]);
                    return (leftMax + rightMin) / 2.0;
                }
            }
        }
        return 0;
    }
};
