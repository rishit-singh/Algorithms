#include <iostream>
#include <vector>

// A program to implement Sieve of Eratosthenes to obtain prime numbers up to a certain limit
// The time complexity is O(n(log(log(n))))
// Intuition: Summation of reciprocals of prime numbers, i.e 1/2 + 1/3 + 1/5 + 1/7 + ...

using namespace std;

int main()  {
    long long int limit;
    cin >> limit;
    long long int counter;
    vector<bool> isPrime;

    for (long long int i = 0; i <= limit; i++)   
        isPrime.push_back(1);
    
    for (counter = 2; counter <= limit; counter++)  {

        if (isPrime[counter] == 1)  {
            for (long long int i = counter * counter; i <= limit; i += counter)
                isPrime[i] = 0;
        }

    }

    for (long long int i = 2; i <= limit; i++)
        if (isPrime[i] == 1)    
            cout << i << " ";

    cout << "\n";

    return 0;
}
