import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        str = str.toUpperCase();
        int cnt[] = new int[26];
        for (int i = 0; i < str.length(); i++) {
            int a = str.charAt(i);
            a -= 65;
            cnt[a]++;
        }
        int tmp = 0, max = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > max) {
                max = cnt[i];
                tmp = i;
            }
        }
        int tst = 0;
        for (int i = 0; i < 26; i++) {
            if (max == cnt[i]) tst++;
        }
        if (tst > 1) System.out.println("?");
        else System.out.println((char) (tmp + 65));
    }
}