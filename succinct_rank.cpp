#include <bits/stdc++.h>
using namespace std;
using clk = chrono::high_resolution_clock;

int main() {
    ifstream file("sequence.fasta");
    if (!file.is_open()) {
        cout << "Error opening file\n";
        return 1;
    }

    vector<uint8_t> B;
    B.push_back(0);   // dummy element for 1-based indexing

    string line;
    while (getline(file, line)) {
        if (line.empty() || line[0] == '>') continue;

        for (char c : line) {
            if (c == 'A' || c == 'a')
                B.push_back(1);
            else
                B.push_back(0);
        }
    }
    file.close();

    // length excluding dummy index
    uint32_t n = B.size() - 1;
    cout << "Sequence length = " << n << "\n";

    const uint32_t L = 512;   // superblock size
    const uint32_t K = 64;    // block size

    vector<uint32_t> super;
    vector<uint16_t> block;
   super.push_back(0);  // rank at position 0
   block.push_back(0);  // rank at position 0


   uint32_t rank = 0;

for (uint32_t i = 1; i <= n; i++) {

    rank += B[i];

    if (i % L == 0)
        super.push_back(rank);

    if (i % K == 0)
        block.push_back(rank - super.back());
}


    // ----------------------------
    // Index size
    // ----------------------------
    size_t index_bytes =
        B.size() * sizeof(uint8_t) +
        super.size() * sizeof(uint32_t) +
        block.size() * sizeof(uint16_t);

    cout << "Index size = "
         << (index_bytes / (1024.0 * 1024.0)) << " MB\n";

    // ----------------------------
    // Rank query (1-based)
    // ----------------------------
    auto rank_query = [&](uint32_t pos) {
    
    uint32_t sb = pos / L;
    uint32_t bk = pos / K;
    uint32_t res = super[sb] + block[bk];
    uint32_t start = bk * K + 1;
    for (uint32_t i = start; i <= pos; i++)
        res += B[i];

    return res;
};


    // ----------------------------
    // Timing
    // ----------------------------
    const int Q = 100000;
    uint64_t dummy = 0;

    for (int i = 0; i < Q; i++) {
        uint32_t pos = (rand() % n) + 1;
        dummy += rank_query(pos);
    }

    auto t1 = clk::now();
    for (int i = 0; i < Q; i++) {
        uint32_t pos = (rand() % n) + 1;
        dummy += rank_query(pos);
    }
    auto t2 = clk::now();

    double avg_ns =
        chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count()
        / (double)Q;

    cout << "Average rank query time = "
         << avg_ns << " ns\n";

    // Required query
    cout << "rank(14343555) = "
         << rank_query(14343555) << "\n";

    return 0;
}
