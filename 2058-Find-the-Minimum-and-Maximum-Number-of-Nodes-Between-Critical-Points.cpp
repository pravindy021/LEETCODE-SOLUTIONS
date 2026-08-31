class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        ListNode* dummy = head;

        int pos = 1;              // Current node position
        int prev = 0;             // Previous critical point
        int f = 0, l = 0;         // First & last critical point

        int minDist = INT_MAX;
        int maxDist = INT_MIN;

        while (dummy->next != nullptr && dummy->next->next != nullptr) {

            int left = dummy->val;
            int middle = dummy->next->val;
            int right = dummy->next->next->val;

            pos++;

            if ((middle > left && middle > right) ||
                (middle < left && middle < right)) {

                if (prev == 0) {
                    prev = pos;
                    f = pos;
                    dummy = dummy->next;
                    continue;
                }

                minDist = min(minDist, pos - prev);

                prev = pos;
                l = pos;
            }

            dummy = dummy->next;
        }

        maxDist = l - f;    
        if (minDist == INT_MAX || maxDist == INT_MIN)
            return {-1, -1};

        return {minDist, maxDist};
    }
};