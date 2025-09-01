#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> arrLarger, vector<int> arrSmaller)
{
    int current = arrLarger.size() - 1;
    int idxL = arrLarger.size() - arrSmaller.size() - 1;
    int idxS = arrSmaller.size() - 1;
    for (int curr = current; curr >= 0; curr--)
    {
        if(arrLarger[idxL]>arrSmaller[idxS] || idxS<0){
            arrLarger[curr] = arrLarger[idxL];
            idxL--;
        }
        else {
            arrLarger[curr] = arrSmaller[idxS];
            idxS--;
        }
    }
    return arrLarger;
}

int main()
{

    vector<int> arrLarger = {1, 3, 4, 6, 0, 0, 0};
    vector<int> arrSmaller = {2, 3, 4};
    vector<int> ans = merge(arrLarger, arrSmaller);

    cout << "Larger Array : ";
    for (int val : arrLarger)
    {
        cout << val << " ";
    }

    cout << "\nSmaller Array : ";
    for (int val : arrSmaller)
    {
        cout << val << " ";
    }

    cout << "\nMerged Array : ";
    for (int val : ans)
    {
        cout << val << " ";
    }

    return 0;
}