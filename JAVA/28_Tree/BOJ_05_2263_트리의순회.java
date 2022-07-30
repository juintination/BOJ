import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[] in, inIdx, post;
    static StringBuilder sb = new StringBuilder();

    public static void getPreorder(int inLeft, int inRight, int postLeft, int postRight) {
        if (inLeft > inRight || postLeft > postRight) return;
        int root = post[postRight];
        sb.append(root).append(" ");
        int rootIdx = inIdx[root];
        int leftOfRoot = rootIdx - inLeft;
        getPreorder(inLeft, rootIdx - 1, postLeft, postLeft + leftOfRoot - 1);
        getPreorder(rootIdx + 1, inRight, postLeft + leftOfRoot, postRight - 1);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        in = new int[n + 1];
        inIdx = new int[n + 1];
        post = new int[n + 1];
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 1; i <= n; i++) {
            in[i] = Integer.parseInt(st.nextToken());
            inIdx[in[i]] = i;
        }
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 1; i <= n; i++) {
            post[i] = Integer.parseInt(st.nextToken());
        }
        getPreorder(1, n, 1, n);
        System.out.println(sb);
    }
}