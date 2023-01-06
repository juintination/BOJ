import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static int[] getPi(String pattern) {
        int lenPtn = pattern.length();
        int[] pi = new int[lenPtn];
        int idx = 0;
        for (int i = 1; i < lenPtn; i++) {
            while (idx > 0 && pattern.charAt(i) != pattern.charAt(idx)) {
                idx = pi[idx - 1];
            }
            if (pattern.charAt(i) == pattern.charAt(idx)) {
                pi[i] = ++idx;
            }
        }
        return pi;
    }

    public static int KMP(String target, String pattern) {
        int lenTxt = target.length(), lenPtn = pattern.length();
        int[] pi = getPi(pattern);
        int idx = 0;
        for (int i = 0; i < lenTxt; i++) {
            while (idx > 0 && target.charAt(i) != pattern.charAt(idx)) {
                idx = pi[idx - 1];
            }
            if (target.charAt(i) == pattern.charAt(idx)) {
                if (idx == lenPtn - 1) {
                    return 1;
                } else idx++;
            }
        }
        return 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String text = br.readLine();
        String pattern = br.readLine();
        System.out.println(KMP(text, pattern));
    }
}