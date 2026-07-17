#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int findCeleb(vector<vector<int>> mat)
{

    // hme n * n ki matrix bnane h jisme m[i][j] =0 ka mtlab i j ko janta nhi h aur =1 hua to janta h
    // hme aisa index dhoondna h jo khud kisi ko nhi janta par sab use janta h ya kho
    // hme aise index dhoondna h jiske liye m[i][celeb] = 1 ho sabhi i ke liye aur m[celeb][i] = 0 ho ...
    // ab uske liye sabse pehle stack me sare index push kar liye..
    // ab while loop ke har iteration me ek index eliminate karenge ek condition ke through seee if lese inside while loop
    // uske bad last me ek bachega but hmne wrong ko eliminate kiya iska matlab ye nhi jo bacha wo sahi h
    // to last loop me us last element ke liye try karenge..
    // aur ha usme ek aur cheez koi banda khudko jane wala index i mean m[i][i] for each i can be 0 no problem ...
    stack<int> s;
    for (int i = 0; i < mat.size(); i++)
    {
        s.push(i);
    }
    while (s.size() > 1)
    {
        int i = s.top();
        s.pop();
        int j = s.top();
        s.pop();

        if (mat[i][j] == 0)
        {
            s.push(i); // i,j 0 matlab i j ko nhi janta to j celeb nhi ho skta...
        }
        else
        {
            s.push(j); // agar i,j 1 matlab i j ko janta h aur celeb kisi ko nhi jan skta....
        }
    }

    int celeb = s.top();
    s.pop();

    for (int i = 0; i < mat.size(); i++)
    {
        if (i != celeb && (mat[i][celeb] == 0 || mat[celeb][i] == 1))
        {
            return -1;
        }
    }
    return celeb;
}

int main()
{

    vector<vector<int>> mat = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    int celeb = findCeleb(mat);

    if (celeb == -1)
    {
        cout << "No celebrity found.";
    }

    else
    {
        cout << "Celebrity among all is at index : " << celeb;
    }
    return 0;
}