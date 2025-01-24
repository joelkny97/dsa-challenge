"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
from collections import defaultdict

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        mapping = {None:None}
        tmp = head
        while tmp:
            mapping[tmp] = Node(tmp.val)
            tmp = tmp.next
        tmp = head
        while tmp:
            copy = mapping[tmp]
            copy.next = mapping[tmp.next]
            copy.random = mapping[tmp.random]
            tmp = tmp.next
        return mapping[head]

        
        