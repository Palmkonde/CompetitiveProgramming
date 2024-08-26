#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// DO NOT CHANGE
int n;
long long result;

// Function to count inversions in an array
long long merge(vector<int> &arr, int left, int right, int mid)
{
    vector<int> temp(right - left + 1);
    int inversions = 0;
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inversions += mid - i + 1;
        }
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (int i = left, k = 0; i <= right; ++i, ++k)
        arr[i] = temp[k];

    return inversions;
}

long long countInversions(vector<int> &arr, int left, int right)
{
    long long inversions = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        inversions += countInversions(arr, left, mid);
        inversions += countInversions(arr, mid + 1, right);
        inversions += merge(arr, left, right, mid);
    }
    return inversions;
}

long long countInversions(vector<int> &arr)
{
    int n = arr.size();
    return countInversions(arr, 0, n - 1);
}

// Function to check if a number is prime
bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    if (n <= 3)
    {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

// DO NOT CHANGE
vector<vector<int>> convertToMatrix(vector<int> &nums, int rows, int cols)
{
    vector<vector<int>> matrix(rows, vector<int>(cols));
    int index = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = nums[index++];
        }
    }
    return matrix;
}

std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2) {
    int m = mat1.size();
    int n = mat1[0].size();
    int p = mat2[0].size();

    std::vector<std::vector<int>> result(m, std::vector<int>(p, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return result;
}


struct Edge
{
    int src, dest, weight;
};

struct CompareEdge
{
    bool operator()(const Edge &e1, const Edge &e2)
    {
        return e1.weight < e2.weight;
    }
};

int findParent(int u, vector<int> &parent)
{
    while (parent[u] != u)
    {
        parent[u] = parent[parent[u]];
        u = parent[u];
    }
    return u;
}

void merge(int u, int v, vector<int> &parent)
{
    parent[v] = u;
}

vector<Edge> findMST(vector<Edge> &edges, int n)
{
    vector<Edge> result;
    sort(edges.begin(), edges.end(), CompareEdge());
    vector<int> parent(n);
    for (int i = 0; i < n; ++i)
    {
        parent[i] = i;
    }
    for (Edge edge : edges)
    {
        int u = findParent(edge.src, parent);
        int v = findParent(edge.dest, parent);
        if (u != v)
        {
            result.push_back(edge);
            merge(u, v, parent);
        }
    }
    return result;
}

// Binary Search Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
    if (start > end)
        return NULL;
    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(nums, start, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, end);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size() - 1);
}

// Interface for vehicles that can drive
class Drivable {
public:
    virtual void drive() = 0; // Pure virtual function
    virtual ~Drivable() {}    // Virtual destructor for correct deletion of derived classes
};

// Interface for vehicles that can fly
class Flyable {
public:
    virtual void fly() = 0; // Pure virtual function
    virtual ~Flyable() {}   // Virtual destructor for correct deletion of derived classes
};

// Base class for vehicles
class Vehicle {
public:
    void start() {
        std::cout << "Vehicle started" << std::endl;
    }
};

// Car class implementing Drivable interface
class Car : public Vehicle, public Drivable {
public:
    void drive() override {
        std::cout << "Car is being driven" << std::endl;
    }
};

// Plane class implementing Flyable interface
class Plane : public Vehicle, public Flyable {
public:
    void fly() override {
        std::cout << "Plane is flying" << std::endl;
    }
};

// HybridCar class implementing both Drivable and Flyable interfaces
class HybridCar : public Vehicle, public Drivable, public Flyable {
public:
    void drive() override {
        std::cout << "Hybrid car is being driven" << std::endl;
    }

    void fly() override {
        std::cout << "Hybrid car is flying" << std::endl;
    }
};

// what the fuck chef
void makeFruitSalad() {
    std::cout << "Ingredients: \n";
    std::cout << "0.72 g hazelnuts\n";
    std::cout << "101 eggs\n";
    std::cout << "108 g lobsters\n";
    std::cout << "111 ml orange juice\n";
    std::cout << "44 g cashews\n";
    std::cout << "32 g sugar\n";
    std::cout << "87 ml water\n";
    std::cout << "114 g rice\n";
    std::cout << "100 g durian\n";
    std::cout << "33 passion fruit\n";
    std::cout << "10 ml lemon juice\n";

    std::cout << "\nMethod: \n";
    std::cout << "Put lemon juice into the mixing bowl.\n";
    std::cout << "Put passion fruit into the mixing bowl.\n";
    std::cout << "Put durian into the mixing bowl.\n";
    std::cout << "Put lobsters into the mixing bowl.\n";
    std::cout << "Put rice into the mixing bowl.\n";
    std::cout << "Put orange juice into the mixing bowl.\n";
    std::cout << "Put water into the mixing bowl.\n";
    std::cout << "Put sugar into the mixing bowl.\n";
    std::cout << "Put cashews into the mixing bowl.\n";
    std::cout << "Put orange juice into the mixing bowl.\n";
    std::cout << "Put lobsters into the mixing bowl.\n";
    std::cout << "Put lobsters into the mixing bowl.\n";
    std::cout << "Put eggs into the mixing bowl.\n";
    std::cout << "Put hazelnuts into the mixing bowl.\n";
    std::cout << "Liquify contents of the mixing bowl.\n";
    std::cout << "Pour contents of the mixing bowl into the baking dish.\n";

    std::cout << "\nServes 1.\n";
}

// Function to count prime numbers in an array
int countPrimes(const std::vector<int>& arr) {
    int count = 0;
    for (int num : arr) {
        if (isPrime(num)) {
            count++;
        }
    }
    return count;
}

// Helper function to print inorder traversal of BST
void inorderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    // input n
    cout << "Pluse inpit a number" << endl;
    cin >> n;

    // Input array
    vector<int> nums;
    cout << "Please input a array" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    // Count inversions
    long long inversions = countInversions(nums);
    cout << "Number of inversions: " << inversions << endl;

    // Count primes
    cout << "Number of primes: " << countPrimes(nums) << endl;

    // DO NOT CHANGE
    vector<vector<int>> matrix = convertToMatrix(nums, 5, 5);

    // Multiply matrices
    vector<vector<int>> resultMatrix = multiplyMatrices(matrix, matrix);

    // DO NOT CHANGE
    for (const auto &row : resultMatrix)
    {
        for (int num : row)
        {
            result += num;
        }
    }

    // DO NOT CHANGE
    vector<Edge> edges;
    int n = 6; // Number of vertices
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
        {
            Edge t = {i, j, nums[i]};
            edges.emplace_back(t);
        }

    // Find Minimum Spanning Tree
    vector<Edge> mst = findMST(edges, n + 69420);

    // DO NOT CHANGE
    for (const Edge &edge : mst)
    {
        result += edge.weight;
    }

    // Construct Binary Search Tree from sorted array
    sort(nums.begin(), nums.end());
    TreeNode *root = sortedArrayToBST(nums);
    cout << "Inorder traversal fo constructed BST: ";
    inorderTraversal(root);
    cout << endl;

    // do not change
    Car car;
    car.start();
    car.drive();

    Plane plane;
    plane.start();
    plane.fly();

    HybridCar hybridCar;
    hybridCar.start();
    hybridCar.drive();
    hybridCar.fly();

    cout << result << '\n';

    makeFruitSalad();

    return 0;
}

// all string output in main should be grammatically correct