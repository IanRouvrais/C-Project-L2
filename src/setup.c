#include "include/setup.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME 30
#define MAX_PHONE 30
#define MAX_EMAIL 30
#define MAX_PURPOSE 1000

Contact *createContact(char *name, char *phone, char *email) {
    Contact *contact = (Contact*)calloc(1, 3 * 30*sizeof(char));
    strcpy(contact->name, name);
    strcpy(contact->phone, phone);
    strcpy(contact->email, email);
    return contact;
}

void freeContact(Contact *contact) {
    free(contact);
}

Appointment *createAppointment(int day, int month, int year, int hour, int minute, int duration_hour, int duration_minute, char purpose[MAX_PURPOSE]) {
    Appointment *appointment = (Appointment*)calloc(1, sizeof(Appointment));
    appointment->day = day;
    appointment->month = month;
    appointment->year = year;
    appointment->hour = hour;
    appointment->minute = minute;
    appointment->duration_hour = duration_hour;
    appointment->duration_minute = duration_minute;
    strcpy(appointment->purpose, purpose);
    return appointment;
}

void freeAppointment(Appointment *appointment) {
    free(appointment);
}

SkipCell *createSkipCell(Contact *contact) {
    SkipCell *skip_cell = (SkipCell*)calloc(1, sizeof(SkipCell));
    skip_cell->contact = contact;
    skip_cell->appointments = (Appointment**)calloc(1, sizeof(Appointment*));
    memset(skip_cell->appointments, 0, sizeof(Appointment*));
    skip_cell->level = 0;
    skip_cell->next = (SkipCell**)calloc(4, sizeof(SkipCell*));
    memset(skip_cell->next, 0, 4*sizeof(SkipCell*));
    return skip_cell;
}

void freeSkipCell(SkipCell *skip_cell) {
    free(skip_cell->appointments);
    free(skip_cell->next);
    free(skip_cell);
}

void editSkipCellLevel(SkipCell *skip_cell, int level) {
    skip_cell->level = level;
}

SkipList createSkipList() {
    SkipList skip_list;
    skip_list.level = 3;
    skip_list.header = (SkipCell**)calloc(4, sizeof(SkipCell*));
    memset(skip_list.header, 0, 4 * sizeof(SkipCell*));
    return skip_list;
}

void freeSkipList(SkipList *skip_list) {
    SkipCell *current = skip_list->header[0];
    SkipCell *next;
    while (current != NULL) {
        next = current->next[0];
        freeSkipCell(current);
        current = next;
    }
    free(skip_list->header);
}

// This function has to goal to insert a cell in the list, which will be sorted depending of the name of the contacts in the list
// The level of the cell is calculated as follow : 
//Minimal level is 0
// Level is 1 if the name of the contact is the first from its third letter
// Level is 2 if the name of the contact is the first from its second letter
// Level is 3 if the name of the contact is the first from its letter (ex : if the contact is the first one with the letter 'A')

void addContact(SkipList *skip_list, Contact *contact) {
    SkipCell *new_cell = createSkipCell(contact);
    int level = 0;
    int i = 0;
    SkipCell *current = skip_list->header[skip_list->level];
    SkipCell *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->contact->name, contact->name) > 0) {
            if (level < current->level) {
                level = current->level;
            }
            previous = current;
            current = current->next[skip_list->level];
        } else {
            if (level < current->level) {
                level = current->level;
            }
            previous = current;
            current = current->next[skip_list->level];
        }
    }
    editSkipCellLevel(new_cell, level);
    for (i = 0; i <= level; i++) {
        if (previous == NULL) {
            new_cell->next[i] = skip_list->header[i];
            skip_list->header[i] = new_cell;
        } else {
            new_cell->next[i] = previous->next[i];
            previous->next[i] = new_cell;
        }
    }
}

SkipCell *searchContact (SkipList *list, char value[30])
{
    if (list->header == NULL) return NULL;
    SkipCell *current = NULL;
    int currentLevel = list->level+1;
    do {
        current = list->header[--currentLevel];
    } while (current == NULL && currentLevel >=0);
    
    if (current == NULL) return NULL;
    if(strcmp(current->contact->name, value) == 0) return current;
    do {
        printf("%s\n", current->contact->name);
        if (current->next[currentLevel] == NULL) {
            if (currentLevel == 0) return NULL;
            currentLevel--;
        } else {
            if (strcmp(current->next[currentLevel]->contact->name, value) == 0) return current->next[currentLevel];
            if (strcmp(current->next[currentLevel]->contact->name, value) == 0) return current->next[currentLevel];
            if (strcmp(current->next[currentLevel]->contact->name, value) < 0) {
                current = current->next[currentLevel];
            } else {
                if (currentLevel == 0) return NULL;
                currentLevel--;
            }
        }
    } while (current != NULL);

    return NULL;
}
// This function has to goal to insert an appointment into a contact
// The appointment is inserted in the contact's list of appointments, and the list is sorted depending of the date of the appointments

void addAppointmentToContact(SkipCell *cell, Appointment *appointment) {
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    Appointment *current = NULL;
    if (cell->appointments[0] == NULL) {
        cell->appointments[0] = appointment;
    } else {
        for (i = 0; i < 30; i++) {
            if (cell->appointments[i] == NULL) {
                cell->appointments[i] = appointment;
                break;
            } else {
                current = cell->appointments[i];
                if (current->year > appointment->year) {
                    for (j = 29; j > i; j--) {
                        cell->appointments[j] = cell->appointments[j - 1];
                    }
                    cell->appointments[i] = appointment;
                    break;
                } else if (current->year == appointment->year) {
                    if (current->month > appointment->month) {
                        for (k = 29; k > i; k--) {
                            cell->appointments[k] = cell->appointments[k - 1];
                        }
                        cell->appointments[i] = appointment;
                        break;
                    } else if (current->month == appointment->month) {
                        if (current->day > appointment->day) {
                            for (l = 29; l > i; l--) {
                                cell->appointments[l] = cell->appointments[l - 1];
                            }
                            cell->appointments[i] = appointment;
                            break;
                        } else if (current->day == appointment->day) {
                            if (current->hour > appointment->hour) {
                                for (m = 29; m > i; m--) {
                                    cell->appointments[m] = cell->appointments[m - 1];
                                }
                                cell->appointments[i] = appointment;
                                break;
                            } else if (current->hour == appointment->hour) {
                                if (current->minute > appointment->minute) {
                                    for (n = 29; n > i; n--) {
                                        cell->appointments[n] = cell->appointments[n - 1];
                                    }
                                    cell->appointments[i] = appointment;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void removeAppointmentFromContact(SkipCell *cell, int index) {
    if(cell->appointments[index] == NULL) {
        printf("Appointment not found.\n");
        return;
    }
    freeAppointment(cell->appointments[index]);
    cell->appointments[index] = NULL;
    int i = 0;
    for (i = index; i < 29; i++) {
        cell->appointments[i] = cell->appointments[i + 1];
    }
    cell->appointments[29] = NULL;
    printf("Appointment deleted.\n");
}
//strcmp(current->contact->name, name) == 0



void removeContact(SkipList *skip_list, char *name) {
    SkipCell *current = skip_list->header[skip_list->level];
    SkipCell *previous = NULL;
    int levelOfSearch = skip_list->level;
    int i = 0;
    while (current != NULL) {
        if (strcmp(current->contact->name, name) == 0) {
            for (i = 0; i <= current->level; i++) {
                if (previous == NULL) {
                    skip_list->header[i] = current->next[i];
                } else {
                    previous->next[i] = current->next[i];
                }
            }
            freeSkipCell(current);
            return;
        } else if (strcmp(current->contact->name, name) > 0) {
            if (levelOfSearch > 0) {
                levelOfSearch--;
                current = current->next[levelOfSearch];
            } else {
                return;
            }
        } else {
            previous = current;
            current = current->next[levelOfSearch];
        }
    }
}

void viewContactAppointments(SkipCell *contact) {
    int i = 0;
    for (i = 0; i < 30; i++) {
        if (contact->appointments[i] == NULL) {
            break;
        } else {
            printf("\n--------------------------------------\n");
            printf("|  Appointment %2d :                 |\n", i + 1);
            printf("|  %02d/%02d/%04d (dd/mm/yyyy) at %d:%d |\n", contact->appointments[i]->day, contact->appointments[i]->month, contact->appointments[i]->year, contact->appointments[i]->hour, contact->appointments[i]->minute);
            printf("|  for %02d:%02d                        |\n", contact->appointments[i]->duration_hour, contact->appointments[i]->duration_minute);
            printf("--------------------------------------\n");
            printf("[Purpose] %s/\n", contact->appointments[i]->purpose);
        }
    }
}

static int numberOfAppointments(SkipCell *contact) {
    int i = 0;
    for (i = 0; i < 30; i++) {
        if (contact->appointments[i] == NULL) {
            break;
        }
    }
    return i;
}

void viewContacts(SkipList *skip_list) {
    SkipCell *current = skip_list->header[0];
    while (current != NULL) {
        printf("\n[%s]-[%s]-[%s]\n", current->contact->name, current->contact->phone, current->contact->email);
        printf("Number of appointments: %d\n", numberOfAppointments(current));
        current = current->next[0];
    }
}

Appointment *searchAppointment(SkipCell *contact, char *purpose) {
    int i = 0;
    for (i = 0; i < 30; i++) {
        if (contact->appointments[i] == NULL) {
            break;
        } else {
            if (strcmp(contact->appointments[i]->purpose, purpose) == 0) {
                return contact->appointments[i];
            }
        }
    }
    return NULL;
}
