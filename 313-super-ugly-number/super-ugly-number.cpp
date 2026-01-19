class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<long long> ugly(n);
        ugly[0] = 1;

        vector<int> idx(k, 0);           // pointers for primes
        vector<long long> next(k);       // next multiples

        for (int i = 0; i < k; i++) {
            next[i] = primes[i];
        }

        for (int i = 1; i < n; i++) {
            long long nextUgly = *min_element(next.begin(), next.end());
            ugly[i] = nextUgly;

            for (int j = 0; j < k; j++) {
                if (next[j] == nextUgly) {
                    idx[j]++;
                    next[j] = ugly[idx[j]] * primes[j];
                }
            }
        }

        return (int)ugly[n - 1];
    }
};
