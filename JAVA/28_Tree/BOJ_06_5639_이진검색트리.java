import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class TreeNode {
    Integer data;
    TreeNode left, right;

    public TreeNode(Integer data) {
        this.data = data;
    }

    public void insert(int data) {
        if (this.data == null) this.data = data;
        if (data < this.data) {
            if (this.left == null) this.left = new TreeNode(data);
            else this.left.insert(data);
        } else if (data > this.data) {
            if (this.right == null) this.right = new TreeNode(data);
            else  this.right.insert(data);
        }
    }
}

public class Main {

    static StringBuilder sb = new StringBuilder();

    public static void postorder(TreeNode root) {
        if (root == null) return;
        if (root.left != null) postorder(root.left);
        if (root.right != null) postorder(root.right);
        sb.append(root.data).append("\n");
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        TreeNode root = new TreeNode(null);
        String data = null;
        while ((data = br.readLine()) != null) {
            root.insert(Integer.parseInt(data));
        }
        postorder(root);
        System.out.print(sb);
    }
}