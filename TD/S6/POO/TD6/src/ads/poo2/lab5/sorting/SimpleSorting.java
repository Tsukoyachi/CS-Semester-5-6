package ads.poo2.lab5.sorting;

/**
 * A class for simple sorting methods
 * We use the Comparable interface to compare elements
 * It's a utility class, so we don't need to instantiate it
 *
 * @author Marc Gaetano
 * @author Mireille blay
 */
public class SimpleSorting {

    /**
     * Sort the array in place using the selection sort algorithm
     * Complexity :
     * - Always O(n²)
     */
    public static <T extends Comparable<T>> void selection(T[] array) {
        for(int i = 0; i< array.length; i++){
            int index = i;
            for(int j = i; j< array.length;j++){
                if(array[j].compareTo(array[index]) < 0){
                    index = j;
                }
            }
            swap(array,i,index);
        }
    }

    /**
     * Sort the array in place using the insertion sort algorithm
     * Complexity:
     * - O(n) if already sorted
     * - O(n²) if reverse sorted
     * - O(n²) in general
     */
    public static <T extends Comparable<T>> void insertion(T[] array) {
        for (int i = 0; i < array.length; i++) {
            int index = -1;
            for (int j = 0; j<i; j++){
                if(array[i].compareTo(array[j]) < 0) {
                    index = j;
                    break;
                }
            }
            if(index != -1){
                for(int j = index; j<i;j++){
                    swap(array,j,i);
                }
            }
        }
    }

    /**
     * Swap array[i] and array[j]
     */
    private static <T> void swap(T[] array, int i, int j) {
        T tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
}
