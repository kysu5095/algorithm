#include <cstdio>

 

using namespace std;

 

long long Sigma(int N)

{

    return 1LL * N * (N + 1LL) / 2LL;

}

 

int main()

{

    int N, K, R = 0, C = 0;

    scanf("%d %d\n", &N, &K);

    long long result = 1;

    for (int i = 0; i < K; i++)

    {

        switch (getchar())

        {

        case 'U':

            --R;

            break;

        case 'D':

            ++R;

            break;

        case 'L':

            --C;

            break;

        default:

            ++C;

        }

        

        // 좌표를 이용해서 값을 얻어낼 수 있다.

        long long first, dist;

        if (R + C < N)

        {

            // 각 줄은 1의 등차수열이다.

            // 첫번째 값을 얻어내고

            first = 1LL + Sigma(R + C);

            // 첫번쨰 값의 좌표로부터 얼마나 떨어져 있는지를 계산한다.

            dist = ((R + C) % 2 ? R : C);

        } 

        // 여기를 계산할 때 주의해야 한다.

        else

        {

            first = 1LL + Sigma(N) + Sigma(N - 1) - Sigma(2 * N - (R + C + 1));

            dist = ((R + C) % 2 ? R : C) - ((long long)R + C - N + 1);

        }

        result += (first + dist);

    }

 

    printf("%lld\n", result);

}



출처: https://haedallog.tistory.com/161 [SM's Development Log]