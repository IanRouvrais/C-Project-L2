#ifndef SET_H
#define SET_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME 30
#define MAX_PHONE 30
#define MAX_EMAIL 30
#define MAX_PURPOSE 1000

typedef struct contact {
    char name[MAX_NAME];
    char phone[MAX_PHONE];
    char email[MAX_EMAIL];
} Contact;

typedef struct appointment {
    int day, month, year;
    int hour, minute;
    int duration_hour, duration_minute;
    char purpose[MAX_PURPOSE];
} Appointment;

typedef struct skipCell {
    Contact *contact;
    Appointment **appointments;
    int level;
    struct skipCell **next;
} SkipCell;

typedef struct skipList {
    int level;
    SkipCell **header;
} SkipList;

/**
 * @brief creates a contact
 * 
 * @param name 
 * @param phone 
 * @param email 
 * 
 * @return Contact* 
 */
Contact *createContact(char *name, char *phone, char *email);

/**
 * @brief frees a contact
 * 
 * @param contact 
 */
void freeContact(Contact *contact);

/**
 * @brief creates an appointment
 * 
 * @param date 
 * @param time 
 * @param duration 
 * @param purpose 
 * 
 * @return Appointment* 
 */
Appointment *createAppointment(int day, int month, int year, 
                               int hour, int minute, 
                               int duration_hour, int duration_minute, 
                               char purpose[MAX_PURPOSE]);

/**
 * @brief frees an appointment
 * 
 * @param appointment 
 */
void freeAppointment(Appointment *appointment);

/**
 * @brief creates a skip cell
 * 
 * @param contact 
 * @param appointment 
 * @param level 
 * 
 * @return SkipCell* 
 */
SkipCell *createSkipCell(Contact *contact);

/**
 * @brief frees a skip cell
 * 
 * @param skip_cell 
 */
void freeSkipCell(SkipCell *skip_cell);

/**
 * @brief creates a skip list
 * 
 * @return SkipList* 
 */
SkipList createSkipList();

/**
 * @brief frees a skip list
 * 
 * @param skip_list 
 */
void freeSkipList(SkipList *skip_list);

/**
 * @brief edits the level of a skip cell
 * 
 * @param skip_cell 
 * @param level 
 */
void editSkipCellLevel(SkipCell *skip_cell, int level);

/**
 * @brief creates a skip cell
 * 
 * @param skip_list 
 * @param contact 
 */
void addContact(SkipList *skip_list, Contact *contact);

/**
 * @brief adds an appointment to a given contact
 * 
 * @param skip_list 
 * @param appointment 
 */
void addAppointmentToContact(SkipCell *cell, Appointment *appointment);

/**
 * @brief removes an appointment from a given contact
 * 
 * @param skip_list 
 * @param contact 
 */
void removeAppointmentFromContact(SkipCell *cell, int index);


/**
 * @brief Gives the adress of the contact with the given name
 * 
 * @param skip_list 
 * @param name 
 * @return SkipCell* 
 */
SkipCell *searchContact(SkipList *skip_list, char name[30]);

/**
 * @brief prints the appointments of a given contact
 * 
 * @param contact 
 */
void viewContactAppointments(SkipCell *contact);

/**
 * @brief searches for an appointment with the given purpose
 * 
 * @param contact 
 * @param purpose 
 * @return Appointment* 
 */
Appointment *searchAppointment(SkipCell *contact, char *purpose);

/**
 * @brief prints the contacts of a given skip list
 * 
 * @param skip_list 
 */
void viewContacts(SkipList *skip_list);

#endif
