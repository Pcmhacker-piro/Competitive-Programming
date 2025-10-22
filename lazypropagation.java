import java.util.*;

public class First {
    static class SGT {
        int[] tree, lazy;

        public SGT(int n) {
            tree = new int[4 * n];
            lazy = new int[4 * n];
        }

        void build(int node, int[] arr, int start, int end) {
            if (start == end) {
                tree[node] = arr[start];
                return;
            }
            int mid = (start + end) / 2;
            build(2 * node + 1, arr, start, mid);
            build(2 * node + 2, arr, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }

        void update(int node, int start, int end, int l, int r, int value) {
            // Apply pending lazy updates
            if (lazy[node] != 0) {
                tree[node] += (end - start + 1) * lazy[node];
                if (start != end) {
                    lazy[2 * node + 1] += lazy[node];
                    lazy[2 * node + 2] += lazy[node];
                }
                lazy[node] = 0;
            }

            // No overlap
            if (r < start || end < l) return;

            // Complete overlap
            if (l <= start && end <= r) {
                tree[node] += (end - start + 1) * value;
                if (start != end) {
                    lazy[2 * node + 1] += value;
                    lazy[2 * node + 2] += value;
                }
                return;
            }

            // Partial overlap
            int mid = (start + end) / 2;
            update(2 * node + 1, start, mid, l, r, value);
            update(2 * node + 2, mid + 1, end, l, r, value);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }

        int query(int node, int start, int end, int l, int r) {
            // Apply pending lazy updates
            if (lazy[node] != 0) {
                tree[node] += (end - start + 1) * lazy[node];
                if (start != end) {
                    lazy[2 * node + 1] += lazy[node];
                    lazy[2 * node + 2] += lazy[node];
                }
                lazy[node] = 0;
            }

            // No overlap
            if (r < start || end < l) return 0;

            // Complete overlap
            if (l <= start && end <= r) return tree[node];

            // Partial overlap
            int mid = (start + end) / 2;
            int left = query(2 * node + 1, start, mid, l, r);
            int right = query(2 * node + 2, mid + 1, end, l, r);
            return left + right;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

        SGT sg = new SGT(n);
        sg.build(0, arr, 0, n - 1);

        int t = sc.nextInt();
        while (t-- > 0) {
            int type = sc.nextInt();
            if (type == 1) { // Query
                int l = sc.nextInt();
                int r = sc.nextInt();
                System.out.println(sg.query(0, 0, n - 1, l, r));
            } else { // Update
                int l = sc.nextInt();
                int r = sc.nextInt();
                int val = sc.nextInt();
                sg.update(0, 0, n - 1, l, r, val);
            }
        }
    }
}
