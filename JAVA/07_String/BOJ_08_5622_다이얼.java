import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int time = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) >= 65 && str.charAt(i) <= 79) {
                time += ((str.charAt(i) - 65) / 3 + 3);
            }
            else if (str.charAt(i) > 79 && str.charAt(i) <= 83) {
                time += 8;
            } else if (str.charAt(i) > 83 && str.charAt(i) <= 86) {
                time += 9;
            } else if (str.charAt(i) > 86 && str.charAt(i) <= 90) {
                time += 10;
            }
        }
        System.out.println(time);
    }
}