package ads.poo2.lab3.bst2.ORIGIN;

import java.util.*;

/**
 * A class for Binary Search Trees
 */
public class BinarySearchTree<T extends Comparable<? super T>> implements Iterable<T> {

    private T element;
    private BinarySearchTree<T> left;
    private BinarySearchTree<T> right;


    //return the value of the root of the tree
    public T getElement() {
        return this.element;
    }

    protected void setElement(T element) {
        this.element = element;
    }

    protected BinarySearchTree<T> getLeft() {
        return this.left;
    }

    protected void setLeft(BinarySearchTree<T> left) {
        this.left = left;
    }

    protected BinarySearchTree<T> getRight() {
        return this.right;
    }

    protected void setRight(BinarySearchTree<T> right) {
        this.right = right;
    }


    /**
     * Construct the tree.
     */
    public BinarySearchTree(T element, BinarySearchTree<T> left, BinarySearchTree<T> right) {
        this.element = element;
        this.left = left;
        this.right = right;
    }

    public BinarySearchTree(T element) {
        this(element, null, null);
    }

    public BinarySearchTree() {
        this(null, null, null);
    }

    /////////////// isEmpty

    /**
     * Test if the tree is logically empty.
     *
     * @return true if empty, false otherwise.
     */
    public boolean isEmpty() {
        return this.getElement() == null && this.getLeft() == null && this.getRight() == null;
    }

    /////////////// makeEmpty  

    /**
     * Make the tree logically empty.
     */
    public void makeEmpty() {
        this.setLeft(null);
        this.setRight(null);
        this.setElement(null);
    }

    /////////////// contains

    /**
     * Find an item in the tree.
     *
     * @param x the item to search for.
     * @return true if not found.
     */
    public boolean contains(T x) {
        if (this.getElement() == null) {
            return false;
        }
        int comparison = x.compareTo(this.getElement());
        if (comparison == 0) {
            return true;
        }
        if (comparison < 0) {
            return this.getLeft() != null && this.getLeft().contains(x);
        }
        return this.getRight() != null && this.getRight().contains(x);
    }

    //////////////// size ////////////////
    // The size of a BN is its number of
    // non-null nodes
    public int getSize() {
        if (this.isEmpty()) {
            return 0;
        }
        int x = 0;
        if (this.getElement() != null) {
            x = 1;
        }
        if (this.getLeft() != null) {
            x += this.getLeft().getSize();
        }
        if (this.getRight() != null) {
            x += this.getRight().getSize();
        }
        return x;
    }

    public boolean isLeaf() {
        return this.getLeft() == null && this.getRight() == null;
    }

    /////////////// insert

    /**
     * Insert into the tree; duplicates are ignored.
     *
     * @param x the item to insert.
     */
    public void insert(T x) {
        if (this.getElement() == null) {
            this.setElement(x);
            return;
        }
        int comparison = x.compareTo(this.getElement());
        if (comparison == 0) {
            return;
        }
        if (comparison < 0) {
            if (this.left != null) {
                this.getLeft().insert(x);
            } else {
                this.setLeft(new BinarySearchTree<>(x, null, null));
            }
        } else {
            if (this.right != null) {
                this.getRight().insert(x);
            } else {
                this.setRight(new BinarySearchTree<>(x, null, null));
            }
        }
    }

    /**
     * Find the smallest item in the tree.
     *
     * @return smallest item or null if empty.
     */
    public T findMin() {
        if (this.isLeaf() || this.getLeft() == null) {
            return this.getElement();
        }
        return this.getLeft().findMin();
    }

    /////////////// findMax

    /**
     * Find the largest item in the tree.
     *
     * @return the largest item or null if empty.
     */
    public T findMax() {
        if (this.isLeaf() || this.getRight() == null) {
            return this.getElement();
        }
        return this.getRight().findMax();
    }

    /////////////// remove

    /**
     * Remove from the tree. Nothing is done if x is not found.
     * In the test, we replace the removed element by the largest element of the left subtree
     *
     * @param x the item to remove.
     */
    public void remove(T x) {
        //Tip : deal with removing the root of the tree in a special way
        int compareResult = x.compareTo(this.getElement());
        if (compareResult == 0) {
            removeRoot();
        }
        if (compareResult < 0 && this.getLeft() != null) {
            this.getLeft().remove(x);
        }
        if (compareResult > 0 && this.getRight() != null) {
            this.getRight().remove(x);
        }
    }

    public void removeRoot() {
        if (this.isEmpty() || this.isLeaf()) {
            this.makeEmpty();
            return;
        }
        if (this.getLeft() == null) {
            this.element = this.right.getElement();
            this.left = this.right.left;
            this.right = this.right.right;
            return;
        }
        if (this.getRight() == null) {
            this.element = this.left.getElement();
            this.right = this.left.right;
            this.left = this.left.left;
            return;
        }
        T newRoot = this.getLeft().findMax();
        this.remove(newRoot);
        this.setElement(newRoot);
    }

    /////////////// removeLessThan

    /**
     * Remove from the tree all the elements
     * less than min
     *
     * @param min the minimum value left in the tree
     */
    public void removeLessThan(T min) {
        if(this.element == null){
            return;
        }
        int comparisonResult = min.compareTo(this.element);
        System.out.println(comparisonResult);
        if (comparisonResult == 0){
            this.setLeft(null);
            return;
        }
        if(comparisonResult > 0) {
            this.setLeft(null);
            if(this.getRight() != null){
                this.getRight().removeLessThan(min);
            }
            this.removeRoot();
            return;
        }
        if(this.getLeft() != null) {
            this.getLeft().removeLessThan(min);
        }
    }

    /////////////// removeGreaterThan

    /**
     * Remove from the tree all the elements
     * greater than max
     *
     * @param max the maximum value left in the tree
     */
    public void removeGreaterThan(T max) {
        if(this.element == null){
            return;
        }
        int comparisonResult = max.compareTo(this.element);
        System.out.println(comparisonResult);
        if (comparisonResult == 0){
            this.setRight(null);
            return;
        }
        if(comparisonResult < 0) {
            this.setRight(null);
            if(this.getLeft() != null){
                this.getLeft().removeGreaterThan(max);
            }
            this.removeRoot();
            return;
        }
        if(this.getRight() != null) {
            this.getRight().removeGreaterThan(max);
        }
    }

    /////////////// toSortedList

    /**
     * Return a sorted list (increasing) of all
     * the elements of the tree
     *
     * @return the sorted list of all the elements of the tree
     */
    public List<T> toSortedList() {
        if (this.isEmpty()) {
            return List.of();
        }
        if (this.isLeaf()) {
            return List.of(this.getElement());
        }
        List<T> res = new ArrayList<>();
        if (this.getLeft() != null) {
            res.addAll(this.getLeft().toSortedList());
        }
        res.add(this.getElement());
        if (this.getRight() != null) {
            res.addAll(this.getRight().toSortedList());
        }
        return res;
    }

    /////////////// sorted list to binary search tree

    /**
     * Build a binary search tree with all the
     * elements of the list
     *
     * @param list a sorted (increasing) list of elements
     */
    public BinarySearchTree(List<T> list) {
        makeTree(list, 0, list.size() - 1);
    }

    //Usefull method to build a binary search tree  from a sorted list
    //The list is divided in two parts, the first part is used to build
    //the left subtree, the second part is used to build the right subtree
    private BinarySearchTree<T> makeTree(List<T> list, int i, int j) {
        return null;
    }


    /////////////// iterator on binary search tree


    /**
     * Return an iterator over the elements of the tree.
     * The elements are enumerated in increasing order.
     */
    public Iterator<T> iterator() {
        return new BinarySearchTree<T>.BSTiterator(this);
    }


    /**
     * Inner class to build iterator over the elements of
     * a tree
     */
    private class BSTiterator implements Iterator<T> {

        // we must push some binary nodes on the stack

        Deque<BinarySearchTree<T>> stack;


        /**
         * Build an iterator over the binary node n.
         * The elements are enumerated in increasing order.
         */
        BSTiterator(BinarySearchTree<T> n) {
            stack = new ArrayDeque<>();
            // push all the left nodes on the stack
            //TODO

        }

        /**
         * Check if there are more elements in the
         * iterator
         */
        public boolean hasNext() {
            return !stack.isEmpty();
        }

        /**
         * Return and remove the next element from
         * the iterator
         */
        public T next() {
            return stack.pop().getElement();
        }

        /**
         * Unsupported operation
         */
        @Override
        public void remove() {
            throw new UnsupportedOperationException("remove");
        }
    }

    ////////////////////////////////////////////////////
    // Convenience method to print a tree
    ////////////////////////////////////////////////////


    public void display() {
        display(this, "", "");
    }

    private void display(BinarySearchTree<T> t, String r, String p) {
        if (t == null || t.isEmpty()) {
            System.out.println(r);
        } else {
            String rs = t.getElement().toString();
            System.out.println(r + rs);
            if (t.getLeft() != null || t.getRight() != null) {
                String rr = p + '|' + makeString('_', rs.length()) + ' ';
                display(t.getLeft(), rr, p + '|' + makeString(' ', rs.length() + 1));
                System.out.println(p + '|');
                display(t.getRight(), rr, p + makeString(' ', rs.length() + 2));
            }
        }
    }

    private String makeString(char c, int k) {
        return String.valueOf(c).repeat(Math.max(0, k));
    }


    ////////////////////////////////////////////////////
    // Convenience methods to build a list of integer from a string
    ////////////////////////////////////////////////////

    private static List<Integer> read(String inputString) {
        List<Integer> list = new LinkedList<>();
        Scanner input = new Scanner(inputString);
        while (input.hasNextInt())
            list.add(input.nextInt());
        input.close();
        return list;
    }

    /**
     * A short main for quick testing
     */
    public static void main(String[] args) {
        List<Integer> list = read("50 30 70 20 40 80 60");
        BinarySearchTree<Integer> bst = new BinarySearchTree<>();
        for (Integer n : list)
            bst.insert(n);
        bst.display();
        //From the lesson
        list = Arrays.asList(12, 17, 21, 19, 14, 13, 16, 9, 11, 10, 5, 8);
        System.out.println("---- From the lesson one by one");
        bst = new BinarySearchTree<>();
        //To control the position
        for (Integer n : list) {
            bst.insert(n);
        }
        System.out.println("Before insert 3");
        bst.display();
        bst.insert(3);
        System.out.println("After insert 3");
        bst.display();
        bst.remove(17);
        System.out.println("After remove 17");
        bst.display();
        System.out.println("---- From the lesson using initialisation with Arrays.asList");
        bst = new BinarySearchTree<>(list);
        bst.display();
        bst.insert(3);
        bst.display();
        bst.remove(17);
        bst.display();
    }
}
