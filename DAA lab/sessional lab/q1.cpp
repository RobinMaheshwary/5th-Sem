// Implement a priority queue using heap.


#include <iostream>
#include <vector>
using namespace std;

void priority_Queue(vector<int> &heap, int size)
{
    int i = size - 1;
    while (i > 0 && heap[i] > heap[(i - 1) / 2])
    {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void pop(vector<int> &heap, int size)
{
    if (size == 0)
        return;
    heap[0] = heap[size - 1];
    heap.pop_back();
    size--;
    int i = 0;
    while (i < size)
    {
        int l = 2 * i + 1, r = 2 * i + 2;
        if (l >= size)
            break;
        if (r >= size)
        {
            if (heap[i] < heap[l])
                swap(heap[i], heap[l]);
            break;
        }
        if (heap[i] < heap[l] && heap[l] >= heap[r])
        {
            swap(heap[i], heap[l]);
            i = l;
        }
        else if (heap[i] < heap[r] && heap[r] >= heap[l])
        {
            swap(heap[i], heap[r]);
            i = r;
        }
        else
            break;

    }
    
}

int main()
{
    cout << "20051828, robin" << endl;
    vector<int> heap;
    int n;
    cin >> n;
    int size = n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        heap.push_back(x);
        priority_Queue(heap, size);
    }

    while (size > 0)
    {
        cout << heap[0] << " ";
        pop(heap, size);
        size--;
        
    }
    return 0;
}