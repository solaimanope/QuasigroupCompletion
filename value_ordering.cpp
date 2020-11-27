namespace ValueOrdering {
    const int SEQUENTIAL_ORDERING = 0;
    const int DIAGONAL_FREQUENCY_ORDERING = 1;
    int currentOrdering;
    int dim;

    const int dx[] = {1, 1, -1, -1};
    const int dy[] = {1, -1, 1, -1};
    vector<int> diagonalFrequencyWithDomain(const Matrix &cur, const Cell &c, int domain) {
        vector< int >diagonallyAdjacentColors;
        for (int k = 0; k < 4; k++) {
            Cell e(c.first+dx[k], c.second+dy[k]);
            if (min(e.first, e.second) < 0 || max(e.first, e.second) >= dim) continue;
            if (cur[e.first][e.second]) {
                diagonallyAdjacentColors.push_back(cur[e.first][e.second]);
            }
        }
        vector< pair< int , int > >vp;
        for (int x = 1; x <= dim; x++) {
            if (domain&(1<<x)) {
                ///contains x
                vp.emplace_back(0, x);
                for (int y : diagonallyAdjacentColors) {
                    vp.back().first += x == y;
                }
            }
        }
        sort(vp.rbegin(), vp.rend());
        vector< int >v(vp.size());
        for (int i = 0; i < vp.size(); i++) v[i] = vp[i].second;
        return v;
    }

    vector<int> diagonalFrequencyWithoutDomain(const Matrix &cur, const Cell &c) {
        vector< int >diagonallyAdjacentColors;
        for (int k = 0; k < 4; k++) {
            Cell e(c.first+dx[k], c.second+dy[k]);
            if (min(e.first, e.second) < 0 || max(e.first, e.second) >= dim) continue;
            if (cur[e.first][e.second]) {
                diagonallyAdjacentColors.push_back(cur[e.first][e.second]);
            }
        }
        vector< pair< int , int > >vp;
        for (int x = 1; x <= dim; x++) {
            ///contains x
            vp.emplace_back(0, x);
            for (int y : diagonallyAdjacentColors) {
                vp.back().first += x == y;
            }
        }
        sort(vp.rbegin(), vp.rend());
        vector< int >v(vp.size());
        for (int i = 0; i < vp.size(); i++) v[i] = vp[i].second;
        return v;
    }

    vector< int >getValueOrderWithDomain(const Matrix &cur, const Cell &c, int domain) {
        dim = cur.size();
        if (currentOrdering == DIAGONAL_FREQUENCY_ORDERING) {
            return diagonalFrequencyWithDomain(cur, c, domain);
        } else {
            ///currentOrdering == SEQUENTIAL_ORDERING
            vector< int >v;
            for (int x = 1; x <= dim; x++) {
                if (domain&(1<<x)) {
                    ///contains x
                    v.push_back(x);
                }
            }
            return v;
        }
    }

    vector< int >getValueOrderWithoutDomain(const Matrix &cur, const Cell &c) {
        dim = cur.size();
        if (currentOrdering == DIAGONAL_FREQUENCY_ORDERING) {
            return diagonalFrequencyWithoutDomain(cur, c);
        } else {
            ///currentOrdering == SEQUENTIAL_ORDERING
            vector< int >v(dim);
            for (int x = 1; x <= dim; x++) {
                v[x-1] = x;
            }
            return v;
        }
    }
}
