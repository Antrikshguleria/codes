#include <iostream>
using namespace std;
#include <queue>

int main()
{
    // max heap
    //  priority_queue<int> pq;

    // pq.push(16);
    // pq.push(1);
    // pq.push(167);
    // pq.push(7);
    // pq.push(45);
    // pq.push(32);

    // cout << "size :" << pq.size() << endl;
    // cout << "Top :" << pq.top() << endl;

    // while (!pq.empty())
    // {
    //     cout << pq.top() << endl;
    //     pq.pop();
    // }
    // min heap
    priority_queue<int, vector<int>, greater<int> > pq;

    pq.push(16);
    pq.push(1);
    pq.push(167);
    pq.push(7);
    pq.push(45);
    pq.push(32);

    cout << "size :" << pq.size() << endl;
    cout << "Top :" << pq.top() << endl;

    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}