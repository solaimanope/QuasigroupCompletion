namespace BackTracking {
    int numberOfNodes;
    int numberOfBacktracks;
    bool backTrack(Matrix &cur, vector< Cell >&unassigned) {
        numberOfNodes++;
        if (!isConsistent(cur)) {
            numberOfBacktracks++;
            return false;
        }
        if (unassigned.empty()) return true;

        if (timer.timesUp()) return false;

        int dim = cur.size();
        int nxtIdx = VariableOrdering::chooseNextIndex(cur, unassigned);
        swap(unassigned[nxtIdx], unassigned[unassigned.size()-1]);
        const Cell p = unassigned.back();
        unassigned.pop_back();

        for (int x : ValueOrdering::getValueOrderWithoutDomain(cur, p)) {
            cur[p.first][p.second] = x;
            if (backTrack(cur, unassigned)) return true;
            cur[p.first][p.second] = 0;
        }

        unassigned.push_back(p);
        swap(unassigned[nxtIdx], unassigned[unassigned.size()-1]);
        return false;
    }

    void solveWithBackTrack(Matrix start) {
        vector<Cell> unassigned = getUnassignedPlaces(start);
        numberOfNodes = numberOfBacktracks = 0;
        if (backTrack(start, unassigned)) {
            cout << "Found a solution with backtracking:" << endl;
            printMat(start);
        } else {
            cout << "Solution not found!" << endl;
            numberOfNodes = numberOfBacktracks = -1;
        }

        cout << "Number of nodes: " << numberOfNodes << endl;
        cout << "Number of backtracks: " << numberOfBacktracks << endl;
        cout << endl;
    }
}
