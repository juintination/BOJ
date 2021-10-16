import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int len = str.length();
        String[] arr = new String[len];
        for (int i = 0; i < len; i++) {
            arr[i] = str.substring(i);
        }
        Arrays.sort(arr);
        StringBuilder sb = new StringBuilder();
        for (String e : arr) {
            sb.append(e).append("\n");
        }
        System.out.println(sb);
    }
}