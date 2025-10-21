public class SegmentTree {

    public static class SGETree {
        int[] tree;
        int n;

        public SGETree(int[] arr) {
            n = arr.length;
            tree = new int[4 * n];
            build(arr, 0, 0, n - 1);
        }

        public void build(int[] arr, int node, int start, int end) {
            if (start == end) {
                tree[node] = arr[start];
            } else {
                int mid = (start + end) / 2;
                build(arr, 2 * node + 1, start, mid);
                build(arr, 2 * node + 2, mid + 1, end);
                tree[node] = Math.min(tree[2 * node + 1], tree[2 * node + 2]);
            }
        }

        public void update(int index, int value) {
            update(tree, 0, 0, n - 1, index, value);
        }

        public void update(int[] tree, int node, int start, int end, int indx, int value) {
            if (start == end) {
                tree[node] = value;
                return;
            }

            int mid = (start + end) / 2;
            if (indx <= mid)
                update(tree, 2 * node + 1, start, mid, indx, value);
            else
                update(tree, 2 * node + 2, mid + 1, end, indx, value);

            tree[node] = Math.min(tree[2 * node + 1], tree[2 * node + 2]);
        }

        public int query(int left, int right) {
            return query(0, 0, n - 1, left, right);
        }

        public int query(int node, int start, int end, int left, int right) {
            if (right < start || end < left)
                return Integer.MAX_VALUE;

            if (left <= start && end <= right)
                return tree[node];

            int mid = (start + end) / 2;
            int leftMin = query(2 * node + 1, start, mid, left, right);
            int rightMin = query(2 * node + 2, mid + 1, end, left, right);
            return Math.min(leftMin, rightMin);
        }
    }

    public static void main(String[] args) {
        int[] arr = {4, 2, 7, 1, 3, 6};
        SGETree tree = new SGETree(arr);
        System.out.println("Min in range [1,4]: " + tree.query(1, 4)); // Expected 1
        tree.update(3, 8); // update index 3 (value 1 → 8)
        System.out.println("Min in range [1,4] after update: " + tree.query(1, 4)); // Expected 2
    }
}
