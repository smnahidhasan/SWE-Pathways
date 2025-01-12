### **ACID Properties in SQL Databases**

ACID is an acronym for Atomicity, Consistency, Isolation, and Durability, which are the key properties of reliable database transactions. Here's what each property means with examples:

---

#### **1. Atomicity**
Ensures that a transaction is "all or nothing." Either all operations in a transaction succeed, or none of them take effect.

- **Example:**
    Suppose you are transferring $100 from Account A to Account B. The transaction consists of two steps:
    1. Deduct $100 from Account A.
    2. Add $100 to Account B.

    If either step fails (e.g., system crashes after deducting $100 but before adding it to Account B), the transaction is rolled back, ensuring no partial changes.

    ```sql
    BEGIN TRANSACTION;
    UPDATE accounts SET balance = balance - 100 WHERE account_id = 'A';
    UPDATE accounts SET balance = balance + 100 WHERE account_id = 'B';
    COMMIT;
    ```

---

#### **2. Consistency**
Ensures the database remains in a valid state before and after a transaction, preserving data integrity and rules.

- **Example:**
    A transaction ensures that the total balance of all accounts in a bank remains constant during money transfers.

    ```sql
    -- Before Transaction:
    SELECT SUM(balance) FROM accounts; -- Returns 10,000

    -- Transfer $100 from Account A to Account B
    BEGIN TRANSACTION;
    UPDATE accounts SET balance = balance - 100 WHERE account_id = 'A';
    UPDATE accounts SET balance = balance + 100 WHERE account_id = 'B';
    COMMIT;

    -- After Transaction:
    SELECT SUM(balance) FROM accounts; -- Still returns 10,000
    ```

---

#### **3. Isolation**
Ensures that transactions operate independently without interfering with each other, preventing issues like dirty reads or race conditions.

- **Example:**
    Two users, User X and User Y, simultaneously withdraw money from the same account. Isolation ensures one transaction completes before the other starts.

    ```sql
    -- User X starts transaction
    BEGIN TRANSACTION;
    SELECT balance FROM accounts WHERE account_id = 'A'; -- Returns $500

    -- User Y tries to withdraw
    BEGIN TRANSACTION;
    UPDATE accounts SET balance = balance - 200 WHERE account_id = 'A';
    COMMIT;

    -- User X completes transaction
    UPDATE accounts SET balance = balance - 300 WHERE account_id = 'A';
    COMMIT;
    ```

    Isolation ensures the database correctly processes these transactions without conflict.

---

#### **4. Durability**
Ensures that once a transaction is committed, its changes are permanently saved, even in the event of a system crash.

- **Example:**
    After committing a transaction to transfer $100 from Account A to Account B, the changes are written to disk. If the database server crashes, the updates remain intact when it restarts.

    ```sql
    BEGIN TRANSACTION;
    UPDATE accounts SET balance = balance - 100 WHERE account_id = 'A';
    UPDATE accounts SET balance = balance + 100 WHERE account_id = 'B';
    COMMIT; -- Changes are now permanent.
    ```

---

### **Summary of ACID**
| Property    | Description                                           |
|-------------|-------------------------------------------------------|
| **Atomicity** | All operations succeed or none of them take effect. |
| **Consistency** | Ensures data integrity before and after a transaction. |
| **Isolation**   | Transactions are executed independently.          |
| **Durability**  | Changes are permanent after a commit.             |
