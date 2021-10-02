/*
* Requires the array of values to be build RMQ with in a LongArray format
* */
class RMQ(values: LongArray) {
    var lift: Array<LongArray>
    val N: Int

    init {
        val n = values.size
        N = n
        val maxLog = Integer.numberOfTrailingZeros(Integer.highestOneBit(n)) + 2
        lift = Array(maxLog) { LongArray(n) }
        for(i in 0 until n) {
            lift[0][i] = values[i]
        }

        var lastRange = 1
        for(lg in 1 until maxLog) {
            for(i in 0 until n) {
                lift[lg][i] = combine(lift[lg -1][i], lift[lg - 1][minOf(i + lastRange, n - 1)])
            }
            lastRange *= 2
        }
    }

    /*
    * Define your merge function for the RMQ
    * */
    private fun combine(a: Long, b: Long): Long {
        return minOf(a, b);
    }

    /*
    * @param l range start
    * @param r range end
    * @return query of the function defined in the range [l, r)
    * */
    fun query(l: Int, r: Int): Long {
        assert(l in 0 until r && r <= N)
        val range = r - l
        val exp = Integer.highestOneBit(range)
        val lg = Integer.numberOfTrailingZeros(exp)
        return combine(lift[lg][l], lift[lg][r - exp])
    }
}