#include "../utils/Solution.hpp"
int Solution::minCostConnectPoints(vector<vector<int>>& points) {
    int cost = 0;
    int size = points.size();
    std::set<int> unvisited;
    //populate the unvisted set
    for (int i = 1; i < size; ++i) {
        unvisited.insert(i);
    }
    //create minimum priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minpq;
    //initialize min heap with possible paths from starting point
    for (int i = 1; i < size; ++i) {
        minpq.push(std::make_pair (abs(points[0][0] - points[i][0]) + abs(points[0][1] - points[i][1]), i) );
    }
    // main loop
    while(!unvisited.empty()) {
        cost += minpq.top().first;
        int index = minpq.top().second;
        minpq.pop();
        //move remove index from unvisited
        unvisited.erase(index);
        std::cout << "Erasing " << index << " from unvisited. Unvisted size is now " << unvisited.size() << std::endl;
        //delete minimum paths from min heap that have been visited
        while(!unvisited.empty() && !unvisited.count(minpq.top().second)) {
            minpq.pop();
        }
        //add paths to min heap from recently accessed point
        for (int i = 0; i < size; ++i) {
            if (unvisited.count(i)) {
                minpq.push( make_pair( abs(points[index][0] - points[i][0]) + abs(points[index][1] - points[i][1]), i ));
            }
        }
    }
    return cost;
}