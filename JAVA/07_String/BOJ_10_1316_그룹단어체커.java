import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int cnt = n;
        for (int i = 0; i < n; i++) {
            boolean test = true;
            String str = br.readLine();
            for (int j = 0; j < str.length() - 1; j++) {
                for (int k = j + 1; k < str.length(); k++) {
                    if (str.charAt(j) == str.charAt(k)) {
                        int gap = k - j;
                        if (gap >= 2) {
                            if (str.charAt(k) != str.charAt(k - 1)) {
                                test = false;
                                break;
                            }
                        }
                    }
                }
                if (test == false) break;
            }
            if (test == false) cnt--;
        }
        System.out.println(cnt);
    }
}