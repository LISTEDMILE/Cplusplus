#include <iostream>
using namespace std;

/*
    Problem:
    Find the sum of two integers without using '+' or '-'.

    Idea:
    1. XOR (^) gives the sum without considering carry.
    2. AND (&) finds the carry bits.
    3. Left shift (<< 1) moves the carry to the next position.
    4. Repeat until there is no carry left.
*/

class Solution
{
public:
    int getSum(int a, int b)
    {

        // Continue until there is no carry
        while (b != 0)
        {

            // Calculate carry
            int carry = (a & b) << 1;

            // Sum without carry
            a = a ^ b;

            // Update carry for the next iteration
            b = carry;
        }

        return a;
    }
};

int main()
{

    Solution obj;

    int a, b;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    cout << "Sum = " << obj.getSum(a, b) << endl;

    return 0;
}