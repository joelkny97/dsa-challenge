# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.m = float('-inf')



        def dfs(root):
            if not root:
                return 0

            l = max(dfs(root.left), 0)
            r = max(dfs(root.right), 0)

            total = root.val + l + r

            self.m = max(self.m, total) #update global max 

            return root.val + max(l,r)

        dfs(root)

        return self.m


        