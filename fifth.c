#include <stdio.h>
#include <string.h>w

char  name[100][50];
char  rollNo[100][20];
char  password[100][20];
char  branch[100][20];
int   sem[100];
float cgpa[100];
float attendance[100];
float totalFee[100];
float paidFee[100];
int   count = 0;

int main() {
    int choice, adminChoice, facultyChoice, studentChoice;
    int i, found;
    char user[20], pass[20], roll[20];
    float amount;

    while (1) {   // main menu keeps repeating until user chooses Exit
        printf("\n--- MITS Student System ---\n");
        printf("1. Admin Login\n");
        printf("2. Faculty Login\n");
        printf("3. Student Login\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Bye!\n");
            break;   // stops the main loop
        }

        /* ---------- ADMIN ---------- */
        if (choice == 1) {
            printf("\nAdmin Username: ");
            scanf("%s", user);
            printf("Admin Password: ");
            scanf("%s", pass);

            if (strcmp(user, "admin") == 0 && strcmp(pass, "admin123") == 0) {
                adminChoice = 0;

                while (adminChoice != 4) {
                    printf("\n--- Admin Menu ---\n");
                    printf("1. Add Student\n");
                    printf("2. View Students\n");
                    printf("3. Update Fee Payment\n");
                    printf("4. Logout\n");
                    printf("Choice: ");
                    scanf("%d", &adminChoice);

                    if (adminChoice == 1) {
                        if (count >= 100) {
                            printf("Array is full!\n");
                        } else {
                            printf("Enter Name (no spaces): ");
                            scanf("%s", name[count]);

                            printf("Enter Roll No: ");
                            scanf("%s", rollNo[count]);

                            found = 0;
                            for (i = 0; i < count; i++) {  
                                if (strcmp(rollNo[i], rollNo[count]) == 0) {
                                    found = 1;  
                                }
                            }

                            if (found == 1) {
                                printf("This roll number already exists!\n");
                            } else {
                                printf("Set Student Password: ");
                                scanf("%s", password[count]);

                                printf("Enter Branch: ");
                                scanf("%s", branch[count]);

                                printf("Enter Semester: ");
                                scanf("%d", &sem[count]);

                                printf("Enter CGPA: ");
                                scanf("%f", &cgpa[count]);

                                printf("Enter Attendance: ");
                                scanf("%f", &attendance[count]);

                                printf("Enter Total Fee: ");
                                scanf("%f", &totalFee[count]);

                                printf("Enter Paid Fee: ");
                                scanf("%f", &paidFee[count]);

                                count++;
                                printf("Student added successfully!\n");
                            }
                        }
                    }
                    else if (adminChoice == 2) {
                        if (count == 0) {
                            printf("No students added yet.\n");
                        } else {
                            printf("\nRoll No\tName\tBranch\tSem\tAtten.\tCGPA\tDue Fee\n");
                            printf("--------------------------------------------------------------\n");
                            for (i = 0; i < count; i++) {
                                printf("%s\t%s\t%s\t%d\t%.2f\t%.2f\t%.2f\n",
                                       rollNo[i], name[i], branch[i], sem[i],
                                       attendance[i], cgpa[i], totalFee[i] - paidFee[i]);
                            }
                        }
                    }
                    else if (adminChoice == 3) {
                        printf("Enter Roll No: ");
                        scanf("%s", roll);

                        found = 0;
                        for (i = 0; i < count; i++) {
                            if (strcmp(rollNo[i], roll) == 0) {
                                found = 1;
                                printf("Due fee: %.2f\n", totalFee[i] - paidFee[i]);
                                printf("Enter amount paid now: ");
                                scanf("%f", &amount);
                                paidFee[i] = paidFee[i] + amount;
                                printf("Fee updated.\n");
                            }
                        }
                        if (found == 0) {
                            printf("Student not found!\n");
                        }
                    }
                    else if (adminChoice != 4) {
                        printf("Wrong choice, try again.\n");
                    }
                }
            } else {
                printf("Wrong username or password!\n");
            }
        }

        /* ---------- FACULTY ---------- */
        else if (choice == 2) {
            printf("\nFaculty Username: ");
            scanf("%s", user);
            printf("Faculty Password: ");
            scanf("%s", pass);

            if (strcmp(user, "faculty") == 0 && strcmp(pass, "faculty123") == 0) {
                facultyChoice = 0;

                while (facultyChoice != 5) {
                    printf("\n--- Faculty Menu ---\n");
                    printf("1. View All Students\n");
                    printf("2. Search Student by Roll No\n");
                    printf("3. Update Attendance\n");
                    printf("4. Update CGPA\n");
                    printf("5. Logout\n");
                    printf("Choice: ");
                    scanf("%d", &facultyChoice);

                    if (facultyChoice == 1) {
                        if (count == 0) {
                            printf("No students added yet.\n");
                        } else {
                            printf("\nRoll No\tName\tBranch\tSem\tAtten.\tCGPA\n");
                            printf("----------------------------------------------\n");
                            for (i = 0; i < count; i++) {
                                printf("%s\t%s\t%s\t%d\t%.2f\t%.2f\n",
                                       rollNo[i], name[i], branch[i], sem[i],
                                       attendance[i], cgpa[i]);
                            }
                        }
                    }
                    else if (facultyChoice == 2) {
                        printf("Enter Roll No: ");
                        scanf("%s", roll);

                        found = 0;  
                        for (i = 0; i < count; i++) {
                            if (strcmp(rollNo[i], roll) == 0) {
                                found = 1;  
                                printf("\nName      : %s\n", name[i]);
                                printf("Roll No   : %s\n", rollNo[i]);
                                printf("Branch    : %s\n", branch[i]);
                                printf("Semester  : %d\n", sem[i]);
                                printf("CGPA      : %.2f\n", cgpa[i]);
                                printf("Attendance: %.2f\n", attendance[i]);
                            }
                        }
                        if (found == 0) {
                            printf("Student not found!\n");
                        }
                    }
                    else if (facultyChoice == 3) {
                        printf("Enter Roll No: ");
                        scanf("%s", roll);

                        found = 0; 
                        for (i = 0; i < count; i++) {
                            if (strcmp(rollNo[i], roll) == 0) {
                                found = 1;  
                                printf("Current attendance: %.2f\n", attendance[i]);
                                printf("Enter new attendance (0-100): ");
                                scanf("%f", &amount);
                                if (amount < 0 || amount > 100) {
                                    printf("Invalid attendance!\n");
                                } else {
                                    attendance[i] = amount;
                                    printf("Attendance updated.\n");
                                }
                            }
                        }
                        if (found == 0) {
                            printf("Student not found!\n");
                        }
                    }
                    else if (facultyChoice == 4) {
                        printf("Enter Roll No: ");
                        scanf("%s", roll);

                        found = 0;
                        for (i = 0; i < count; i++) {
                            if (strcmp(rollNo[i], roll) == 0) {
                                found = 1;   // student found
                                printf("Current CGPA: %.2f\n", cgpa[i]);
                                printf("Enter new CGPA (0-10): ");
                                scanf("%f", &amount);
                                if (amount < 0 || amount > 10) {
                                    printf("Invalid CGPA!\n");
                                } else {
                                    cgpa[i] = amount;
                                    printf("CGPA updated.\n");
                                }
                            }
                        }
                        if (found == 0) {
                            printf("Student not found!\n");
                        }
                    }
                    else if (facultyChoice != 5) {
                        printf("Wrong choice, try again.\n");
                    }
                }
            } else {
                printf("Wrong username or password!\n");
            }
        }

        /* ---------- STUDENT ---------- */
        else if (choice == 3) {
            printf("\nStudent Roll No: ");
            scanf("%s", user);
            printf("Password: ");
            scanf("%s", pass);

            found = 0;  
            for (i = 0; i < count; i++) {
            
                if (strcmp(rollNo[i], user) == 0 && strcmp(password[i], pass) == 0) {
                    found = 1; 
                    printf("\nWelcome, %s!\n", name[i]);
                    studentChoice = 0;

                    while (studentChoice != 4) {
                        printf("\n--- Student Menu ---\n");
                        printf("1. View My Details\n");
                        printf("2. View Attendance\n");
                        printf("3. View Fee Status\n");
                        printf("4. Logout\n");
                        printf("Choice: ");
                        scanf("%d", &studentChoice);

                        if (studentChoice == 1) {
                            printf("\nName    : %s\n", name[i]);
                            printf("Roll No : %s\n", rollNo[i]);
                            printf("Branch  : %s\n", branch[i]);
                            printf("Semester: %d\n", sem[i]);
                            printf("CGPA    : %.2f\n", cgpa[i]);
                        }
                        else if (studentChoice == 2) {
                            printf("\nYour attendance: %.2f\n", attendance[i]);
                            if (attendance[i] < 75) {
                                printf("Warning: Attendance is below 75!\n");
                            } else {
                                printf("Your attendance is good.\n");
                            }
                        }
                        else if (studentChoice == 3) {
                            printf("\nTotal Fee: %.2f\n", totalFee[i]);
                            printf("Paid Fee : %.2f\n", paidFee[i]);
                            printf("Due Fee  : %.2f\n", totalFee[i] - paidFee[i]);
                        }
                        else if (studentChoice != 4) {
                            printf("Wrong choice, try again.\n");
                        }
                    }
                }
            }
            if (found == 0) {
                printf("Wrong roll number or password!\n");
            }
        }
        else {
            printf("Wrong choice, try again.\n");
        }
    }
    return 0;
}