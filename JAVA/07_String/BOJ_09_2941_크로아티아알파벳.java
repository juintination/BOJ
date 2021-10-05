import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int sum = 0;
        for (int i = 0; i < str.length(); i++) {
            sum++;
            if (i < str.length() - 1) {
                if (str.charAt(i) == 'c') {
                    if (str.charAt(i + 1) == '=' || str.charAt(i + 1) == '-') {
                        sum--;
                    }
                } else if (str.charAt(i) == 'd') {
                    if (str.charAt(i + 1) == 'z') {
                        if (i < str.length() - 2 && str.charAt(i + 2) == '=') {
                            sum--;
                        }
                    } else if (str.charAt(i + 1) == '-') {
                        sum--;
                    }
                } else if (str.charAt(i) == 'l' || str.charAt(i) == 'n') {
                    if (str.charAt(i + 1) == 'j') {
                        sum--;
                    }
                } else if (str.charAt(i) == 's' || str.charAt(i) == 'z') {
                    if (str.charAt(i + 1) == '=') {
                        sum--;
                    }
                }
            }
        }
        System.out.println(sum);
    }
}