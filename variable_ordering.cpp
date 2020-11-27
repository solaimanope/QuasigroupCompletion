namespace VariableOrdering {
    const int ROW_MAJOR = 0;
    const int SMALLEST_DOMAIN_FIRST = 1;
    const int MAX_STATIC_DEGREE = 2;
    const int MIN_FORWARD_DEGREE = 3;
    const int BRELAZ = 4;
    const int DOMDEG = 5;
    const int DOMDDEG = 6;
    const int RANDOM = 7;
    const int IBS = 8;
    int currentOrdering;

    int currentDomainSize(const Matrix &cur, const Cell &p) {
        int msk = 0;
        for (int i = 0; i < cur.size(); i++) {
            if (i == p.first) continue;
            if (cur[i][p.second]) {
                msk |= 1<<cur[i][p.second];
            }
        }
        for (int j = 0; j < cur.size(); j++) {
            if (j == p.second) continue;
            if (cur[p.first][j]) {
                msk |= 1<<cur[p.first][j];
            }
        }

        int ans = 0;
        for (int x = 1; x <= cur.size(); x++) {
            if (msk&(1<<x)) continue;
            ans++;
        }
        return ans;
    }

    int currentDegree(const Matrix &cur, const Cell &p) {
        int ans = 0;
        for (int i = 0; i < cur.size(); i++) {
            if (i == p.first) continue;
            if (cur[i][p.second] == 0) ans++;
        }
        for (int j = 0; j < cur.size(); j++) {
            if (j == p.second) continue;
            if (cur[p.first][j] == 0) ans++;
        }
        return ans;
    }

    int chooseNextIndex(const Matrix &cur, const vector<Cell>&unassigned) {
        assert(!unassigned.empty());
        if (currentOrdering == ROW_MAJOR) {
            return unassigned.size()-1;
        } else if (currentOrdering == SMALLEST_DOMAIN_FIRST) {
            ///Smallest Domain First
            int idx = -1;
            int sz = cur.size()+1;
            for (int i = 0; i < unassigned.size(); i++) {
                int tmp = currentDomainSize(cur, unassigned[i]);
                if (tmp < sz) {
                    sz = tmp;
                    idx = i;
                }
            }
            assert(idx != -1);
            return idx;
        } else if (currentOrdering == MIN_FORWARD_DEGREE) {
            ///Minimum Forward Degree First
            int idx = -1;
            int deg = cur.size()*2;
            for (int i = 0; i < unassigned.size(); i++) {
                int tmp = currentDegree(cur, unassigned[i]);
                if (tmp < deg) {
                    deg = tmp;
                    idx = i;
                }
            }
            assert(idx != -1);
            return idx;
        } else if (currentOrdering == DOMDDEG) {
            ///minimizes the ratio of domain size to forward degree
            int idx = -1;
            double z = cur.size()+2;
            for (int i = 0; i < unassigned.size(); i++) {
                Cell tmp(currentDomainSize(cur, unassigned[i]), currentDegree(cur, unassigned[i]));
                double x = tmp.first;
                if (tmp.second) x /= tmp.second;
                else x = cur.size()+1;

                if (x < z) {
                    z = x;
                    idx = i;
                }
            }
            assert(idx != -1);
            return idx;
        } else if (currentOrdering == BRELAZ) {
            ///Minimum pair(domain size, forward degree) First
            int idx = -1;
            Cell p(cur.size()*cur.size(), cur.size()*cur.size());
            for (int i = 0; i < unassigned.size(); i++) {
                Cell tmp(currentDomainSize(cur, unassigned[i]), currentDegree(cur, unassigned[i]));
                if (tmp < p) {
                    p = tmp;
                    idx = i;
                }
            }
            assert(idx != -1);
            return idx;
        } else if (currentOrdering == RANDOM) {
            ///Minimum pair(smallest domain, forward degree) First
            int idx = rand()%unassigned.size();
            return idx;
        }
        return unassigned.size()-1;
    }
}

