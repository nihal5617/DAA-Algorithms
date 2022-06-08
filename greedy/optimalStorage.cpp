#include <bits/stdc++.h>
using namespace std;

int n;

void optimal(int l[], int n)
{

    int i, j, sum;

    sort(l, l + n);

    cout << "The optimal sequence to store tapes is :";
    for (int i = 0; i < n; i++)
        cout << l[i] << " ";
    cout << endl;

    double MRT = 0;
    for (i = 0; i < n; i++)
    {
        sum = 0;
        for (j = 0; j <= i; j++)
        {
            sum += l[j];
        }
        MRT += sum;
    }
    cout<<MRT;

    MRT /= n;

    cout << "The MRT is :";
    cout << MRT;
}

int main()
{

    cout << "Enter  the number of tapes :";
    cin >> n;

    int l[100];
    int i;

    cout << "\nEnter the elements of the tape :";
    for (i = 0; i < n; i++)
    {
        cin >> l[i];
    }

    optimal(l, n);
    return 0;
}
