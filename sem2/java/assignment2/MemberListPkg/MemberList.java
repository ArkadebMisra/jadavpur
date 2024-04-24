package MemberListPkg;

public class MemberList {
    private Member[] members;
    private int size;
    private final int MAX_MEMBERS = 100; // Example: Maximum number of members allowed in the list
    private final int maxBooksAllowed=10;

    public MemberList(int capacity) {
        members = new Member[capacity];
        size = 0;
    }

    // Add member in the list
    public void addMember(Member member) {
        if (size < MAX_MEMBERS) {
            members[size++] = member;
            System.out.println("Member added successfully.");
        } else {
            System.out.println("Cannot add more members. Member list is full.");
        }
    }

    // Show all members
    public void displayAllMembers() {
        if (size == 0) {
            System.out.println("No members available in the list.");
        } else {
            System.out.println("All Members:");
            for (int i = 0; i < size; i++) {
                System.out.println("Member ID: " + members[i].getMemberId());
                System.out.println("Name: " + members[i].getName());
                System.out.println("Date of Birth: " + members[i].getDob());
                System.out.println("Books Issued: " + members[i].getBooksIssued());
                System.out.println("-----------------------------");
            }
        }
    }

    // Show details of a member
    public void displayMemberDetails(String memberId) {
        for (int i = 0; i < size; i++) {
            if (members[i].getMemberId().equals(memberId)) {
                System.out.println("Member ID: " + members[i].getMemberId());
                System.out.println("Name: " + members[i].getName());
                System.out.println("Date of Birth: " + members[i].getDob());
                System.out.println("Books Issued: " + members[i].getBooksIssued());
                return;
            }
        }
        System.out.println("Member with ID " + memberId + " not found.");
    }

    public Member findMemberById(String memberId) {
        for (int i = 0; i < size; i++) {
            if (members[i].getMemberId().equals(memberId)) {
                return members[i];
            }
        }
        return null; // Member not found
    }

    public int getMaxBooksAllowed() {
        return maxBooksAllowed;
    }

    public void incrementBooksIssued(String memberId) {
        for (int i = 0; i < size; i++) {
            if (members[i].getMemberId().equals(memberId)) {
                members[i].setBooksIssued(members[i].getBooksIssued() + 1);
                break;
            }
        }
    }
    public void decrementBooksIssued(String memberId) {
        for (int i = 0; i < size; i++) {
            if (members[i].getMemberId().equals(memberId)) {
                members[i].setBooksIssued(members[i].getBooksIssued() - 1);
                break;
            }
        }
    }
    
}