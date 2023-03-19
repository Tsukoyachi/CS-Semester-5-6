package ads.poo2.lab3;

import java.util.*;

/**
 * A class for binary search tree with rank
 */
public class RankedBSTWithInnerClass<T extends Comparable<? super T>> implements RankedBSTInterface<T> {

    // The tree root
    private BinaryNode<T> root;

    /**
     * Construct the tree.
     */
    public RankedBSTWithInnerClass() {
        this.root = new BinaryNode<>(null);
    }

    /////////////// isEmpty


    @Override
    public int getSize() {
        int res = 0;
        BinaryNode<T> tmp = root;
        while (tmp != null) {
            res += 1 + tmp.sizeOfLeft;
            tmp = tmp.right;
        }
        return res;
    }


    @Override
    public T elementInRank(int r) {
        int parentRank = 0;
        BinaryNode<T> tmp = root;
        while (tmp != null) {
            int comparisonResult = r - (tmp.sizeOfLeft + 1 + parentRank);
            if (comparisonResult == 0) {
                return tmp.element;
            }
            if (comparisonResult < 0) {
                tmp = tmp.left;
            }
            if (comparisonResult > 0) {
                parentRank += tmp.sizeOfLeft + 1;
                tmp = tmp.right;
            }
        }
        return null;
    }

    /**
     * Test if the tree is logically empty.
     *
     * @return true if empty, false otherwise.
     */
    public boolean isEmpty() {
        return root.element == null && root.right == null && root.left == null;
    }

    /////////////// makeEmpty  

    /**
     * Make the tree logically empty.
     */
    public void makeEmpty() {
        root.element = null;
        root.right = null;
        root.left = null;
    }


    /////////////// rank

    /**
     * Return the rank of x in the tree
     *
     * @param x the element
     * @return the rank of x in the tree
     * if x is in the tree, 0 otherwise
     */
    public int rank(T x) {
        int parentRank = 0;
        BinaryNode<T> tmp = root;
        while (tmp != null) {
            int comparisonResult = x.compareTo(tmp.element);
            if (comparisonResult == 0) {
                return 1 + tmp.sizeOfLeft + parentRank;
            }
            if (comparisonResult < 0) {
                tmp = tmp.left;
            }
            if (comparisonResult > 0) {
                parentRank += tmp.sizeOfLeft + 1;
                tmp = tmp.right;
            }
        }
        return 0;
    }

    private int rank(BinaryNode<T> t, T x) {
        return 0;
    }

    /////////////// element

    /**
     * Return the element of rank r in the tree
     *
     * @param r the rank
     * @return the element of rank r in the tree
     * if such element exists, null otherwise
     */
    public T element(int r) {
        return null;
    }

    private T element(BinaryNode<T> t, int r) {
        return null;
    }

    /////////////// contains

    /**
     * Find an item in the tree.
     *
     * @param x the item to search for.
     * @return true if not found.
     */
    public boolean contains(T x) {
        if (this.isEmpty() || this.root.element == null) {
            return false;
        }
        return contains(x, this.root);
    }

    /**
     * Internal method to find an item in a subtree.
     *
     * @param x is item to search for.
     * @param t the node that roots the subtree.
     * @return node containing the matched item.
     */
    private boolean contains(T x, BinaryNode<T> t) {
        int comparisonResult = x.compareTo(t.element);
        if (comparisonResult == 0) {
            return true;
        }
        if (comparisonResult < 0 && t.left != null) {
            return contains(x, t.left);
        }
        if (comparisonResult > 0 && t.right != null) {
            return contains(x, t.right);
        }
        return false;
    }

    /////////////// insert

    /**
     * Insert into the tree; duplicates are ignored.
     *
     * @param x the item to insert.
     */
    public void insert(T x) {
        if (this.isEmpty() || this.root.element == null) {
            this.root.element = x;
        } else {
            this.insert(x, this.root);
        }
    }

    /**
     * Internal method to insert into a subtree.
     *
     * @param x the item to insert.
     * @param t the node that roots the subtree.
     * @return the new root of the subtree.
     */
    private BinaryNode<T> insert(T x, BinaryNode<T> t) {
        int comparisonResult = x.compareTo(t.element);
        if (comparisonResult < 0) {
            t.sizeOfLeft += 1;
            if (t.left == null) {
                t.left = new BinaryNode<>(x);
                return t.left;
            }
            return insert(x, t.left);
        }
        if (comparisonResult > 0) {
            if (t.right == null) {
                t.right = new BinaryNode<>(x);
                return t.right;
            }
            return insert(x, t.right);
        }
        return null;
    }

    /////////////// remove

    /**
     * Remove from the tree. Nothing is done if x is not found.
     *
     * @param x the item to remove.
     */
    public void remove(T x) {
        if(this.isEmpty() || !this.contains(x)){
            return;
        }
        remove(x,this.root);
    }

    /**
     * Internal method to remove from a subtree.
     *
     * @param x the item to remove.
     * @param t the node that roots the subtree.
     * @return the new root of the subtree.
     */
    private BinaryNode<T> remove(T x, BinaryNode<T> t) {
        return null;
    }

    /**
     * Internal method to find the smallest item in a subtree.
     *
     * @param t the node that roots the subtree.
     * @return node containing the smallest item.
     */
    private BinaryNode<T> findMin(BinaryNode<T> t) {
        while (t != null) {
            t = t.left;
        }
        return t;
    }

    ////////////////////////////////////////////////////
    // Convenience method to print a tree
    ////////////////////////////////////////////////////

    public void display() {
        display(root, "", "");
    }

    private void display(BinaryNode<T> t, String r, String p) {
        if (t == null) {
            System.out.println(r);
        } else {
            String rs = t.element.toString();
            rs = "(" + t.sizeOfLeft + ")" + rs;
            System.out.println(r + rs);
            if (t.left != null || t.right != null) {
                String rr = p + '|' + makeString('_', rs.length()) + ' ';
                display(t.right, rr, p + '|' + makeString(' ', rs.length() + 1));
                System.out.println(p + '|');
                display(t.left, rr, p + makeString(' ', rs.length() + 2));
            }
        }
    }

    private String makeString(char c, int k) {
        String s = "";
        for (int i = 0; i < k; i++) {
            s += c;
        }
        return s;
    }

    ////////////////////////////////////////////////////
    // Inner class BinaryNode<T>
    ////////////////////////////////////////////////////

    // Basic node stored in unbalanced binary search trees
    private static class BinaryNode<AnyType> {
        // Constructors
        BinaryNode(AnyType theElement) {
            element = theElement;
            left = null;
            right = null;
            sizeOfLeft = 0;
        }

        AnyType element;            // The getData in the node
        BinaryNode<AnyType> left;   // Left child
        BinaryNode<AnyType> right;  // Right child

        int sizeOfLeft; // The size of the left subtree
    }

    ////////////////////////////////////////////////////
    // Convenience methods to build a list of integer from a string
    ////////////////////////////////////////////////////

    private static List<Integer> read(String inputString) {
        List<Integer> list = new LinkedList<Integer>();
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
        RankedBSTWithInnerClass<Integer> bst = new RankedBSTWithInnerClass<Integer>();
        for (Integer n : list)
            bst.insert(n);
        bst.display();
        System.out.println("Rank of 60: " + bst.rank(60));
        System.out.println("Element of rank 6: " + bst.element(6));
    }
}
