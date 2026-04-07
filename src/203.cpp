#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *nextPtr = nullptr;
    ListNode(int x):val(x),nextPtr(nullptr){};
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->nextPtr = head;
        ListNode* curr = dummyHead;
        while(curr->nextPtr != nullptr){
            if(curr->nextPtr->val!=val)  curr = curr->nextPtr;
            else{
                ListNode* temp = curr->nextPtr;
                
                curr->nextPtr = curr->nextPtr->nextPtr;
                delete temp;
            }
        }
        head = dummyHead->nextPtr;
        delete dummyHead;
        return head;
    }
};

ListNode* createLinkedList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* cur = head;
    for (int i = 1; i < nums.size(); ++i) {
        cur->nextPtr = new ListNode(nums[i]);
        cur = cur->nextPtr;
    }
    return head;
}

void printLinkedList(ListNode* head) {
    ListNode* cur = head;
    cout << "链表内容：";
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->nextPtr;
    }
    cout << endl;
}

int main() {
    vector<int> nums = {1, 2, 6, 3, 4, 5, 6};
    ListNode* head = createLinkedList(nums);
    printLinkedList(head);
    Solution Sol;
    Sol.removeElements(head,6);
    printLinkedList(head);
    return 0;
}