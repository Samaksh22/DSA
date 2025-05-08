//
//  This implementation was a disaster.
//  The correct one is in birthday_paradox2.cpp
//


#include <iostream>
#include <random>
#include <ctime>

#define DAYS 365
#define MAX_SIZE 200
#define TOTAL_EXP 50

using namespace std;

void printArray(int arr[], int size);
int experiment(int people[], int N);

int main()
{
    srand(42);
    int people[MAX_SIZE];
    double probability[MAX_SIZE/5-1];

    // assign random birthdays
    for (int i = 0; i < MAX_SIZE; i++)
    {
        people[i] = rand() % DAYS;
    }

    // printArray(people, MAX_SIZE);

    for (int i = 5; i < MAX_SIZE + 1; i += 5)
    {
        int same_count = experiment(people, i);
        int total_pairs = TOTAL_EXP * (TOTAL_EXP - 1) / 2;

        cout << "Number of People: " << i
            << "\nTotal Number of experiments: " << total_pairs
            << "\nCount of Pairs People having same birthday: " << same_count << endl << endl;
        
        probability[i/5-1] = (same_count/(double)total_pairs) * 100;
    }

    for (int i = 0; i < sizeof(probability) / sizeof(double); i++) {
        cout << probability[i] << " ";
    }
    cout << endl;

    return 0;
}

// display the output array
void printArray(int arr[], int size)
{
    cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//
int experiment(int people[], int N)
{
    int total_exp = TOTAL_EXP;
    int same_res_exp = 0;

    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++)
            if (people[i] == people[j])
                same_res_exp++;

    return same_res_exp;
}