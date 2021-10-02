/*
* takes n as a optional argument when initialising DSU class
* This class uses 0-indexing, elements are in the range [0, n)
* Note: Use Threads to solve if you get StackOverFLow Error
* */
class DSU(var n: Int = -1) {
    lateinit var parent: IntArray
    lateinit var size: IntArray

    init {
        if(n != -1) {
            init(n)
        }
    }

    // Initialises the DSU data structure
    fun init(n: Int) {
        parent = IntArray(n)
        size = IntArray(n) { 1 }
        for(i in 0 until n) {
            parent[i] = i
        }
    }

    /*
    * Finds the representative element of `a`
    * uses path compression heuristic
    * */
    fun findParent(a: Int): Int {
        if(parent[a] == a){
            return a
        }
        parent[a] = findParent(parent[a])
        return parent[a]
    }

    /*
    * Merges 2 elements `a` and `b`
    * returns true if merge is possible else false
    * uses size heuristic while merging `a` and `b`
    * */
    fun merge(a: Int, b: Int): Boolean {
        var parentA = findParent(a)
        var parentB = findParent(b)

        if(parentA == parentB) {
            return false
        }

        if(size[parentA] > size[parentB]) {
            val tmp = parentA
            parentA = parentB
            parentB = tmp
        }

        parent[parentB] = parentA
        size[parentA] += size[parentB]

        return true
    }

    /*
    * returns the size of the component in which this element `a` is in
    * */
    fun getSize(a: Int): Int {
        return size[findParent(a)]
    }
}