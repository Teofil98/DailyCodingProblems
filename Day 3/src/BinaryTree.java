public class BinaryTree {

    private Node root;
    private String serialized;

    public BinaryTree()
    {
        root = null;
    }

    private void insertNode(Node currentNode, Node node)
    {
        //if(currentNode == null)
        // currentNode = node;
       // else
       // {
            if(node.getVal() < currentNode.getVal())
            {
                if(currentNode.getLeft() != null)
                 insertNode(currentNode.getLeft(), node);
                else currentNode.setLeft(node);
            }
            else
            {
                if(currentNode.getRight() != null)
                    insertNode(currentNode.getRight(), node);
                else currentNode.setRight(node);
            }

    //    }
    }

    private void serializeTree(Node currentNode)
    {
       // System.out.print(currentNode + " ");

        if(currentNode != null)
        {
            serialized += currentNode.toString();
            serializeTree(currentNode.getLeft());
            serializeTree(currentNode.getRight());

        }
        else serialized += "x";

    }


    public static BinaryTree deserialize(String s)
    {
        Node.index = 0;
        BinaryTree b = new BinaryTree();
        b.insert(Node.deserialize(s));
        return b;
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


    @Override
    public String toString()
    {
        serialized = "";
        serializeTree(root);
        return serialized;
    }



}
