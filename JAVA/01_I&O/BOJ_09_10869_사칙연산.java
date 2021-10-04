import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class func {
    int left, right;

    public void setOprands(int left, int right) {
        this.left = left;
        this.right = right;
    }

    public void sum() {
        System.out.println(this.left + this.right);
    }

    public void sub() {
        System.out.println(this.left - this.right);
    }

    public void mult() {
        System.out.println(this.left * this.right);
    }

    public void div() {
        System.out.println(this.left / this.right);
    }

    public void rest() {
        System.out.println(this.left % this.right);
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
 		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str," ");
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
        func c = new func();
        c.setOprands(a, b);
        c.sum();
        c.sub();
        c.mult();
        c.div();
        c.rest();
    }
}
