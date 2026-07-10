class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> passenger_changes;
        
        for (const auto& trip : trips) {
            int numPassengers = trip[0];
            int from = trip[1];
            int to = trip[2];
            
            // Add passengers at the pick-up location
            passenger_changes[from] += numPassengers;
            // Subtract passengers at the drop-off location
            passenger_changes[to] -= numPassengers;
        }
        
        int current_passengers = 0;
        
        // Iterate through the map chronologically (West to East)
        for (const auto& [location, change] : passenger_changes) {
            current_passengers += change;
            
            // If at any point capacity is exceeded, return false
            if (current_passengers > capacity) {
                return false;
            }
        }
        
        return true;
}
};