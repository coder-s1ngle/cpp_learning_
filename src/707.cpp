#include <iostream>
#include <vector>
using namespace std;

class MyLinkedList {
public:
    struct LinkedNode{
        int val;
        LinkedNode* nextPtr;
        LinkedNode(int x):val(x),nextPtr(NULL){}
    };

    MyLinkedList() {
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }
    
    int get(int index) {
        if(index<0 || _size - 1<index)
            return -1;
        else{
            LinkedNode* cur = _dummyHead->nextPtr;
            while(index){
                cur = cur->nextPtr;
                index--;
            }
            return cur->val;
        }
    }
    
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->nextPtr = _dummyHead->nextPtr;
        _dummyHead->nextPtr = newNode;
        _size++; 
    }
    
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(cur->nextPtr!=NULL){
            cur = cur->nextPtr;
        }
        cur->nextPtr = newNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        LinkedNode* newNode = new LinkedNode(val);
        if(index<0) return;
        LinkedNode* cur = _dummyHead;
        while(index--){
            cur = cur->nextPtr;
        }
        newNode->nextPtr = cur->nextPtr;
        cur->nextPtr = newNode;
        _size++;
        
    }
    
    void deleteAtIndex(int index) {
        if(_size==0 || index > _size-1){
            return;
        }else{
            LinkedNode* cur = _dummyHead;
            while(index >= 1){
                cur = cur->nextPtr;
                index --;
            }
            LinkedNode* temp = cur->nextPtr;
            cur->nextPtr = cur->nextPtr->nextPtr;
            delete temp;
            _size --;
        }
    }
    int getSize(){
        return _size;
    }
    // LinkedNode* createLinkedList(const vector<int>& nums) {
    //     if (nums.empty()) return nullptr;
    //     LinkedNode* head = new LinkedNode(nums[0]);
    //     LinkedNode* cur = head;
    //     for (int i = 1; i < nums.size(); ++i) {
    //         cur->nextPtr = new LinkedNode(nums[i]);
    //         cur = cur->nextPtr;
    //         _size++;
    //     }
    //     cout<<_size;
    //     return head;
    // }

    // void printLinkedList(LinkedNode* head) {
    //     LinkedNode* cur = head;
    //     cout << "链表内容：";
    //     while (cur != nullptr) {
    //         cout << cur->val << " ";
    //         cur = cur->nextPtr;
    //     }
    //     cout << endl;
    // }


private:
    LinkedNode* _dummyHead;
    int _size = 0;
};



int main() {
    MyLinkedList LinkedList;
    // vector<int> nums = {2,3,4,1,6};
    // MyLinkedList::LinkedNode* L = LinkedList.createLinkedList(nums);
    // LinkedList.printLinkedList(L);
    
    LinkedList.addAtTail(0);
    LinkedList.addAtTail(1);
    LinkedList.addAtTail(2);
    LinkedList.addAtIndex(1,5);
    cout << std::endl <<LinkedList.get(1);
    // cout<<LinkedList.getSize();
    return 0;
}