

int IsPrime(n)
{
    int i, n;
    for (i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
        {
            printf(“Not Prime\n”);
            return 0;
        }
    return 1;
}