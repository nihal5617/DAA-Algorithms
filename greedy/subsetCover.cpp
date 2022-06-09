#include <bits/stdc++.h>
using namespace std;

int diffSet(vector<int> u, vector<int> s)
{
    sort(s.begin(), s.end());
    sort(u.begin(), u.end());
    vector<int> diff;
    set_difference(u.begin(), u.end(), s.begin(), s.end(), back_inserter(diff));
    return diff.size();
}

int mini(float *array, int n)
{
    int index = 0;

    for (int i = 1; i < n; i++)
        if (array[i] < array[index])
            index = i;

    return index;
}

int subset(vector<int> u, vector<vector<int>> s, int *c, int n, int *arr)
{
    vector<int> sn;
    float ratio[n] = {0};

    int cost = 0;
    while (u != sn)
    {
        for (int i = 0; i < n; i++)
        {
            vector<int> set = s[i];
            int x = diffSet(set, sn);
            if (x != 0)
                ratio[i] = c[i] / x;
            else
                ratio[i] = 999;
        }
        int index = mini(ratio, n);
        if (sn.size() == 0)
            sn.insert(sn.end(), s[index].begin(), s[index].end());
        else
        {
            for (int i = 0; i < s[index].size(); i++)
            {
                bool flag = false;
                for (int j = 0; j <= sn.size(); j++)
                    if (s[index][i] == sn[j])
                    {
                        flag = true;
                        break;
                    }
                if (!flag)
                    sn.push_back(s[index][i]);
            }
        }
        arr[index] = 1;
        cost = cost + c[index];
        sort(sn.begin(), sn.end());
    }
    cout << (u == sn);
    return cost;
}

int main()
{
    vector<int> u;
    vector<vector<int>> s;
    int un;
    cout << "Enter no. of elements in universal set: ";
    cin >> un;
    cout << "Enter elements of universal set: ";
    for (int i = 0; i < un; i++)
    {
        int x;
        cin >> x;
        u.push_back(x);
    }

    int n = 5;
    cout << "Enter number of subsets: ";
    cin >> n;

    int arr[n] = {0};
    int c[n];

    for (int i = 0; i < n; i++)
    {
        int k;
        cout << "Enter number of elements in subset " << i + 1 << ": ";
        cin >> k;
        cout << "Enter elements of subset " << i + 1 << ": ";
        vector<int> x;
        for (int j = 0; j < k; j++)
        {
            int y;
            cin >> y;
            x.push_back(y);
        }
        s.push_back(x);
        cout << "Enter the cost of subset " << i + 1 << ": ";
        cin >> c[i];
    }

    int cost = subset(u, s, c, n, arr);
    cout << "The solution vector is: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl
         << "The cost is: " << cost;
    return 0;
}