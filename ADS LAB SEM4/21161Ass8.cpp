
#include <bits/stdc++.h>
using namespace std;

class OBST
{
    int *freq, *key;
    int size;

public:
    OBST(int n)
    {
        size = n;
        freq = new int[n];
        key = new int[n];
    }

    void readNodes()
    {
        cout << "Enter the nodes and corresponding frequencies in increasing order." << endl;

        for (int i = 0; i < size; i++)
        {
            cout << "Enter the {" << i << "} node:";
            cin >> key[i];
            cout << "Enter its frequency:";
            cin >> freq[i];
        }
    }
    // A utility function to get sum of
    // array elements freq[i] to freq[j]
    int sumOf(int i, int j)
    {
        int s = 0;
        for (int k = i; k <= j; k++)
            s += freq[k];
        return s;
    }

    // A recursive function to calculate
    // cost of optimal binary search tree
    int optCost(int i, int j)
    {
        // Base cases
        if (j < i) // no elements in this subarray
            return 0;
        if (j == i) // one element in this subarray
            return freq[i];

        // Get sum of freq[i], freq[i+1], ... freq[j]
        int fsum = sumOf(i, j);

        // Initialize minimum value
        int min = INT_MAX;

        // One by one consider all elements
        // as root and recursively find cost
        // of the BST, compare the cost with
        // min and update min if needed
        for (int r = i; r <= j; ++r)
        {
            int cost = optCost(i, r - 1) +
                       optCost(r + 1, j);
            if (cost < min)
                min = cost;
        }

        // Return minimum value
        return min + fsum;
    }

    // The main function that calculates
    // minimum cost of a Binary Search Tree.
    // It mainly uses optCost() to find
    // the optimal cost.
    int optimalSearchTree()
    {
        // Here array keys[] is assumed to be
        // sorted in increasing order. If keys[]
        // is not sorted, then add code to sort
        // keys, and rearrange freq[] accordingly.
        return optCost(0, size - 1);
    }
};

int main()
{
    int size;
    cout << "Enter the no. of nodes: ";
    cin >> size;
    OBST o(size);
    o.readNodes();
    cout << "--------------------------------------------" << endl;
    cout << "Cost of Optimal BST is "
         << o.optimalSearchTree() << endl;
    cout << "--------------------------------------------" << endl;
    return 0;
}
