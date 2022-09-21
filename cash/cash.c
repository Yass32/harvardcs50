#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int cents;

int get_cents(void)
{
    // TODO
    do
    {
        cents = get_int("Number of cents? ");
    }
    while (!(cents > 0));

    printf("%i", )
}

int calculate_quarters(int cents)
{
    // TODO
    cents / 25 = int quart;
    printf("%i", quart);

}

int calculate_dimes(int cents)
{
    // TODO
    cents / 10 = int dim;
    printf("%i", dim);

}

int calculate_nickels(int cents)
{
    // TODO
    cents / 5 = int nick;
    printf("%i", nick);

}

int calculate_pennies(int cents)
{
    // TODO
    cents / 1 = int pen;
    printf("%i", pen);
}
