#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int main() {
    ifstream file("sequence.fasta");
    if (!file.is_open()) {
        cout << "Error opening FASTA file" << endl;
        return 1;
    }

    // Bit vector: 1 if base is 'A', else 0
    vector<uint8_t> B;
    B.push_back(0);   // dummy for 1-based indexing

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        if (line[0] == '>') continue;

        for (char c : line) {
            if (c == 'A' || c == 'a')
                B.push_back(1);
            else
                B.push_back(0);
        }
    }
    file.close();

    uint32_t n = B.size() - 1;
    cout << "Sequence length = " << n << endl;

    // Building naive rank array
    vector<uint32_t> rank1(n + 1, 0);
    for (uint32_t i = 1; i <= n; i++) {
        rank1[i] = rank1[i - 1] + B[i];
    }

    
    // Index size
    
    size_t index_size_bytes =
        B.size() * sizeof(uint8_t) +
        rank1.size() * sizeof(uint32_t);

    double index_size_mb =
        index_size_bytes / (1024.0 * 1024.0);

    cout << "Index size: " << index_size_mb << " MB" << endl;

   
    // Average select query time
    
    const int NUM_QUERIES = 99865;   
    uint64_t dummy_sum = 0;

    auto start = high_resolution_clock::now();

    for (int q = 0; q < NUM_QUERIES; q++) {
        uint32_t k = rand() % rank1[n] + 1; 
        for (uint32_t i = 1; i <= n; i++) {
            if (rank1[i] == k) {
                dummy_sum += i;
                break;
            }
        }
    }

    auto end = high_resolution_clock::now();

    auto total_time_ns =
        duration_cast<nanoseconds>(end - start).count();

    double avg_time_ns =
        (double) total_time_ns / NUM_QUERIES;

    cout << "Average select query time: "
         << avg_time_ns << " ns" << endl;

    
    // Specific query:
    // // position of 888484th 'A'
    
        uint32_t target_k = 888484;
        uint32_t position = 0;

    for (uint32_t i = 1; i <= n; i++) {
        if (rank1[i] == target_k) {
            position = i;
            break;
        }
    }

    if (position != 0)
        cout << "Position of the 888484th A: "
             << position << endl;
    else
        cout << "888484th A does not exist in the sequence" << endl;

    
    if (dummy_sum == 0) cout << "";

    return 0;
}
