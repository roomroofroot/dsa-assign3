class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if (list1 == NULL) return list2;
		else if (list2 == NULL) return list1;

		ListNode *h1 = list1, *h2 = list2, *head = list1, *tmp;
		if (h1->val > h2->val) {
		    head = h2;
	 	   h2 = list1;
	 	   h1 = list2;
		}

		while (h1->next != NULL && h2 != NULL) {
	 	   if (h1->next->val >= h2->val) {
				tmp = h1->next;
				h1->next = h2;
				h2 = h2->next;
				h1->next->next = tmp;
		   }
	    	h1 = h1->next;
		}
		if (h2 != NULL) h1->next = h2;
		return head;
	}
};
