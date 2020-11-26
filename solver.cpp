#include<iostream>
#include<algorithm>
#include<cassert>
#include<set>
#include<queue>
#include<chrono>
#include "tests.h"
#include "util.cpp"
#include "variable_ordering.cpp"
#include "backtracking.cpp"
#include "forward_checking.cpp"
#include "maintaining_arc_consistency.cpp"
using namespace std;

int main() {
    Matrix example = {
        {1, 0, 0, 4},
        {0, 0, 2, 0},
        {3, 0, 1, 0},
        {0, 3, 0, 0}
    };


    vector< pair< string , Matrix > >testSets;
    testSets.emplace_back("d-10-01", d_10_01);
    testSets.emplace_back("d-10-06", d_10_06);
    testSets.emplace_back("d-10-07", d_10_07);
    testSets.emplace_back("d-10-08", d_10_08);
    testSets.emplace_back("d-10-09", d_10_09);
    testSets.emplace_back("d-15-01", d_15_01);

    vector< int >reportedOrderings;
    reportedOrderings.push_back(VariableOrdering::SDF);
    reportedOrderings.push_back(VariableOrdering::MIN_DYNAMIC_DEGREE);
    reportedOrderings.push_back(VariableOrdering::BRELAZ);
    reportedOrderings.push_back(VariableOrdering::DOMDDEG);
    reportedOrderings.push_back(VariableOrdering::ROW_MAJOR);

    vector< vector< int > >table;

    for (auto pr : testSets) {
        cout << "test " << pr.first << endl;
        table.emplace_back();
        for (int ordering : reportedOrderings) {
            VariableOrdering::currentOrdering = ordering;
            timer.startTimer();

//            BackTracking::solveWithBackTrack(pr.second);
//            table.back().push_back(BackTracking::numberOfNodes);
//            table.back().push_back(BackTracking::numberOfBacktracks);

//            ForwardChecking::solveWithForwardChecking(pr.second);
//            table.back().push_back(ForwardChecking::numberOfNodes);
//            table.back().push_back(ForwardChecking::numberOfBacktracks);

            MaintainingArcConsistency::solveWithMaintainingArcConsistency(pr.second);
            table.back().push_back(MaintainingArcConsistency::numberOfNodes);
            table.back().push_back(MaintainingArcConsistency::numberOfBacktracks);
        }
        cout << endl;
    }

    for (int i = 0; i < testSets.size(); i++) {
        cout << "test " << testSets[i].first << endl;
        for (int j = 0; j < table[i].size(); j++) {
            if (j) cout << ",";
            cout << table[i][j];
        }
        cout << endl;
    }

    return 0;
}
