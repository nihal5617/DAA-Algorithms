/ C++ Program to implement 0 / 1
// knapsack using LC Branch and Bound

#include <bits/stdc++.h>
    using namespace std;

// Stores the number of items
int size;

// Stores the knapsack capacity
float capacity;

typedef struct Item
{

    // Stores the weight of items
    float weight;

    // Stores the value of items
    int value;

    // Stores the index of items
    int idx;
} Item;

typedef struct Node
{

    // Upper Bound: Best case
    // (Fractional Knapsack)
    float ub;

    // Lower Bound: Worst case (0/1)
    float lb;

    // Level of the node
    // in the decision tree
    int level;

    // Stores if the current item is
    // selected or not
    bool flag;

    // Total Value: Stores the sum of the
    // values of the items included
    float tv;

    // Total Weight: Stores the sum of the
    // weights of the items included
    float tw;
} Node;

// Function to calculate upper bound
// (includes fractional part of the items)
float upper_bound(float tv, float tw,
                  int idx, vector<Item> &arr)
{
    float value = tv;
    float weight = tw;
    for (int i = idx; i < size; i++)
    {
        if (weight + arr[i].weight <= capacity)
        {
            weight += arr[i].weight;
            value -= arr[i].value;
        }
        else
        {
            value -= (float)(capacity - weight) / arr[i].weight * arr[i].value;
            break;
        }
    }
    return value;
}

// Function to calculate lower bound (doesn't
// include fractional part of the items)
float lower_bound(float tv, float tw,
                  int idx, vector<Item> &arr)
{
    float value = tv;
    float weight = tw;
    for (int i = idx; i < size; i++)
    {
        if (weight + arr[i].weight <= capacity)
        {
            weight += arr[i].weight;
            value -= arr[i].value;
        }
        else
        {
            break;
        }
    }
    return value;
}

class comp
{
public:
    bool operator()(Node a, Node b)
    {
        return a.lb > b.lb;
    }
};

void assign(Node &a, float ub, float lb,
            int level, bool flag,
            float tv, float tw)
{
    a.ub = ub;
    a.lb = lb;
    a.level = level;
    a.flag = flag;
    a.tv = tv;
    a.tw = tw;
}

void knapsack(vector<Item> &arr)
{

    // Sort the items based on the
    // profit/weight ratio
    sort(arr.begin(), arr.end(),
         [&](Item &a, Item &b)
         {
             return a.value / a.weight > b.value / b.weight;
         });

    // min_lb -> Minimum lower bound
    // of all the nodes explored

    // final_lb -> Minimum lower bound
    // of all the paths that reached
    // the final level
    float min_lb = 0, final_lb = INT_MAX;

    // curr_path -> Boolean array to store
    // at every index if the element is
    // included or not

    // final_path -> Boolean array to store
    // the result of selection array when
    // it reached the last level
    bool curr_path[size], final_path[size];

    // Priority queue to store the nodes
    // based on lower bounds
    priority_queue<Node, vector<Node>,
                   comp>
        pq;

    Node current, left, right;
    current.lb = current.ub = current.tw = current.tv = current.level = current.flag = 0;

    // Insert a dummy node
    pq.push(current);

    for (int i = 0; i < size; i++)
        curr_path[i] = final_path[i] = false;

    while (!pq.empty())
    {
        current = pq.top();
        pq.pop();

        if (current.ub > min_lb || current.ub >= final_lb)
        {

            // If the current node's best case
            // value is not optimal than min_lb,
            // then there is no reason to explore
            // that path including final_lb
            // eliminates all those paths whose
            // best values is equal to final_lb
            continue;
        }

        // update the path
        if (current.level != 0)
            curr_path[current.level - 1] = current.flag;

        if (current.level == size)
        {
            // Reached last level
            if (current.lb < final_lb)
                for (int i = 0; i < size; i++)
                    final_path[arr[i].idx] = curr_path[i];
            final_lb = min(current.lb, final_lb);
            continue;
        }

        int level = current.level;

        // right node -> Excludes current item
        // Hence, cp, cw will obtain the value
        // of that of parent
        assign(right,
               upper_bound(current.tv,
                           current.tw, level + 1,
                           arr),
               lower_bound(current.tv, current.tw,
                           level + 1, arr),
               level + 1, false,
               current.tv, current.tw);

        // Check whether adding the current
        // item will not exceed the knapsack weight
        if (current.tw + arr[current.level].weight <= capacity)
        {

            // left node -> includes current item
            // c and lb should be calculated
            // including the current item.
            left.ub = upper_bound(
                current.tv - arr[level].value,
                current.tw + arr[level].weight,
                level + 1, arr);

            left.lb = lower_bound(
                current.tv - arr[level].value,
                current.tw + arr[level].weight,
                level + 1, arr);

            assign(left, left.ub, left.lb,
                   level + 1, true,
                   current.tv - arr[level].value,
                   current.tw + arr[level].weight);
        }

        // If Left node cannot be inserted
        else
        {

            // Stop the left node from
            // getting added to the
            // priority queue
            left.ub = left.lb = 1;
        }

        // Update the lower bound
        min_lb = min(min_lb, left.lb);
        min_lb = min(min_lb, right.lb);

        // Exploring nodes whose
        // upper bound is greater than
        // min_lb will never give
        // the optimal result

        if (min_lb >= left.ub)
            pq.push(left);
        if (min_lb >= right.ub)
            pq.push(right);
    }

    cout << "Items taken into the"
         << " knapsack are : \n";
    if (final_lb == INT_MAX)
        final_lb = 0;
    for (int i = 0; i < size; i++)
        cout << final_path[i] << " ";
    cout << "\n";
    cout << "Maximum profit is : "
         << (-final_lb) << "\n";
}

// Driver Code
int main()
{
    size = 4;

    capacity = 15;

    vector<Item> arr;
    arr.push_back({2, 10, 0});
    arr.push_back({4, 10, 1});
    arr.push_back({6, 12, 2});
    arr.push_back({9, 18, 3});

    knapsack(arr);

    return 0;
}
