/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    struct comparator
    {
        bool operator()(ListNode* a,ListNode* b)
        {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.empty())
            return NULL;

        priority_queue<ListNode*,vector<ListNode*>,comparator> pq;

        int n = lists.size();
        for(int i=0;i<n;i++)
        {
            pq.push(lists[i]);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;


        while(!pq.empty())
        {
            ListNode* node = pq.top();
            pq.pop();

            temp->next = node;
            temp = node;

            if(node->next != NULL)
                pq.push(node->next);
        }

        return dummy->next;
    }
};
