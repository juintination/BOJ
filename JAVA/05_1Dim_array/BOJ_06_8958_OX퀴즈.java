import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String ans[] = new String[n];
        int sum = 0, score = 0;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            ans[i] = br.readLine();
            for (int j = 0; j < ans[i].length(); j++) {
                if (ans[i].charAt(j) == 'O') {
                    score++;
                    sum += score;
                }
                else score = 0;
            }
            sb.append(sum).append("\n");
            score = 0;
            sum = 0;
        }
        System.out.println(sb);
    }
}