#include <iostream>
#include <chrono>

int main() {
    using namespace std;
    using namespace std::chrono;

    auto start = high_resolution_clock::now();

    char baseline[30];
    for (int i = 0; i < 30; i++)
    baseline[i] = '8';

    int toChange[14][20] = {
        {
            1,
            -1
        },
        {
            -1
        },
        {
            13,
            14,
            15,
            16,
            24,
            25,
            -1
        },
        {
            9,
            10,
            11,
            12,
            13,
            14,
            15,
            16,
            17,
            18,
            19,
            22,
            23,
            24,
            -1
        },
        {
            7,
            8,
            9,
            10,
            11,
            12,
            20,
            21,
            22,
            23,
            -1
        },
        {
            6,
            7,
            8,
            9,
            18,
            19,
            20,
            21,
            22,
            23,
            24,
            -1
        },
        {
            6,
            7,
            8,
            16,
            17,
            18,
            21,
            22,
            23,
            -1
        },
        {
            6,
            7,
            8,
            14,
            15,
            16,
            22,
            23,
            24,
            -1
        },
        {
            6,
            7,
            8,
            9,
            21,
            22,
            23,
            -1
        },
        {
            7,
            8,
            9,
            18,
            19,
            20,
            21,
            22,
            23,
            -1
        },
        {
            6,
            7,
            8,
            10,
            11,
            12,
            13,
            14,
            15,
            16,
            17,
            18,
            19,
            20,
            21,
            -1
        },
        {
            4,
            5,
            11,
            12,
            13,
            14,
            15,
            16,
            17,
            18,
            -1
        },
        {
            -1
        },
        {
            29,
            -1
        }
    };
    for (int t = 0; t < 1000000; t++) {
        for (int i = 0; i < 14; i++) {
            char thisLine[30];

            for (int j = 0; j < 30; j++)
            thisLine[j] = baseline[j];

            for (int k = 0; toChange[i][k] != -1; k++) {
                int index = toChange[i][k];
                thisLine[index] = (i == 0) ? '0': '1';
            }

        }
    }

    auto end = high_resolution_clock::now();
    auto micros = duration_cast < microseconds > (end - start).count();

    cout << "Time taken in microseconds: " << micros << "\n";
    cout << "Time taken in milliseconds: " << micros / 1000.0 << "\n";
    cout << "Time taken in seconds: " << micros / 1000000.0 << "\n";

    return 0;
}