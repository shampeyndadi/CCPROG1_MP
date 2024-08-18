/*
Description: The bus ticketing system is a program designed to digitize and simulate the buying of tickets through an agent.
The program will serve as the digitized version of an agent. This program uses conditional statements and loops to function
Programmed by: Jedidiah Kyle Martin Julian S13A
Last modified: 11/26/23
Version: V 3.0
Acknowledgements: <list of sites or borrowed libraries and sources>
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*This function displays opening header at the start of main menu
Precondition: None
@return opening header
*/
void displayOpening()
{
    printf("\nWelcome to DLSU Shuttle Service!\nBook your tickets now\n\n");
}
/*This function displays main menu options
Precondition: None
@return option menu
*/
void displayMenu(){
    printf("Main menu:\n\n%s%s%s%s%s",
           "[A] Book a ticket\n", "[B] Cancel a Booking\n",
           "[C] Display Schedule\n", "[D] Update Departure Time [Agent Only]\n",
           "[E] Close Application\n\n");
}
/*This functions checks the validity of the ID number
Precondition: The sum of the ID number should be divisible by 11
@param *IDnum serves as the temporary place holder for the checking of validity of the ID number
@return the validity of the Id number if 1 (Valid), 0 (Invalid)
*/
int checkIDnumber(int *IDnum) 
{
    int nNum, nSum, nMultiplier, nDigit;

    nNum = *IDnum; // Stores ID number 
    nSum = 0;
    nMultiplier = 1; // Will serve as the place value 

    while (nNum > 0){ // Checks if Id number is valid 
        nDigit = nNum % 10;  // Removes last digit from the ID number 
        nSum += nDigit * nMultiplier;  // Updates the value of nSum 
        nMultiplier++; // Increments multiplier 
        nNum /= 10;  // Gets the last digit of nNum 
    }

    if (nSum % 11 == 0){
        return 1; // If ID number is divisible by 11, it will return 1 (Valid)
    } else {
        return 0; // If ID number is not, it will retrun 0 (Invalid)
    }
}
/*This function executes the booking of ticket
Precondition: ID number should be valid, ID number shouldnt be taken yet, seat number shouldnt be taken yet, seats are still available, booked seats shouldnt be marked as available. Inputs should be an integer
@param *s1...*s14 stores the seat number of the bus
@param *IDnum is the temporary place holder to check if ID number is valid before storing it
@param *ID1...*ID14 stores ID number 
@param *TotalBusSeats displays available seats. Decrements to 1 every time a seat has been booked 
@param CurrentHour and CurrentMins displays and stores the time the program is running 
@param *NewPeriod displays the time period (AM/PM)
@param *TotalBookedSeats counts the number of tickets booked during the run of the entire program. Increments when booked, decrements when cancelled
@return Individual seat booked by a user (One seat is limited to one user)
*/
void executeBookTicket(int* s1, int* s2, int* s3, int* s4, int* s5, int* s6, int* s7, int* s8, int* s9, int* s10, int* s11, int* s12, int* s13, int* s14, int* IDnum, int* ID1, int* ID2, int* ID3, int* ID4, int* ID5, int* ID6, int* ID7, int* ID8, int* ID9, int* ID10, int* ID11, int* ID12, int* ID13, int* ID14, int* TotalBusSeats, int CurrentHour, int CurrentMins, char *NewPeriod1, int* TotalBookedSeats)
{
	int i = 1;
    int back;

    printf("\nBOOK A TICKET\n");
    printf("\n");
    printf("\nTime: %02d:%02d %cM\n", CurrentHour, CurrentMins, *NewPeriod1);
    printf("\n");
    // Displaying the route based on current time
    if (CurrentHour % 2 == 0)
    {
        printf("ROUTE: Depart Manila - %02d:00 %cM : Arrive Laguna - %02d:00 %cM\n", CurrentHour, *NewPeriod1, CurrentHour + 1, *NewPeriod1);
    }else
    {
        if(CurrentHour == 11 && *NewPeriod1 == 'A')
        {
            printf("ROUTE: Depart Laguna - %02d:00 %cM : Arrive Manila - %02d:00 PM\n", CurrentHour, *NewPeriod1, CurrentHour + 1);
        }  
        else {
            printf("ROUTE: Depart Laguna - %02d:00 %cM : Arrive Manila - %02d:00 %cM\n", CurrentHour, *NewPeriod1, CurrentHour + 1, *NewPeriod1);
        }
    }
    printf("\n");
    printf("Total seats left: %d\n", *TotalBusSeats);
    printf("\n");
    printf("Available seats: "); // Displays available seats
    // Checks if seats are booked and removes it by counting until it reaches the seat booked
    for (i = 1; i <= 14; i++) 
    {
        int isBooked = 0; 
        // i counts until it reaches the same value stored in the pointer variables 
        if (*s1  == i || *s2 == i || *s3  == i || *s4 == i || *s5  == i || *s6 == i|| *s7  == i || *s8 == i || *s9  == i || *s10 == i || *s11  == i || *s12 == i || *s13  == i || *s14 == i) 
        {
            isBooked = 1; // If there is it will initialize isBooked to 1 
        }
        if (!(isBooked))
        {
            printf("%d ", i); // If it is not booked, prints seat number 
        }
        else 
        {
            printf(" "); // If it is, displays a blank space 
        }
    }
    printf("\n");
    printf("\n");
    // Displays bus layout and checks if seats are booked
    printf("Seat layout: ");
    printf("\n");
    printf("\n");
    printf(" _______/    /_________________________________\n");
    printf("/                                              | \n");
    for (i = 1; i <= 14; i++) {
        int isBooked = 0;
        // i counts until it reaches the same value stored in the pointer variables 
        if (*s1 == i || *s2 == i || *s3 == i || *s4 == i || *s5 == i || *s6 == i || *s7 == i || *s8 == i || *s9 == i || *s10 == i || *s11 == i || *s12 == i || *s13 == i || *s14 == i) {
            isBooked = 1;
        }
        if (isBooked) {
            printf("| [X] "); // If it is booked prints X 
        } 
        else {
            printf("| [%d] ", i); // If it is not, prints seat number 
        } 
        
        if (i == 7)
        {
            printf("\t|\n");
        }
        else if (i == 14)
        {
            printf("\t|\n");
        }
        else if (i % 7 == 0) 
        {
            printf(" \n");
        }
    }
    printf("\\______________________________________________|");
    printf("\n");  
    printf("\n");
    // Checks if Total Bus Seats are fully booked
    if (*TotalBusSeats == 0)
    {
        printf("Trip is fully booked! Please wait for next trip\n");
        printf("\n");
    }
    // If condition is false, it will enter the booking phase
    else 
    {
    printf("ONE ID NUMBER IS LIMITED TO ONE SEAT\n");
    printf("\n");
    printf("Book a ticket\n"); 
    printf("\n");
    printf("Enter ID Number: ");
    scanf("%d", IDnum); // Ask for user to input. IDnum is temporary placeholder for id number input
    if (checkIDnumber(IDnum) && *IDnum > 0 && *IDnum != *ID14 && *IDnum != *ID13 && *IDnum != *ID12 && *IDnum != *ID11 && *IDnum != *ID10 && *IDnum != *ID9 && *IDnum != *ID8 && *IDnum != *ID7 && *IDnum != *ID6 && *IDnum != *ID5 && *IDnum != *ID4 && *IDnum != *ID3 && *IDnum != *ID2 && *IDnum != *ID1) // ID Validation function will execute 
    {
        if (*ID1 == 0) // IDnum checks if ID1 has a ID number stored, if none IDnum will pass the value to ID1. If there is, it will pass to another variable that doesnt hold an ID number
    {
        *ID1 = *IDnum;  // Passes the value to ID1
        printf("Book a seat: "); 
        scanf("%d", s1);  // Prompts user to book seat
        getchar(); // Input buffer if user inputs an invalid input other than an integer, specifically a character
        if (*s1 < 1 || *s1 > 14) // Checks if user placed a seat number within the range of available seats in the bus
        {
            *s1 = 0; // s1 and ID1 resets if it is invalid 
            *ID1 = 0;
            printf("Invalid seat number\n");
        }
        else 
        {
            *TotalBusSeats -=  1; // Increments and decrements Bus seats and Booked seats
            *TotalBookedSeats += 1;
            printf("\nBooking successful!\n");
        }
    }
    else if (*ID2 == 0 && *IDnum != *ID1) // IDnum checks if ID12has a ID number stored and is different with other ID numbers, if none IDnum will pass the value to ID2. If there is, it will pass to another variable that doesnt hold an ID number
    {
        *ID2 = *IDnum; // Passes the value to ID2
        printf("Book a seat: ");
        scanf("%d", s2);  // Prompts user to book seat
        getchar(); // Input buffer if user inputs an invalid input other than an integer, specifically a character
        if (*s2 < 1 || *s2 > 14) // Checks if user placed a seat number within the range of available seats in the bus
        {
            *s2 = 0; // s2 and ID2 resets if it is invalid 
            *ID2 = 0;
            printf("Invalid seat number\n");
        }
        else if (*s2 == *s1) // Check if seat was taken already
        {
            *s2 = 0; 
            *ID2 = 0;
            printf("Booking cannot be made as seat is not available\n");
        }
        else 
        {
            *TotalBusSeats -= 1; // Increments and decrements Bus seats and Booked seats
            *TotalBookedSeats += 1;
            printf("Booking successful!\n");
        }
    }
    else if (*ID3 == 0 && *IDnum != *ID2 && *IDnum != *ID1) // IDnum checks if ID3 has a ID number stored and is different with other ID numbers, if none IDnum will pass the value to ID3. If there is, it will pass to another variable that doesnt hold an ID number
    {
        *ID3 = *IDnum; // Passes the value to ID3
        printf("Book a seat: ");
        scanf("%d", s3); // Prompts user to book seat
        getchar(); // Input buffer if user inputs an invalid input other than an integer, specifically a character
        if (*s3 < 1 || *s3 > 14) // Checks if user placed a seat number within the range of available seats in the bus
        {
            *s3 = 0; // s3 and ID3 resets if it is invalid 
            *ID3 = 0;
            printf("Invalid seat number\n");
        }
        else if (*s3 == *s2 || *s3 == *s1) // Check if seat was taken already
        {
            *s3 = 0; 
            *ID3 = 0;
            printf("Booking cannot be made as seat is not available\n");
        }
        else 
        {
            *TotalBusSeats -= 1; // Increments and decrements Bus seats and Booked seats
            *TotalBookedSeats += 1;
            printf("Booking successful!\n");
        }
    }
    else if (*ID4 == 0 && *IDnum != *ID3 && *IDnum != *ID2 && *IDnum != *ID1) // IDnum checks if ID4 has a ID number stored and is different with other ID numbers, if none, IDnum will pass the value to ID4. If there is, it will pass to another variable that doesnt hold an ID number
    {
        *ID4 = *IDnum; // Passes the value to ID4
        printf("Book a seat: ");
        scanf("%d", s4); // Prompts user to book seat
        getchar(); // Input buffer if user inputs an invalid input other than an integer, specifically a character
        if (*s4 < 1 || *s4 > 14) // Checks if user placed a seat number within the range of available seats in the bus
        {
            *s4 = 0; // s4 and ID4 resets if it is invalid 
            *ID4 = 0;
            printf("Invalid seat number\n");
        }
        else if (*s4 == *s3 || *s4 == *s3 || *s4 == *s1) // Check if seat was taken already
        {
            *s4 = 0;
            *ID4 = 0;
            printf("Booking cannot be made as seat is not available\n");
        }
        else 
        {
            *TotalBusSeats -= 1; // Increments and decrements Bus seats and Booked seats
            *TotalBookedSeats += 1;
            printf("Booking successful!\n");
        }
    }
    else if (*ID5 == 0 && *IDnum != *ID4 && *IDnum != *ID3 && *IDnum != *ID2 && *IDnum != *ID1) // IDnum checks if ID5 has a ID number stored and is different with other ID numbers, if none, IDnum will pass the value to ID5. If there is, it will pass to another variable that doesnt hold an ID number
    {
        *ID5 = *IDnum; // Passes the value to ID5
        printf("Book a seat: ");
        scanf("%d", s5); // Prompts user to book seat
        getchar(); // Input buffer if user inputs an invalid input other than an integer, specifically a character
        if (*s5 < 1 || *s5 > 14) // Checks if user placed a seat number within the range of available seats in the bus
        {
            *s5 = 0; // s5 and ID5 resets if it is invalid 
            *ID5 = 0;
            printf("Invalid seat number\n");
        }
        else if (*s5 == *s4 || *s5 == *s3 || *s5 == *s2 || *s5 == *s1) // Check if seat was taken already
        {
            *s5 = 0;
            *ID5 = 0;
            printf("Booking cannot be made as seat is not available\n");
        }
        else 
        {
            *TotalBusSeats -= 1; // Increments and decrements Bus seats and Booked seats
            *TotalBookedSeats += 1;
            printf("Booking successful!\n");
        }
    }
    else if (*ID6 == 0 && *IDnum != *ID5 && *IDnum != *ID4 && *IDnum != *ID3 && *IDnum != *ID2 && *IDnum != *ID1) // IDnum checks if ID6 has a ID number stored and is different with other ID numbers, if none, IDnum will pass the value to ID6. If there is, it will pass to another variable that doesnt hold an ID number
    {
        *ID6 = *IDnum; // Passes the value to ID6
        printf("Book a seat: ");
        scanf("%d", s6); // Prompts user to book seat
        getchar(); // Input buffer if user inputs an invalid input other than an integer, specifically a character
        if (*s6 < 1 || *s6 > 14) // Checks if user placed a seat number within the range of available seats in the bus
        {
            *s6 = 0; // s6 and ID6 resets if it is invalid 
            *ID6 = 0;
            printf("Invalid seat number\n");
        }
        else if (*s6 == *s5 || *s6 == *s4 || *s6 == *s3 || *s6 == *s2 || *s6 == *s1) // Check if seat was taken already
        {
            *s6 = 0;
            *ID6 = 0;
            printf("Booking cannot be made as seat is not available\n");
        }
        else 
        {
            *TotalBusSeats -= 1; // Increments and decrements Bus seats and Booked seats
            *TotalBookedSeats += 1;
            printf("Booking successful!\n");
        }
    }
    else if (*ID7 == 0 && *IDnum != *ID6 && *IDnum != *ID5 && *IDnum != *ID4 && *IDnum != *ID3 && *IDnum != *ID2 && *IDnum != *ID1) // IDnum checks if ID7 has a ID number stored and is different with other ID numbers, if none, IDnum will pass the value to ID7. If there is, it will pass to another variable that doesnt hold an ID number
    {
        *ID7 = *IDnum; // Passes the value to ID7
        printf("Book a seat: ");
        scanf("%d", s7); // Prompts user to book seat
        getchar(); // Input buffer if user inputs an invalid input other than an integer, specifically a character
        if (*s7 < 1 || *s7 > 14) // Checks if user placed a seat number within the range of available seats in the bus
        {
            *s7 = 0; // s7 and ID7 resets if it is invalid 
            *ID7 = 0;
            printf("Invalid seat number\n");
        }
        else if (*s7 == *s6 || *s7 == *s5 || *s7 == *s4 || *s7 == *s3 || *s7 == *s2 || *s7 == *s1) // Check if seat was taken already
        {
            *s7 = 0;
            *ID7 = 0;
            printf("Booking cannot be made as seat is not available\n");
        }
        else 
        {
            *TotalBusSeats -= 1; // Increments and decrements Bus seats and Booked seats
            *TotalBookedSeats += 1;
            printf("Booking successful!\n");
        }
    }
    else if (*ID8 == 0 && *IDnum != *ID7 && *IDnum != *ID6 && *IDnum != *ID5 && *IDnum != *ID4 && *IDnum != *ID3 && *IDnum != *ID2 && *IDnum != *ID1) // IDnum checks if ID8 has a ID number stored and is different with other ID numbers, if none, IDnum will pass the value to ID8. If there is, it will pass to another variable that doesnt hold an ID number
    {
        *ID8 = *IDnum; // Passes the value to ID8
        printf("Book a seat: ");
        scanf("%d", s8); // Prompts user to book seat
        getchar(); // Input buffer if user inputs an invalid input other than an integer, specifically a character
        if (*s8 < 1 || *s8 > 14) // Checks if user placed a seat number within the range of available seats in the bus
        {
            *s8 = 0; // s8 and ID8 resets if it is invalid 
            *ID8 = 0;
            printf("Invalid seat number\n");
        }
        else if (*s8 == *s7 || *s8 == *s6 || *s8 == *s5 || *s8 == *s4 || *s8 == *s3 || *s8 == *s2 || *s8 == *s1) // Check if seat was taken already
        {
            *s8 = 0;
            *ID8 = 0;
            printf("Booking cannot be made as seat is not available\n");
        }
        else 
        {
            *TotalBusSeats -= 1; // Increments and decrements Bus seats and Booked seats
            *TotalBookedSeats += 1;
            printf("Booking successful!\n");
        }
    }
    else if (*ID9 == 0 && *IDnum != *ID8 && *IDnum != *ID7 && *IDnum != *ID6 && *IDnum != *ID5 && *IDnum != *ID4 && *IDnum != *ID3 && *IDnum != *ID2 && *IDnum != *ID1) // IDnum checks if ID9 has a ID number stored and is different with other ID numbers, if none, IDnum will pass the value to ID9. If there is, it will pass to another variable that doesnt hold an ID number
    {
        *ID9 = *IDnum; // Passes the value to ID9
        printf("Book a seat: ");
        scanf("%d", s9); // Prompts user to book seat
        getchar(); // Input buffer if user inputs an invalid input other than an integer, specifically a character
        if (*s9 < 1 || *s9 > 14) // Checks if user placed a seat number within the range of available seats in the bus
        {
            *s9 = 0; // s9 and ID9 resets if it is invalid 
            *ID9 = 0;
            printf("Invalid seat number\n");
        }
        else if (*s9 == *s8 ||*s9 == *s7 || *s9 == *s6 || *s9 == *s5 || *s9 == *s4 || *s9 == *s3 || *s9 == *s2 || *s9 == *s1) // Check if seat was taken already
        {
            *s9 = 0;
            *ID9 = 0;
            printf("Booking cannot be made as seat is not available\n");
        }
        else 
        {
            *TotalBusSeats -= 1; // Increments and decrements Bus seats and Booked seats
            *TotalBookedSeats += 1;
            printf("Booking successful!\n");
        }
    }
    else if (*ID10 == 0 && *IDnum != *ID9 && *IDnum != *ID8 && *IDnum != *ID7 && *IDnum != *ID6 && *IDnum != *ID5 && *IDnum != *ID4 && *IDnum != *ID3 && *IDnum != *ID2 && *IDnum != *ID1) // IDnum checks if ID10 has a ID number stored and is different with other ID numbers, if none, IDnum will pass the value to ID10. If there is, it will pass to another variable that doesnt hold an ID number
    {
        *ID10 = *IDnum; // Passes the value to ID10
        printf("Book a seat: ");
        scanf("%d", s10); // Prompts user to book seat
        getchar(); // Input buffer if user inputs an invalid input other than an integer, specifically a character
        if (*s10 < 1 || *s10 > 14) // Checks if user placed a seat number within the range of available seats in the bus
        {
            *s10 = 0; // s10 and ID10 resets if it is invalid 
            *ID10 = 0;
            printf("Invalid seat number\n");
        }
        else if (*s10 == *s9 || *s10 == *s8 ||*s10 == *s7 || *s10 == *s6 || *s10 == *s5 || *s10 == *s4 || *s10 == *s3 || *s10 == *s2 || *s10 == *s1) // Check if seat was taken already
        {
            *s10 = 0;
            *ID10 = 0;
            printf("Booking cannot be made as seat is not available\n");
        }
        else 
        { 
            *TotalBusSeats -= 1; // Increments and decrements Bus seats and Booked seats
            *TotalBookedSeats += 1;
            printf("Booking successful!\n");
        }
    }
    else if (*ID11 == 0 && *IDnum != *ID10 &&*IDnum != *ID9 && *IDnum != *ID8 && *IDnum != *ID7 && *IDnum != *ID6 && *IDnum != *ID5 && *IDnum != *ID4 && *IDnum != *ID3 && *IDnum != *ID2 && *IDnum != *ID1) // IDnum checks if ID11 has a ID number stored and is different with other ID numbers, if none, IDnum will pass the value to ID11. If there is, it will pass to another variable that doesnt hold an ID number
    {
        *ID11 = *IDnum; // Passes the value to ID11
        printf("Book a seat: "); 
        scanf("%d", s11); // Prompts user to book seat
        getchar(); // Input buffer if user inputs an invalid input other than an integer, specifically a character
        if (*s11 < 1 || *s11 > 14) // Checks if user placed a seat number within the range of available seats in the bus
        {
            *s11 = 0; // s11 and ID11 resets if it is invalid 
            *ID11 = 0;
            printf("Invalid seat number\n");
        }
        else if (*s11 == *s10 || *s11 == *s9 || *s11 == *s8 ||*s11 == *s7 || *s11 == *s6 || *s11 == *s5 || *s11 == *s4 || *s11 == *s3 || *s11 == *s2 || *s11 == *s1) // Check if seat was taken already
        {
            *s11 = 0; 
            *ID11 = 0;
            printf("Booking cannot be made as seat is not available\n");
        }
        else 
        {
            *TotalBusSeats -= 1; // Increments and decrements Bus seats and Booked seats
            *TotalBookedSeats += 1;
            printf("Booking successful!\n");
        }
    }
    else if (*ID12 == 0 && *IDnum != *ID11 && *IDnum != *ID10 && *IDnum != *ID9 && *IDnum != *ID8 && *IDnum != *ID7 && *IDnum != *ID6 && *IDnum != *ID5 && *IDnum != *ID4 && *IDnum != *ID3 && *IDnum != *ID2 && *IDnum != *ID1) // IDnum checks if ID12 has a ID number stored and is different with other ID numbers, if none, IDnum will pass the value to ID12. If there is, it will pass to another variable that doesnt hold an ID number
    {
       *ID12 = *IDnum; // Passes the value to ID12
        printf("Book a seat: ");
        scanf("%d", s12); // Prompts user to book seat
        getchar(); // Input buffer if user inputs an invalid input other than an integer, specifically a character
        if (*s12 < 1 || *s12 > 14) // Checks if user placed a seat number within the range of available seats in the bus
        {
            *s12 = 0; // s12 and ID12 resets if it is invalid 
            *ID12 = 0;
            printf("Invalid seat number\n");
        }
        else if (*s12 == *s11 || *s12 == *s10 || *s12 == *s9 || *s12 == *s8 ||*s12 == *s7 || *s12 == *s6 || *s12 == *s5 || *s12 == *s4 || *s12 == *s3 || *s12 == *s2 || *s12 == *s1) // Check if seat was taken already
        {
            *s12 = 0;
            *ID12 = 0;
            printf("Booking cannot be made as seat is not available\n");
        }
        else 
        {
            *TotalBusSeats -= 1; // Increments and decrements Bus seats and Booked seats
            *TotalBookedSeats += 1;
            printf("Booking successful!\n");
        }
    }
    else if (*ID13 == 0 && *IDnum != *ID12 && *IDnum != *ID11 && *IDnum != *ID10 && *IDnum != *ID9 && *IDnum != *ID8 && *IDnum != *ID7 && *IDnum != *ID6 && *IDnum != *ID5 && *IDnum != *ID4 && *IDnum != *ID3 && *IDnum != *ID2 && *IDnum != *ID1) // IDnum checks if ID13 has a ID number stored and is different with other ID numbers, if none, IDnum will pass the value to ID13. If there is, it will pass to another variable that doesnt hold an ID number
    {
        *ID13 = *IDnum; // Passes the value to ID13
        printf("Book a seat: ");
        scanf("%d", s13); // Prompts user to book seat
        getchar(); // Input buffer if user inputs an invalid input other than an integer, specifically a character
        if (*s13 < 1 || *s13 > 14) // Checks if user placed a seat number within the range of available seats in the bus
        {
            *s13 = 0; // s13 and ID13 resets if it is invalid 
            *ID13 = 0;
            printf("Invalid seat number\n");
        }
        else if (*s13 == *s12 || *s13 == *s11 || *s13 == *s10 || *s13 == *s9 || *s13 == *s8 ||*s13 == *s7 || *s13 == *s6 || *s13 == *s5 || *s13 == *s4 || *s13 == *s3 || *s13 == *s2 || *s13 == *s1) // Check if seat was taken already
        {
            *s13 = 0; // s12 and ID12 resets if it is invalid 
            *ID13 = 0;
            printf("Booking cannot be made as seat is not available\n");
        }
        else 
        {
            *TotalBusSeats -= 1; // Increments and decrements Bus seats and Booked seats
            *TotalBookedSeats += 1;
            printf("Booking successful!\n");
        }
    }
    else if (*ID14 == 0 && *IDnum != *ID13 && *IDnum != *ID12 && *IDnum != *ID11 && *IDnum != *ID10 && *IDnum != *ID9 && *IDnum != *ID8 && *IDnum != *ID7 && *IDnum != *ID6 && *IDnum != *ID5 && *IDnum != *ID4 && *IDnum != *ID3 && *IDnum != *ID2 && *IDnum != *ID1) // IDnum checks if ID14 has a ID number stored and is different with other ID numbers, if none, IDnum will pass the value to ID14. If there is, it will pass to another variable that doesnt hold an ID number
    {
        *ID14 = *IDnum; // Passes the value to ID14
        printf("Book a seat: ");
        scanf("%d", s14); // Prompts user to book seat
        getchar(); // Input buffer if user inputs an invalid input other than an integer, specifically a character
        if (*s14 < 1 || *s14 > 14 ) // Checks if user placed a seat number within the range of available seats in the bus
        {
            *s14 = 0; // s13 and ID13 resets if it is invalid 
            *ID14 = 0;
            printf("Invalid seat number\n");
        }
        else if (*s14 == *s13 || *s14 == *s12 || *s14 == *s11 || *s14 == *s10 || *s14 == *s9 || *s14 == *s8 ||*s14 == *s7 || *s14 == *s6 || *s14 == *s5 || *s14 == *s4 || *s14 == *s3 || *s14 == *s2 || *s14 == *s1) // Check if seat was taken already
        {
            *s14 = 0;
            *ID14 = 0;
            printf("Booking cannot be made as seat is not available\n");
        }
        else 
        {
            *TotalBusSeats -= 1; // Increments and decrements Bus seats and Booked seats
            *TotalBookedSeats += 1;
            printf("Booking successful!\n");
        }
    }
    else 
        {
            *IDnum = 0; //IDnum resets
            getchar(); // Input buffer if user inputs an invalid input other than an integer, specifically a character
            printf("\n");
            printf("Booking unsuccessful\n");
            printf("\n");
            printf("Possible reasons: \n");
            printf("ID number is invalid\n");
            printf("ID Number is assigned to a seat already");
            printf("\n");
        }
    }
    else 
    {
       *IDnum = 0; //IDnum resets
        getchar(); // Input buffer if user inputs an invalid input other than an integer, specifically a character
        printf("\n");
        printf("Booking unsuccessful\n");
        printf("\n");
        printf("Possible reasons: \n");
        printf("ID number is invalid\n");
        printf("ID Number is assigned to a seat already");
        printf("\n");
    }
    printf("\n");
    printf("Booked seats / seats that are no long available: \n");
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d \n", *s1, *s2, *s3, *s4, *s5, *s6, *s7, *s8, *s9, *s10, *s11, *s12, *s13, *s14); // Displays booked seats
    printf("\n");
    }
    system("pause");
    system("CLS");
}
/*This function displays taken seats and ID numbers of different users
Precondition: ID number shouldnt be doubled, seats shouldnt be doubled. 
@param *s1...*s14 stores the seat number of the bus
@param *ID1...*ID14 stores ID number 
@return Display the seat booked by an ID number 
*/
void IDnumAndSeat(int* s1, int* s2, int* s3, int* s4, int* s5, int* s6, int* s7, int* s8, int* s9, int* s10, int* s11, int* s12, int* s13, int* s14, int* ID1, int* ID2, int* ID3, int* ID4, int* ID5, int* ID6, int* ID7, int* ID8, int* ID9, int* ID10, int* ID11, int* ID12, int* ID13, int* ID14)
{
    printf("Seat:   %2d  :  ID number:     %2d\n", *s1, *ID1);
    printf("Seat:   %2d  :  ID number:     %2d\n", *s2, *ID2);
    printf("Seat:   %2d  :  ID number:     %2d\n", *s3, *ID3);
    printf("Seat:   %2d  :  ID number:     %2d\n", *s4, *ID4);
    printf("Seat:   %2d  :  ID number:     %2d\n", *s5, *ID5);
    printf("Seat:   %2d  :  ID number:     %2d\n", *s6, *ID6);  //Display the taken seats of different ID numbers 
    printf("Seat:   %2d  :  ID number:     %2d\n", *s7, *ID7);
    printf("Seat:   %2d  :  ID number:     %2d\n", *s8, *ID8);
    printf("Seat:   %2d  :  ID number:     %2d\n", *s9, *ID9);
    printf("Seat:   %2d  :  ID number:     %2d\n", *s10, *ID10);
    printf("Seat:   %2d  :  ID number:     %2d\n", *s11, *ID11);
    printf("Seat:   %2d  :  ID number:     %2d\n", *s12, *ID12);
    printf("Seat:   %2d  :  ID number:     %2d\n", *s13, *ID13);
    printf("Seat:   %2d  :  ID number:     %2d\n", *s14, *ID14);
}
/*This function allows users to cancel their bookings 
Precondition: Seats should be taken, Booked seats shouldnt be marked as available. Inputs should be an integer
@param *s1...*s14 stores the seat number of the bus
@param *ID1...*ID14 stores ID number 
@param *TotalBusSeats displays available seats. Decrements to 1 every time a seat has been booked 
@param CurrentHour and CurrentMins displays and stores the time the program is running 
@param *NewPeriod displays the time period (AM/PM)
@param *TotalBookedSeats counts the number of tickets booked during the run of the entire program. Increments when booked, decrements when cancelled
@return availability of seats
*/
void executeCancelBooking(int* s1, int* s2, int* s3, int* s4, int* s5, int* s6, int* s7, int* s8, int* s9, int* s10, int* s11, int* s12, int* s13, int* s14, int* ID1, int* ID2, int* ID3, int* ID4, int* ID5, int* ID6, int* ID7, int* ID8, int* ID9, int* ID10, int* ID11, int* ID12, int* ID13, int* ID14, int* TotalBusSeats, int CurrentHour, int CurrentMins, char *NewPeriod1, int* TotalBookedSeats)
{
    int back;
    int i;
    int matchidnumber;
    printf("\nCANCEL A TICKET\n");
    printf("\n");
    printf("\nTime: %02d:%02d %cM\n", CurrentHour, CurrentMins, *NewPeriod1); // Displays Current Hour, Mins, and Period 
    printf("\n");

    if (CurrentHour % 2 == 0) // Displays available transportation route 
    {
        printf("ROUTE: Depart Manila - %02d:00 %cM : Arrive Laguna - %02d:00 %cM\n", CurrentHour, *NewPeriod1, CurrentHour + 1, *NewPeriod1);
    }else
    {
        if(CurrentHour == 11 && *NewPeriod1 == 'A')
        {
            printf("ROUTE: Depart Laguna - %02d:00 %cM : Arrive Manila - %02d:00 PM\n", CurrentHour, *NewPeriod1, CurrentHour + 1);
        }  
        else {
            printf("ROUTE: Depart Laguna - %02d:00 %cM : Arrive Manila - %02d:00 %cM\n", CurrentHour, *NewPeriod1, CurrentHour + 1, *NewPeriod1);
        }
    }
    printf("\n");
    printf("Cancel a ticket\n");
    printf("Total seats left: %d\n", *TotalBusSeats);
    printf("\n");
    printf("Seat layout: ");
    printf("\n");
    printf("\n");
    // Displays bus layout
    printf(" _______/    /_________________________________\n");
    printf("/                                              | \n");
    for (i = 1; i <= 14; i++) {
        int isBooked = 0;
        if (*s1 == i || *s2 == i || *s3 == i || *s4 == i || *s5 == i || *s6 == i || *s7 == i || *s8 == i || *s9 == i || *s10 == i || *s11 == i || *s12 == i || *s13 == i || *s14 == i) {
            isBooked = 1;
        }
        if (isBooked) {
            printf("| [X] ");
        } 
        else {
            printf("| [%d] ", i);
        } 
        
        if (i == 7)
        {
            printf("\t|\n");
        }
        else if (i == 14)
        {
            printf("\t|\n");
        }
        else if (i % 7 == 0) 
        {
            printf(" \n");
        }
    }
    printf("\\______________________________________________|");
    printf("\n");
    printf("\n");
    printf("Booked seats / seats that are no long available: \n");
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d \n", *s1, *s2, *s3, *s4, *s5, *s6, *s7, *s8, *s9, *s10, *s11, *s12, *s13, *s14); // Calls function that displays taken seats and ID numbers 
    printf("\n");
    IDnumAndSeat(s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, ID1, ID2, ID3, ID4, ID5, ID6, ID7, ID8, ID9, ID10, ID11, ID12, ID13, ID14);
    printf("\n");
    printf("Enter ID Number: ");
    scanf("%d", &matchidnumber); // Prompts user to enter a ID number 
    getchar(); // Input buffer if user inputs an invalid input other than an integer, specifically a character
    if (matchidnumber > 0){
    if (matchidnumber == *ID1) // ID number checks if there are bookings stored in the specific ID number 
    { 
        printf("\nBooking found!\n"); 
        printf("Seat: %d | ID number: %d\n", *s1, *ID1);
        printf("Do you want to cancel your ticket? [1] Yes or [0] No: ");
        int YesOrNo;
        scanf("%d", &YesOrNo); // Prompts user to select if they wish to cancel booking 
        getchar(); // input buffer if user inputs an invalid input other than an integer, specifically a character
        if (YesOrNo == 1) // If user selects 1 (Yes) Id number and seat will reset to 0
        {
            *ID1 = 0; // initialize the variable to 0 if the user selects 1
            *s1 = 0;
            *TotalBusSeats += 1;
            *TotalBookedSeats -= 1;
            printf("\nYou have succesfully cancelled your ticket!\n"); // Displays successful cancellation 
         } else if (YesOrNo == 0){
            printf("\nCancel unsuccessful\n"); // Displays if user selects 0 (No) the cancellation wont continue 
         }
         else 
         {
            printf("\nInvalid Input. Please try again\n"); // Displays if invalid input
         }
    }
    else if (matchidnumber == *ID2) // ID number checks if there are bookings stored in the specific ID number
    {   
        printf("\nBooking found!\n");
        printf("Seat: %d | ID number: %d\n", *s2, *ID2); 
        printf("Do you want to cancel your ticket? [1] Yes or [0] No: ");
        int YesOrNo;
        scanf("%d", &YesOrNo); // Prompts user to select if they wish to cancel booking 
        getchar(); // input buffer if user inputs an invalid input other than an integer, specifically a character
        if (YesOrNo == 1) // If user selects 1 (Yes) Id number and seat will reset to 0
        {
            *ID2 = 0; // initialize the variable to 0 if the user selects 0
            *s2 = 0;
            *TotalBusSeats += 1;
            *TotalBookedSeats -= 1;
            printf("\nYou have succesfully cancelled your ticket!\n"); // Displays successful cancellation 
         } else if (YesOrNo == 0){
            printf("\nCancel unsuccessful\n");  // Displays if user selects 0 (No) the cancellation wont continue 
         }
         else 
         {
            printf("\nInvalid Input. Please try again\n"); // Displays if invalid input
         }
    }
    else if (matchidnumber == *ID3) // ID number checks if there are bookings stored in the specific ID number
    {
        printf("\nBooking found!\n");
        printf("Seat: %d | ID number: %d\n", *s3, *ID3);
        printf("Do you want to cancel your ticket? [1] Yes or [0] No: ");
        int YesOrNo;
        scanf("%d", &YesOrNo); // Prompts user to select if they wish to cancel booking 
        getchar(); // input buffer if user inputs an invalid input other than an integer, specifically a character
        if (YesOrNo == 1) // If user selects 1 (Yes) Id number and seat will reset to 0
        {
            *ID3 = 0; // initialize the variable to 0 if the user selects 0
            *s3 = 0;
            *TotalBusSeats += 1;
            *TotalBookedSeats -= 1;
            printf("\nYou have succesfully cancelled your ticket!\n"); // Displays successful cancellation 
         } else if (YesOrNo == 0){
            printf("\nCancel unsuccessful\n"); // Displays if user selects 0 (No) the cancellation wont continue 
         }
         else 
         {
            printf("\nInvalid Input. Please try again\n"); // Displays if invalid input
         }
    }
    else if (matchidnumber == *ID4) // ID number checks if there are bookings stored in the specific ID number
    {
        printf("\nBooking found!\n");
        printf("Seat: %d | ID number: %d\n", *s4, *ID4);
        printf("Do you want to cancel your ticket? [1] Yes or [0] No: ");
        int YesOrNo;
        scanf("%d", &YesOrNo); // Prompts user to select if they wish to cancel booking 
        getchar(); // input buffer if user inputs an invalid input other than an integer, specifically a character
        if (YesOrNo == 1) // If user selects 1 (Yes) Id number and seat will reset to 0
        {
            *ID4 = 0; // initialize the variable to 0 if the user selects 0
            *s4 = 0;
            *TotalBusSeats += 1;
            *TotalBookedSeats -= 1;
            printf("\nYou have succesfully cancelled your ticket!\n"); // Displays successful cancellation 
         } else if (YesOrNo == 0){
            printf("\nCancel unsuccessful\n"); // Displays if user selects 0 (No) the cancellation wont continue 
         }
         else 
         {
            printf("\nInvalid Input. Please try again\n"); // Displays if invalid input
         }
    }
    else if (matchidnumber == *ID5) // ID number checks if there are bookings stored in the specific ID number
    {
        printf("\nBooking found!\n");
        printf("Seat: %d | ID number: %d\n", *s5, *ID5);
        printf("Do you want to cancel your ticket? [1] Yes or [0] No: ");
        int YesOrNo;
        scanf("%d", &YesOrNo); // Prompts user to select if they wish to cancel booking 
        getchar(); // input buffer if user inputs an invalid input other than an integer, specifically a character
        if (YesOrNo == 1) // If user selects 1 (Yes) Id number and seat will reset to 0
        {
            *ID5 = 0; // initialize the variable to 0 if the user selects 0
            *s5 = 0;
            *TotalBusSeats += 1;
            *TotalBookedSeats -= 1;
            printf("\nYou have succesfully cancelled your ticket!\n"); // Displays successful cancellation 
         } else if (YesOrNo == 0){
            printf("\nCancel unsuccessful\n"); // Displays if user selects 0 (No) the cancellation wont continue 
         }
         else 
         {  
            printf("\nInvalid Input. Please try again\n"); // Displays if invalid input
         }
    }
    else if (matchidnumber == *ID6) // ID number checks if there are bookings stored in the specific ID number
    {
        printf("\nBooking found!\n");
        printf("Seat: %d | ID number: %d\n", *s6, *ID6);
        printf("Do you want to cancel your ticket? [1] Yes or [0] No: ");
        int YesOrNo;
        scanf("%d", &YesOrNo); // Prompts user to select if they wish to cancel booking 
        getchar(); // input buffer if user inputs an invalid input other than an integer, specifically a character
        if (YesOrNo == 1) // If user selects 1 (Yes) Id number and seat will reset to 0
        {
            *ID6 = 0; // initialize the variable to 0 if the user selects 0
            *s6 = 0;
            *TotalBusSeats += 1;
            *TotalBookedSeats -= 1;
            printf("\nYou have succesfully cancelled your ticket!\n"); // Displays successful cancellation 
         } else if (YesOrNo == 0){
            printf("\nCancel unsuccessful\n"); // Displays if user selects 0 (No) the cancellation wont continue
         }
         else 
         {
            printf("\nInvalid Input. Please try again\n"); // Displays if invalid input
         }
    }
    else if (matchidnumber == *ID7) // ID number checks if there are bookings stored in the specific ID number
    {
        printf("\nBooking found!\n");
        printf("Seat: %d | ID number: %d\n", *s7, *ID7);
        printf("Do you want to cancel your ticket? [1] Yes or [0] No: ");
        int YesOrNo;
        scanf("%d", &YesOrNo);  // Prompts user to select if they wish to cancel booking 
        getchar(); // input buffer if user inputs an invalid input other than an integer, specifically a character
        if (YesOrNo == 1) // If user selects 1 (Yes) Id number and seat will reset to 0
        {
            *ID7 = 0; // initialize the variable to 0 if the user selects 0
            *s7 = 0;
            *TotalBusSeats += 1;
            *TotalBookedSeats -= 1;
            printf("\nYou have succesfully cancelled your ticket!\n"); // Displays successful cancellation 
         } else if (YesOrNo == 0){
            printf("\nCancel unsuccessful\n"); // Displays if user selects 0 (No) the cancellation wont continue
         }
         else 
         {
            printf("\nInvalid Input. Please try again\n"); // Displays if invalid input
         }
    }
    else if (matchidnumber == *ID8) // ID number checks if there are bookings stored in the specific ID number
    {
        printf("\nBooking found!\n");
        printf("Seat: %d | ID number: %d\n", *s8, *ID8);
        printf("Do you want to cancel your ticket? [1] Yes or [0] No: ");
        int YesOrNo;
        scanf("%d", &YesOrNo); // Prompts user to select if they wish to cancel booking 
        getchar(); // input buffer if user inputs an invalid input other than an integer, specifically a character
        if (YesOrNo == 1) // If user selects 1 (Yes) Id number and seat will reset to 0
        {
            *ID8 = 0; // initialize the variable to 0 if the user selects 0
            *s8 = 0;
            *TotalBusSeats += 1;
            *TotalBookedSeats -= 1;
            printf("\nYou have succesfully cancelled your ticket!\n"); // Displays successful cancellation 
         } else if (YesOrNo == 0){
            printf("\nCancel unsuccessful\n"); // Displays if user selects 0 (No) the cancellation wont continue
         }
         else 
         {
            printf("\nInvalid Input. Please try again\n"); // Displays if invalid input
         }
    }
    else if (matchidnumber == *ID9) // ID number checks if there are bookings stored in the specific ID number
    {
        printf("\nBooking found!\n");
        printf("Seat: %d | ID number: %d\n", *s9, *ID9);
        printf("Do you want to cancel your ticket? [1] Yes or [0] No: ");
        int YesOrNo;
        scanf("%d", &YesOrNo); // Prompts user to select if they wish to cancel booking 
        getchar(); // input buffer if user inputs an invalid input other than an integer, specifically a character
        if (YesOrNo == 1) // If user selects 1 (Yes) Id number and seat will reset to 0
        {
            *ID9 = 0; // initialize the variable to 0 if the user selects 0
            *s9 = 0;
            *TotalBusSeats += 1;
            *TotalBookedSeats -= 1;
            printf("\nYou have succesfully cancelled your ticket!\n"); // Displays successful cancellation 
         } else if (YesOrNo == 0){
            printf("\nCancel unsuccessful\n"); // Displays if user selects 0 (No) the cancellation wont continue
         }
         else 
         {
            printf("\nInvalid Input. Please try again\n"); // Displays if invalid input
         }
    }
    else if (matchidnumber == *ID10) // ID number checks if there are bookings stored in the specific ID number
    {
        printf("\nBooking found!\n");
        printf("Seat: %d | ID number: %d\n", *s10, *ID10);
        printf("Do you want to cancel your ticket? [1] Yes or [0] No: ");
        int YesOrNo;
        scanf("%d", &YesOrNo); // Prompts user to select if they wish to cancel booking 
        getchar(); // input buffer if user inputs an invalid input other than an integer, specifically a character
        if (YesOrNo == 1) // If user selects 1 (Yes) Id number and seat will reset to 0
        {
            *ID10 = 0; // initialize the variable to 0 if the user selects 0
            *s10 = 0;
            *TotalBusSeats += 1;
            *TotalBookedSeats -= 1;
            printf("\nYou have succesfully cancelled your ticket!\n"); // Displays successful cancellation 
         } else if (YesOrNo == 0){
            printf("\nCancel unsuccessful\n"); // Displays if user selects 0 (No) the cancellation wont continue
         }
         else 
         {
            printf("\nInvalid Input. Please try again\n"); // Displays if invalid input
         }
    }
    else if (matchidnumber == *ID11) // ID number checks if there are bookings stored in the specific ID number
    {
        printf("\nBooking found!\n");
        printf("Seat: %d | ID number: %d\n", *s11, *ID11);
        printf("Do you want to cancel your ticket? [1] Yes or [0] No: ");
        int YesOrNo;
        scanf("%d", &YesOrNo); // Prompts user to select if they wish to cancel booking
        getchar(); // input buffer if user inputs an invalid input other than an integer, specifically a character
        if (YesOrNo == 1) // If user selects 1 (Yes) Id number and seat will reset to 0
        {
            *ID11 = 0; // initialize the variable to 0 if the user selects 0
            *s11 = 0;
            *TotalBusSeats += 1;
            *TotalBookedSeats -= 1;
            printf("\nYou have succesfully cancelled your ticket!\n"); // Displays successful cancellation 
         } else if (YesOrNo == 0){
            printf("\nCancel unsuccessful\n"); // Displays if user selects 0 (No) the cancellation wont continue
         }
         else 
         {
            printf("\nInvalid Input. Please try again\n"); // Displays if invalid input
         }
    }
    else if (matchidnumber == *ID12) // ID number checks if there are bookings stored in the specific ID number
    {
        printf("\nBooking found!\n");
        printf("Seat: %d | ID number: %d\n", *s12, *ID12);
        printf("Do you want to cancel your ticket? [1] Yes or [0] No: ");
        int YesOrNo;
        scanf("%d", &YesOrNo); // Prompts user to select if they wish to cancel booking
        getchar(); // input buffer if user inputs an invalid input other than an integer, specifically a character
        if (YesOrNo == 1) // If user selects 1 (Yes) Id number and seat will reset to 0
        {
            *ID12 = 0; // initialize the variable to 0 if the user selects 0
            *s12 = 0;
            *TotalBusSeats += 1;
            *TotalBookedSeats -= 1;
            printf("\nYou have succesfully cancelled your ticket!\n"); // Displays successful cancellation  
         } else if (YesOrNo == 0){
            printf("\nCancel unsuccessful\n"); // Displays if user selects 0 (No) the cancellation wont continue
         }
         else 
         {
            printf("\nInvalid Input. Please try again\n"); // Displays if invalid input
         }
    }
    else if (matchidnumber == *ID13) // ID number checks if there are bookings stored in the specific ID number
    {
        printf("\nBooking found!\n");
        printf("Seat: %d | ID number: %d\n", *s13, *ID13);
        printf("Do you want to cancel your ticket? [1] Yes or [0] No: ");
        int YesOrNo;
        scanf("%d", &YesOrNo); // Prompts user to select if they wish to cancel booking
        getchar(); // input buffer if user inputs an invalid input other than an integer, specifically a character
        if (YesOrNo == 1) // If user selects 1 (Yes) Id number and seat will reset to 0
        {
            *ID13 = 0; // initialize the variable to 0 if the user selects 0
            *s13 = 0;
            *TotalBusSeats += 1;
            *TotalBookedSeats -= 1;
            printf("\nYou have succesfully cancelled your ticket!\n"); // Displays successful cancellation
         } else if (YesOrNo == 0){
            printf("\nCancel unsuccessful\n"); // Displays if user selects 0 (No) the cancellation wont continue
         }
         else 
         {
            printf("\nInvalid Input. Please try again\n"); // Displays if invalid input
         }
    }
    else if (matchidnumber == *ID14) // ID number checks if there are bookings stored in the specific ID number
    {
        printf("\nBooking found!\n");
        printf("Seat: %d | ID number: %d\n", *s14, *ID14);
        printf("Do you want to cancel your ticket? [1] Yes or [0] No: ");
        int YesOrNo;
        scanf("%d", &YesOrNo); // Prompts user to select if they wish to cancel booking
        getchar(); // input buffer if user inputs an invalid input other than an integer, specifically a character
        if (YesOrNo == 1) // If user selects 1 (Yes) Id number and seat will reset to 0
        {
            *ID14 = 0; // initialize the variable to 0 if the user selects 0
            *s14 = 0;
            *TotalBusSeats += 1;
            *TotalBookedSeats -= 1;
            printf("\nYou have succesfully cancelled your ticket!\n"); // Displays successful cancellation
         } else if (YesOrNo == 0){
            printf("\nCancel unsuccessful\n"); // Displays if user selects 0 (No) the cancellation wont continue
         }
         else 
         {
            printf("\nInvalid Input. Please try again\n"); // Displays if invalid input
         }
    }
    else if (*s1 == 0 || *s2 == 0 || *s3 == 0 || *s4 == 0 || *s5 == 0 || *s6 == 0 || *s7 == 0 || *s8 == 0 || *s9 == 0 || *s10 == 0 || *s11 == 0 || *s12 == 0 || *s13 == 0 || *s14 == 0) // Checks if theres a valid id number, but no seat was taken 
    { 
        printf("No records found\n");
    }
    else 
    { 
        printf("No records found\n");
    }
    }
    else 
    {
        printf("No records found\n"); // Display if ID number is not valid 
    }
    matchidnumber = 0; // Resets variable to 0 at the end of the function
    printf("\n");
    system("pause");
    system("CLS");
}
/*This function allows the user to change the departure time
Precondition: Updates of departure time should only be of future time, AM period should range until 4 - 11 AM, PM period should range until 2-7 PM.
@param *s1...*s14 stores the seat number of the bus
@param *ID1...*ID14 stores ID number 
@param *TotalBusSeats displays available seats. Decrements to 1 every time a seat has been booked
@param CurrentHour, CurrentMins, and period1 displays and stores the time the program is running 
@param *NewHour, *NewPeriod, and period2 updates the current time of the program
@param *Flag sets as an indicator that past time is done
@return updated time of the program
*/
void executeUpdateDepartureTime(int *s1, int *s2, int *s3, int *s4, int *s5, int *s6, int *s7, int *s8, int *s9, int *s10, int *s11, int *s12, int *s13, int* s14, int* ID1, int* ID2, int* ID3, int* ID4, int* ID5, int* ID6, int* ID7, int* ID8, int* ID9, int* ID10, int* ID11, int* ID12, int* ID13, int* ID14, int* TotalBusSeats, int currentHour, int currentMins, char period1, int* NewHour, int* NewMinutes, char* NewPeriod1, int* Flag, char period2)
{
   int password = 1111;
   int pass;
   int back; 
   printf("\n");
   printf("Enter password first: "); // Asks user to enter password. Password: 1111
   scanf("%d", &pass);

   if (pass == password)
   {
    printf("\nHello agent!\n");

    printf("\nCurrent departure time: %02d:%02d %cM\n", *NewHour, *NewMinutes, *NewPeriod1); // Display current time 
    printf("Change Departure time [AM / PM]: "); 
    scanf("%02d:%02d %c%c", NewHour, NewMinutes, NewPeriod1, &period2); // Asks user to input time 

   if ((*NewPeriod1 == 'A' || *NewPeriod1 == 'P') && *NewHour >= 2 && *NewHour <= 12 && *NewMinutes <= 59 && period2 == 'M') // Checks condition if input time is within the range of available trips 
   {
        if (*NewPeriod1 == 'A' && *NewHour > currentHour && *NewHour != currentHour && *NewHour >= 4 && *NewHour <= 11 && !(*Flag)) // Compares New Time and Current Time for AM 
        {
            if (*NewHour % 2 == 0) // If satisfied, checks route if it is manila to laguna 
            {
                printf("New time: %02d:%02d %c%c\n", *NewHour, *NewMinutes, *NewPeriod1, period2); // Displays time 
                printf("Route available: Depart Manila - Arrive Laguna\n"); // Detects available route
                currentHour = *NewHour; // Updates current hour 
                currentMins = *NewMinutes;  
                period1 = *NewPeriod1;

                *s1 = 0, *s2 = 0, *s3 = 0, *s4 = 0, *s5 = 0, *s6 = 0, *s7 = 0, *s8 = 0, *s9 = 0, *s10 = 0, *s11 = 0, *s12 = 0, *s13 = 0, *s14 = 0; 
                *ID1 = 0, *ID2 = 0, *ID3 = 0, *ID4 = 0, *ID5 = 0, *ID6 = 0, *ID7 = 0, *ID8 = 0, *ID9= 0, *ID10 = 0, *ID11 = 0, *ID12= 0, *ID13 = 0, *ID14 = 0; // Resets values to 0
                *TotalBusSeats = 14; 
                printf("\nDeparture time updated!\n");
                system("pause");
                system("CLS");
            }
            else // Determines that it is laguna to manila
            {
                printf("New time: %02d:%02d %c%c\n", *NewHour, *NewMinutes, *NewPeriod1, period2); // Displays time 
                printf("Route available: Depart Laguna - Arrive Manila\n"); // Detects available route
                currentHour = *NewHour; // Updates current hour
                currentMins = *NewMinutes;  
                period1 = *NewPeriod1;

                *s1 = 0, *s2 = 0, *s3 = 0, *s4 = 0, *s5 = 0, *s6 = 0, *s7 = 0, *s8 = 0, *s9 = 0, *s10 = 0, *s11 = 0, *s12 = 0, *s13 = 0, *s14 = 0; 
                *ID1 = 0, *ID2 = 0, *ID3 = 0, *ID4 = 0, *ID5 = 0, *ID6 = 0, *ID7 = 0, *ID8 = 0, *ID9= 0, *ID10 = 0, *ID11 = 0, *ID12= 0, *ID13 = 0, *ID14 = 0; // Resets values to 0
                *TotalBusSeats = 14;
                printf("\nDeparture time updated!\n");
                system("pause");
                system("CLS");
            }
        }
        else if (*NewHour == currentHour && *NewPeriod1 == 'P' && *Flag == 0) // Compares New Time and Current Time for PM. This is an entry point condition for PM. Will start to negate after it is satisfied 
        {
            *Flag = 1; // Sets a flag that AM is done. Will start to negate AM period. 
            if (*NewHour % 2 == 0) // If satisfied, checks route if it is manila to laguna 
            {
                printf("New time: %02d:%02d %c%c\n", *NewHour, *NewMinutes, *NewPeriod1, period2); // Displays time 
                printf("Route available: Depart Manila - Arrive Laguna\n"); // Detects available route
                currentHour = *NewHour; // Updates current hour 
                currentMins = *NewMinutes;  
                period1 = *NewPeriod1;
                
                *s1 = 0, *s2 = 0, *s3 = 0, *s4 = 0, *s5 = 0, *s6 = 0, *s7 = 0, *s8 = 0, *s9 = 0, *s10 = 0, *s11 = 0, *s12 = 0, *s13 = 0, *s14 = 0; 
                *ID1 = 0, *ID2 = 0, *ID3 = 0, *ID4 = 0, *ID5 = 0, *ID6 = 0, *ID7 = 0, *ID8 = 0, *ID9= 0, *ID10 = 0, *ID11 = 0, *ID12= 0, *ID13 = 0, *ID14 = 0; // Resets values to 0
                *TotalBusSeats = 14;
                printf("\nDeparture time updated!\n");
                system("pause");
                system("CLS");
            } 
            else // Determines that it is laguna to manila
            {
                printf("New time: %02d:%02d %c%c\n", *NewHour, *NewMinutes, *NewPeriod1, period2); // Displays time
                printf("Route available: Depart Laguna - Arrive Manila\n"); // Detects available route
                currentHour = *NewHour; // Updates current hour
                currentMins = *NewMinutes;  
                period1 = *NewPeriod1;

                *s1 = 0, *s2 = 0, *s3 = 0, *s4 = 0, *s5 = 0, *s6 = 0, *s7 = 0, *s8 = 0, *s9 = 0, *s10 = 0, *s11 = 0, *s12 = 0, *s13 = 0, *s14 = 0; 
                *ID1 = 0, *ID2 = 0, *ID3 = 0, *ID4 = 0, *ID5 = 0, *ID6 = 0, *ID7 = 0, *ID8 = 0, *ID9= 0, *ID10 = 0, *ID11 = 0, *ID12= 0, *ID13 = 0, *ID14 = 0; // Resets values to 0
                *TotalBusSeats = 14;
                printf("\nDeparture time updated!\n");
                system("pause");
                system("CLS");
            }
        }
        else if (*NewHour < currentHour && *NewPeriod1 == 'P' && *Flag == 0) // Compares New Time and Current Time for PM. This is an entry point condition for PM. Will start to negate after it is satisfied 
        {
            *Flag = 1; // Sets a flag that AM is done. Will start to negate AM period.
            if (*NewHour % 2 == 0) // If satisfied, checks route if it is manila to laguna
            {
                printf("New time: %02d:%02d %c%c\n", *NewHour, *NewMinutes, *NewPeriod1, period2); // Displays time 
                printf("Route available: Depart Manila - Arrive Laguna\n"); // Detects available route
                currentHour = *NewHour; // Updates current hour 
                currentMins = *NewMinutes;  
                period1 = *NewPeriod1;

                *s1 = 0, *s2 = 0, *s3 = 0, *s4 = 0, *s5 = 0, *s6 = 0, *s7 = 0, *s8 = 0, *s9 = 0, *s10 = 0, *s11 = 0, *s12 = 0, *s13 = 0, *s14 = 0; 
                *ID1 = 0, *ID2 = 0, *ID3 = 0, *ID4 = 0, *ID5 = 0, *ID6 = 0, *ID7 = 0, *ID8 = 0, *ID9= 0, *ID10 = 0, *ID11 = 0, *ID12= 0, *ID13 = 0, *ID14 = 0; // Resets values to 0
                *TotalBusSeats = 14;
                printf("\nDeparture time updated!\n");
                system("pause");
                system("CLS");
            }
            else // Determines that it is laguna to manila
            {
                printf("New time: %02d:%02d %c%c\n", *NewHour, *NewMinutes, *NewPeriod1, period2); // Displays time
                printf("Route available: Depart Laguna - Arrive Manila\n"); // Detects available route
                currentHour = *NewHour; // Updates current hour
                currentMins = *NewMinutes;  
                period1 = *NewPeriod1;
                
                *s1 = 0, *s2 = 0, *s3 = 0, *s4 = 0, *s5 = 0, *s6 = 0, *s7 = 0, *s8 = 0, *s9 = 0, *s10 = 0, *s11 = 0, *s12 = 0, *s13 = 0, *s14 = 0; 
                *ID1 = 0, *ID2 = 0, *ID3 = 0, *ID4 = 0, *ID5 = 0, *ID6 = 0, *ID7 = 0, *ID8 = 0, *ID9= 0, *ID10 = 0, *ID11 = 0, *ID12= 0, *ID13 = 0, *ID14 = 0; // Resets values to 0
                *TotalBusSeats = 14;
                printf("\nDeparture time updated!\n");
                system("pause");
                system("CLS");
            }
        }
        else if (*NewPeriod1  == 'P' && *NewHour > currentHour && *NewHour != currentHour && *NewHour >= 2 && *NewHour <= 7) // Main condition for PM time 
        {
            *Flag = 1;  // Sets a flag that AM is done. Will start to negate AM period.
            if (*NewHour % 2 == 0) // If satisfied, checks route if it is manila to laguna
            {
                printf("New time: %02d:%02d %c%c\n", *NewHour, *NewMinutes, *NewPeriod1, period2); // Displays time 
                printf("Route available: Depart Manila - Arrive Laguna\n"); // Detects available route
                currentHour = *NewHour; // Updates current hour 
                currentMins = *NewMinutes;  
                period1 = *NewPeriod1;

                *s1 = 0, *s2 = 0, *s3 = 0, *s4 = 0, *s5 = 0, *s6 = 0, *s7 = 0, *s8 = 0, *s9 = 0, *s10 = 0, *s11 = 0, *s12 = 0, *s13 = 0, *s14 = 0; 
                *ID1 = 0, *ID2 = 0, *ID3 = 0, *ID4 = 0, *ID5 = 0, *ID6 = 0, *ID7 = 0, *ID8 = 0, *ID9= 0, *ID10 = 0, *ID11 = 0, *ID12= 0, *ID13 = 0, *ID14 = 0; // Resets values to 0
                *TotalBusSeats = 14;
                printf("\nDeparture time updated!\n");
                system("pause");
                system("CLS");
            }
            else // Determines that it is laguna to manila
            {
                printf("New time: %02d:%02d %c%c\n", *NewHour, *NewMinutes, *NewPeriod1, period2); // Displays time
                printf("Route available: Depart Laguna - Arrive Manila\n"); // Detects available route
                currentHour = *NewHour; // Updates current hour
                currentMins = *NewMinutes;  
                period1 = *NewPeriod1;

                *s1 = 0, *s2 = 0, *s3 = 0, *s4 = 0, *s5 = 0, *s6 = 0, *s7 = 0, *s8 = 0, *s9 = 0, *s10 = 0, *s11 = 0, *s12 = 0, *s13 = 0, *s14 = 0; 
                *ID1 = 0, *ID2 = 0, *ID3 = 0, *ID4 = 0, *ID5 = 0, *ID6 = 0, *ID7 = 0, *ID8 = 0, *ID9= 0, *ID10 = 0, *ID11 = 0, *ID12= 0, *ID13 = 0, *ID14 = 0; // Resets values to 0
                *TotalBusSeats = 14; 
                printf("\nDeparture time updated!\n");
                system("pause");
                system("CLS");
            }
        }
        else 
        {   
            if (*NewHour == 12 && *NewPeriod1 == 'P') 
            {
            *NewHour = currentHour; // Current hour remains the same 
            *NewMinutes = currentMins;
            *NewPeriod1 = period1;
            printf("Time cannot be updated!\n");
            printf("\n");
            printf("Input any digit to go back to main menu: "); // Prompts user to go back to main menu 
            scanf("%d", &back);
            getchar();
            }
            else 
            {
            *NewHour = currentHour; // Current hour remains the same 
            *NewMinutes = currentMins;
            *NewPeriod1 = period1;
            printf("Time cannot be updated!\n");
            printf("\n");
            system("pause");
            system("CLS");
            }
        }
    }
    else 
    {
        *NewHour = currentHour;
        *NewMinutes = currentMins;
        *NewPeriod1 = period1;
        printf("Invalid time\n");
        printf("\n");
        system("pause");
        system("CLS");
    }
  }
else 
   {
    printf("Incorrect password\n");
    printf("\n");
    system("pause");
    system("CLS"); // Displays if password is incorrect
   }
}
/*This function displays the schedule of the shuttle service 
Precondition: Updated time shouldnt be of past time, time should be within the range of available trip schedules. 
@param CurrentHour, CurrentMins, and *NewPeriod1 displays and stores the current hour of the program 
@return schedule of shuttle service
*/
void executeDisplaySchedule(int CurrentHour, int CurrentMins, char *NewPeriod1)
{
    int back;
    int i; 
    printf("\n");
    printf("DLSU SHUTTLE SERVICE SCHEDULE\n");
    printf("\nTime: %02d:%02d %cM\n", CurrentHour, CurrentMins, *NewPeriod1);
    printf("\n");
    printf("Trip status: [N]ext : [P]resent : [D]one\n"); // Displays trip status of schedule 
    printf("\n");
    for (i = 1; i <= 8; i++) // Loops AM time 
    {
        int TripHour = 3 + i; // Initializes Trip hour to 4 
        int Minutes = 0;
        char status; 

        if (TripHour > CurrentHour && *NewPeriod1 == 'A') // Condition for Next 
        {
            status = 'N';
        }
        else if (TripHour == CurrentHour &&  *NewPeriod1 == 'A') // Condition for Present 
        {
            status = 'P';
        }
        else if ((TripHour < CurrentHour && *NewPeriod1 == 'A') || (*NewPeriod1 == 'P')) // Condition for Done 
        {
            status = 'D';
        }

        if (TripHour % 2 == 0)
        {
            printf("[%d] Depart Manila: %02d:%02d AM : Arrive Laguna: %02d:%02d AM - [%c]", i, TripHour, Minutes, TripHour + 1, Minutes, status); // Checks if time is manila to laguna 
        }
        else // Determines if laguna to manila
        {
            if (TripHour == 11)
            {
                printf("[%d] Depart Laguna: %02d:%02d AM : Arrive Manila: %02d:%02d PM - [%c]", i, TripHour, Minutes, TripHour + 1, Minutes, status);
            }
            else 
            {
                printf("[%d] Depart Laguna: %02d:%02d AM : Arrive Manila: %02d:%02d AM - [%c]", i, TripHour, Minutes, TripHour + 1, Minutes, status);
            }
        }
        printf("\n");
    
    }
    printf("\n");
    for (i = 1; i <= 6; i++) // Loops PM time 
    {
        int TripHour = 1 + i; // Initializes Trip hour to 2
        int Minutes = 0;
        char status; 

        if ((TripHour > CurrentHour && *NewPeriod1 == 'P') || (*NewPeriod1 == 'A')) // Condition for Next 
        {
            status = 'N';
        }
        else if (TripHour == CurrentHour && *NewPeriod1 == 'P') // Condition for Present 
        {
            status = 'P';
        }
        else if (TripHour < CurrentHour && *NewPeriod1 == 'P') // Condition for Done 
        {
            status = 'D';
        }

        if (TripHour % 2 == 0)
        { 
            printf("[%d] Depart Manila: %02d:%02d PM : Arrive Laguna: %02d:%02d PM - [%c]", i + 8, TripHour, Minutes, TripHour + 1, Minutes, status); // Checks if time is manila to laguna 
        }
        else // Determines if laguna to manila
        {
            printf("[%d] Depart Laguna: %02d:%02d PM : Arrive Manila: %02d:%02d PM - [%c]", i + 8, TripHour, Minutes, TripHour + 1, Minutes, status);
        }
        printf("\n");
    
    }
    printf("\n");
    system("pause");
    system("CLS");
}
/*This function executes the Close Application 
Precondition: If user chooses to end the program it should end the program, if not, it should loop back to the main menu
@param @param *s1...*s14 stores the seat number of the bus
@param *ID1...*ID14 stores ID number 
@param *TotalBusSeats displays available seats. Decrements to 1 every time a seat has been booked 
@param *TotalBookedSeats counts the number of tickets booked during the run of the entire program. Increments when booked, decrements when cancelled
@param *YesOrNo determines if the progam should end or not
@return the cancellation of the program
*/
void executeCloseApplication(int *s1, int *s2, int *s3, int *s4, int *s5, int *s6, int *s7, int *s8, int *s9, int *s10, int *s11, int *s12, int *s13, int* s14, int* ID1, int* ID2, int* ID3, int* ID4, int* ID5, int* ID6, int* ID7, int* ID8, int* ID9, int* ID10, int* ID11, int* ID12, int* ID13, int* ID14, int* TotalBusSeats, int *TotalBookedSeats, int *YesOrNo)
{

        printf("\nAre you sure you want terminate the program?\n"); // As
        printf("\n");
        printf("All data will be removed");
        printf("\n");
        printf("[1] Yes or [0] No: ");
        scanf("%d", YesOrNo);
        getchar(); // To handle any invalid inputs other than integers 
        if (*YesOrNo == 1) // Ends program
        {
            printf("\nThank you for using the DLSU Online Shuttle Service\n");
            printf("===================================================\n");
            printf("Total Booked seats: %d\n", *TotalBookedSeats);
            *s1 = 0, *s2 = 0, *s3 = 0, *s4 = 0, *s5 = 0, *s6 = 0, *s7 = 0, *s8 = 0, *s9 = 0, *s10 = 0, *s11 = 0, *s12 = 0, *s13 = 0, *s14 = 0; 
            *ID1 = 0, *ID2 = 0, *ID3 = 0, *ID4 = 0, *ID5 = 0, *ID6 = 0, *ID7 = 0, *ID8 = 0, *ID9= 0, *ID10 = 0, *ID11 = 0, *ID12= 0, *ID13 = 0, *ID14 = 0; // Resets values to 0
            *TotalBusSeats = 14;
            printf("\n");
            printf("Program and designed by Jedidiah Kyle Martin Julian\n");
        } else if (*YesOrNo == 0){ 
            printf("\nTermination cancelled\n"); 
            system("pause");
            system("CLS");
        } 
        else {
            printf("\nTermination cancelled\n");
            system("pause");
            system("CLS");
        }
}
/*Executes main menu 
Precondition: User selects what function they want to execute. Inputs are of characters
@param Options stores the main menu option
@param *IDnum is the temporary place holder to check if ID number is valid before storing it
@param *s1...*s14 stores the seat number of the bus
@param *ID1...*ID14 stores ID number 
@param *TotalBusSeats displays available seats. Decrements to 1 every time a seat has been booked 
@param CurrentHour, CurrentMins, period1 displays and stores the time the program is running 
@param *NewHour, *NewPeriod, and period2 updates the current time of the program
@param *Flag sets as an indicator that past time is done
@param *TotalBookedSeats counts the number of tickets booked during the run of the entire program. Increments when booked, decrements when cancelled
@param *YesOrNo determines if the progam should end or not
@return option to execute main menu
*/
void executeMenu(char Options, int *IDnum, int *s1, int *s2, int *s3, int *s4, int *s5, int *s6, int *s7, int *s8, int *s9, int *s10, int *s11, int *s12, int *s13, int* s14, int* ID1, int* ID2, int* ID3, int* ID4, int* ID5, int* ID6, int* ID7, int* ID8, int* ID9, int* ID10, int* ID11, int* ID12, int* ID13, int* ID14, int* TotalBusSeats, int CurrentHour, int CurrentMins, char period1, int *NewHour, int *NewMinutes, char *NewPeriod1, int* Flag, char period2, int* TotalBookedSeats, int *YesOrNo){
// Executes the main menu
    switch (Options){
        case 'A':
        case 'a':
            executeBookTicket(s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, IDnum, ID1, ID2, ID3, ID4, ID5, ID6, ID7, ID8, ID9, ID10, ID11, ID12, ID13, ID14, TotalBusSeats, CurrentHour, CurrentMins, NewPeriod1, TotalBookedSeats);
            break;
        case 'B':
        case 'b':
            executeCancelBooking(s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, ID1, ID2, ID3, ID4, ID5, ID6, ID7, ID8, ID9, ID10, ID11, ID12, ID13, ID14, TotalBusSeats, CurrentHour, CurrentMins, NewPeriod1, TotalBookedSeats);
            break;
        case 'C':
        case 'c':
            executeDisplaySchedule(CurrentHour, CurrentMins, NewPeriod1);
            break;
        case 'D':
        case 'd':
            executeUpdateDepartureTime(s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, ID1, ID2, ID3, ID4, ID5, ID6, ID7, ID8, ID9, ID10, ID11, ID12, ID13, ID14, TotalBusSeats, CurrentHour, CurrentMins, period1, NewHour, NewMinutes, NewPeriod1, Flag, period2);
            break;
        case 'E':
        case 'e':
            executeCloseApplication(s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, ID1, ID2, ID3, ID4, ID5, ID6, ID7, ID8, ID9, ID10, ID11, ID12, ID13, ID14, TotalBusSeats, TotalBookedSeats, YesOrNo);
            break;
        default:
            printf("Invalid input. Please Try again\n");
        }
}

int main()
{
    //For functions A and B
    char optionmenu;
    int IDNum = 0;
    //Seats
    int s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0, s9 = 0, s10 = 0, s11 = 0, s12 = 0, s13 = 0, s14 = 0;
    //ID Number
    int ID1 = 0, ID2 = 0, ID3 = 0, ID4 = 0, ID5 = 0, ID6 = 0, ID7 = 0, ID8 = 0, ID9= 0, ID10 = 0, ID11 = 0, ID12= 0, ID13 = 0, ID14 = 0;
    int totalseats = 14;
    int* TotalBusSeats = &totalseats;
    // for function C and D
    int CurrentHour= 4;
    int CurrentMins = 0;
    char period1 = 'A';
    int futuretime = 0; 
   
    int* NewHour = &CurrentHour; 
    int* NewMinutes = &CurrentMins;
    char* NewPeriod1 = &period1;
    int* Flag = &futuretime; 
    char period2 = 'M';

    int Total = 0;
    int* TotalBookedSeats = &Total;
    int EndProgram = 0;
    int* YesOrNo = &EndProgram;
   
    do // Loops program
    {
    displayOpening(); 
    printf("Current time: %02d:%02d %cM\n", CurrentHour, CurrentMins, *NewPeriod1); // Displays current time 
    printf("\n");
    displayMenu(); 
    
    printf("\n");
    printf("How can we help you today? ");
    scanf(" %c", &optionmenu);
    system("CLS");
    executeMenu(optionmenu, &IDNum, &s1, &s2, &s3, &s4, &s5, &s6, &s7, &s8, &s9, &s10, &s11, &s12, &s13, &s14, &ID1, &ID2, &ID3, &ID4, &ID5, &ID6, &ID7, &ID8, &ID9, &ID10, &ID11, &ID12, &ID13, &ID14, TotalBusSeats, CurrentHour, CurrentMins, period1, NewHour, NewMinutes, NewPeriod1, Flag, period2, TotalBookedSeats, YesOrNo);

    } while (EndProgram != 1); // End program
    
    return 0;
}

/******************************************************************
This is to certify that this project is my own work, based on my
personal efforts in studying and applying the concepts learned. I
have constructed the functions and their respective algorithms
and corresponding code by myself. The program was run, tested, and
debugged by my own efforts. I further certify that I have not
copied in part or whole or otherwise plagiarized the work of other
students and/or persons.
<Julian, Jedidiah Kyle Martin>, DLSU ID# <12307211>
******************************************************************/
