# Description

It is required to write a program that will maintain a library system. The system manages 
books information, library visitors, borrowing, ... etc.
The system stores for each book the title, author, publisher, ISBN, date of publication,
number of copies, current available number of copies, and category.
In a library, a member may borrow many books at the same time. However, he must
return the books before their due date. A member has a name (last and first), ID, address
(building, street and city), phone number, age, and email address.
You should maintain a structure that links a user with the book he borrowed, you should
store book ISBN, user ID, date borrowed, data due to return, and date returned.
You should have 3 separated files, one for books, another for users, and the last one for
borrowing. It is better to read the files at the start of the program only, and you should
save the changes only when the user selects save from the menu.

## Features 

### Book Management

###### 1. Insert a new book

This command adds a new book to our library. The added data is stored in a file. The
file is a text file that is comma delimited in which each entry (book) is found on a
separate line. Each entry must contain the main book information mentioned before. An
example of one line in the file is as follows:

###### 2. Search for a book

The system should process a request by the user to look up information about a
specific entry. The user can supply one of the following; book title (or part of it), author
name, ISBN or category. The system should provide a list of books that matches the user
request.

###### 3. Add new copy

The system should prompt the user to enter book ISBN and the number of its copies
and update the Book entry in the file with the new number of copies. (Validate it is not a
negative number)

###### 4. Delete book

The user should be prompted for the book ISBN and that entry should be deleted from
the system (books file).

### Member Transactions

###### 5. Registration

Adding new user to our system. Data is stored in a separate file in the same format of
books file (comma delimited, and each entry, user, is on a separate line).
Hamdy, Ahmed, 95314, 35, Shatby, Alexandria, 0123456789, 26, ahmed@gmail.com

###### 6. Borrowing

For each member who borrows a book, we store book ISBN, user ID, date issued, date
due to return, and date returned. Again, all borrowing data should be stored into a
separate file. Also, the number of available copies for that book should be decremented.
A Member cannot borrow more than 3 books at a time.
0-13-612356-2, 95314, 17/11/2017, 22/11/2017, null

###### 7. Returning book

When a user returns a borrowed book back to the library, the entry for his borrowing
action must be updated with the date returned. Also for book entry; the number of
available copies of the book must be incremented.
The above record “in task 6” should be updated to look like:
0-13-612356-2, 95314, 17/11/2017, 22/11/2017, 21/11/2017

###### 8. Remove member

When a member wants to leave our system, the system must make sure that this user
does not have any borrowed books (all entries in Borrowing file for this user must have
its return date filled in)

### Administrative actions

###### 9. Overdue books

A list of overdue books -books that were borrowed and their return date has been
passed without returning it back- should be available for our system administrators.

###### 10. Most popular books

A list shows the most borrowed 5 books title should be printed at the beginning of our
program.
