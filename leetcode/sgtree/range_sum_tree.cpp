#include <bits/stdc++.h>
using namespace std;

class NumArray {
vector<int> sgtree;
public:
    NumArray(vector<int>& nums) {
        vector<int> tree (4 * nums.size(), 0);
        sgtree = tree;
        if(sgtree.size() != 0) {
            build(1,1,nums.size(), nums);    
        }
    }
    
    void update(int i, int val) {
        i++;
        update(1, 1, sgtree.size() / 4, i, val);
    }
    
    int sumRange(int i, int j) {
        i++;
        j++;
        return query(1, 1, sgtree.size() / 4, i, j);
    }
    void build(unsigned int id, int l, int r, vector<int> &nums) {
        if(l == r) {
            sgtree[id] = nums[l - 1];
        } else {
            int m = (l + r) / 2;
            build(2 * id, l, m, nums);
            build(2 * id + 1, m + 1, r, nums);
            sgtree[id] = sgtree[2 * id] + sgtree[2 * id + 1];
        }
    }
    int query(unsigned int id, int l, int r, int &x, int &y) {
        if (x <= l && r <= y) {
            return sgtree[id];
        } else if (y < l || x > r)  {
            return 0;
        } else {
            int m = (l + r) / 2;
            return query(2 * id, l, m, x, y) + query(2 * id + 1, m + 1, r, x, y);
        }
    }
    void update(unsigned int id, int l, int r, int &i, int &val) {
        if (l == r) {
            sgtree[id] = val;
        } else {
            int m = (l + r) / 2;
            if (i <= m) {
                update(2 * id, l, m, i, val);
            } else {
                update(2 * id + 1, m + 1, r, i, val);
            }
            sgtree[id] = sgtree[2 * id] + sgtree[2 * id + 1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

int main() {
    vector<int> nums = {9, -8};
    NumArray * na = new NumArray(nums);

    na->update(0, 3);
    printf("%d\n", (na->sumRange(1,1)));
    printf("%d\n", (na->sumRange(0,1)));
    na->update(1, -3);

    return 0;
}