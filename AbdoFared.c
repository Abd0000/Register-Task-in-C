#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_USERS 10

struct User {
  char username[50];
  char password[50];
  union {
    bool isLoggedIn;
    bool isActive;
  };
};

struct User users[MAX_USERS];
int numUsers = 0;

// Function to register a new user
void registerUser() {
  if (numUsers >= MAX_USERS) {
    printf("Sorry, maximum number of users reached.\n");
    return;
  }

  char username[50];
  char password[50];
  bool isActive;

  printf("Enter a username: ");
  scanf("%s", username);

  // Check for duplicate usernames
  for (int i = 0; i < numUsers; i++) {
    if (strcmp(username, users[i].username) == 0) {
      printf("Username already exists. Registration failed.\n");
      return;
    }
  }

  printf("Enter a password: ");
  scanf("%s", password);

  int tempActive;
  printf("Choose user state (1 for active, 0 for inactive): ");
  scanf("%d", &tempActive);
  isActive = tempActive != 0; // Convert to boolean


  strcpy(users[numUsers].username, username);
  strcpy(users[numUsers].password, password);
  users[numUsers].isActive = isActive;

  printf("Registration successful!\n");
  numUsers++;
}

// Function to log in
void loginUser() {
  char username[50];
  char password[50];

  printf("Enter your username: ");
  scanf("%s", username);

  printf("Enter your password: ");
  scanf("%s", password);

  for (int i = 0; i < numUsers; i++) {
    if (strcmp(username, users[i].username) == 0 &&
        strcmp(password, users[i].password) == 0) {
      if (users[i].isActive) {
        users[i].isLoggedIn = true;
        printf("Login successful!\n");
      } else {
        printf("Login failed. User is inactive.\n");
      }
      return;
    }
  }

  printf("Login failed. Invalid username or password.\n");
}

// Function to log out
void logoutUser() {
  char username[50];

  printf("Enter your username: ");
  scanf("%s", username);

  for (int i = 0; i < numUsers; i++) {
    if (strcmp(username, users[i].username) == 0) {
      users[i].isLoggedIn = false;
      printf("Logout successful!\n");
      return;
    }
  }

  printf("User not found. Logout failed.\n");
}

int main() {
  int ans;

  while (1) {
    printf("\n------------------------\n");
    printf("Choose an option:\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Logout\n");
    printf("4. Exit\n");
    printf("\n------------------------\n");
    printf("ans : ");
    scanf("%d", &ans);

    if (ans == 1)
      registerUser();
    else if (ans == 2)
      loginUser();
    else if (ans == 3)
      logoutUser();
    else if (ans == 4) {
      printf("Goodbye!\n");
      return 0;
    } else
      printf("Invalid choice. Please try again.\n");
  }
  return 0;
}
