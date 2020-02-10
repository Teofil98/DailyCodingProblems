public class Node {
    private int val;
    private Node left;
    private Node right;

    public Node()
    {
        val = 0;
        left = null;
        right = null;
    }

    public Node(int val)
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
                return Integer.toString(val);
        else return "x";
    }

    public static int index ;

    public static Node deserialize(String s)
    {

        Node n = new Node(Integer.parseInt(s.charAt(index) + ""));


        if(s.length() > index + 1)
        {
            index++;
            if(s.charAt(index ) == 'x')
                n.setLeft(null);
            else n.setLeft(Node.deserialize(s));
        }

        if(s.length() > index + 1)
        {
            index++;
            if(s.charAt(index ) == 'x')
                n.setRight(null);
            else n.setRight(Node.deserialize(s));
        }

        return n;
    }
}
