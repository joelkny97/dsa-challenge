# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        res = []
        parent={}
        bfs = deque()
        bfs.append(root)

        # traverse usng bfs and add the parent-child relationship in a dict
        while bfs:
            size=len(bfs)

            # iterate all the current level
            for _ in range(size):
                top = bfs.popleft()

                if top.left:
                    # add the left child parent relationship to the dict
                    parent[top.left.val] = top
                    # add the child to the queue
                    bfs.append(top.left)

                if top.right:
                    # add the right child parent relationship to the dict
                    parent[top.right.val] = top
                    # add the child to the queue
                    bfs.append(top.right)

        visited = {}
        # to find the nearest k, append the target node to the queue
        bfs.append(target)
        # while queue is not empty and within k
        while k>0 and bfs:
            size = len(bfs)

            for _ in range(size):
                top = bfs.popleft()
                #mark the current node as visited
                visited[top.val] = 1

                # check if left exists and left val not yet visited
                if top.left and top.left.val not in visited:
                    bfs.append(top.left)
                # check if right exists and right val not yet visited
                if top.right and top.right.val not in visited:
                    bfs.append(top.right)
                # check if current node val not yet visited and parent-child relationship not stored
                if top.val in parent and parent[top.val].val not in visited:
                    bfs.append(parent[top.val])

            k -= 1

        while bfs:
            res.append(bfs.popleft().val)

        return res
        