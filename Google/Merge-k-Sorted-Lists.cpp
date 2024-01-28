class Solution {
	public:
    struct comp {
        bool operator()(const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };
	ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = new ListNode(0);
        ListNode *temp = head;
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        for(int i=0; i<lists.size(); i++){
            if(lists[i] != NULL) pq.push(lists[i]);
        }

        while(!pq.empty()){
            auto smallest = pq.top();
            pq.pop();
            temp->next = smallest;
            temp = temp->next;
            if(smallest->next) pq.push(smallest->next);
        }
        return head->next;
    }
};


/*
* Ques Link : https://leetcode.com/problems/merge-k-sorted-lists/
* Solution Link : https://leetcode.com/problems/merge-k-sorted-lists/submissions/1159386463/
*/
