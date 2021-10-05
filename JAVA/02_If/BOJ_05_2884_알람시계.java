import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		int hour = Integer.parseInt(st.nextToken());
		int minute = Integer.parseInt(st.nextToken());
        if (0 <= hour && hour <= 23 && 0 <= minute && minute <= 59) {
            if (hour == 0 && minute < 45) {
                System.out.println(23 + " " + (minute + 15));
            }
            else if (minute >= 45) {
                System.out.println(hour + " " + (minute - 45));
            }
            else if (hour != 0 && minute < 45) {
                System.out.println((hour - 1) + " " + (minute + 15));
            }
        }
        else System.out.println(0);
    }
}