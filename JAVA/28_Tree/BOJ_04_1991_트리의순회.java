import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class node {
	char data;
	node left, right;

	public node(char data) {
		this.data = data;
	}
}

public class Main {

	static node[] tree;
	static StringBuilder sb;

	public static void preorder(char data) {
		sb.append(tree[data - 'A'].data);
		if (tree[data - 'A'].left != null) {
			preorder(tree[data - 'A'].left.data);
		}
		if (tree[data - 'A'].right != null) {
			preorder(tree[data - 'A'].right.data);
		}
	}

	public static void inorder(char data) {
		if (tree[data - 'A'].left != null) {
			inorder(tree[data - 'A'].left.data);
		}
		sb.append(tree[data - 'A'].data);
		if (tree[data - 'A'].right != null) {
			inorder(tree[data - 'A'].right.data);
		}
	}

	public static void postorder(char data) {
		if (tree[data - 'A'].left != null) {
			postorder(tree[data - 'A'].left.data);
		}
		if (tree[data - 'A'].right != null) {
			postorder(tree[data - 'A'].right.data);
		}
		sb.append(tree[data - 'A'].data);
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		tree = new node[n];
		for (int i = 0; i < n; i++) {
			tree[i] = new node((char) ('A' + i));
		}
		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			char root = st.nextToken().charAt(0);
			char left = st.nextToken().charAt(0);
			char right = st.nextToken().charAt(0);
			if (left != '.') {
				tree[root - 'A'].left = tree[left - 'A'];
			}
			if (right != '.') {
				tree[root - 'A'].right = tree[right - 'A'];
			}
		}
		sb = new StringBuilder();
		preorder('A');
		sb.append("\n");
		inorder('A');
		sb.append("\n");
		postorder('A');
		System.out.print(sb);
	}
}