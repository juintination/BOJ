import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int alph[] = new int[26];
        for (int i = 0; i < 26; i++) alph[i] = -1;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < str.length(); j++) {
                if (97 + i == str.charAt(j)) {
                    alph[i] += j + 1;
                    break;
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 26; i++) sb.append(alph[i]).append(" ");
        System.out.println(sb);
    }
}