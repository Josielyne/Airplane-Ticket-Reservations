# Airplane-Ticket-Reservations
A program that lets people reserve seats on an airplane for an airline.
The main tool for this program is a two-dimensional array filled with 1s and 0s that represent the seats taken and seats available. The dimensions of the array correspond to how 
many rows and columns there are in the plane. 
1s represet taken seats and 0s represent available seats. Everytime the user makes a reservation, the array is updated at the user's chosen
location to a 1. The map, or the display for the seating, is also updated each time through a display function. For the user input, the rows go by letters starting at A and
the columns go by numbers starting at 1. A1 would be a proper user input corresponding with [0,0] in the array.
