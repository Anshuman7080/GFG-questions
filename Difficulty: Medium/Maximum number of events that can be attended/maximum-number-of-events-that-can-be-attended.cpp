//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

#include <vector>
#include <algorithm>
#include <queue>

class Solution {
public:
    int maxEvents(int start[], int end[], int N) {
        // Create a vector of events (start, end)
        std::vector<std::pair<int, int>> events(N);
        for (int i = 0; i < N; i++) {
            events[i] = {start[i], end[i]};
        }
        
        // Sort events by start day, then by end day
        std::sort(events.begin(), events.end());
        
        // Min-heap to track end days of scheduled events
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        int cnt = 0, day = 0, i = 0;

        while (i < N || !minHeap.empty()) {
            // If no events are scheduled, jump to the next start day
            if (minHeap.empty()) {
                day = events[i].first; // Move to the start of the next event
            }

            // Add all events that start on or before 'day' to the heap
            while (i < N && events[i].first <= day) {
                minHeap.push(events[i].second);
                i++;
            }

            
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }

           
            if (!minHeap.empty()) {
                minHeap.pop(); 
                cnt++; // Increment the count of events scheduled
            }

            // Move to the next day
            day++;
        }

        return cnt;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];

        Solution ob;
        cout << ob.maxEvents(start,end,N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends