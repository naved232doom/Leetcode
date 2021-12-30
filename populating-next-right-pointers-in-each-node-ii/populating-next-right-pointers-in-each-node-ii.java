/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public void bfs(Node root) {
        if (root == null) return;
        Node tmp_root = root;
        Node dummy = new Node(-200);
        while (tmp_root != null) {
            if (tmp_root.left != null) {
                dummy.next = tmp_root.left;
                dummy = dummy.next;
            }
            if (tmp_root.right != null) {
                dummy.next = tmp_root.right;
                dummy = dummy.next;
            }

            tmp_root = tmp_root.next;
        }
        bfs(root.left);
        bfs(root.right);
    }
    public Node connect(Node root) {
        bfs(root);
        return root;
    }
}