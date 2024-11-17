#include <iostream>
#include <cmath>

using namespace std;

double P0(const int N, const int K)
{
    double n = 1.0;
    for (int i = N; i <= K; i++)
        n += (1.0 * i * N) / ((1.0 * i * i) + (1.0 * N * N));
    return n;
}
double P1(const int N, const int K, const int i)
{
    if (i > K)
        return 1;
    else
        return (1.0 * i * N) / (1.0 * i * i + 1.0 * N * N) * P1(N, K, i + 1);
}
double P2(const int N, const int K, const int i)
{
    if (i < N)
        return 1;
    else
        return (1.0 * i * N) / (1.0 * i * i + 1.0 * N * N) * P2(N, K, i - 1);
}
double P3(const int N, const int K, const int i, double t)
{
    t = t * (1.0 * i * N) / (1.0 * i * i + 1.0 * N * N);
    if (i >= K)
        return t;
    else
        return P3(N, K, i + 1, t);
}
double P4(const int N, const int K, const int i, double t)
{
    t = t * (1.0 * i * N) / (1.0 * i * i + 1.0 * N * N);
    if (i <= N)
        return t;
    else
        return P4(N, K, i - 1, t);
}

int main()
{
    int N;
    int K = 16;

    cout << "N = "; cin >> N;
    cout << "(Iter) P0 = " << P0(K, N) << endl;
    cout << "(Rec up ++) P1 = " << P1(K, N, K) << endl;
    cout << "(Rec up --) P2 = " << P2(K, N, N) << endl;
    cout << "(Rec down ++) P3 = " << P3(K, N, K, 0) << endl;
    cout << "(Rec down --) P4 = " << P4(K, N, N, 0) << endl;

    return 0;
}