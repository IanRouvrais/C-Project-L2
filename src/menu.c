#include "include/menu.h"
#include "include/setup.h"
#include "include/strings.h"
#include <ctype.h>

void create_contact(SkipList *skip_list) {
    printf("Enter the contact's name: ");
    char name[30];
    getString(name);
    upper(name);
    printf("Enter the contact's surname: ");
    char surname[30];
    getString(surname);
    lower(surname);
    surname[0] = toupper(surname[0]);
    printf("Enter the contact's phone number: ");
    char phone[30];
    getString(phone);
    printf("Enter the contact's email: ");
    char email[30];
    getString(email);

    char fullName[30]; // should be NAME_Surname
    for(int i = 0; i < strlen(name) + strlen(surname) + 1; i++) {
        if (i < strlen(name)) {
            fullName[i] = name[i];
        } else if (i == strlen(name)) {
            fullName[i] = '_';
        } else {
            fullName[i] = surname[i - strlen(name) - 1];
        }
    }
    fullName[strlen(name) + strlen(surname) + 1] = '\0';
    printf("Creation of contact: %s\n", fullName);
    Contact *contact = createContact(fullName, phone, email);
    printf("Contact: %s created\n", fullName);
    addContact(skip_list, contact);
    printf("Contact: %s added to the List\n", fullName);
}

void create_appointment(SkipList *skip_list) {
    printf("Enter the contact's name: ");
    char name[30];
    getString(name);
    upper(name);
    printf("Enter the contact's surname: ");
    char surname[30];
    getString(surname);
    lower(surname);
    surname[0] = toupper(surname[0]);
    char fullName[30]; // should be NAME_Surname
    for(int i = 0; i < strlen(name) + strlen(surname) + 1; i++) {
        if (i < strlen(name)) {
            fullName[i] = name[i];
        } else if (i == strlen(name)) {
            fullName[i] = '_';
        } else {
            fullName[i] = surname[i - strlen(name) - 1];
        }
    }
    fullName[strlen(name) + strlen(surname) + 1] = '\0';
    SkipCell *contact = searchContact(skip_list, fullName);
    if (contact ==NULL) {
        printf("Contact not found.\n");
        return;
    }
    printf("Enter the date of the appointment(d/m/y): ");
    int day, month, year;
    while(scanf("%d/%d/%d", &day, &month, &year) != 3) {
        printf("Invalid date. Please enter a valid date: ");
        while(getchar() != '\n');
    }
    printf("Enter the time of the appointment (h:m): ");
    int hour, minute;
    while(scanf("%d:%d", &hour, &minute) != 2) {
        printf("Invalid time. Please enter a valid time: ");
        while(getchar() != '\n');
    }
    printf("Enter the duration of the appointment (h:m): ");
    int duration_hour, duration_minute;
    while(scanf("%d:%d", &duration_hour, &duration_minute) != 2) {
        printf("Invalid duration. Please enter a valid duration: ");
        while(getchar() != '\n');
    }
    printf("Enter the purpose of the appointment: ");
    char purpose[1000];
    getString(purpose);

    Appointment *appointment = createAppointment(day, month, year, hour, minute, duration_hour, duration_minute, purpose);
    addAppointmentToContact(contact, appointment);
    printf("Appointment added.\n");
}

void delete_appointment(SkipList *skip_list) {
    printf("Enter the contact's name: ");
    char name[30];
    getString(name);
    upper(name);
    printf("Enter the contact's surname: ");
    char surname[30];
    getString(surname);
    lower(surname);
    surname[0] = toupper(surname[0]);
    char fullName[30]; // should be NAME_Surname
    for(int i = 0; i < strlen(name) + strlen(surname) + 1; i++) {
        if (i < strlen(name)) {
            fullName[i] = name[i];
        } else if (i == strlen(name)) {
            fullName[i] = '_';
        } else {
            fullName[i] = surname[i - strlen(name) - 1];
        }
    }
    fullName[strlen(name) + strlen(surname) + 1] = '\0';
    SkipCell *contact = searchContact(skip_list, fullName);
    if (contact ==NULL) {
        printf("Contact not found.\n");
        return;
    }
    printf("Enter the index of the appointment: ");
    int index;
    while(scanf("%d", &index) != 1) {
        printf("Invalid index. Please enter a valid index: ");
        while(getchar() != '\n');
    }
    removeAppointmentFromContact(contact, index - 1);
}

void view_contact_appointments(SkipList *skip_list) { 
    printf("Enter the contact's name: ");
    char name[30];
    getString(name);
    upper(name);
    printf("Enter the contact's surname: ");
    char surname[30];
    getString(surname);
    lower(surname);
    surname[0] = toupper(surname[0]);
    char fullName[30]; // should be NAME_Surname
    for(int i = 0; i < strlen(name) + strlen(surname) + 1; i++) {
        if (i < strlen(name)) {
            fullName[i] = name[i];
        } else if (i == strlen(name)) {
            fullName[i] = '_';
        } else {
            fullName[i] = surname[i - strlen(name) - 1];
        }
    }
    fullName[strlen(name) + strlen(surname) + 1] = '\0';
    SkipCell *contact = searchContact(skip_list, fullName);
    if (contact ==NULL) {
        printf("Contact not found.\n");
        return;
    }
    viewContactAppointments(contact);
}

void delete_contact(SkipList *skip_list) {
    printf("Enter the contact's name: ");
    char name[30];
    getString(name);
    upper(name);
    printf("Enter the contact's surname: ");
    char surname[30];
    getString(surname);
    lower(surname);
    surname[0] = toupper(surname[0]);
    char fullName[30]; // should be NAME_Surname
    for(int i = 0; i < strlen(name) + strlen(surname) + 1; i++) {
        if (i < strlen(name)) {
            fullName[i] = name[i];
        } else if (i == strlen(name)) {
            fullName[i] = '_';
        } else {
            fullName[i] = surname[i - strlen(name) - 1];
        }
    }
    fullName[strlen(name) + strlen(surname) + 1] = '\0';
    
    SkipCell *contact = searchContact(skip_list, fullName);
    if (contact == NULL) {
        printf("Contact not found.\n");
        return;
    }
    freeSkipCell(contact);
    printf("Contact deleted.\n");
}

void menu(SkipList *skip_list) 
{
    char choice;
    do {
        printf("\n\n");
        printf("1. Create a contact\n");
        printf("2. Create an appointment\n");
        printf("3. Delete an appointment\n");
        printf("4. View contact appointments\n");
        printf("5. View contacts\n");
        printf("q. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        while (getchar() != '\n');
        switch (choice) {
            case '1':
                create_contact(skip_list);
                break;
            case '2':
                create_appointment(skip_list);
                break;
            case '3':
                delete_appointment(skip_list);
                break;
            case '4':
                view_contact_appointments(skip_list);
                break;
            case '5':
                viewContacts(skip_list);
                break;
            case 'q':
                break;
            default:
                printf("Invalid choice\n");
        }

    } while (choice != 'q');
}