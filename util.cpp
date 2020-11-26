#include<iostream>
#include<chrono>
#include<vector>
using namespace std;
typedef pair< int , int >Cell;
typedef vector< vector< int > >Matrix;

class Timer {
    chrono::time_point<chrono::system_clock> start_time, current_time;

public:
    int TIME_LIMIT = 120000;
    Timer() {}

    void startTimer() {
        start_time = chrono::high_resolution_clock::now();
    }

    int elapsedMilis() {
        current_time = chrono::high_resolution_clock::now();
        return chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time).count();
    }

    bool timesUp() {
        return elapsedMilis() > TIME_LIMIT;
    }
} timer;

void printMat(const Matrix &cur) {
    for (vector< int > v : cur) {
        for (int x : v) cout << x << " ";
        cout << endl;
    }
}

bool isConsistent(const Matrix &cur) {
    int dim = cur.size();
    for (int i = 0; i < dim; i++) {
        int rowMask = 0;
        int colMask = 0;
        for (int j = 0; j < dim; j++) {
            if (cur[i][j]) {
                int tmp = 1<<cur[i][j];
                if (rowMask&tmp) {
                    return false;
                }
                rowMask |= tmp;
            }
            if (cur[j][i]) {
                int tmp = 1<<cur[j][i];
                if (colMask&tmp) {
                    return false;
                }
                colMask |= tmp;
            }
        }
    }
    return true;
}

vector< Cell >getUnassignedPlaces(const Matrix &cur) {
    vector< Cell >v;
    for (int i = 0; i < cur.size(); i++) {
        for (int j = 0; j < cur.size(); j++) {
            if (cur[i][j] == 0) {
                v.emplace_back(i, j);
            }
        }
    }
    return v;
}

vector< int >getDomains(const Matrix &start, const vector< Cell >&unassigned) {
    int dim = start.size();
    vector<int> domains;
    vector< int >rowMasks(dim, 0);
    vector< int >colMasks(dim, 0);
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (start[i][j]) {
                rowMasks[i] |= 1<<start[i][j];
                colMasks[j] |= 1<<start[i][j];
            }
        }
    }
    for (Cell p : unassigned) {
        int msk = rowMasks[p.first] | colMasks[p.second];
        for (int j = 1; j <= dim; j++) msk ^= 1<<j;
        domains.push_back(msk);
    }
    return domains;
}

bool isArc(Cell p, Cell q) {
    if (p == q) return false;
    return p.first == q.first || p.second == q.second;
}
