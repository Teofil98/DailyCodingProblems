public class Node {
    private char val;
    private Node left;
    private Node right;

    public Node()
    {
        val = 0;
        left = null;
        right = null;
    }

    public Node(char val)
    {
        this.val = val;
        left = null;
        right = null;
    }

    public Node getLeft()
    {
        return left;
    }

    public Node getRight()
    {
        return right;
    }

    public int getVal()
    {
        return val;
    }

    public void setLeft(Node left)
    {
        this.left = left;
    }

    public void setRight(Node right)
    {
        this.right = right;
    }

    public void setVal(char val)
    {
        this.val = val;
    }

    @Override
    public String toString()
    {
        if(this != null)
                return Character.toString(val);
        else return "x";
    }

}
