#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    double minMaxDist(vector<int> &stations, int K) {
        // Code here
        int len = stations.size();
        std::priority_queue<pair<double, int>> maxHeap;
        unordered_map<int, int> occ_map; 

        for (int i=1; i < len ; i++) {
          double dist = stations[i] - stations[i-1];
          maxHeap.push({dist, i});
        }

        int added = 0;
        while (added < K) {
          added += 1;
          double top = maxHeap.pop();
          double dist = (stations[i] - stations[i-1]) / (double) ++occ_map[top.1];
        
          maxHeap.push({dist, i});
        }

        return maxHeap.top();
    }
};