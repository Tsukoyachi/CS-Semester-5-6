package ads.poo2.lab5.sorting;

/**
 * A class for the recursive merge sort algorithm.
 */
public class MergeSort {

    /**
     * Sort the array using the recursive merge sort algorithm.
     * This algorithm is not in place and needs an auxiliary array of
     * the same size than the array to sort
     * Complexity: THETA( n.log(n) ) where n is the size of the array
     */
    @SuppressWarnings("unchecked")
    public static <T extends Comparable<T>> void sort(T[] array) {
        T[] tmp = (T[]) new Comparable[array.length];
        sort(array, tmp, 0, array.length - 1);
    }

    /**
     * Sort the array in the range [lo, hi] using the portion [lo, hi]
     * of the auxiliary array tmp
     * Complexity: THETA( n.log(n) ) where n = hi - lo + 1
     */
    private static <T extends Comparable<T>> void sort(T[] array, T[] tmp, int lo, int hi) {
        if (lo >= hi) {
            return;
        }

        int mid = lo + (hi-lo)/2;
        sort(array, tmp, lo, mid);
        sort(array, tmp, mid + 1, hi);

        merge(array, tmp, lo, mid, hi);
    }

    /**
     * Merge array[lo, mid] and array[mid+1, hi] into tmp[lo, hi]
     * and copy back the result into array[lo, hi]
     * Precondition: array[lo, mid] and array[mid+1, hi] are sorted
     * Complexity: THETA( n ) where n = hi - lo + 1
     */
    private static <T extends Comparable<T>> void merge(T[] array, T[] tmp, int lo, int mid, int hi) {
        int size1 = mid - lo + 1;
        int size2 = hi - mid;
        int i = 0;
        int j = 0;
        int index = lo;
        while (i < size1 && j < size2){
            if(array[lo+i].compareTo(array[mid+1+j]) <= 0) {
                tmp[index] = array[lo+i];
                i++;
            }
            else {
                tmp[index] = array[mid+1+j];
                j++;
            }
            index++;
        }

        while(i < size1){
            tmp[index] = array[lo+i];
            i++;
            index++;
        }

        while(j < size2){
            tmp[index] = array[mid+1+j];
            j++;
            index++;
        }

        transfer(tmp,array,lo,hi);
    }

    /**
     * Copy the elements from tmp[lo, hi] into array[lo, hi]
     * Complexity: THETA( n ) where n = hi - lo + 1
     */
    private static <T> void transfer(T[] tmp, T[] array, int lo, int hi) {
        for (int i = lo; i <= hi; i++) {
            array[i] = tmp[i];
        }
    }
}
