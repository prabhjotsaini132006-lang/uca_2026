import java.util.Scanner;

public class IntersectionLL {

    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    public static Node createList(Scanner scanner, int n) {
        Node head = null;
        Node tail = null;

        for (int i = 0; i < n; i++) {
            int value = scanner.nextInt();

            Node newNode = new Node(value);

            if (head == null) {
                head = newNode;
                tail = newNode;
            } else {
                tail.next = newNode;
                tail = newNode;
            }
        }

        return head;
    }

    public static Node intersection(Node head1, Node head2) {

        Node current1 = head1;
        Node current2 = head2;

        Node dummy = new Node(0);
        Node tail = dummy;

        while (current1 != null && current2 != null) {

            if (current1.data == current2.data) {
                tail.next = new Node(current1.data);
                tail = tail.next;

                current1 = current1.next;
                current2 = current2.next;

            } else if (current1.data < current2.data) {
                current1 = current1.next;

            } else {
                current2 = current2.next;
            }
        }

        return dummy.next;
    }

    public static void printList(Node head) {

        Node current = head;

        while (current != null) {
            System.out.print(current.data);

            if (current.next != null) {
                System.out.print(" -> ");
            }

            current = current.next;
        }

        System.out.println();
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter number of nodes for first list: ");
        int n = scanner.nextInt();

        System.out.println("Enter elements:");
        Node head1 = createList(scanner, n);

        System.out.print("Enter number of nodes for second list: ");
        int n2 = scanner.nextInt();

        System.out.println("Enter elements:");
        Node head2 = createList(scanner, n2);

        Node result = intersection(head1, head2);

        System.out.println("Intersection List:");
        printList(result);

        scanner.close();
    }
}
