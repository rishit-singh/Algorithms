#include <iostream>
#include <cmath>

// This is a program to determine the factorial of small numbers in C++
// which is something that requires more memory than even a long long int data type.
// We use a traditional multiplication algorithm.

using namespace std;

int multiply(int * number, int number_size, int i)  {
    int carry = 0;
    int prod = 0;
    for (int j = 0; j < number_size; j++)   {
        prod = (number[j] * i) + carry;
        number[j] = prod % 10;
        carry = prod / 10;
    }

    while (carry)   {
        number[number_size] = carry % 10;
        carry /= 10;
        number_size++;
    }

    return number_size;
}

void factorial()    {
    int n;
    cin >> n;
    int ans = 0;
    int number[1000] = {0};
    number[0] = 1;
    int number_size = 1;
    for (int i = 1; i <= n; i++) 
        number_size = multiply(number, number_size, i);

    for (int i = number_size - 1; i >= 0; i--)
        cout << number[i];
    
    cout << "\n";
}

int main()  {
    int t;
    cin >> t;
    while (t--)
        factorial();
    return 0;
}