//Name: Vamsi krishna
//Description: To create an "AddressBook" which holds data of contacts of particular memebers in which a single contact contains name,phone,email
//              and also user is allowed to choose different options and is allowed to perform some operations like adding ,deleting,editing and saving of contacts.
//Date of submission: 04/12/2024
//Topics included in this project:  data types,conditional constructs,arrays,strings,funtions,pointers,file handling, 

#include <stdio.h>
#include "contact.h"

int main() {
    int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do {
        printf("\nAddress Book\n");
        printf("-------------------\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. Display contacts\n");
    	printf("6. Save contacts\n");		
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        getchar();
        switch (choice) {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:          
                listContacts(&addressBook);
                break;
            case 6:
                printf("\nSaving and Exiting...");
                saveContactsToFile(&addressBook);
                break;
            case 7:
                printf("\n-------------------");
                printf("\nExiting AddressBook\n");
                printf("-------------------\n");
                return 0;
            default:
                printf("\n---------------------------------");
                printf("\nInvalid choice. Please try again.\n");
                printf("---------------------------------\n");
        }
    } while (choice != 7);
    
       return 0;
}
