#include <iostream>
#include <string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<stack>
using namespace std;

int main()
{
    int n;
    int k;
    
    while (cin >> n) {
        int num = 1;
        k = 1;

        while (1) {
            if (num % n == 0) {
                break;
            }
            else {
                k++;
                num = num * 10 + 1;
                num %= n;
            }
        }

        cout << k << "\n";
    }


    
    return 0;
}