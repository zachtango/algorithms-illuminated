#include <vector>
#include <utility>
#include <stack>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        /*
            position[i] position of ith car
            speed[i] speed of ith car (mph)

            car can never pass another car, can catch up to it and drive
                at the same speed (bumper to bumper)
            
            fast car slows down to match slower car's speed

            distance between these 2 cars ignored (they have same pos)

            a car fleet is some non empty set of cars driving at same position and speed

            if car catches up to car fleet at destination, consider it one car fleet

            return num car fleets arriving at destination
            
            Order position in greatest to least
            
            - store time it takes for car to get to target
                (target - position) / speed
        */

        vector<pair<int, int>> v;
        for (int i = 0; i < position.size(); i++) {
            v.push_back({position[i], speed[i]});
        }

        sort(v.begin(), v.end(), [](auto p1, auto p2) {
            return p1.first > p2.first;
        });

        vector<double> time(position.size(), 0);

        for (int i = 0; i < v.size(); i++) {
            time[i] = static_cast<double> (target - v[i].first) /
                        static_cast<double> (v[i].second);
        }

        int numCarFleets = 0;
        double lastTime = *time.rbegin();

        for (auto t : time) {
            if (t > lastTime) {
                lastTime = t;
                numCarFleets += 1;
            }
        }

        return numCarFleets;
    }
};
