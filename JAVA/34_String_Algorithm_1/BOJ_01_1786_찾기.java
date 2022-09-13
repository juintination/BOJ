import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

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

    public static ArrayList<Integer> KMP(String target, String pattern) {
        ArrayList<Integer> list = new ArrayList<>();
        int lenTxt = target.length(), lenPtn = pattern.length();
        int[] pi = getPi(pattern);
        for (int i = 0, idx = 0; i < lenTxt; i++) {
            while (idx > 0 && target.charAt(i) != pattern.charAt(idx)) {
                idx = pi[idx - 1];
            }
            if (target.charAt(i) == pattern.charAt(idx)) {
                if (idx == lenPtn - 1) {
                    list.add(i - idx + 1);
                    idx = pi[idx];
                } else idx++;
            }
        }
        return list;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String text = br.readLine();
        String pattern = br.readLine();
        StringBuilder sb = new StringBuilder();
        ArrayList<Integer> list = KMP(text, pattern);
        sb.append(list.size()).append("\n");
        for (int e : list) {
            sb.append(e).append(" ");
        }
        System.out.println(sb);
    }
}