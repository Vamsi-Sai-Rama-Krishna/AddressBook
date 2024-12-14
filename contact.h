#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[100];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *addressBook);

//for printing and reading sub-option.
int print_option();

//for create contact validation.
int validation_of_name(char temp_name[]);
int validation_of_mobile(char temp_mobile[],AddressBook *addressBook);
int vaildation_of_mail(char temp_mail[],AddressBook *addressBook);

//for finding index of searched contact.
int validation_search_of_mobile(char temp_mobile[],AddressBook *addressBook);
int validation_search_of_mail(char temp_mail[],AddressBook *addressBook);

//for finding index of the name,mobile,mail for editing.
int name_index_finder(char name[],AddressBook *addressBook);
int mobile_index_finder(char mobile[],AddressBook *addressBook);
int mail_index_finder(char mail[],AddressBook *addressBook);

//for checking the read string from user in run time.
int read_check_name(char name,AddressBook *addressBook);
int read_check_mobile(char mobile[]);
int read_check_mail(char mail[]);

#endif
