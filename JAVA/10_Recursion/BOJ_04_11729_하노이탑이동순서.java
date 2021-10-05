import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {

    static int cnt = 0;
    static StringBuilder sb = new StringBuilder();

    public static void hanoi(int n, int start, int mid, int goal) throws IOException {
        if (n == 1) {
            sb.append(start);
            sb.append(' ');
            sb.append(goal);
            sb.append('\n');
            cnt++;
        } else {
            hanoi(n - 1, start, goal, mid);
            hanoi(1, start, mid, goal);
            hanoi(n - 1, mid, start, goal);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        hanoi(n, 1, 2, 3);
        System.out.println(cnt);
        System.out.print(sb);
    }
}