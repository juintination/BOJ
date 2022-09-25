import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static int[] getPi(String pattern) {
        int lenPtn = pattern.length();
        int[] pi = new int[lenPtn];
        for (int i = 1, idx = 0; i < lenPtn; i++) {
            while (idx > 0 && pattern.charAt(i) != pattern.charAt(idx)) {
                idx = pi[idx - 1];
            }
            if (pattern.charAt(i) == pattern.charAt(idx)) {
                pi[i] = ++idx;
            }
        }
        return pi;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int l = Integer.parseInt(br.readLine());
        String ad = br.readLine();
        int[] pi = getPi(ad);
        System.out.println(l - pi[l - 1]);
    }
}