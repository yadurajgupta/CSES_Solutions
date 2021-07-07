#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct SegmentTree
{
    int val;
    int index_l;
    int index_r;
    SegmentTree *lower = NULL;
    SegmentTree *upper = NULL;
    bool is_leaf = false;
    static const int INVALID_ANSWER;

    SegmentTree(const int _index_l,
                const int _index_r)
    {
        index_l = _index_l;
        index_r = _index_r;
        is_leaf = (index_l == index_r);
    }
    ~SegmentTree()
    {
        if (lower)
            delete lower;
        if (upper)
            delete upper;
    }
    bool overlap(const int &other_index_l, const int &other_index_r) const
    {
        return (index_l <= other_index_r) &&
               (index_r >= other_index_l);
    }
    bool enclosed_in(const int &other_index_l, const int &other_index_r) const
    {
        return (other_index_l <= index_l) &&
               (index_r <= other_index_r);
    }
    bool index_lies_in_node(const int &index) const
    {
        return (index_l <= index) &&
               (index <= index_r);
    }
    static void update_segment_tree(SegmentTree *&root, const int &update_node_index, const int &update_node_new_val)
    {
        if (!root)
            return;
        root->update_node(update_node_index, update_node_new_val);
        return;
    }
    static pair<bool, int> query_segment_tree(SegmentTree *&root, const int &target_l, const int &target_r)
    {
        return root->query_tree(target_l, target_r);
    }
    bool update_node(const int &update_node_index, const int &update_node_new_val)
    {
        if (!index_lies_in_node(update_node_index))
            return false;
        if (is_leaf)
        {
            // val = update_node_new_val;
            return true;
        }
        if (lower->update_node(update_node_index, update_node_new_val) ||
            upper->update_node(update_node_index, update_node_new_val))
        {
            this->update_node_based_on_children();
            return true;
        }
        return false;
    }

    template <typename type_t>
    static SegmentTree *build_segment_tree(const type_t &arr,
                                           const int &curr_index_l,
                                           const int &curr_index_r)
    {
        SegmentTree *node = new SegmentTree(curr_index_l, curr_index_r);
        if (node->is_leaf)
        {
            // node->val = arr[curr_index_l];
        }
        else
        {
            int curr_index_m = curr_index_l + (curr_index_r - curr_index_l) / 2;
            node->lower = build_segment_tree(arr, curr_index_l, curr_index_m);
            node->upper = build_segment_tree(arr, curr_index_m + 1, curr_index_r);
            node->update_node_based_on_children();
        }
        return node;
    }
    void update_node_based_on_children()
    {
        if (is_leaf)
            return;
        // this->val = lower->val + upper->val;
    }
    pair<bool, int> query_tree(const int &target_l, const int &target_r) const
    {
        if (enclosed_in(target_l, target_r))
            return {true, val};
        else if (overlap(target_l, target_r) && !is_leaf)
        {
            const auto &[lower_valid, lower_ans] = lower->query_tree(target_l, target_r);
            const auto &[upper_valid, upper_ans] = upper->query_tree(target_l, target_r);
            if (!lower_valid)
                return {upper_valid, upper_ans};
            if (!upper_valid)
                return {lower_valid, lower_ans};
            //Merge the answers together
            // return {true, lower_ans + upper_ans};
        }
        return {false, INVALID_ANSWER};
    }
};
const int SegmentTree::INVALID_ANSWER = 0;