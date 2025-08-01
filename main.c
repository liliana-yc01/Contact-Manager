#include <stdio.h>
#include <string.h>
#include <ctype.h>

char names[100][100];
char phones[100][20];
int totalContacts = 0;

void add_contact() {
    char name[100];
    char phone[20];

    printf("Enter contact name: ");
    fgets(name, sizeof(name), stdin);
    int len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }

    printf("Enter phone number (10 digits): ");
    fgets(phone, sizeof(phone), stdin);
    len = strlen(phone);
    if (len > 0 && phone[len - 1] == '\n') {
        phone[len - 1] = '\0';
    }

    if (strlen(name) == 0 || strlen(phone) != 10) {
        printf("Invalid input! Please enter a valid name and 10-digit phone number.\n");
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (!isdigit(phone[i])) {
            printf("Invalid input! Please enter a valid name and 10-digit phone number.\n");
            return;
        }
    }

    for (int i = 0; i < totalContacts; i++) {
        if (strcmp(names[i], name) == 0) {
            printf("Contact already exists!\n");
            return;
        }
    }

    strcpy(names[totalContacts], name);
    strcpy(phones[totalContacts], phone);
    totalContacts++;

    printf("Contact '%s' added successfully!\n", name);
}

void view_contacts() {
    if (totalContacts == 0) {
        printf("No contacts available!\n");
        return;
    }

    printf("\nContact List:\n");
    for (int i = 0; i < totalContacts; i++) {
        printf("%s: %s\n", names[i], phones[i]);
    }
}

void search_contact() {
    char name[100];
    printf("Enter the name to search: ");
    fgets(name, sizeof(name), stdin);
    int len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }

    for (int i = 0; i < totalContacts; i++) {
        if (strcmp(names[i], name) == 0) {
            printf("%s: %s\n", names[i], phones[i]);
            return;
        }
    }

    printf("Contact not found!\n");
}


void update_contact() {
    char old_name[100], new_name[100], new_phone[20];

    printf("Enter the contact name to update: ");
    fgets(old_name, sizeof(old_name), stdin);
    int len = strlen(old_name);
    if (len > 0 && old_name[len - 1] == '\n') {
        old_name[len - 1] = '\0';
    }

    for (int i = 0; i < totalContacts; i++) {
        if (strcmp(names[i], old_name) == 0) {
            printf("Enter the new name (press Enter to keep the same): ");
            fgets(new_name, sizeof(new_name), stdin);
            len = strlen(new_name);
            if (len > 0 && new_name[len - 1] == '\n') {
                new_name[len - 1] = '\0';
            }

            printf("Enter new phone number (10 digits, press Enter to keep the same): ");
            fgets(new_phone, sizeof(new_phone), stdin);
            len = strlen(new_phone);
            if (len > 0 && new_phone[len - 1] == '\n') {
                new_phone[len - 1] = '\0';
            }

            if (strlen(new_phone) > 0 && (strlen(new_phone) != 10)) {
                printf("Invalid phone number! Must be 10 digits.\n");
                return;
            }

            if (strlen(new_name) > 0) {
                strcpy(names[i], new_name);
            }

            if (strlen(new_phone) > 0) {
                strcpy(phones[i], new_phone);
            }

            printf("Contact '%s' updated successfully!\n", old_name);
            return;
        }
    }

    printf("Contact not found!\n");
}

void delete_contact() {
    char name[100];
    printf("Enter the name to delete: ");
    fgets(name, sizeof(name), stdin);
    int len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }

    for (int i = 0; i < totalContacts; i++) {
        if (strcmp(names[i], name) == 0) {
            for (int j = i; j < totalContacts - 1; j++) {
                strcpy(names[j], names[j + 1]);
                strcpy(phones[j], phones[j + 1]);
            }
            totalContacts--;
            printf("Contact '%s' deleted successfully!\n", name);
            return;
        }
    }

    printf("Contact not found!\n");
}

void userChoice(char *choice) {
    if (strcmp(choice, "1") == 0) {
        add_contact();
    } else if (strcmp(choice, "2") == 0) {
        view_contacts();
    } else if (strcmp(choice, "3") == 0) {
        search_contact();
    } else if (strcmp(choice, "4") == 0) {
        update_contact();
    } else if (strcmp(choice, "5") == 0) {
        delete_contact();
    } else if (strcmp(choice, "6") == 0) {
        printf("Goodbye!\n");
    } else {
        printf("Invalid choice! Please enter a number between 1 and 6.\n");
    }
}

int main() {
    char choice[10];

    while (1) {
        printf("\nContact Manager Menu:\n");
        printf("1. Add a Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search for a Contact\n");
        printf("4. Update a Contact\n");
        printf("5. Delete a Contact\n");
        printf("6. Exit\n");

        printf("Choose an option (1-6): ");
        fgets(choice, sizeof(choice), stdin);
        int len = strlen(choice);
        if (len > 0 && choice[len - 1] == '\n') {
            choice[len - 1] = '\0';
        }

        if (strcmp(choice, "6") == 0) {
            printf("Goodbye!\n");
            break;
        }

        userChoice(choice);
    }

    return 0;
}
