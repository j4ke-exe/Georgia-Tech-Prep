#include <stdio.h>
#include <limits.h>
#include <string.h>

// Item structure
typedef struct
{
  char name[50];
  int price;
  int quantity;
} Item;

// Function prototypes
void viewCart(Item *cart, int totalCost);
void placeOrder(Item *cart, int totalCost);
void formatWithCommas(int value, char *output);

// Function to add items to the cart
void addItemToCart(Item *cart, int *totalCost)
{
  int itemChoice, quantity;
  printf("\nItems available:\n");
  printf("1. Shoes: 647\n");
  printf("2. Yacht: 483,000\n");
  printf("3. Private Plane: 147,000,000\n");
  printf("4. Beach Front Property: 1,000,000,000\n");
  printf("Choose an item to add to your cart: ");
  scanf("%d", &itemChoice);

  if (itemChoice < 1 || itemChoice > 4)
  {
    printf("Invalid item selection.\n");
    return;
  }

  printf("How many would you like to add? ");
  scanf("%d", &quantity);

  int itemPrice = 0;
  switch (itemChoice)
  {
  case 1:
    itemPrice = 647;
    break;
  case 2:
    itemPrice = 483000;
    break;
  case 3:
    itemPrice = 147000000;
    break;
  case 4:
    itemPrice = 1000000000;
    break;
  }

  int totalItemCost;
  if (__builtin_mul_overflow(itemPrice, quantity, &totalItemCost)) { // Checks for int overflow, if false add to totalItemCost
    printf("The order was too large!\n");
    return;
  }

  if (__builtin_add_overflow(*totalCost, totalItemCost, totalCost)) { // Checks for int overflow, if false mul to totalCost
    printf("Error: Integer overflow detected when updating total cost.\n");
    return;
  }
  // *totalCost += itemPrice * quantity; // Potential integer overflow vulnerability here
  cart[itemChoice - 1].quantity += quantity;
}

int main()
{
  Item storeItems[4] = {
      {"Shoes", 647, 0},
      {"Yacht", 483000, 0},
      {"Private Plane", 147000000, 0},
      {"Beach Front Property", 1000000000, 0}};

  Item cart[4] = {
      {"Shoes", 0, 0},
      {"Yacht", 0, 0},
      {"Private Plane", 0, 0},
      {"Beach Front Property", 0, 0}};

  int totalCost = 0;
  int choice;

  do
  {
    printf("\nWelcome to the Store!\n");
    printf("1. Add Items To Your Cart\n");
    printf("2. View Your Cart\n");
    printf("3. Place Order\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      addItemToCart(cart, &totalCost);
      break;
    case 2:
      viewCart(cart, totalCost);
      break;
    case 3:
      placeOrder(cart, totalCost);
      choice = 4; // Quit after placing order
      break;
    case 4:
      if (totalCost > 0)
      {
        char confirm;
        printf("\nYou have items in your cart. Would you like to place the order before exiting? (y/n): ");
        scanf(" %c", &confirm);
        if (confirm == 'y' || confirm == 'Y')
        {
          placeOrder(cart, totalCost);
        }
        else
        {
          printf("Exiting without placing the order.\n");
        }
      }
      else
      {
        printf("Thank you for visiting the store!\n");
      }
      break;
    default:
      printf("Invalid option. Please choose again.\n");
    }
  } while (choice != 4);

  return 0;
}

// Function to view the cart
void viewCart(Item *cart, int totalCost)
{
  char formattedTotal[50];
  formatWithCommas(totalCost, formattedTotal);

  printf("\nYour Cart:\n");
  for (int i = 0; i < 4; i++)
  {
    if (cart[i].quantity > 0)
    {
      printf("%s: %d items\n", cart[i].name, cart[i].quantity);
    }
  }
  printf("Total cost: %s\n", formattedTotal);
}

// Function to place the order
void placeOrder(Item *cart, int totalCost)
{
  printf("\nPlacing order...\n");
  viewCart(cart, totalCost);
  printf("Order placed successfully! Thank you for your purchase.\n");
}

// Function to format integers with commas
void formatWithCommas(int value, char *output)
{
  char buffer[50];
  int isNegative = 0;
  unsigned int absValue;

  if (value == INT_MIN)
  {
    isNegative = 1;
    absValue = (unsigned int)INT_MAX + 1;
  }
  else if (value < 0)
  {
    isNegative = 1;
    absValue = -value;
  }
  else
  {
    absValue = value;
  }

  sprintf(buffer, "%u", absValue);

  int len = strlen(buffer);
  int comma_count = (len - 1) / 3;

  int total_len = len + comma_count + isNegative;
  output[total_len] = '\0';

  int i = len - 1;
  int j = total_len - 1;
  int k = 0;

  while (i >= 0)
  {
    output[j--] = buffer[i--];
    k++;
    if (k == 3 && i >= 0)
    {
      output[j--] = ',';
      k = 0;
    }
  }

  if (isNegative)
  {
    output[0] = '-';
  }
}
