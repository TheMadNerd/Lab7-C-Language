#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 

uint64_t power_modulo_fast(uint64_t a, uint64_t b, uint64_t m)
{
    uint64_t i;
    uint64_t result = 1;
    uint64_t x = a % m;

    for (i = 1; i <= b; i <<= 1)
    {
        x %= m;
        if ((b & i) != 0)
        {
            result *= x;
            result %= m;
        }
        x *= x;
    }

    return result;
}

int Miller_Rabin(uint64_t n, int k)
{
    int s = 0;
    uint64_t s2 = 1;
    uint64_t a, d, i, r, prime;

    if (n < 4)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return 0;
    }

    while ((s2 & (n - 1)) == 0)
    {
        s += 1;
        s2 <<= 1;
    }
    d = n / s2;

    for (i = 0; i < k; i++)
    {
        a = 1 + ((n - 1) * rand() / (RAND_MAX + 1.0));
        if (power_modulo_fast(a, d, n) != 1)
        {
            prime = 0;
            for (r = 0; r <= s - 1; r++)
            {
                if (power_modulo_fast(a, (uint64_t)1 << r * d, n) == n - 1)
                {
                    prime = 1;
                    break;
                }
            }
            if (prime == 0)
            {
                return 0;
            }
        }
    }

    return 1;
}

int main()
{
    uint64_t n;
    int k;

    printf("Podaj liczbe do sprawdzenia.\n");
    scanf("%lu", &n); 

    printf("Podaj dokladnosc sprawdzenia.\n");
    scanf("%d", &k);

    if (Miller_Rabin(n, k) == 1)
    {
        printf("Liczba jest prawdopodobnie pierwsza.\n");
    }
    else
    {
        printf("Liczba jest zlozona.\n");
    }

    return 0;
}
