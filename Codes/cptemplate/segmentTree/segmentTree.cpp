int CST(int ss, int se, int si, vector<int>&arr, vector<int>&tree)
{
    if (ss == se)
    {
        tree[si] = arr[ss];
        return arr[ss];
    }

    int mid = (ss + se) / 2;

    tree[si] = CST(ss, mid, 2 * si + 1, arr, tree)
               + CST(mid + 1, se, 2 * si + 2, arr, tree);

    return tree[si];
}

//initially ss = 0, se = n-1, {qs,qe} -> user range input, si = 0 (root)
int getSegTreeRangeSum(int qs, int qe, int ss, int se, int si, vector<int> &tree)
{
    if (se < qs || ss > qe)
        return 0;
    if (qs <= ss &&  qe >= se)
        return tree[si];

    int mid = (ss + se) / 2;

    return getSegTreeRangeSum(qs, qe, ss, mid, 2 * si + 1, tree)
           + getSegTreeRangeSum(qs, qe, mid + 1, se, 2 * si + 2, tree);
}

//initially ss = 0, se = n-1, i -> update index, si = 0 (root)
// calculate diff = new_value - tree[i]
void updateSegTree(int ss, int se, int i, int si, int diff, vector<int> &tree)
{
    if (i < ss || i > se)
        return;

    tree[si] = tree[si] + diff;

    if (se > ss)
    {
        int mid = (ss + se) / 2;

        updateSegTree(ss, mid, i, 2 * si + 1, diff, tree);
        updateSegTree(mid + 1, se, i, 2 * si + 2, diff, tree);

    }
}

vector<int> segmentTree(vector<int>&arr) {
    int n = arr.size();
    vector<int>tree(4 * n);
    CST(0, n - 1, 0, arr, tree);
    return tree;
}
