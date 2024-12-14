#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "populate.h"

//this function is used for printing sub-options after main menu.
int print_option()
{
    while (1)
    {
        printf("1.By name\n");
        printf("2.By mobile\n");
        printf("3.By E-mail\n");
        printf("4.EXIT\n");

        int option;
        scanf(" %d",&option);
        if(option == 1 || option == 2 || option == 3)
        {
            return option;
        }
        if(option == 4)
        {
            return -1;
        }
        printf("\n----------------------------------");
        printf("\nInvalid option, please try again\n");
        printf("----------------------------------\n");
    }
}

int read_check_mobile(char mobile[])
{
    int i = 0, count=0;
        while (mobile[i] != '\0' && (mobile[i] >= '0' && mobile[i] <= '9'))
        {
            count++;
            i++;
        }

        if(count == 10)     //if entered string has all digits and length == 10 then compare that string in contact list.
        {
            
            return 0;
        }
        printf("\n-------------------------------");
        printf("\nPlease Enter valid phone Number\n");
        printf("-------------------------------\n");
        
        return 1;
}

int read_check_mail(char mail[])
{
    char *found = strstr(mail,"@gmail.com"); 
    char *found1 = strstr(mail,"@yahoo.com");
    if(found == NULL && found1 == NULL)
    {   
        printf("\n----------------------------");
        printf("\nplease Enter valid E-mail Id\n");
        printf("----------------------------\n");
        return 1;
    }

    //if "@gmail.com" is found in entered mail now check the position such that it is before '\0' or not.
    if(found != NULL)
    {
        if(found[10] != '\0')
        {
            printf("\n----------------------------");
            printf("\nplease Enter valid E-mail Id\n");
            printf("----------------------------\n");
            return 1;
        }
    }

    if(found1 != NULL)
    {
        if(found1[10] != '\0')
        {
            printf("\n----------------------------");
            printf("\nplease Enter valid E-mail Id\n");
            printf("----------------------------\n");
            return 1;
        }
    }
    return 0;
}

int validation_search_of_mobile(char temp_mobile[],AddressBook *addressBook)
{
    // check all characters are digits or not and meanwhile find the length
    int i = 0, count=0;
    while (temp_mobile[i] != '\0' && (temp_mobile[i] >= '0' && temp_mobile[i] <= '9'))
    {
        count++;
        i++;
    }
    int match=0;
    if(count == 10)
    {
        //if mobile number have 10 digits.
        //also validate whether 'temp_num' is already present in contact list or not.
        for(int i=0; i<(addressBook->contactCount); i++)
        {
            if(strcmp(temp_mobile,addressBook->contacts[i].phone) == 0)
            {
                return i;       //if mobile number is found  
            }
        }
        //if no match found then "return 0".
        if(match==0)       
        {
          return -1;
        } 
    }
    
    return -1;       //"return -1" when mobile is Invalid, asks user to re-enter again.
}

int validation_search_of_mail(char temp_mail[],AddressBook *addressBook)
{
    if(temp_mail[0] == '@' || temp_mail[0] == '.')
    {
        printf("\n------------------------------------------------");
        printf("\nEntered mail is Invalid, please Enter mail again\n");
        printf("------------------------------------------------\n");
        return 1;
    }
    int i=0;
    int count1=0;
    while(temp_mail[i] != '\0')
    {
        if(temp_mail[i] == '@')
        {
            count1++;
        }
        i++;
    }
    if(count1 >1)
    {
        printf("\n------------------------------------------------");
        printf("\nEntered mail is Invalid, please Enter mail again\n");
        printf("------------------------------------------------\n");
        return 1;
    }

    int j=0;
    int count2=0;
    while(temp_mail[j] != '\0')
    {
        if(temp_mail[j] == '.')
        {
            count2++;
        }
        j++;
    }
    if(count2 >1)
    {
        printf("\n------------------------------------------------");
        printf("\nEntered mail is Invalid, please Enter mail again\n");
        printf("------------------------------------------------\n");
        return 1;
    }


    int k=0;
    int count3 = 0;
    while(temp_mail[k] != '\0')
    {
        if(temp_mail[k] == ' ')
        {
            printf("\n------------------------------------------------");
            printf("\nEntered mail is Invalid, please Enter mail again\n");
            printf("------------------------------------------------\n");
            return 1;
        }
        k++;
    }

    char *found = strstr(temp_mail,"@gmail.com"); 
    char *found1 = strstr(temp_mail,"@yahoo.com");
    char *found2 = strstr(temp_mail,"@email.com"); 
    if(found == NULL && found1 == NULL && found2 == NULL )
    {
        printf("\n------------------------------------------------");
        printf("\nEntered mail is Invalid, please Enter mail again\n");
        printf("------------------------------------------------\n");
        return 1;
    }

    //if "@gmail.com" is found in entered mail now check the position such that it is before '\0' or not.
    if(found != NULL )
    {
        if(found[10] != '\0')
        {
            printf("\n------------------------------------------------");
            printf("\nEntered mail is Invalid, please Enter mail again\n");
            printf("------------------------------------------------\n");
            return 1;
        }
    }

    if(found1 != NULL)
    {
        if(found1[10] != '\0')
        {
            printf("\n------------------------------------------------");
            printf("\nEntered mail is Invalid, please Enter mail again\n");
            printf("------------------------------------------------\n");
            return 1;
        }
    }

    if(found2 != NULL)
    {
        if(found2[10] != '\0')
        {
            printf("\n------------------------------------------------");
            printf("\nEntered mail is Invalid, please Enter mail again\n");
            printf("------------------------------------------------\n");
            return 1;
        }
    }  

    for(int i = 0;i<addressBook->contactCount;i++)
    {
        if(strcmp(temp_mail,addressBook->contacts[i].email) == 0)
        {
            //printf("hi");
            printf("Name: %s phone: %s E-mail: %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
    }
    return 0;
}

//function for searching index value.
int name_index_finder(char name[],AddressBook *addressBook)
{
    int match=0;
    
    for(int i=0; i<(addressBook->contactCount); i++)
    {
        if(strcmp(name,(addressBook->contacts[i].name)) == 0)
        {
            match++;
            printf("Name: %s phone: %s E-mail: %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
    }
    if(match == 0)
    {
        return 0;
    }
    return 1;
} 

int mobile_index_finder(char mobile[],AddressBook *addressBook)
{
    for(int i=0; i<(addressBook->contactCount); i++)
    {
        if(strcmp(mobile,(addressBook->contacts[i].phone)) == 0)
        {
            return i;
        }
    }
    return -1;
}

int mail_index_finder(char mail[],AddressBook *addressBook)
{
    for(int i=0; i<(addressBook->contactCount); i++)
    {
        if(strcmp(mail,(addressBook->contacts[i].email)) == 0)
        {
            return i;
        }
    }
    return -1;
}

//this function is used to validate name without numericals.
int validation_of_name(char temp_name[])
{
    // name should contain only alphabets.
    int i = 0;
    while (temp_name[i] != '\0')
    {
        if (!(temp_name[i] >= 'a' && temp_name[i] <= 'z' || temp_name[i] >= 'A' && temp_name[i] <= 'Z'))
        {
            printf("\n---------------------------------------------------");
            printf("\nName shouldn't contain digits or special characters\n");
            printf("---------------------------------------------------\n");
            return 1;
        }
        i++;
    }
    return 0;
}

//this funtion is used to validate mobile number..
int validation_of_mobile(char temp_mobile[],AddressBook *addressBook)
{
    // check all characters are digits or not and meanwhile find the length
    int i = 0, count=0;
    while (temp_mobile[i] != '\0' && (temp_mobile[i] >= '0' && temp_mobile[i] <= '9'))
    {
        count++;
        i++;
    }
    int match=0;
    if(count == 10)
    {
        //if mobile number have 10 digits.
        //also validate whether 'temp_num' is already present in contact list or not.
        for(int i=0; i<(addressBook->contactCount); i++)
        {
            if(strcmp(temp_mobile,addressBook->contacts[i].phone) == 0)
            {
                match++;    //increment if match found.
            }
        }
        //if no match found then "return 0".
        if(match==0)       
        {
            strcpy(addressBook->contacts[addressBook->contactCount].phone,temp_mobile);
            return 0; 
        }
        else
        {
            printf("\n-------------------------------------------------");
            printf("\nMobile Number already present in the contact list\n");
            printf("-------------------------------------------------\n"); 
        }  
    }
    else
    {
        printf("\n-------------------------------");
        printf("\nMobile number length insuffient\n");
        printf("-------------------------------\n");
    }
    
    return 1;       //"return 1" when mobile is Invalid, asks user to re-enter again.
}

//this function is used to validate mail.
int validation_of_mail(char temp_mail[],AddressBook *addressBook)
{
    if(temp_mail[0] == '@' || temp_mail[0] == '.')
    {
        printf("\n------------------------------------------------");
        printf("\nEntered mail is Invalid, please Enter mail again\n");
        printf("------------------------------------------------\n");
        return 1;
    }
    int i=0;
    int count1=0;
    while(temp_mail[i] != '\0')
    {
        if(temp_mail[i] == '@')
        {
            count1++;
        }
        i++;
    }
    if(count1 >1)
    {
        printf("\n------------------------------------------------");
        printf("\nEntered mail is Invalid, please Enter mail again\n");
        printf("------------------------------------------------\n");
        return 1;
    }

    int j=0;
    int count2=0;
    while(temp_mail[j] != '\0')
    {
        if(temp_mail[j] == '.')
        {
            count2++;
        }
        j++;
    }
    if(count2 >1)
    {
        printf("\n------------------------------------------------");
        printf("\nEntered mail is Invalid, please Enter mail again\n");
        printf("------------------------------------------------\n");
        return 1;
    }


    int k=0;
    int count3 = 0;
    while(temp_mail[k] != '\0')
    {
        if(temp_mail[k] == ' ')
        {
            printf("\n------------------------------------------------");
            printf("\nEntered mail is Invalid, please Enter mail again\n");
            printf("------------------------------------------------\n");
            return 1;
        }
        k++;
    }

    char *found = strstr(temp_mail,"@gmail.com"); 
    char *found1 = strstr(temp_mail,"@yahoo.com");
    char *found2 = strstr(temp_mail,"@email.com"); 
    if(found == NULL && found1 == NULL && found2 == NULL )
    {
        printf("\n------------------------------------------------");
        printf("\nEntered mail is Invalid, please Enter mail again\n");
        printf("------------------------------------------------\n");
        return 1;
    }

    //if "@gmail.com" is found in entered mail now check the position such that it is before '\0' or not.
    if(found != NULL )
    {
        if(found[10] != '\0')
        {
            printf("\n------------------------------------------------");
            printf("\nEntered mail is Invalid, please Enter mail again\n");
            printf("------------------------------------------------\n");
            return 1;
        }
    }

    if(found1 != NULL)
    {
        if(found1[10] != '\0')
        {
            printf("\n------------------------------------------------");
            printf("\nEntered mail is Invalid, please Enter mail again\n");
            printf("------------------------------------------------\n");
            return 1;
        }
    }

    if(found2 != NULL)
    {
        if(found2[10] != '\0')
        {
            printf("\n------------------------------------------------");
            printf("\nEntered mail is Invalid, please Enter mail again\n");
            printf("------------------------------------------------\n");
            return 1;
        }
    }  

    for(int i = 0;i<addressBook->contactCount;i++)
    {
        if(strcmp(temp_mail,addressBook->contacts[i].email) == 0)
        {
            printf("\n---------------------------------------------------");
            printf("\nEntered mail is already present in the contact list\n");
            printf("---------------------------------------------------\n");
            return 1;
        }
    }
    return 0;
}

//this function helps to initialise the data/contacts from the backupfile which is from permenant memory to RAM memory for doing operations
void initialize(AddressBook *addressBook)
{
    addressBook->contactCount = 0;
    // Load contacts from file during initialization (After files)
    // loadContactsFromFile(addressBook);

    FILE *fptr = fopen("contact.csv","r");      //open the file to create a buffer.

    if(fptr == NULL)
    {
        printf("Error,file not found\n");
        return;
    }

    fscanf(fptr,"%d\n",&(addressBook->contactCount));
    char name[100];
    char mobile[100];
    char mail[100];
    
    int i=0;
     while(i<addressBook->contactCount)
   
    {
        fscanf(fptr, " %[^,], %[^,], %[^,\n]", name, mobile, mail);            //read from file
        // Copy data into the addressBook's contacts array
        strcpy(addressBook->contacts[i].name, name);
        strcpy(addressBook->contacts[i].phone, mobile);
        strcpy(addressBook->contacts[i].email, mail);
        i++;
    }
    fclose(fptr);       //close the file.
}

//this function helps user to list/display all the contacts in the addressbook.
void listContacts(AddressBook *addressBook)
{
    printf("-------------------------------------------------------------\n");
    printf("%-17s %-17s %-30s\n", "Name", "Mobile", "Email");
    printf("-------------------------------------------------------------\n");
    for(int i=0; i< (addressBook->contactCount);i++)
    {
        printf("%-15s %-15s %-15s\n",addressBook->contacts[i].name, addressBook->contacts[i].phone,addressBook->contacts[i].email);
    } 
}

//this function helps user to create new contact containing name,mobile, and email.
void createContact(AddressBook *addressBook)
{
    // for name.
    char temp_name[100];
    int ret_name = 0;
    do
    {
        // to store in temperory variable,after validation is true,then use strcpy to copy to contact list.
        printf("Enter Name: ");
        scanf(" %[^\n]", temp_name); // read name.

        ret_name = validation_of_name(temp_name); // call the validate function.
        if(ret_name == 0)
        {
            strcpy(addressBook->contacts[addressBook->contactCount].name,temp_name);
        }
    } while (ret_name);

    // for mobile number.
    int ret_mobile = 0;
    char temp_mobile[100];
    do
    {
        printf("Enter Mobile NUmber: ");
        scanf(" %[^\n]", temp_mobile);
        ret_mobile = validation_of_mobile(temp_mobile,addressBook);
        if (ret_mobile == 0)
        {
            strcpy(addressBook->contacts[addressBook->contactCount].phone,temp_mobile);
        }

    } while (ret_mobile);       //cond "true" when invalid ,so asks user to re-enter 

    //for e-mail.
    char temp_mail[100];
    int ret_mail=0;
    do
    {
        printf("Enter Email-Id: ");
        scanf(" %[^\n]",temp_mail);
        ret_mail = validation_of_mail(temp_mail,addressBook);
        
        if(ret_mail == 0)
        {
            strcpy(addressBook->contacts[addressBook->contactCount].email,temp_mail);
        }

    }while(ret_mail);
    addressBook->contactCount++;        //increment contactCount after creating a new contact.
    printf("\n----------------------------");
    printf("\nContact created sucuessfully\n");
    printf("----------------------------\n");
}

//this function helps user to search contacts based on name,mobile or email.
void searchContact(AddressBook *addressBook)
{
    /* Define the logic for search */
    printf("\nchoose by which  parameter you want search:\n");
    int option = print_option();
    if(option == -1)
    {
        printf("\n--------------");
        printf("\nExiting Search\n");
        printf("--------------\n");
        return;
    }
    int valid;
    switch (option)
    {
        case 1:     //case for checking name.
            do
            {   
                char name[100];
                printf("Enter name to search (or) Enter ""exit"" to go back\n");
                scanf(" %[^\n]",name);      //read name from user to search.
            
                if(strcmp(name,"exit") == 0)
                {
                    printf("\n--------------");
                    printf("\nExiting search\n");
                    printf("--------------\n");
                    break; //terminate loop hear only if exit is entered.
                }

                int match1 = 0 ;
                for(int i=0; i<(addressBook->contactCount); i++)
                {
                    if(strcmp(name,(addressBook->contacts[i].name)) == 0)
                    {
                        match1++;
                        printf("Name: %s phone: %s E-mail: %s",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    }
                }
                if(match1 == 0)
                {
                    printf("\n-----------------------------------------------------------");
                    printf("\nEntered name is not found in contact-list, Please try again\n");      //if return value is negative index is not found.
                    printf("-----------------------------------------------------------\n");
                }
                else
                {
                    return;
                }
            }while (1);
        break;
        case 2:     //case for checking mobile
            do
            {
                char mobile[100];
                printf("Enter phone number to search (or) Enter ""exit"" to go back\n");
                scanf(" %[^\n]",mobile);      //read name from user to search.
            
                //check if entered string is "exit" or not.
                if(strcmp(mobile,"exit") == 0)
                {
                    printf("\n--------------");
                    printf("\nExiting search\n");
                    printf("--------------\n");
                    break;  //terminate loop hear only if exit is entered.
                }

                //if not "exit" then validate whether entered string is 10 digit number or not. so, call "(validation of mobile function)".
                int valid_index = validation_search_of_mobile(mobile,addressBook);
                if(valid_index>=0)
                {
                    //if index is found the print the respective details and break the loop.
                    printf("Name: %s phone: %s E-mail: %s",addressBook->contacts[valid_index].name,addressBook->contacts[valid_index].phone,addressBook->contacts[valid_index].email);
                    break;
                }
                else
                {
                    printf("\n----------------------------------------------");
                    printf("\ncontact not found or Invalid ,Please Try again\n");
                    printf("----------------------------------------------\n");
                }
            }while (1);
        break;
        case 3: //case for checking mail
            do
            {
                char mail[100];
                printf("Enter mail to search (or) Enter ""exit"" to go back\n");
                scanf(" %[^\n]",mail);      //read name from user to search.
            
                //check if entered string is "exit" or not.
                if(strcmp(mail,"exit") == 0)
                {
                    printf("\n--------------");
                    printf("\nExiting search\n");
                    printf("--------------\n");
                    break;  //terminate loop hear only if exit is entered.
                }

                //if not "exit" then validate whether entered string is 10 digit number or not. so, call "(validation of mail function)".
                valid = validation_search_of_mail(mail,addressBook);
        
            }while (valid);
        break;
    }
}

//this function helps user to edit content of already stored contacts by name, by mobile or by email-id.
void editContact(AddressBook *addressBook)
{
    /* Define the logic for Editcontact */
    printf("\nchoose by which  parameter you want edit:\n");
    int option = print_option();
    if(option == -1)
    {
        printf("\n--------------");
        printf("\nExiting Search\n");
        printf("--------------\n");
        return;
    }

    char mobile[100];
    int valid_mobile;
    char mail[100];
    int valid_mail;
    switch(option)
    {
        case 1:         //case for editing by name.
            printf("\nEnter contact name which you want to edit\n");
            char name[100];
            scanf(" %[^\n]",name);
            
            int match=0;
            for(int i=0; i<(addressBook->contactCount); i++)
            {
                if(strcmp(name,addressBook->contacts[i].name) == 0)
                {
                    match++;
                    printf("S.no: %d ",i);
                    printf(" %s\t%s\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                }
            }

            if(match != 0)
            {
                printf("Enter ""S.no"" to confirm Edit: ");
                int edit_index1;
                scanf("%d",&edit_index1);
                
                if(strcmp(addressBook->contacts[edit_index1].name, name) == 0)
                {
                    char new_name[100];
                    printf("Enter new name: ");
                    scanf(" %[^\n]",new_name);
                    strcpy((addressBook->contacts[edit_index1].name),new_name);
                    printf("\n------------------------");
                    printf("\nName Updated Sucessfully\n");
                    printf("------------------------\n");
                }
                else
                {
                    printf("\n-----------------------------------");
                    printf("\nEntered wrong S.no please try again\n");
                    printf("-----------------------------------\n");
                    return;
                }
            }
            else
            {
                printf("\n---------------------------------------------");
                printf("\nEntered name is not found in the contact list\n");
                printf("---------------------------------------------\n");
            }

        break;
        case 2:     //for editing mobile number.
            do
            {
                printf("\nEnter contact mobile which you want to edit\n");
                scanf(" %[^\n]",mobile);

                valid_mobile = read_check_mobile(mobile);

            }while(valid_mobile);

        int index = mobile_index_finder(mobile,addressBook);
        if(index >= 0)
        {
            char new_mobile[100];
            int valid_mobile;
            do
            {          
                printf("Enter new mobile number: ");
                scanf(" %[^\n]",new_mobile);

                valid_mobile = read_check_mobile(new_mobile);

            } while (valid_mobile);

            strcpy(addressBook->contacts[index].phone,new_mobile);
            
            printf("\n---------------------------------");
            printf("\nMobile Number updated sucessfully\n");
            printf("---------------------------------\n");           
        }
        else
        {
            printf("\n------------------------------------------------------");
            printf("\nEntered mobile number is not found in the contact list\n");
            printf("------------------------------------------------------\n");
        }
        break;

        case 3:     //for editing E-mail id.
            do
            {
                printf("\nEnter contact E-mail which you want to edit: \n");
                scanf(" %[^\n]",mail);

                valid_mail = read_check_mail(mail);     //function to check wether entered mail is valid or not.
        
            } while (valid_mail);
            
            int mail_index = mail_index_finder(mail,addressBook);

            if(mail_index == -1)
            {
                printf("\n------------------");
                printf("\nEmail_Id not found\n");
                printf("------------------\n");
                return;
            }

            char new_mail[100];
            do
            {
                printf("Enter new E-mail Id : ");
                scanf(" %[^\n]",new_mail);

                valid_mail = read_check_mail(new_mail);

            } while(valid_mail);

        if(mail_index >=0 )
        {
            strcpy(addressBook->contacts[mail_index].email,new_mail);
            printf("\n-----------------------------");
            printf("\nE-mail Id updated sucessfully\n");
            printf("-----------------------------\n");
        }
        break;
    }

}

//this function helps in deleteing the contacts based on user requirement.
void deleteContact(AddressBook *addressBook)
{
    printf("choose by which  parameter you want delete:\n");
    int option = print_option();
    
    if(option == -1)
    {
        printf("\n--------------");
        printf("\nExiting Search\n");
        printf("--------------\n");
        return;
    }

    switch(option)
    {
        case 1:
            printf("Enter contact Name you want to delete: ");
            char name[100];
            scanf(" %[^\n]",name);

            int match1=0;
            for(int i=0; i< (addressBook->contactCount) ;i++)
            {
                if(strcmp(name,(addressBook->contacts[i].name)) == 0)
                {
                    match1++;
                    printf("S.no: %d ",i);
                    printf(" %s\t%s\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                }
            }

            if(match1 != 0)
            {
                printf("Enter ""S.no"" to confirm delete: ");
                int del_index1;
                scanf("%d",&del_index1);
                
                if(strcmp(addressBook->contacts[del_index1].name, name) == 0)
                {
                    for(int j=del_index1; j<(addressBook->contactCount) ; j++)
                    {
                        strcpy(addressBook->contacts[j].name,addressBook->contacts[j+1].name);
                        strcpy(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone);
                        strcpy(addressBook->contacts[j].email,addressBook->contacts[j+1].email);
                    }
                    addressBook->contactCount--;
                    printf("\n---------------------------");
                    printf("\nContact deleted sucessfully\n");
                    printf("---------------------------\n"); 
                }
                else
                {
                    printf("\n-----------------------------------");
                    printf("\nEntered wrong S.no please try again\n");
                    printf("-----------------------------------\n");
                    return;
                }
            }
            else
            {
                printf("\n------------------------------");
                printf("\nNo contact, named ""%s"" found\n",name);
                printf("------------------------------\n");
            }
        break;
        case 2:
            printf("Enter contact Mobile you want to delete: ");
            char mobile[100];
            scanf(" %[^\n]",mobile);
            
            int match2=0;
            for(int i=0; i< (addressBook->contactCount) ;i++)
            {
                if(strcmp(mobile,(addressBook->contacts[i].phone)) == 0)
                {
                    match2++;
                    printf("S.no: %d ",i);
                    printf(" %s\t%s\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                }
            }
            if(match2 != 0)
            {
                printf("Enter ""S.no"" to confirm delete: ");
                int del_index2;
                scanf("%d",&del_index2);

                if(strcmp(addressBook->contacts[del_index2].phone, mobile) == 0)
                {
                    for(int j=del_index2; j<(addressBook->contactCount); j++)
                    {
                        strcpy(addressBook->contacts[j].name,addressBook->contacts[j+1].name);
                        strcpy(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone);
                        strcpy(addressBook->contacts[j].email,addressBook->contacts[j+1].email);
                    }
                    addressBook->contactCount--;
                    printf("\n---------------------------");
                    printf("\nContact deleted sucessfully\n");
                    printf("---------------------------\n");
                }
                else
                {
                    printf("\n-----------------------------------");
                    printf("\nEntered wrong S.no please try again\n");
                    printf("-----------------------------------\n");
                    return;
                }
            }
            else
            {
                printf("\n----------------------------------");
                printf("\nEntered mobile number is not found\n");
                printf("----------------------------------\n");
            }
        break;
        case 3:
            printf("Enter contact Email-Id you want to delete: ");
            char mail[100];
            scanf(" %[^\n]",mail);
            
            int match3 = 0;
            for(int i=0; i< (addressBook->contactCount) ;i++)
            {
                if(strcmp(mail,(addressBook->contacts[i].email)) == 0)
                {
                    match3++;
                    printf("S.no: %d ",i);
                    printf(" %s\t%s\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                }
            }
            if(match3 != 0)
            {
                printf("Enter ""S.no"" to confirm delete: ");
                int del_index3;
                scanf("%d",&del_index3);

                if(strcmp(addressBook->contacts[del_index3].email,mail) == 0)
                {
                    for(int j=del_index3; j<(addressBook->contactCount) ; j++)
                    {
                        strcpy(addressBook->contacts[j].name,addressBook->contacts[j+1].name);
                        strcpy(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone);
                        strcpy(addressBook->contacts[j].email,addressBook->contacts[j+1].email);
                    }
                    addressBook->contactCount--;
                    printf("\n---------------------------");
                    printf("\nContact deleted sucessfully\n");
                    printf("---------------------------\n");
                }
                else
                {
                    printf("\n-----------------------------------");
                    printf("\nEntered wrong S.no please try again\n");
                    printf("-----------------------------------\n");
                    return;
                }
            }
            else
            {
                printf("\n------------------------------");
                printf("\nEntered Email-Id is not found\n");
                printf("------------------------------\n");
            }
        break;
    }
}

//for saving contacts to a backupfile i.e to store contacts to permenant memory.
void saveContactsToFile(AddressBook *addressBook)
{
    FILE *fptr = fopen("contact.csv","w");
    if(fptr == NULL)
    {
        printf("\n-------------------");
        printf("\nError, opening file\n");
        printf("-------------------\n");
        return;
    }
    //for storing contactcount.
    fprintf(fptr,"%d\n",addressBook->contactCount);

    //for storing each index of contacts and every member of index i.e,name,phone,email.
    for(int i=0; i<(addressBook->contactCount);i++)
    {
        fprintf(fptr,"%s, %s, %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }

    fclose(fptr);
    printf("\n--------------------------");
    printf("\nContacts saved sucessfully\n");
    printf("--------------------------\n");

}