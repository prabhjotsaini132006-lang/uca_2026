import java.util.Scanner;

public class SearchLL {

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

    public static boolean searchList(Node list1, Node list2) {

        if (list1 == null) {
            return true;
        }

        Node current2 = list2;

        while (current2 != null) {

            Node current1 = list1;
            Node temp2 = current2;

            while (current1 != null &&
                   temp2 != null &&
                   current1.data == temp2.data) {

                current1 = current1.next;
                temp2 = temp2.next;
            }

            if (current1 == null) {
                return true;
            }

            current2 = current2.next;
        }

        return false;
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

        boolean result = searchList(head1, head2);

        System.out.println(result);

        scanner.close();
    }
}
