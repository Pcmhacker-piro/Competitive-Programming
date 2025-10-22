    static class SGT {
        int[] tree;
        int[] lazy;
        int n;

        public SGT(int[] arr) {
            n = arr.length;
            tree = new int[4 * n];
            lazy = new int[4 * n];
            build(0, arr, 0, n - 1);
        }

        void build(int node, int[] arr, int start, int end) {
            if (start == end) {
                tree[node] = arr[start];
                return;
            }
            int mid = (start + end) / 2;
            build(2 * node + 1, arr, start, mid);
            build(2 * node + 2, arr, mid + 1, end);
            tree[node] = Math.min(tree[2 * node + 1], tree[2 * node + 2]);
        }

        void update(int node, int start, int end, int l, int r, int value) {
            // Apply pending lazy updates
            if (lazy[node] != 0) {
                tree[node] += lazy[node];
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
                tree[node] += value;
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
            tree[node] = Math.min(tree[2 * node + 1], tree[2 * node + 2]);
        }

        int query(int node, int start, int end, int l, int r) {
            // Apply pending lazy updates
            if (lazy[node] != 0) {
                tree[node] += lazy[node];
                if (start != end) {
                    lazy[2 * node + 1] += lazy[node];
                    lazy[2 * node + 2] += lazy[node];
                }
                lazy[node] = 0;
            }

            // No overlap
            if (r < start || end < l) return Integer.MAX_VALUE;

            // Complete overlap
            if (l <= start && end <= r) return tree[node];

            // Partial overlap
            int mid = (start + end) / 2;
            int left = query(2 * node + 1, start, mid, l, r);
            int right = query(2 * node + 2, mid + 1, end, l, r);
            return Math.min(left, right);
        }
    }
