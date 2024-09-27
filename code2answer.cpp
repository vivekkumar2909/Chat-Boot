#include <bits/stdc++.h>
using namespace std;
bool isPossible(const string &str)
{
    for (char ch : str)
    {
        if (ch != 'M' && ch != 'L')
        {
            return false;
        }
    }
    return true;
}
int countStringValidCombo(const string &str)
{
    int size = str.size();
    int count = 0;

    vector<int> prefixM(size + 1, 0), prefixL(size + 1, 0);
    for (int i = 0; i < size; ++i)
    {
        prefixM[i + 1] = prefixM[i] + (str[i] == 'M' ? 1 : 0);
        prefixL[i + 1] = prefixL[i] + (str[i] == 'L' ? 1 : 0);
    }

    for (int j = 1; j < size - 1; ++j)
    {
        if (str[j] == 'L')
        {
            int leftM = prefixM[j];
            int rightM = prefixM[size] - prefixM[j + 1];
            count += leftM * rightM;
        }
        else if (str[j] == 'M')
        {
            int leftL = prefixL[j];
            int rightL = prefixL[size] - prefixL[j + 1];
            count += leftL * rightL;
        }
    }

    return count;
}

int main()
{
    string AshokStr, AnandStr;
    cin >> AshokStr >> AnandStr;
    if (!isPossible(AshokStr) || !isPossible(AnandStr))
    {
        cout << "Invalid input" << endl;
        return 0;
    }
    int ashok = countStringValidCombo(AshokStr);
    int anand = countStringValidCombo(AnandStr);
    if (ashok > anand)
    {
        cout << "Ashok" << endl;
    }
    else if (anand > ashok)
    {
        cout << "Anand" << endl;
    }
    else
    {
        cout << "Draw" << endl;
    }

    return 0;
}
