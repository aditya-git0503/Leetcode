class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> l;
        vector<int> g;
        vector<int> e;

        for(int i : nums){
            if(i < pivot)
            l.push_back(i);
            else if(i > pivot)
            g.push_back(i);
            else
            e.push_back(i);
        }

        for(int i : e){
            l.push_back(i);
        }

        for(int i : g){
            l.push_back(i);
        }

        return l;
    }
};