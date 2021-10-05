public class Main {
    public static int selfnum(int n) {
        int create = n;
        while (n != 0) {
            create += n % 10;
            n /= 10;
        }
        return create;
    }

    public static void main(String[] args) {
        boolean arr[] = new boolean[10000];
        for (int i = 1; i < 10000; i++) {
            if (selfnum(i) < 10000) arr[selfnum(i)] = true;
        }
        for (int i = 1; i < 10000; i++) {
            if (arr[i] == false) System.out.println(i);
        }
    }
}