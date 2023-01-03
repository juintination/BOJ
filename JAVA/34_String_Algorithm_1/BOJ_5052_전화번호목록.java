import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;

class trieNode {
    HashMap<Character, trieNode> child = new HashMap<>();
    // boolean isEnd = false;

    public void insert(String word) {
        trieNode tNode = this;
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            tNode.child.putIfAbsent(c, new trieNode());
            tNode = tNode.child.get(c);
        }
        // tNode.isEnd = true;
    }

    public boolean isPrefix(String word) {
        trieNode tNode = this;
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            tNode = tNode.child.get(c);
        }
        return tNode.child.size() != 0;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] arr = new String[n];
            trieNode trie = new trieNode();
            for (int i = 0; i < n; i++) {
                arr[i] = br.readLine();
                trie.insert(arr[i]);
            }
            boolean consistency = true;
            for (int i = 0; i < n; i++) {
                if (trie.isPrefix(arr[i])) {
                    sb.append("NO\n");
                    consistency = false;
                    break;
                }
            }
            if (consistency) {
                sb.append("YES\n");
            }
        }
        System.out.print(sb);
    }
}