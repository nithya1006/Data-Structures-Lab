//To implement Priority Queue ADT using a max heap
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    int parent(int i);
    int left(int i);
    int right(int i);
    void heapifyUp(int index);
    void heapifyDown(int index);
    void heapifyDownTemp(vector<int>& h, int index);

public:
    void insert(int val);
    int deleteMax();
    void display();
    void search(int key);
    void heapSort();
};

int main() {
    MaxHeap pq;
    int choice, value, deleted;

    do {
        cout << "\nMenu\n";
        cout << "1. Insert\n2. Delete (Max)\n3. Display\n4. Search\n5. Sort (Heap Sort)\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                pq.insert(value);
                break;

            case 2:
                deleted = pq.deleteMax();
                if (deleted != -1){
                    cout << "Deleted element: " << deleted << "\n";
                }
                break;
            
            case 3:
                pq.display();
                break;

            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                pq.search(value);
                break;

            case 5:
                pq.heapSort();
                break;

            case 6:
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}

int MaxHeap::parent(int i) {
    return (i - 1) / 2;
}

int MaxHeap::left(int i) {
    return 2 * i + 1;
}

int MaxHeap::right(int i) {
    return 2 * i + 2;
}

// For insertion
void MaxHeap::heapifyUp(int index) {
    while (index > 0 && heap[parent(index)] < heap[index]) {
        swap(heap[parent(index)], heap[index]);
        index = parent(index);
    }
}

// For deletion
void MaxHeap::heapifyDown(int index) {
    int largest = index;
    int leftIdx = left(index);
    int rightIdx = right(index);

    if (leftIdx < heap.size() && heap[leftIdx] > heap[largest])
        largest = leftIdx;
    if (rightIdx < heap.size() && heap[rightIdx] > heap[largest])
        largest = rightIdx;

    if (largest != index) {
        swap(heap[index], heap[largest]);
        heapifyDown(largest);
    }
}

// To insert an element
void MaxHeap::insert(int val) {
    heap.push_back(val);
    heapifyUp(heap.size() - 1);
}

// To delete an element
int MaxHeap::deleteMax() {
    if (heap.empty()) {
        cout << "Priority Queue is empty. Cannot delete.\n";
        return -1;  
    }

    int maxValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
    return maxValue;
}


// To display heap
void MaxHeap::display() {
    if (heap.empty()) {
        cout << "Priority Queue is empty.\n";
        return;
    }
    cout << "Priority Queue (Max Heap): ";
    for (int val : heap)
        cout << val << " ";
    cout << "\n";
}

// To search for an element
void MaxHeap::search(int key) {
    auto it = find(heap.begin(), heap.end(), key);
    if (it != heap.end())
        cout << key << " found at index " << distance(heap.begin(), it) << ".\n";
    else
        cout << key << " not found in the priority queue.\n";
}

// Heap sort in descending order
void MaxHeap::heapSort() {
    if (heap.empty()) {
        cout << "Priority Queue is empty. Cannot sort.\n";
        return;
    }

    vector<int> tempHeap = heap;
    vector<int> sorted;

    while (!tempHeap.empty()) {
        sorted.push_back(tempHeap[0]);
        tempHeap[0] = tempHeap.back();
        tempHeap.pop_back();
        heapifyDownTemp(tempHeap, 0);
    }

    cout << "Sorted elements (descending): ";
    for (int val : sorted)
        cout << val << " ";
    cout << "\n";
}

// Helper function for heap sort
void MaxHeap::heapifyDownTemp(vector<int>& h, int index) {
    int largest = index;
    int l = 2 * index + 1;
    int r = 2 * index + 2;

    if (l < h.size() && h[l] > h[largest])
        largest = l;
    if (r < h.size() && h[r] > h[largest])
        largest = r;

    if (largest != index) {
        swap(h[index], h[largest]);
        heapifyDownTemp(h, largest);
    }
}
