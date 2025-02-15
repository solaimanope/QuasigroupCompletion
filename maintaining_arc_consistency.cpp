namespace MaintainingArcConsistency {
    int numberOfNodes;
    int numberOfBacktracks;
    int dim;

    bool revise(vector<int>&domains, int i, int j) {
        bool doDelete = false;
        for (int x = 1; x <= dim; x++) {
            int containsx = 1<<x;
            ///check if x is in domain of vi
            if (domains[i]&containsx) {
                ///check if domain of vj contains only x
                if (domains[j] == containsx) {
                    ///delete x from domain of vi
                    domains[i] ^= containsx;
                    doDelete = true;
                }
            }
        }
        return doDelete;
    }

    typedef pair< int, int > Arc;
    bool AC3(const Matrix &cur, const vector<Cell>&unassigned, vector<int>&domains, int cv) {
        set< Arc >Q;
        ///push arcs to source node
        for (int i = 0; i < unassigned.size(); i++) {
            if (isArc(unassigned[i], unassigned[cv])) {
                Q.emplace(i, cv);
            }
        }

        bool consistent = true;
        while (!Q.empty() && consistent) {
            Arc arc = *Q.begin();
            Q.erase(Q.begin());
            int k = arc.first;
            int m = arc.second;

            if (revise(domains, k, m)) {
                for (int i = 0; i < unassigned.size(); i++) {
                    if (i == k || i == m) continue;
                    if (isArc(unassigned[i], unassigned[k])) {
                        Q.emplace(i, k);
                    }
                }
                consistent = domains[k] != 0;
            }
        }
        return consistent;
    }

    bool maintainingArcConsistency(Matrix &cur, vector<Cell>&unassigned, vector< int >&domains) {
        numberOfNodes++;
        if (unassigned.empty()) return true;
        if (timer.timesUp()) return false;

        int nxtIdx = VariableOrdering::chooseNextIndex(cur, unassigned);
        swap(unassigned[nxtIdx], unassigned[unassigned.size()-1]);
        swap(domains[nxtIdx], domains[domains.size()-1]);
        const Cell p = unassigned.back();
        const int options = domains.back();

        bool wentDeeper = false;
        for (int x : ValueOrdering::getValueOrderWithDomain(cur, p, options)) {
            cur[p.first][p.second] = x;

            vector<int>newDomains(domains);
            newDomains.back() = 1<<x;

            if (AC3(cur, unassigned, newDomains, unassigned.size()-1)) {
                wentDeeper = true;
                unassigned.pop_back();
                newDomains.pop_back();
                if (maintainingArcConsistency(cur, unassigned, newDomains)) return true;
                unassigned.push_back(p);
            }

            cur[p.first][p.second] = 0;
        }

        if (!wentDeeper) numberOfBacktracks++;

        swap(unassigned[nxtIdx], unassigned[unassigned.size()-1]);
        swap(domains[nxtIdx], domains[domains.size()-1]);
        return false;
    }

    void solveWithMaintainingArcConsistency(Matrix start) {
        dim = start.size();
        vector<Cell> unassigned = getUnassignedPlaces(start);
        vector<int> domains = getDomains(start, unassigned);

        numberOfNodes = numberOfBacktracks = 0;
        if (maintainingArcConsistency(start, unassigned, domains)) {
            cout << "Found a solution with maintaining arc consistency:" << endl;
            printMat(start);
            assert(isConsistent(start));
        } else {
            cout << "Solution not found!" << endl;
            numberOfNodes = numberOfBacktracks = -1;
        }

        cout << "Number of nodes: " << numberOfNodes << endl;
        cout << "Number of backtracks: " << numberOfBacktracks << endl;
        cout << endl;
    }
}
