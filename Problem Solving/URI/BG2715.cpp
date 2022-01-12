#include <iostream>
#include <vector>

int main()
{
    std::vector<long long> resSet{};
    long long n, temp, diff;

    while (std::cin >> n)
    {
        std::vector<long long> inputs{};
        std::vector<long long> sum{};

        for (auto i = 0; i < n; i++)
        {
            std::cin >> temp;
            inputs.emplace_back(temp);
            if (i == 0)
            {
                sum.emplace_back(temp);
            }
            else
            {
                sum.emplace_back(sum[i - 1] + temp);
            }
        }

        long long half = sum[sum.size() - 1] / 2;

        auto idx = 0;
        if (sum.size() > 1)
        {
            idx = sum.size() - 2;
        }

        while (sum[idx] > half)
        {
            if (idx == 0)
            {
                break;
            }

            idx--;
        }

        long long rsum1 = sum[sum.size() - 1] - sum[idx];
        long long rsum2 = sum[sum.size() - 1] - sum[idx + 1];

        if (idx == sum.size() - 1)
        {
            resSet.emplace_back(std::abs(rsum1 - sum[idx]));
        }
        else
        {
            long long diff1 = std::abs(rsum1 - sum[idx]);
            long long diff2 = std::abs(rsum2 - sum[idx + 1]);

            resSet.emplace_back(std::min(diff1, diff2));
        }
    }

    for (auto i : resSet)
    {
        std::cout << i << std::endl;
    }

    return 0;
}