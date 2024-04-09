# [2073. Time Needed To Buy Tickets](https://leetcode.com/problems/time-needed-to-buy-tickets/description/)

![image](https://github.com/ToheedAsghar/LeetCode-Problems/assets/121859513/27428858-3a7b-4e03-b3b0-694f6befa9d3)

## Analysis

The Person had to atleast wait until he buys the tickets for himself. Afterwards, he had to wait the time the persons before him to buy tickets. But he waits till he had remaining tickets. If the person on the left want to buy more tickets than the person of interest, then the *person of interest* only waits until he has tickets. Remaining time is excluded from person of interests time. For the persons on the right, he had to wait for them to complete also. But what if they want to buy more tickets than him. In this case, the person wouldnot wait for them. Instead, when he finishes buying his tickets, he leaves the queue.

## Pseudocode

```
while tickets:
  if persons on left wants to buy less tickets than the person of interest:
    time += person_left_time
  if person on the left wants to buy more tickets than the person of interest:
    time += person_of_interest_time
  if person on the right wants to buy less tickets than the person of interest:
    time += person_right_time
  if person on the right wants to buy more tickets than the person of interest:
    time += person_of_interest_time - 1
return time
```

## Python Code

```
class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        time: int = 0
        n = len(tickets)
        flag: bool = False
        
        for i in range(n):
            if i == k:
                flag = True
                time += tickets[i]
            elif tickets[i] >= tickets[k]:
                time += tickets[k]
                if flag:
                    time -= 1
            else:
                time += tickets[i] 

        return time

```

## Time Complexity

O(n) as single traversal

## Space Complexity

O(1), algorithm doesn't requires any extra space except the variables.
