#include <iostream>
#include <string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<stack>
using namespace std;
long long a, b, c;
long long func(int a, int b, int c) {
    if (b == 0) return 1;
    long long tmp = func(a, b / 2, c);
    tmp = tmp * tmp % c;
    if (b % 2 == 0) return tmp;
    else return tmp * a % c;
}
int main()
{
    
    cin >> a >> b >> c;

    
    cout << func(a, b, c);

    
    return 0;
}