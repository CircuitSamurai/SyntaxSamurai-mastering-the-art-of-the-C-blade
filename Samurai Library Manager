#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_BOOKS 100 // Maximum number of books allowed in the library

#ifdef _WIN32
    #define strcasecmp _stricmp   // Windows uses _stricmp
#endif

// Define a structure to store book details
typedef struct book{
    int uniqueId; // Unique ID for each book
    char title[100]; // Title of the book
    char author[100]; // Author of the book
    bool availability; // true = available, false = borrowed
}book;

// Global array to store books
book books[MAX_BOOKS];
int bookCount = 0; // Tracks how many books are in the library

// --------------------- Add Book ---------------------
void addBook(){
    if(bookCount >= MAX_BOOKS){
        printf("Library Full\n"); // No space for new books
        return;
    }
    
    book newBook;
    
    printf("\nPlease enter book ID: ");
    scanf("%d", &newBook.uniqueId);
    
    // Prevent duplicate IDs
    for (int i = 0; i < bookCount; i++) {
        if (books[i].uniqueId == newBook.uniqueId) {
            printf("\nError: A book with ID %d already exists (%s by %s).\n\n", 
                   books[i].uniqueId, books[i].title, books[i].author);
            return;
        }
    }
    
    printf("\nPlease enter the title of the book: ");
    scanf(" %[^\n]", newBook.title);
    
    printf("\nPlease enter author's name: ");
    scanf(" %[^\n]", newBook.author);
    
    newBook.availability = true; // New book is available by default
    
    books[bookCount] = newBook; // Add new book to the array
    bookCount ++; // Increase book count
    
    printf("\nBook \"%s\" by %s added successfully!\n\n", newBook.title, newBook.author);
    
    
}

// --------------------- View Books ---------------------
void viewBooks(){
    if(bookCount == 0){
        printf("No books in the Library\n");
        return;
    }
    
    printf("\n------ Library Book List ------\n");
    for (int i = 0; i < bookCount; i++) {
        printf("\nBook %d:\n", i + 1);
        printf(" ID: %d\n", books[i].uniqueId);
        printf(" Title: %s\n", books[i].title);
        printf(" Author: %s\n", books[i].author);
        printf(" Availability: %s\n", books[i].availability ? "Available" : "Borrowed");
    }
    printf("\n-------------------------------\n\n");
}

// --------------------- Search Book ---------------------
void searchBook(){
    if(bookCount == 0){
        printf("No books in the Library\n");
        return;
    }
    
    int searchOpt;
    
    printf("1. Search by ID\n");
    printf("2. Search by Title\n");
    
    printf("\nPlease select an option: ");
    scanf("%d", &searchOpt);
        
    bool found = false; // Keeps track if we found a match
    
    switch(searchOpt){
        case 1:
            // Search by ID
            int searchID;
            
            printf("\nPlease enter book ID: ");
            scanf("%d", &searchID);
            
            
            for(int i = 0; i < bookCount; i ++){
                if(books[i].uniqueId == searchID){
                    // Display book details if match found
                    printf("\nBook Found!\n");
                    printf("ID: %d\n", books[i].uniqueId);
                    printf("Title: %s\n", books[i].title);
                    printf("Author: %s\n", books[i].author);
                    printf("Availability: %s\n\n", books[i].availability ? "Available" : "Borrowed"); 
                    found = true;
                    break;
                }
            }
            if(!found){
                printf("\nNo Book found with ID: %d\n\n", searchID);
            }
            break;

            
        case 2:
            // Search by Title
            char searchTitle[100];
            
            
            printf("\nPLease enter the Book Title: ");
            scanf(" %[^\n]", searchTitle);
            
            
            for(int i = 0; i < bookCount; i ++){
                if(strcmp(books[i].title, searchTitle) == 0){ // case-insensitive match
                    printf("\nBook Found!\n");
                    printf("ID: %d\n", books[i].uniqueId);
                    printf("Title: %s\n", books[i].title);
                    printf("Author: %s\n", books[i].author);
                    printf("Availability: %s\n\n", books[i].availability ? "Available" : "Borrowed"); 
                    found = true;
                    break;
                }
            }
            if(!found){
                printf("\nNo Book found with the Title: %s\n\n", searchTitle);
            }
            break;
            
            
            
            
        default:
            printf("Invalid choice!");
        }
}

// --------------------- Borrow Book ---------------------
void borrowBook() {
    if (bookCount == 0) {
        printf("No books in the Library\n");
        return;
    }

    int searchOpt;

    printf("1. Borrow by ID\n");
    printf("2. Borrow by Title\n");

    printf("\nPlease select an option: ");
    scanf("%d", &searchOpt);

    bool found = false;

    switch (searchOpt) {
        case 1: 
            int searchID;
            printf("Please enter the book ID: ");
            scanf("%d", &searchID);

            for (int i = 0; i < bookCount; i++) {
                if (books[i].uniqueId == searchID) {
                    found = true;
                    if (books[i].availability) {
                        books[i].availability = false; // mark as borrowed
                        printf("\nBook borrowed successfully: %s by %s\n\n", books[i].title, books[i].author);
                    } 
                    else {
                        printf("\nSorry, this book is already borrowed.\n\n");
                    }
                    break;
                }
            }
            if (!found) {
                printf("\nNo book found with ID: %d\n\n", searchID);
            }
            break;
        

        case 2: 
            char searchTitle[100];
            printf("\nPlease enter the Book Title: ");
            scanf(" %[^\n]", searchTitle);

            for (int i = 0; i < bookCount; i++) {
                if (strcmp(books[i].title, searchTitle) == 0) {
                    found = true;
                    if (books[i].availability) {
                        books[i].availability = false; // mark as borrowed
                        printf("\nBook borrowed successfully: %s by %s\n\n", books[i].title, books[i].author);
                    } 
                    else {
                        printf("\nSorry, this book is already borrowed.\n\n");
                    }
                    break;
                }
            }
            if (!found) {
                printf("\nNo book found with Title: %s\n\n", searchTitle);
            }
            break;
        

        default:
            printf("\nInvalid choice!\n\n");
    }
}

// --------------------- Return Book ---------------------
void returnBook(){
    if(bookCount == 0){
        printf("No books in the library!\n");
        return;
    }
    
    int searchOpt;
    bool found = false;
    
    printf("1. Return by ID\n");
    printf("2. Return by Title\n");
    
    printf("Please select an option: ");
    scanf("%d", &searchOpt);
    
    switch(searchOpt){
        case 1: 
            int searchID;
            
            printf("Please enter the book ID: ");
            scanf("%d", &searchID);
            
            for (int i = 0; i < bookCount; i++){
                if (books[i].uniqueId == searchID){
                    found = true;
                    if (books[i].availability == false){ // book is borrowed
                        books[i].availability = true; 
                        printf("\nBook returned successfully: %s by %s\n\n", books[i].title, books[i].author);
                    }
                    else{
                        printf("Sorry, this book was not borrowed.");
                    }
                    break;
                }          
            }
            if(!found){
                printf("\nNo book found with ID: %d\n\n", searchID);
            }
            break;
        
        case 2:
            char searchTitle[100];
            
            printf("\nPlease enter the Book Title: ");
            scanf(" %[^\n]", searchTitle);
            
            for (int i = 0; i < bookCount; i++) {
                if (strcmp(books[i].title, searchTitle) == 0) {
                    found = true;
                    if (books[i].availability == false) { // book is borrowed
                        books[i].availability = true; 
                        printf("\nBook returned successfully: %s by %s\n\n", books[i].title, books[i].author);
                    } 
                    else {
                        printf("\nSorry, this book was not borrowed.\n\n");
                    }
                    break;
                }
            }
            if(!found){
                printf("\nNo book found with Title: %s\n\n", searchTitle);
            }
            break;
            
        default: 
            printf("Invalid Choice!");
    }
}

// --------------------- Main Menu ---------------------
int main()
{
	int libManoptions;
    
    while(1){
        printf("=== Samurai Library Manager ===\n\n");
        printf("1. Add Book\n");
        printf("2. View All Books\n");
        printf("3. Search Book\n");
        printf("4. Borrow Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        
        printf("\nPlease Select an Option: ");
        scanf("%d", &libManoptions);
        
        switch(libManoptions){
            case 1:
                printf("You selected Add Book!\n");
                addBook();
                break;
            case 2:
                printf("You selected View All Books!\n");
                viewBooks();
                break;
            case 3:
                printf("You selected Search Book!\n");
                searchBook();
                break;
            case 4:
                printf("You selected Borrow Book!\n");
                borrowBook();
                break;
            case 5:
                printf("You selected Return Book!\n");
                returnBook();
                break;
            case 6:
                printf("You selected Exit!\n");
                return 0; // End program
            default:
                printf("Invalid Choice!");
        }   
    }
    
	return 0;
}
