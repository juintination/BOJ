import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class node {
	int data, parent;
	node left, right;

	public node(int data) {
		this.parent = -1;
		this.data = data;
	}
}

public class Main {

	static int cnt = 1, dpth = 1;
	static int[] arr, max, min;
	static node[] tree;

	public static void inorder(int data, int level) {
		if (tree[data].left != null) {
			inorder(tree[data].left.data, level + 1);
		}
		max[level] = Math.max(max[level], cnt);
		min[level] = Math.min(min[level], cnt);
		arr[cnt++] = level;
		if (tree[data].right != null) {
			inorder(tree[data].right.data, level + 1);
		}
		dpth = Math.max(dpth, level);
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		arr = new int[n + 1];
		max = new int[n + 1];
		min = new int[n + 1];
		tree = new node[n + 1];
		for (int i = 1; i <= n; i++) {
			tree[i] = new node(i);
			max[i] = 0;
			min[i] = n;
		}
		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			int data = Integer.parseInt(st.nextToken());
			int left = Integer.parseInt(st.nextToken());
			int right = Integer.parseInt(st.nextToken());
			if (left != -1) {
				tree[left].parent = data;
				tree[data].left = tree[left];
			}
			if (right != -1) {
				tree[right].parent = data;
				tree[data].right = tree[right];
			}
		}
		int root = 1;
		for (int i = 1; i <= n; i++) {
			if (tree[i].parent == -1) {
				root = i;
				break;
			}
		}
		inorder(root, 1);
		int width = 0, level = 1;
		for (int i = 2; i <= dpth; i++) {
			int tmp = max[i] - min[i];
			if (tmp > width) {
				width = tmp;
				level = i;
			}
		}
		StringBuilder sb = new StringBuilder();
		sb.append(level).append(" ").append(width + 1);
		System.out.print(sb);
	}
}