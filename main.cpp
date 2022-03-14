#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int DIM = 6;

int main() {

    int myPoints[DIM][DIM] = {{0, 875000, 1057064, 1557980, 2980494, 4162323},
                              {875000, 0, 533769, 717200, 2375030, 3295278},
                              {1057064, 533769, 0, 1029000, 2801487, 3380146},
                              {1557980, 717200, 1029000, 0, 1786070, 2610053},
                              {2980494, 2375030, 2801487, 1786070, 0, 2319104},
                              {4162323, 3295278, 3380146, 2610053, 2319104, 0}
                              };

    int minCost = INT_MAX;
    int currentCost = 0;
    vector<int> bestRoute;
    vector<int> route;
    int legCost = 0;

    for (int i = 0; i < DIM; ++i)
        route.insert(route.end(), i);


    route.insert(route.end(), 0);

    while (next_permutation(route.begin() + 1, route.end() - 1)) {
        currentCost = 0;
        for (int i = 0; i < DIM; i++) {
            legCost = myPoints[route[i]][route[i + 1]];
            if (legCost == INT_MAX || currentCost == INT_MAX)
                currentCost = INT_MAX;
            else
                currentCost += legCost;

        }
        if (currentCost < minCost) {
            minCost = currentCost;
            bestRoute = route;
        }
    }

    cout << "Best route: ";
    for (int i = 0; i < DIM + 1; i++)
        cout << bestRoute[i]<<"  ";

    cout << '\n' <<"Total cost: " << minCost << '\n';
    return 0;
}
