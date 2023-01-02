import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
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

    public boolean contains(String word) {
        trieNode tNode = this;
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            tNode = tNode.child.get(c);
            if (tNode == null) {
                return false;
            }
        }
        return tNode.isEnd;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        trieNode trie = new trieNode();
        for (int i = 0; i < n; i++) {
            trie.insert(br.readLine());
        }
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            if (trie.contains(br.readLine())) {
                cnt++;
            }
        }
        System.out.println(cnt);
    }
}