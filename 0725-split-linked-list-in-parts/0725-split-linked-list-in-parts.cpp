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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode*curr=head;
        int l=0;
        while(curr){
            l++;
            curr=curr->next;
        }

        int NodesAdd=l/k;
        int extranodes=l%k;
        
        vector<ListNode*> res(k,NULL);
        curr=head;
        ListNode*prev=NULL;

        for(int i=0;i<k;i++){
            res[i]=curr;
            for(int cnt=1;cnt<=NodesAdd+(extranodes>0?1:0);cnt++){
                prev=curr;
                curr=curr->next;
            }
            if(prev!=NULL){
                 prev->next=NULL;
            }
           
            extranodes--;
        }
        return res;
    }
};