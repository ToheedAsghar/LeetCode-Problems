/*
Link:    https://leetcode.com/problems/palindrome-linked-list/
Concept:
    Find the middle node of the linked list.
    Reverse the second half of the linked list.
    Compare the first half with the reversed second half to check for palindrome.
    
    - In case of ODD length of list, move the slow pointer by 1 step.
*/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* head);
ListNode* reverseLinkedList(ListNode* head);
void display(ListNode* head);
 
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    //head->next->next->next = new ListNode(6);
    display(head);
    cout << isPalindrome(head) << endl;
    return 0;
}

bool isPalindrome(ListNode* head) {
    if(!head || !head->next){
        return true;
    }
    else{
        ListNode* slow = head, *fast = head, *prev = slow;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = nullptr;
        if(nullptr != fast){ // means linkedlist has odd length
            mid = slow;
            slow = slow->next;
        }
        prev->next = nullptr;

        slow = reverseLinkedList(slow);

        ListNode* temp = head;
        while(nullptr != temp && nullptr != slow){
            if(temp->val != slow->val){
                return false;
            }
            else{
                slow = slow->next;
                temp = temp->next;
            }
        }

        if(!slow && !temp){
            return true;
        }
        else{
            return false;
        }
    }
}

ListNode* reverseLinkedList(ListNode* head){
    if(nullptr == head){
        return head;
    }

    ListNode* prev = nullptr, *curr = head, *next;
    while(nullptr != curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }    
    return prev;
}

void display(ListNode* head){
    while(nullptr != head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}