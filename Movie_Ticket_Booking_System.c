#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Movies_ctr{
    char name[50];
    int availableSeats;
    float price;    //including gst
};

struct Movies_ctr movies_arr[10];
int num_of_Movies = 0;    //globally declared as zero

void addMovie(char name[], int total_Seats, float final_price){
    // A prototype of a counter that can store only upto 4 movies
    if(num_of_Movies < 10){
        num_of_Movies++;
        strcpy(movies_arr[num_of_Movies].name, name); // as string is not defined in c
        movies_arr[num_of_Movies].availableSeats = total_Seats;
        movies_arr[num_of_Movies].price = final_price;
        printf("\nMovie added successfully!\n");
    }
    else{
        printf("\nMaximum number of movies reached!\n");
    }
}

void display_All_Movies(){
    printf("\nThe List of All Available Movies : \n\n");
    for(int i = 1; i <=num_of_Movies; i++){
        printf("%d-> %s - Available Seats : %d - Price : %f\n", i, movies_arr[i].name, movies_arr[i].availableSeats, movies_arr[i].price);
    }
}

void bookTicket(int movie_number, int num_of_Tickets){
    if(movie_number < 0 || movie_number >= num_of_Movies){
        printf("\nInvalid movie selection!\n");
        return;
    }

    if(movies_arr[movie_number+1].availableSeats >= num_of_Tickets){
        float totalPrice = movies_arr[movie_number].price * num_of_Tickets;
        movies_arr[movie_number+1].availableSeats -= num_of_Tickets;
        printf("\n\nTickets booked successfully!\n");
        // printf("Total Price: %f\n", totalPrice);
    }
    else{
        printf("\nNot enough seats available!\n");
    }
}

int main(){

    printf("\n********** WELCOME TO THE MOVIE TICKET BOOKING COUNTER **********\n");
    int value;
    while(value!=3){
    printf("1-> New User.\n");
    printf("2-> Already an user.\n");
    printf("Enter Your choice : ");
    scanf("%d",&value);
    int id,pw;
    int idu,pwu;
        /* code */
        if(value==1){
            printf("Enter Your ID : ");
            scanf("%d",&id);
            printf("Enter Your Password : ");
            scanf("%d",&pw);
            printf("\n User Registration Successfull..\n\n");
        }
        
        else{
            printf("Enter Your User ID : ");
            scanf("%d",&idu);
            printf("Enter Your Password : ");
            scanf("%d",&pwu);
            if(idu==id){
                if(pwu==pw){
                    printf("\nLOGIN SUCCESSFULL\n");

                    int choice;
                    do{
                        printf("\nWelcome to Movie Ticket Booking System\n\n");
                        printf("**Admin Panel**\n\n");
                        printf("1-> Add a Movie\n");
                        printf("4-> Exit Portal\n\n");
                        printf("**User Panel**\n\n");
                        printf("2-> Display Available Movies\n");
                        printf("3-> Book Tickets\n");
                        printf("4-> Exit Portal\n\n");
                        printf("Enter your Prefefred choice: ");
                        scanf("%d", &choice);

                        switch(choice){
                            case 1:{
                                    //define a character array to store the name of the string
                                    char movie_name[50];
                                    //total_seats represents the total number of seats available for that particular movie
                                    int total_Seats;
                                    //price represents the maximum price of that particular movie
                                    float init_price;
                                    //GST represents the tax per movie
                                    float GST;

                                    printf("Enter movie name: ");
                                    scanf("%s", movie_name);
                                    printf("Enter available seats: ");
                                    scanf("%d", &total_Seats);
                                    printf("Enter initial price per ticket: ");
                                    scanf("%f", &init_price);
                                    printf("Enter the tax to be collected per ticket : ");
                                    scanf("%f",&GST);

                                    //calculation of the total price per ticket with including gst.
                                    float final_price=init_price+((GST/100)*init_price);

                                    addMovie(movie_name, total_Seats, final_price);
                                    break;
                            }
                            case 2:
                                display_All_Movies();
                                break;
                            case 3:{
                                    int movie_number, num_of_Tickets;
                                    printf("Please Enter the movie number: ");
                                    scanf("%d", &movie_number);
                                    printf("Enter number of tickets : ");
                                    scanf("%d", &num_of_Tickets);
                                    bookTicket(movie_number-1, num_of_Tickets);
                                    break;
                            }
                            case 4:
                                printf("Exiting...\n");
                                printf("Exit Successful...\n");
                                break;
                            default:
                                printf("Invalid choice!\n");
                        }
                    }
                    while (choice != 4);

                }
                else{
                    printf("\nFalse Credential... LOGIN Again...\n");
                }
            }
            else{
                printf("\nNO USER FOUND...\n\n");
            }
        }
    }
    return 0;
}