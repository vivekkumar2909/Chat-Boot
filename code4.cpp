#include <bits/stdc++.h>
using namespace std;

int dynamic_priority(int N, vector<int> &priorities, int K)
{
    // Priority queue to store the document priorities and their original indices
    priority_queue<pair<int, int>> pq;
    // Queue to maintain the order of documents
    queue<pair<int, int>> q;

    // Initialize priority queue and the queue with document priorities and indices
    for (int i = 0; i < N; i++)
    {
        pq.push({priorities[i], i});
        q.push({priorities[i], i});
    }
