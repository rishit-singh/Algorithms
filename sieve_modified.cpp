#include <iostream>
#include <vector>

// A program to implement Sieve of Eratosthenes to obtain prime numbers up to a certain limit
// Contrary to the regular sieve algorithm, this one runs in O(n) time, by passing through all items once
// However, it has a much higher memory usage, due to the presence of two arrays of integer values, as opposed to 
// bit vectors or vector <bool>, which uses only one bit per item

#define MAX_SIZE 100000000

using namespace std;

int main()  {
    long long limit;
    cin >> limit;

    vector<long long> SPF(MAX_SIZE + 2, 0);
    vector<long long> primes;

    for (long long counter = 2; counter <= limit; counter++)  {

        // Any value with SPF = 0 is marked as prime, hence has its SPF equal to itself
        // Although expensive, this algorithm provides a way to mark factors of numbers,
        // which may be useful in some applications.

        if (SPF[counter] == 0)  {
            SPF[counter] = counter;
            primes.push_back(counter);
        }

        for (long long j = 0; j < (int)primes.size() && primes[j] <= SPF[counter] && (counter * primes[j] <= limit); j++)
            SPF[counter * primes[j]] = primes[j];

    }

    for (long long int x = 0; x < primes.size(); x++)
        cout << primes[x] << " ";

    cout << "\n";

    return 0;
}