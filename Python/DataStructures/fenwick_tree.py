class FenwickTree:
    def __init__(self, n):
        self.tree_n = n
        self.tree_sum = 0
        self.tree = [0 for _ in range(self.tree_n + 1)]

    '''
    O(n) initialization of the Fenwick tree.
    '''
    def build(self, initial):
        assert len(initial) == self.tree_n
        self.tree_sum = 0

        for i in range(1, self.tree_n + 1):
            self.tree[i] = initial[i - 1]
            self.tree_sum += initial[i - 1]

            k = (i & -i) >> 1
            while k > 0:
                self.tree[i] += self.tree[i - k]
                k = k >> 1

    '''
    index is in [0, tree_n).
    '''
    def update(self, index, change):
        assert 0 <= index < self.tree_n
        self.tree_sum += change

        i = index + 1
        while i <= self.tree_n:
            self.tree[i] += change
            i += (i & -i)

    '''
    Returns the sum of the range [0, count).
    '''
    def query_prefix(self, count):
        count = min(count, self.tree_n)
        sum = 0
        i = count
        while i > 0:
            sum += self.tree[i]
            i -= i & -i
        return sum

    '''
    Returns the sum of the range [start, tree_n).
    '''
    def query_suffix(self, start):
        return self.tree_sum - self.query(start)

    '''
    Returns the sum of the range [a, b).
    '''
    def query(self, a, b):
        return self.query_prefix(b) - self.query_prefix(a)

    '''
    Returns the element at index `a` in O(1) amortized across every index.
    Equivalent to query(a, a + 1).
    '''
    def get(self, a):
        assert 0 <= a < self.tree_n
        above = a + 1
        sum = self.tree[above]
        above -= above & -above

        while a != above:
            sum -= self.tree[a]
            a -= a & -a

        return sum

    '''
    Sets the value of the array at index `index` to `value`
    '''
    def set(self, index, value):
        assert 0 <= index < self.tree_n
        current = self.get(index)

        if current == value:
            return False

        self.update(index, value - current)
        return True