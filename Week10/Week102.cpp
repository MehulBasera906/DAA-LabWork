#include <bits/stdc++.h>
using namespace std;
vector<int> maxTaskSel(vector<int> dur, vector<int> dead)
{
    int n = dur.size();
    priority_queue<pair<int, pair<int, int>>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push({dead[i], {dur[i], i + 1}});
    }
    vector<int> temp(pq.top().first + 1, -1);
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        if (temp[it.first] == -1)
        {
            int j = it.first;
            int cnt = it.second.first;
            while (cnt != 0)
            {
                cnt--;
                temp[j] = it.first;
                j--;
            }
        }
    }
    set<int> st;
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] == -1)
        {
            continue;
        }
        st.insert(temp[i]);
    }
    vector<int> ans;
    for (auto it : st)
    {
        ans.push_back(it);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> dur, dead;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        dur.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        dead.push_back(temp);
    }
    int cnt = 0;
    vector<int> selTask;
    vector<int> ans = maxTaskSel(dur, dead);
    cout << "Max Number of tasks: " << ans.size() << endl;
    cout << "Selected task numbers: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
