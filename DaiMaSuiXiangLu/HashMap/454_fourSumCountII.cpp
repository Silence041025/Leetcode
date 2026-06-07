#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
#include "unordered_map"
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> mp;
        int result = 0;
        for (int i=0;i<nums1.size();i++) {
            for (int j=0;j<nums2.size();j++) {
                mp[nums1[i]+nums2[j]]++;
            }
        }
        for (int i=0;i<nums3.size();i++) {
            for (int j=0;j<nums4.size();j++) {
                if (mp.find(0-(nums3[i]+nums4[j]))!=mp.end()) {
                    result += mp[0-(nums3[i]+nums4[j])];
                }
            }
        }
        return result;
    }
};

int main() {
    
}