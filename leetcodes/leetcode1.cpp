#include <iostream>
using namespace std;
class leetcode1
{
    private:
    int digit;
    int sum = 0;
    int p = 1;
    int answer;
public:
    
    int sub_pro_subtract(int n)
    {
        while (n != 0)
        {
            digit = n % 10;
            n = n / 10;
            p = p * digit;
            sum = sum + digit;
        }
        answer = p - sum;
        cout << "the answer is" << answer;
    }
};

int main()
{
    int n;
    cout << "enter a number";
    cin >> n;
    leetcode1 obj;
    obj.sub_pro_subtract(n);
    return 0;
}