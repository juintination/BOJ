import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    final static int INF = Integer.MAX_VALUE / 2;
    static Integer[][] idxArr;

    public static String floydWarshall(int[][] route, int n) {
        StringBuilder sb = new StringBuilder();
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (route[i][j] > route[i][k] + route[k][j]) {
                        route[i][j] = route[i][k] + route[k][j];
                        idxArr[i][j] = idxArr[k][j];
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                sb.append(route[i][j] != INF ? route[i][j] : 0).append(" ");
            }
            sb.append("\n");
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (idxArr[i][j] == null) {
                    sb.append(0);
                } else {
                    Stack<Integer> stack = new Stack<>();
                    stack.push(j);
                    int k = idxArr[i][j];
                    while (i != k) {
                        stack.push(k);
                        k = idxArr[i][k];
                    }
                    stack.push(i);
                    sb.append(stack.size()).append(" ");
                    while (!stack.isEmpty()) {
                        sb.append(stack.pop()).append(" ");
                    }
                }
                sb.append("\n");
            }
        }
        return sb.toString();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        int[][] route = new int[n + 1][n + 1];
        idxArr = new Integer[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            Arrays.fill(route[i], INF);
            route[i][i] = 0;
        }
        while (m-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            route[a][b] = Math.min(route[a][b], c);
            idxArr[a][b] = a;
        }
        System.out.print(floydWarshall(route, n));
    }
}