
#define SCD(t) scanf("%d", &t)
#define SCLD(t) scanf("%ld", &t)
#define SCLLD(t) scanf("%lld", &t)
#define SCC(t) scanf("%c", &t)
#define SCS(t) scanf("%s", t)
#define SCF(t) scanf("%f", &t)
#define SCLF(t) scanf("%lf", &t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define REPR(i, j, k) FOR(i, j, k, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert(B <= A && A <= C)

vector<llong> onehot2list(vector<llong> arr)
{
    vector<llong> num;
    llong n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            num.push_back(i);
    }
    return num;
}

class PrimeHandler
{
public:
    static llong length;
    static VLL seive;
    static VLL primes;
    static void setLimit(int n)
    {
        length = n;
        seive = VLL(n + 1, 1);
        constructSeive();
        primes = onehot2list(seive);
    }

    static void constructSeive()
    {
        seive[0] = seive[1] = 0;
        for (int i = 2; i <= length; i++)
        {
            if (seive[i] == 0)
                continue;
            for (int j = i * 2; j <= length; j += i)
            {
                seive[j] = 0;
            }
        }
    }

    static VLL getSeive()
    {
        return seive;
    }

    static VLL getPrimes()
    {
        return primes;
    }

    static VPLL primeFactorize(llong num)
    {
        VPLL factors;
        llong iter = 0;
        while (num != 1)
        {
            llong count = 0;
            while (num != 1 && num % primes[iter] == 0)
            {
                count++;
                num /= primes[iter];
            }
            if (count)
            {
                factors.push_back({primes[iter], count});
            }
            iter++;
        }
        return factors;
    }

    llong countDivisors()
    {
        return 1;
    }
};

llong PrimeHandler::length = 0;
VLL PrimeHandler::seive{};
VLL PrimeHandler::primes{};
