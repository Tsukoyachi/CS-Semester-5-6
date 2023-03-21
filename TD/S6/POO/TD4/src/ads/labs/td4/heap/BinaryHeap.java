package ads.labs.td4.heap;

import java.util.Comparator;
import java.util.logging.Logger;

/**
 * array class for binary heap implementation
 */
public class BinaryHeap<T extends Comparable<? super T>> {

    private T[] array; // to store the heap
    private int size;    // the number of elements in the heap

    public static Logger LOGGER = Logger.getLogger("BinaryHeap");

    // comparator to choose
    private Comparator<T> comparator = (e1, e2) -> e1.compareTo(e2);

    /**
     * Return the array of the heap.
     * This method is only for testing purposes.
     *
     * @return the array of the heap
     */
    protected T[] getArray() {
        return array;
    }

    ///////////// Constructors

    /**
     * Build a heap of capacity n.
     * The elements are ordered according to the
     * natural order on T.
     * The heap is empty.
     * Complexity: THETA(1)
     */
    @SuppressWarnings("unchecked")
    public BinaryHeap(int n) {
        array = (T[]) new Comparable[n];
        size = 0;
    }

    /**
     * Build a heap of capacity n.
     * The elements are ordered according to comparator.
     * The heap is empty.
     * Complexity: THETA(1)
     */
    @SuppressWarnings("unchecked")
    public BinaryHeap(int n, Comparator<T> comparator) {
        this.array = (T[]) new Comparable[n];
        this.size = 0;
        this.comparator = comparator;
    }

    /**
     * Build a heap based on array.
     * The elements are ordered according to the
     * natural order on T.
     * The heap is full
     */
    public BinaryHeap(T... elements) {
        this.array = elements;
        this.size = elements.length;
        buildHeap();
    }

    /**
     * Build a heap based on array.
     * The elements are ordered according to comparator.
     * The heap is full
     */
    public BinaryHeap(T[] array, Comparator<T> comparator) {
        this.array = array;
        this.size = array.length;
        this.comparator = comparator;
        buildHeap();
    }

    ///////////// Private methods

    /**
     * Swap values in the array
     * at indexes i and j.
     * Complexity: THETA(1)
     */
    private void swap(int i, int j) {
        T tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }

    /**
     * This method check if an index is defined in the heap
     *
     * @param n the index to check
     * @return true if the index is defined
     */
    private boolean indexExistInHeap(int n) {
        return n <= size && array[n] != null;
    }

    /**
     * Return the number of the left
     * node of node number n.
     * Complexity: THETA(1)
     */
    private int left(int n) {
        return 2 * n + 1;
    }

    /**
     * Return the number of the right
     * node of node number n.
     * Complexity: THETA(1)
     */
    private int right(int n) {
        return 2 * (n + 1);
    }

    /**
     * Return the number of the parent
     * node of node number n.
     * Complexity: THETA(1)
     */
    private int parent(int n) {
        return (n - 1) / 2;
    }

    /**
     * Percolate down the element at node number n
     * Complexity: O(log(size))
     */
    private void percolateDown(int n) {
        int hole;

        T tmp = array[n];

        for (hole = n;
             hole > 1 && comparator.compare(tmp, array[hole / 2]) < 0;
             hole /= 2) {
            array[hole] = array[hole / 2];
        }

        array[hole] = tmp;
    }

    /**
     * Percolate up the element at node number n
     * Complexity: O(log(size))
     */
    private void percolateUp(int n) {
        while (n > 1) {
            if (!indexExistInHeap(n) || !indexExistInHeap(parent(n))) {
                break;
            }
            if (comparator.compare(array[n], array[parent(n)]) < 0) {
                swap(n, parent(n));
                n = parent(n);
            } else {
                break;
            }
        }
    }

    /**
     * Arrange the elements in array such
     * that it has the heap property.
     * Complexity: O(size)
     */
    private void buildHeap() {
        for (int i = size / 2; i >= 0; i--) {
            percolateDown(i);
        }
    }

    ///////////// Public methods

    /**
     * Return the size of the heap
     * (the number of elements in the heap).
     * Complexity: THETA(1)
     */
    public int size() {
        return size;
    }

    /**
     * Check if the heap is empty.
     * Complexity: THETA(1)
     */
    public boolean isEmpty() {
        return size == 0;
    }

    /**
     * Return the extreme element.
     * Complexity: THETA(1)
     */
    public T extreme() throws EmptyHeapException {
        if (indexExistInHeap(1)) {
            return array[1];
        }
        throw new EmptyHeapException();
    }

    /**
     * Check if the element at index n is a leaf
     *
     * @param n the index to check
     * @return true if it's a leaf, else return false
     */
    public boolean isLeaf(int n) {
        return indexExistInHeap(left(n)) || indexExistInHeap(right(n));
    }

    /**
     * Return and delete the extreme element.
     * Ensure that the free space is at the end of the array and does not refer to any element.
     * Complexity: O(log(size))
     */
    public T deleteExtreme() throws EmptyHeapException {
        return null;
    }

    /**
     * Add a new element in the heap
     * Complexity: O(log(size))
     */
    public void add(T e) throws FullHeapException {

    }

    ///////////// Part 3: deleting in the heap

    /**
     * Delete the element e from the heap.
     * Complexity: O(size)
     */
    public void delete(T e) {

    }

    /**
     * Delete all the elements e from the heap.
     * Complexity: O(size)
     */
    public void deleteAll(T e) {
    }

    public String toStringByLevels() {
        StringBuilder bld = new StringBuilder();
        int level = 0;
        int nbNodes = 1;
        for (int i = 0; i < size; i++) {
            if (i == nbNodes) {
                bld.append("\n");
                level++;
                nbNodes += Math.pow(2, level);
            }
            bld.append("(" + i + ")" + array[i] + " ");
        }
        return bld.toString();
    }

    public T inverseExtreme() {
        return null;
    }
}
