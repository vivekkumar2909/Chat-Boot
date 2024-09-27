#include <bits/stdc++.h>
using namespace std;

int mergeAndCount(vector<int> &arr, int left, int mid, int right, bool ascending)
{
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left, swaps = 0;
    int leftSize = leftArr.size(), rightSize = rightArr.size();

    while (i < leftSize && j < rightSize)
    {
        if ((ascending && leftArr[i] <= rightArr[j]) || (!ascending && leftArr[i] >= rightArr[j]))
        {
            arr[k++] = leftArr[i++];
        }
        else
        {
            arr[k++] = rightArr[j++];
            swaps += (leftSize - i); // All elements left in leftArr are greater (or smaller)
        }
    }

    while (i < leftSize)
        arr[k++] = leftArr[i++];

    while (j < rightSize)
        arr[k++] = rightArr[j++];

    return swaps;
}

int mergeSortAndCount(vector<int> &arr, int left, int right, bool ascending)
{
    int swaps = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        swaps += mergeSortAndCount(arr, left, mid, ascending);
        swaps += mergeSortAndCount(arr, mid + 1, right, ascending);

        swaps += mergeAndCount(arr, left, mid, right, ascending);
    }
    return swaps;
}

int main()
{
    int n;
    cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    vector<int> numAsc = num;
    vector<int> numDesc = num;

    int aSwaps = mergeSortAndCount(numAsc, 0, n - 1, true);
    int dSwaps = mergeSortAndCount(numDesc, 0, n - 1, false);

    cout << min(aSwaps, dSwaps) << endl;

    return 0;
}
