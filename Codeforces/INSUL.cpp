#include <algorithm>
#include <iostream>
using namespace std;

int a[100010],n;

int main()
{
//    freopen("insul.in","r",stdin);
//    freopen("insul.ou","w",stdout);
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);  sum += a[i];
    };
    sort(a,a + n);    
    for (int i = n - 1; i >= 0; i--)
    {
        int j = n - 1 - i;
        if (i <= j) break;
        sum += (a[i] - a[j]);
    };
    printf("%d\n", sum);
};