## MovieBookingSystem

#### Introduction
This is a Movie Ticket Manager which can book seats in a theatre based on the preference of the users.

### Functionality
- Adds a Screen
- Reserve a Seat
- Get unreserved seats for a row
- Suggest seats based on User preference
- Get live status of seats
- __Note: It takes care of aisle seats while booking seats and also take cares of it for user preferences__

### How to use the system

To add a screen
Provide : Screen Name, Row Number, Total seats per row, List of aisle seats for each row
Format of command: <Screen-Name><No-of-rows><Total-seats-per-row><Space-separated-list-of-aisle-seats>
Example: Screen1 15 10 4 5 8 9

#### To Reserve a Seat
- **Provide:** Screen Name, Row Number, List of seats to be reserved
- **Format of command:** reserve-seat <Screen-name> <row-number> <list-of-seats-to-be-reserved>
- **Example:** reserve-seat Screen1 4 5 6 7

#### To get Unreserved Seats
- **Provide:** Screen Name, Row Number
- **Format of command:** get-unreserved-seats <Screen-name> <row-number>
- **Example:** get-Unreserved-seats Screen1 4

#### To suggest seats based on user preference
- **Provide:** Screen Name, Number of Seats, Row number, Choice of seat Number
- **Format of command:** suggest-contiguous-seats <Screen-name> <number-of-seats> <row-number> <choice-of-seat-number>
- **Example:** suggest-contiguous-seats Screen1 3 3 4
- **Note: It will suggest contiguous seats, and it will take care of aisle seats and wont consider them contiguous**

#### To print the live seats status
- **command:** Print_Seats()


