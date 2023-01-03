import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;

class trieNode {
    HashMap<Character, trieNode> child = new HashMap<>();
    boolean isEnd = false;

    public void insert(String word) {
        trieNode tNode = this;
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            tNode.child.putIfAbsent(c, new trieNode());
            tNode = tNode.child.get(c);
        }
        tNode.isEnd = true;
    }

    public int getCount(String word) {
        int push = 1;
        char c = word.charAt(0);
        trieNode tNode = this.child.get(c);
        for (int i = 1; i < word.length(); i++) {
            if (tNode.child.size() > 1 || tNode.isEnd) {
                push++;
            }
            c = word.charAt(i);
            tNode = tNode.child.get(c);
        }
        return push;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while (true) {
            String str = br.readLine();
            if (str == null) break;
            int n = Integer.parseInt(str);
            String[] arr = new String[n];
            trieNode trie = new trieNode();
            for (int i = 0; i < n; i++) {
                arr[i] = br.readLine();
                trie.insert(arr[i]);
            }
            double cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += trie.getCount(arr[i]);
            }
            sb.append(String.format("%.02f", cnt / n)).append("\n");
        }
        System.out.print(sb);
    }
}