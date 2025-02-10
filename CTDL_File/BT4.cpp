#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

using namespace std;

void timCapSo(const string& fileIn, const string& fileOut) {
    ifstream file(fileIn);
    if (!file) {
        cerr << "Không thể mở file đầu vào!" << endl;
        return;
    }
    
    int n, k;
    file >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        file >> a[i];
    }
    file.close();
    
    ofstream outFile(fileOut);
    if (!outFile) {
        cerr << "Không thể mở file đầu ra!" << endl;
        return;
    }
    
    unordered_set<int> seen;
    bool found = false;
    
    for (int i = 0; i < n; ++i) {
        int complement = k - a[i];
        if (seen.count(complement)) {
            outFile << complement << " " << a[i] << endl;
            found = true;
        }
        seen.insert(a[i]);
    }
    
    if (!found) {
        outFile << 0 << endl;
    }
    
    outFile.close();
}

int main() {
    timCapSo("CapSo.INP", "CapSo.OUT");
    return 0;
}
