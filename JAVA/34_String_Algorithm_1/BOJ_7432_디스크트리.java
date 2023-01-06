import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;

class trieNode {
    HashMap<String, trieNode> child = new HashMap<>();
    boolean isEnd = false;

    public void insert(String str) {
        trieNode tNode = this;
        String[] directory = str.split("\\\\");
        for (String dir : directory) {
            tNode.child.putIfAbsent(dir, new trieNode());
            tNode = tNode.child.get(dir);
        }
        tNode.isEnd = true;
    }
}

public class Main {

    static StringBuilder sb = new StringBuilder();

    public static void dfs(trieNode tNode, int dpth) {
        if (tNode == null) return;
        ArrayList<String> list = new ArrayList<>(tNode.child.keySet());
        Collections.sort(list);
        for (String str : list) {
            for (int i = 0; i < dpth; i++) {
                sb.append(" ");
            }
            sb.append(str).append("\n");
            dfs(tNode.child.get(str), dpth + 1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        trieNode trie = new trieNode();
        for (int i = 0; i < n; i++) {
            trie.insert(br.readLine());
        }
        dfs(trie, 0);
        System.out.print(sb);
    }
}