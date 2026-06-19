#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int max_coupons = n + 1;

    vector<vector<int>> min_sums(n + 1, vector<int>(max_coupons, INF));

    vector<vector<int>> prev_coupons(n + 1, vector<int>(max_coupons, -1));
    vector<vector<int>> prev_action(n + 1, vector<int>(max_coupons, 0));

    min_sums[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        int price = prices[i - 1];
        for (int j = 0; j < max_coupons; j++) {
            if (price > 500) {
                if (j > 0 && min_sums[i - 1][j - 1] != INF && min_sums[i - 1][j - 1] + price < min_sums[i][j]) {
                    min_sums[i][j] = min_sums[i - 1][j - 1] + price;
                    prev_action[i][j] = 1;
                    prev_coupons[i][j] = j - 1;
                }
            }
            else {
                if (min_sums[i - 1][j] != INF && min_sums[i - 1][j] + price < min_sums[i][j]) {
                    min_sums[i][j] = min_sums[i - 1][j] + price;
                    prev_action[i][j] = 1;
                    prev_coupons[i][j] = j;
                }
            }

            if (j + 1 < max_coupons && min_sums[i - 1][j + 1] != INF && min_sums[i - 1][j + 1] < min_sums[i][j]) {
                min_sums[i][j] = min_sums[i - 1][j + 1];
                prev_action[i][j] = 2;
                prev_coupons[i][j] = j + 1;
            }
        }
    }

    int min_cost = INF;
    int final_j = 0;
    for (int j = 0; j < max_coupons; j++) {
        if (min_sums[n][j] < min_cost) {
            min_cost = min_sums[n][j];
            final_j = j;
        }
    }

    vector<int> coupon_days;
    int curr_j = final_j;

    for (int i = n; i >= 1; i--) {
        if (prev_action[i][curr_j] == 2) {
            coupon_days.push_back(i);
        }
        curr_j = prev_coupons[i][curr_j];
    }

    reverse(coupon_days.begin(), coupon_days.end());

    cout << min_cost << " " << coupon_days.size() << endl;
    if (!coupon_days.empty()) {
        for (size_t i = 0; i < coupon_days.size(); i++) {
            cout << coupon_days[i];
            if (i != coupon_days.size() - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}