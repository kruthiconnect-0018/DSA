#include <stdlib.h>

int findCheapestPrice(int n, int** flights, int flightsSize,
                      int* flightsColSize, int src, int dst, int k)
{
    int *cost = (int *)malloc(n * sizeof(int));

    // Initially, all cities are unreachable
    for (int i = 0; i < n; i++)
        cost[i] = 1000000000;

    // Cost to reach source is 0
    cost[src] = 0;

    // At most k stops = k + 1 flights
    for (int i = 0; i <= k; i++)
    {
        // Copy previous costs
        int *temp = (int *)malloc(n * sizeof(int));

        for (int j = 0; j < n; j++)
            temp[j] = cost[j];

        // Try every flight
        for (int j = 0; j < flightsSize; j++)
        {
            int from = flights[j][0];
            int to = flights[j][1];
            int price = flights[j][2];

            if (cost[from] != 1000000000)
            {
                if (cost[from] + price < temp[to])
                {
                    temp[to] = cost[from] + price;
                }
            }
        }

        free(cost);
        cost = temp;
    }

    int answer = cost[dst];

    free(cost);

    if (answer == 1000000000)
        return -1;

    return answer;
}