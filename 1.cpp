class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
	ListNode *a = head, *b, *x = head, *y = head->next;
	while (y != NULL) {
	    if (a->val > y->val) {
		x->next = y->next;
		y->next = a;
		a = y;
		y = x->next;
	    }
	    else {
		for(b = a; b->next != y; b=b->next) {
		    if (b->next->val > y->val) {
			x->next = y->next;
			y->next = b->next;
			b->next = y;
			y = x->next;
			break;
		    }
		}
		if (b->next == y) {
		    x = y;
		    y = y->next;
		}
	    }
	}
	return a;
    }
};
