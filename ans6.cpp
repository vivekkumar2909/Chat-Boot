#include <bits/stdc++.h>

using namespace std;

int main()
{
    int L, K;
    cin >> L >> K;

    int gap = K + 1;
    int countZeros = L - K;

    int maxiLen = (countZeros + gap - 1) / gap;

    cout << maxiLen << endl;

    return 0;
}
