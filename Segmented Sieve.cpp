#include <iostream>
#include <vector>
#include <cmath>

// This programme calculates all prime numbers between two given numbers
// by making use of the Segmented Sieve of Eratosthenes
// which is an improvement upon the usual sieve, as it uses only sqrt(n) space
// and is much more cache-aware, hence results in a smaller number of cache misses.

void segmented_sieve(int m, int n)  {
    std::vector<bool> base_primes;
    std::vector<int> primes;
    int root = sqrt(n);

    for (int i = 0; i <= root; i++)
        base_primes.push_back(true);

    for (int i = 2; i <= root; i++)
        if (base_primes[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= root; j += i) 
                base_primes[j] = false;
            }

    std::vector<bool> range_primes(n - m + 1, true);
    
    for (auto x : primes) {
        int lower_limit = floor(m / x) * x;
        
        if (lower_limit < m)   
            lower_limit += x;
        
        if (lower_limit == x)
            lower_limit += x;
        
        for (int j = lower_limit; j <= n; j += x) {
            range_primes[j - m] = false;
        } 
    }

    for (int i = m; i <= n; i++)   {
        if (range_primes[i - m] && i != 1 && i != 0)
            std::cout << i << "\n";    
    }
}

int main()  {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> m >> n;
        segmented_sieve(m, n);
    }
    return 0;
}
