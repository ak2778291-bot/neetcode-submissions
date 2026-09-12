class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        // Store each car as {position, speed}
        vector<pair<int, int>> cars;

        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        // Process cars from front to back
        sort(cars.rbegin(), cars.rend());

        // Stores the arrival time of each fleet
        vector<double> fleetTimes;

        for (auto car : cars) {

            int carPosition = car.first;
            int carSpeed = car.second;

            double arrivalTime =
                (double)(target - carPosition) / carSpeed;

            fleetTimes.push_back(arrivalTime);

            // If this car reaches the target earlier than
            // the fleet in front, it catches that fleet.
            if (fleetTimes.size() >= 2) {

                double currentTime = fleetTimes.back();
                double fleetAheadTime =
                    fleetTimes[fleetTimes.size() - 2];

                if (currentTime <= fleetAheadTime) {
                    fleetTimes.pop_back();
                }
            }
        }

        return fleetTimes.size();
    }
};