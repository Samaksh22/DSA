#include <iostream>
#include <random>

#define TOTAL_DAYS 365
#define TOTAL_EXPERIMENTS 200

using namespace std;

int *random_array(int N)
{
    int *arr = new int[N];
    for (int i = 0; i < N; i++)
        arr[i] = rand() % TOTAL_DAYS;

    return arr;
}

bool is_birthday_same(int N)
{
    int *arr = random_array(N);

    for (int i = 0; i < N-1; i++)
        for (int j = i+1; j < N; j++)
            if (arr[i] == arr[j])
                return true;
    
    return false;
}

int experiments(int N, int exp)
{
    int total_count = 0;
    for (int i = 0; i < exp; i++)
        total_count += is_birthday_same(N);
    
    return total_count;
}

int main()
{
    srand(42);
    for (int i = 5; i <= 100; i+=5)
    {
        int total_exp = TOTAL_EXPERIMENTS;
        int positive_exp = experiments(i, total_exp);
        double probab = (double)positive_exp / total_exp * 100;

        cout << "Total People: " << i
             << "\nTotal Experiment: " << total_exp
             << "\nExperiments with same birthday: " << positive_exp 
             << "\nProbability: " << probab << "\n\n";
    }

    return 0;
}