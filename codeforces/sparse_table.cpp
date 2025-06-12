#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

void buildSparseTable(int N, const vector<int> &arr, vector<vector<int>> &sparseTable)
{
    int LOGN_val = (N > 0) ? (static_cast<int>(floor(log2(N))) + 1) : 1;

    sparseTable.assign(N, vector<int>(LOGN_val));

    for (int i = 0; i < N; ++i)
        sparseTable[i][0] = arr[i];

    for (int j = 1; j < LOGN_val; ++j)
        for (int i = 0; i + (1 << j) <= N; ++i)
            sparseTable[i][j] = min(sparseTable[i][j-1], sparseTable[i + (1 << (j-1))][j-1]);
}


int query(int L, int R, const vector<vector<int>>& sparseTable)
{
    int length = R - L + 1;
    int k = static_cast<int>(floor(log2(length)));
    return min(sparseTable[L][k], sparseTable[R - (1 << k) + 1][k]);
}

void printSparseTable(const std::vector<std::vector<int>>& sparseTable, int N) {
    if (N == 0) {
        std::cout << "Sparse Table is empty (N=0).\n";
        return;
    }

    // Get the number of columns (LOGN_val)
    // We can infer it from the size of the first row if N > 0
    int LOGN_val = sparseTable[0].size();

    std::cout << "\n--- Sparse Table Contents ---\n";

    // Print column headers (j values)
    std::cout << "   i\\j |";
    for (int j = 0; j < LOGN_val; ++j) {
        std::cout << std::setw(5) << j << " (2^" << j << ")"; // setw for alignment
    }
    std::cout << "\n-------";
    for (int j = 0; j < LOGN_val; ++j) {
        std::cout << "------------"; // Separator for columns
    }
    std::cout << "\n";

    // Print table rows
    for (int i = 0; i < N; ++i) {
        std::cout << std::setw(5) << i << " |"; // Row index
        for (int j = 0; j < LOGN_val; ++j) {
            // Check if element exists (boundary condition for inner loops)
            // This ensures we don't print garbage if the inner loop didn't fill it
            // (sparseTable[i][j] will be 0 if not filled by default if int)
            // A more robust check might involve knowing the actual range limit for each j
            // But for correctness, the buildSparseTable ensures valid values where needed
            if (i + (1 << j) <= N) { // Check if this (i, j) cell corresponds to a valid segment
                std::cout << std::setw(11) << sparseTable[i][j]; // Print value with setw
            } else {
                std::cout << std::setw(11) << "---"; // Indicate not applicable
            }
        }
        std::cout << "\n";
    }
    std::cout << "-----------------------------\n";
}


int main() {
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    int N; // Size of the array
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> N;

    std::vector<int> arr(N); // Input array
    std::cout << "Enter " << N << " elements:\n";
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    // logTable is no longer declared here
    // std::vector<int> logTable(N + 1);
    // precomputeLogs(N, logTable); // This function is also removed

    // sparseTable will be resized inside buildSparseTable
    std::vector<std::vector<int>> sparseTable;
    buildSparseTable(N, arr, sparseTable); // logTable argument removed

    printSparseTable(sparseTable, N);

    int Q; // Number of queries
    std::cout << "\nEnter the number of queries: ";
    std::cin >> Q;

    for (int q = 0; q < Q; ++q) {
        int L, R;
        std::cout << "Enter query range (L R, 0-indexed): ";
        std::cin >> L >> R;

        if (L < 0 || R >= N || L > R) {
            std::cout << "Invalid range.\n";
            continue;
        }
        std::cout << "Minimum in range [" << L << ", " << R << "] is: " << query(L, R, sparseTable) << "\n"; // logTable argument removed
    }

    return 0;
}