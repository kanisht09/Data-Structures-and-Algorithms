class SegmentChange(var toSet: Long = 0L) {
    // Make sure that the default constructor is the identity segment_change
    private val SENTINEL: Long = 0L
 
    // resets to the SENTINEL value
    fun reset() {
        toSet = SENTINEL
    }
 
    fun hasChange(): Boolean {
        return toSet != SENTINEL
    }
 
    // Return the combined result of applying this segment change followed by the `other`.
    fun combine(other: SegmentChange): SegmentChange {
        return SegmentChange(toSet + other.toSet)
    }
}
 
class Segment(var sum: Long = 0L) {
    // Make sure that the default constructor is the identity segment
    private val SENTINEL: Long = 0L
 
    // checks if the current segment is empty based on the default value
    fun empty(): Boolean {
        return sum == SENTINEL
    }
 
    // evaluating the change on a particular node
    fun apply(length: Int, change: SegmentChange) {
        if (change.hasChange()) {
            sum += length * change.toSet
        }
    }
 
    // merge function
    fun join(other: Segment) {
        sum = sum + other.sum 
    }
 
    fun join(a: Segment, b: Segment) {
        sum = a.sum
        join(b)
    }
}
 
class SegmentTree(var n: Int = -1) {
    var treeN = 0;
    lateinit var tree: Array<Segment>
    lateinit var changes: Array<SegmentChange>
 
    init {
        if (n >= 0) {
            init(n)
        }
    }
 
    fun init(n: Int) {
        treeN = 1
        while (treeN < n) {
            treeN *= 2
        }
 
        tree = Array(2 * treeN) { Segment() }
        changes = Array(2 * treeN) { SegmentChange() }
    }
 
    private fun build(initial: Array<Segment>, x: Int, lx: Int, rx: Int) {
        if (rx - lx == 1) {
            if (lx < initial.size) {
                tree[x] = initial[lx]
            }
            return
        }
 
        val m = (rx + lx) / 2
        build(initial, 2 * x + 1, lx, m)
        build(initial, 2 * x + 2, m, rx)
        tree[x].join(tree[2 * x + 1], tree[2 * x + 2])
    }
 
    // Builds our tree from an array in O(n).
    fun build(initial: Array<Segment>) {
        n = initial.size
        init(n)
        assert(n <= treeN)
 
        build(initial, 0, 0, treeN)
    }
 
    // Apply the change to the current index and push down the change
    private fun propagate(x: Int, lx: Int, rx: Int) {
        if (!changes[x].hasChange()) {
            return
        }
        tree[x].apply(rx - lx, changes[x])
        if (rx - lx != 1) {
            changes[2 * x + 1] = changes[2 * x + 1].combine(changes[x])
            changes[2 * x + 2] = changes[2 * x + 2].combine(changes[x])
        }
        changes[x].reset()
    }
 
    private fun query(l: Int, r: Int, x: Int, lx: Int, rx: Int): Segment {
        propagate(x, lx, rx);
        if (lx >= r || l >= rx) {
            return Segment();
        }
        if (lx >= l && rx <= r) {
            return Segment(tree[x].sum);
        }
        val m = (lx + rx) / 2;
        val left = query(l, r, 2 * x + 1, lx, m);
        val right = query(l, r, 2 * x + 2, m, rx);
        left.join(right);
        return left;
    }

    // Queries in the range [l, r)
    fun query(l: Int, r: Int): Segment {
        return query(l, r, 0, 0, treeN)
    }
 
    private fun update(l: Int, r: Int, change: SegmentChange, x: Int, lx: Int, rx: Int) {
        propagate(x, lx, rx);
        if (lx >= r || l >= rx) {
            return;
        }
        if (lx >= l && rx <= r) {
            changes[x] = changes[x].combine(change);
            propagate(x, lx, rx);
            return;
        }
 
        val m = (lx + rx) / 2;
        update(l, r, change, 2 * x + 1, lx, m);
        update(l, r, change, 2 * x + 2, m, rx);
        tree[x].join(tree[2 * x + 1], tree[2 * x + 2]);
    }
 
    // Updates the change in the range [l, r)
    fun update(l: Int, r: Int, change: SegmentChange) {
        update(l, r, change, 0, 0, treeN);
    }
}