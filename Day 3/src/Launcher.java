public class Launcher
{
    public static void main(String[] args)
    {
        BinaryTree b = new BinaryTree();
        b.insert(new Node(4));
        b.insert(new Node(6));
        b.insert(new Node(2));
        b.insert(new Node(3));

        System.out.println(b);
        System.out.println(BinaryTree.deserialize(b.toString()));

        //Node n = Node.deserialize(b.toString(),0);

      //  System.out.println("Val = " + n.getVal() + "\nLeft = " + n.getLeft() + "\nRight = " + n.getRight());


    }
}
