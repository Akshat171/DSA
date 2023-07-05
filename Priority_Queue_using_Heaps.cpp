#include <bits/stdc++.h>
using namespace std;

// create an heap array
int Heap[50];
// initial size assigning -->1
int size = -1;

// parent of any index will be the index avail at (i/2) position (if 1 indexing) OW (i-1)/2;
int parent(int i)
{
    return (i - 1) / 2;
}

// left child for a node with given index is always available in its next power of one value.
int leftChild(int i)
{
    return ((2 * i) + 1);
}

// right child for any node with given index is always avail able in its next power of two value.
int rightChild(int i)
{
    return ((2 * i) + 2);
}

// if we adding the index at the last position then shift it in the heap based on its priority by compairing it to its patent index
void shiftUp(int i)
{
    while (i > 0 && Heap[parent(i)] < Heap[i])
    {
        swap(Heap[parent(i)], Heap[i]);
        i = parent(i);
    }
}

// if we wnat to shift any index based on its priority from upper side to down side the n we have to capre the value of the index with its left and right childs
void shiftDown(int i)
{
    int maxIndex = i;

    int l = leftChild(i);
    if (l <= size && Heap[l] > Heap[maxIndex])
    {
        maxIndex = l;
    }

    int r = rightChild(i);
    if (r <= size && Heap[r] > Heap[maxIndex])
    {
        maxIndex = r;
    }
    // if at the last maxIndex index and current index are not equal the swap them
    if (maxIndex != i)
    {
        swap(Heap[maxIndex], Heap[i]);
        shiftDown(maxIndex); // recursive approach for the child of that maxIndex
    }
}

// insert any number at the last position
void Insert(int p)
{
    size = size + 1;
    Heap[size] = p;

    shiftUp(size);
}

// extracting maximum number fro the root index of the Heap
int extractMax()
{
    int result = Heap[0];

    Heap[0] = Heap[size];
    size = size - 1;

    shiftDown(0);
    return result;
}

void changePriority(int i, int p)
{
    int oldP = Heap[i];
    Heap[i] = p;

    if (p > oldP)
    {
        shiftUp(i);
    }
    else
    {
        shiftDown(i);
    }
}

int getmax()
{
    return Heap[0];
}

void remove(int i)
{
    Heap[i] = getmax() + 1;

    shiftUp(i);

    extractMax();
}
int main()
{
    //        17
    //       / \
    //     13  7
    //   /  \  / \
    //  11  2 4  5
    //  / \
    // 1  3
    Insert(4);
    Insert(2);
    Insert(5);
    Insert(1);
    Insert(3);
    Insert(7);
    Insert(11);
    Insert(13);
    Insert(17);

    int i = 0;

    // Priority queue before extracting max
    cout << "Priority Queue : ";
    while (i <= size)
    {
        cout << Heap[i] << " ";
        i++;
    }

    cout << endl;

    cout << "Node with maximum priority : "
         << extractMax() << "\n";

    cout << endl;
    cout << "Priority queue after "
         << "extracting maximum : ";
    int j = 0;
    while (j <= size)
    {
        cout << Heap[j] << " ";
        j++;
    }

    changePriority(2, 4);
    cout << "Priority queue after "
         << "priority change : ";
    int k = 0;
    while (k <= size)
    {
        cout << Heap[k] << " ";
        k++;
    }

    cout << "\n";

    // Remove element at index 3
    remove(3);
    cout << "Priority queue after "
         << "removing the element : ";
    int l = 0;
    while (l <= size)
    {
        cout << Heap[l] << " ";
        l++;
    }
    return 0;
}
