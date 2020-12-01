# Quasigroup Completion

A quasigroup or latin square is an n × n array filled with n different symbols, each occurring exactly once in each row and exactly once in each column. In Quasigroup Completion Problem, a partial assignment of a latin square is given and one has to find whether it's possible to assign the remaining cells so that the result is a valid latin square.

![](https://i.imgur.com/Ky74fI6.png)


So how do we approach solving the problem?

### Try plain Backtracking first
We can use [_Backtracking_](https://github.com/solaimanope/QuasigroupCompletion/blob/master/backtracking.cpp) to solve the problem. But _backtracking_ visits a lot of nodes, most of which are backtracked from. If we could somehow avoid assigning the current variable a value that directly clashes with the assignment of past variables, we could have managed to prune a lot of unnecessary branches.

### Don't contradict with past using Forward Checking
[_Forward Checking_](https://github.com/solaimanope/QuasigroupCompletion/blob/master/forward_checking.cpp) makes sure that we don't visit those unncessary branches, that directly contradict with the assignment of past variables. The _AC3 algorithm for FC_ described [here](https://ktiml.mff.cuni.cz/~bartak/constraints/propagation.html#FC) is used to make sure that we never assign the contradicting values to a variable. Still we are visiting a lot of nodes (but a lot less than plain backtracking) from which we are backtracked.

### Detect furture failure with Maintaining Arc Consistency
[_Maintaining Arc Consistency_](https://github.com/solaimanope/QuasigroupCompletion/blob/master/maintaining_arc_consistency.cpp) takes the pruning one step further. It uses a _AC3 algorithm for MAC_ described [here](https://ktiml.mff.cuni.cz/~bartak/constraints/propagation.html#LA) to detect also the conflicts between future variables and therefore allows branches of the search tree that will lead to failure to be pruned earlier than with forward checking.

### Variable Ordering
[_Variable Ordering_](https://github.com/solaimanope/QuasigroupCompletion/blob/master/variable_ordering.cpp) determines which unassigned variable to assign next at some depth of the search tree we are traversing. Five types of ordering were reported:
* Smallest Domain First
* Minimum Forward Degree
* Brelaz (minimizes domain size and then break ties by minimizing forward degree)
* DOMDDEG (minimizes domain size to forward degree ratio)
* Row Major (just pick the unassigned cells one by one sequentially)

### Value Ordeing
After we have picked the variable (cell) for assignment, [_Value Ordeing_](https://github.com/solaimanope/QuasigroupCompletion/blob/master/value_ordering.cpp) is used to determine in which order should we try assigning a value from the current domain of the variable. Two types of ordering were reported:
* Sequential Ordering (try the available values from smallest to largest)
* Diagonal Frequency Ordering (give priority to values which occur more frequently in the diagonally adjacent assigned cells of the selected cell)
