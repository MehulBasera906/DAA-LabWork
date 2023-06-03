#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n;
    vector<int> nums1;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums1.push_back(temp);
    }
    cin >> m;
    vector<int> nums2;
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        nums2.push_back(temp);
    }
    int i = 0, j = 0;
    vector<int> ans;
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(), nums2.end());
    while (i < n && j < m)
    {
        if (nums1[i] == nums2[j])
        {
            ans.push_back(nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}