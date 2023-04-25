package ads.poo2.lab5.sorting;

import ads.poo2.lab4.heaps.EmptyHeapException;

/**
 * A class for the heap sort algorithm.
 */
public class HeapSort {
	
	/**
	 * Sort the array in place using the heapsort algorithm
	 * Complexity: THETA( n.log(n) ) where n is the size of the array
	 */	
	public static <T extends Comparable<T>> void sort(T[] array) {
		BinaryHeap<T> heap = new BinaryHeap<>(array);
		for(int i = 0; i< array.length; i++){
			try {
				T min = heap.deleteExtreme();
				array[array.length-1-i] = min;
			} catch (EmptyHeapException e) {
				throw new RuntimeException(e);
			}
		}
	}
}
