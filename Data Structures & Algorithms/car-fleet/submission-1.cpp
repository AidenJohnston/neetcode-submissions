class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;

        std::vector<std::pair<int, double>> cars(n);
        for (int x = 0; x < n; x++) {
            double time = (double)(target-position[x]) / (speed[x]);
            cars[x] = {position[x], time};
        }

        std::sort(cars.begin(), cars.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        int fleets {0};
        double max_time = 0.0f;

        for (int x = 0; x < n; x++) {
            if (cars[x].second > max_time) {
                fleets++;
                max_time = cars[x].second;
            }
        }
        
        return fleets;
    }
};
