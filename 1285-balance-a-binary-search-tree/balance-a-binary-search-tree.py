# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:

        if not root:
            return None

        inord = []

        
        def inorder(root):
            if root is None:
                return
            
            if root.left:
                inorder(root.left)

            inord.append(root.val)

            if root.right:
                inorder(root.right)
            
        inorder(root)
        # print(inord)
        if len(inord) <= 1:
            return root

        new_root = TreeNode(0)
        q = [(new_root, 0, len(inord)-1 )]

        while q:
            node, l, r = q.pop(0)
            mid = l +(r - l) // 2
            node.val = inord[mid]
            
            if l <= mid-1:
                node.left = TreeNode(0)
                q.append((node.left, l, mid-1))
            if mid+1 <= r:
                node.right = TreeNode(0)
                q.append((node.right, mid+1, r))

            

        return new_root




        