import java.util.*;
class Account {
    private String accountNumber;
    private String name;
    private double balance;

    public Account(String accountNumber, String name, double balance) {
        this.accountNumber = accountNumber;
        this.name = name;
        this.balance = balance;
    }

    public String getAccountNumber() {
        return accountNumber;
    }

    public String getName() {
        return name;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public String toString() {
        return "Account Number: " + accountNumber + ", Name: " + name + ", Balance: " + balance;
    }
}


public class BankQ2 {
    private Map<String, Account> accounts;

    public BankQ2() {
        accounts = new HashMap<>();
    }

    public boolean addAccount(String accountNumber, String name, double balance) {
        if (accounts.containsKey(accountNumber)) {
            return false; // Account with this account number already exists
        }
        Account account = new Account(accountNumber, name, balance);
        accounts.put(accountNumber, account);
        return true;
    }

    public boolean accountExists(String accountNumber) {
        return accounts.containsKey(accountNumber);
    }

    public Account getAccount(String accountNumber) {
        return accounts.get(accountNumber);
    }

    public void displayAllAccounts() {
        for (Account account : accounts.values()) {
            System.out.println(account);
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BankQ2 accountManager = new BankQ2();
        while (true) {
            System.out.println("Choose an option:");
            System.out.println("1. Add Account");
            System.out.println("2. Check Account Existence");
            System.out.println("3. Get Account Balance");
            System.out.println("4. Display All Accounts");
            System.out.println("5. Exit");
            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline
            switch (choice) {
                case 1:
                    System.out.print("Enter account number: ");
                    String accountNumber = scanner.nextLine();
                    System.out.print("Enter account name: ");
                    String name = scanner.nextLine();
                    System.out.print("Enter initial balance: ");
                    double balance = scanner.nextDouble();
                    scanner.nextLine(); // Consume newline
                    if (accountManager.addAccount(accountNumber, name, balance)) {
                        System.out.println("Account added successfully.");
                    } else {
                        System.out.println("Account with this number already exists.");
                    }
                    break;
                case 2:
                    System.out.print("Enter account number: ");
                    accountNumber = scanner.nextLine();
                    if (accountManager.accountExists(accountNumber)) {
                        System.out.println("Account exists.");
                    } else {
                        System.out.println("Account does not exist.");
                    }
                    break;
                case 3:
                    System.out.print("Enter account number: ");
                    accountNumber = scanner.nextLine();
                    Account account = accountManager.getAccount(accountNumber);
                    if (account != null) {
                        System.out.println("Balance: " + account.getBalance());
                    } else {
                        System.out.println("Account not found.");
                    }
                    break;
                case 4:
                    accountManager.displayAllAccounts();
                    break;
                case 5:
                    System.out.println("Exiting...");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid choice. Please try again.");
                    break;
            }
        }
    }
}