#include <iostream>
#include <vector>

// A program to implement Sieve of Eratosthenes to obtain prime numbers up to a certain limit

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