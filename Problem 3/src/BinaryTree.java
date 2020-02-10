public class BinaryTree {

    private Node root;

    public BinaryTree()
    {
        root = null;
    }

    private void insertNode(Node currentNode, Node node)
    {
        if(currentNode == null)
            currentNode = node;
        else
        {
            if(node.getVal() < currentNode.getVal())
                insertNode(currentNode.getLeft(),node);
            else insertNode(currentNode.getRight(), node);

        }
    }

    private void printTree(Node currentNode)
    {
        System.out.print(currentNode + " ");
        if(currentNode != null)
        {
            printTree(currentNode.getLeft());
            printTree(currentNode.getRight());
        }

    }

    public void insert(Node node)
    {
        if (root == null)
            root = node;
        else
        {
            insertNode(root,node);
        }
    }

    public void print()
    {
        printTree(root);
    }

}
