/****************************************************************************************************************
  Written By : Ahmed Salah Abd elmonem /ahmed.salah.31236@gmail.com
 ****************************************************************************************************************/

#include <stdio.h>

void second_menu(void);				//Function to print the second menu after turning on the engine
void print_car_state(void);			//Function to print car state

struct car_state {
    int Engine_state;
    int AC_state;
    int Vehical_speed;
    float Room_temp;
    int Engine_temp_controller;
    int Engine_temp;
} car;

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    char order, input, trafic_light;
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
    //Get the readings of the sensors
    printf("please enter the speed of the car ( from the counter ): ");
    scanf("%d", &car.Vehical_speed);
    printf("Enter the current room temp (from temp. sensor ): ");
    scanf("%f", &car.Room_temp);
    printf("Enter the current Engine temperature (based on temp. sensor's reading ): ");
    scanf("%d", &car.Engine_temp);
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
    while (1) {
        car.AC_state = 0;

        while (1) {
            printf("a. Turn on the vehicle engine\n");
            printf("b. Turn off the vehicle engine\n");
            printf("c. Quit the system\n");
            scanf(" %c", &order);

            switch (order) {
                case 'a':
                case 'A':
                	//Turning on the vehicle engine
                    car.Engine_state = 1;
                    car.Engine_temp_controller = 0;
                    if (car.Vehical_speed == 30) {
                        car.AC_state = 1;
                        car.Room_temp = (car.Room_temp * (5.0 / 4.0)) + 1;
                        car.Engine_temp_controller = 1;
                        car.Engine_temp = (car.Engine_temp * (5.0 / 4.0)) + 1;
                    }
                    break;

                case 'b':
                case 'B':
                	//Turning off the vehicle engine and back for the main menu
                    break;

                case 'c':
                case 'C':
                	//Break and quit the program
                    return 0;

                default:
                    printf("please enter a valid choice\n");
            }

            if (order == 'a'||order == 'A') {
                break;
                //Turning off the vehicle engine and back to the previous menu
            }
        }

        while (1) {
            second_menu();
            scanf(" %c", &input);

            switch (input) {
                case 'a':
                case 'A':
                	 //Turning off the vehicle engine and back to the previous menu
                    break;

                case 'b':
                case 'B':
                	 //Setting the traffic light color
                    printf("Enter the required color: \n");
                    scanf(" %c", &trafic_light);
                    switch (trafic_light) {
                        case 'G':
                        case 'g':   //Green case
                            car.Vehical_speed = 100;
                            print_car_state();
                            break;

                        case 'O':
                        case 'o':	//Orange case
                            car.Vehical_speed = 30;
                            print_car_state();
                            break;

                        case 'R':
                        case 'r':		// Red case
                            car.Vehical_speed = 0;
                            print_car_state();
                            break;

                        default:
                            break;
                    }
                    break;

                case 'c':		//Setting the room temperature
                case 'C':
                    printf("Enter the required room temp: ");
                    scanf("%f", &car.Room_temp);
                    if (car.Room_temp < 10 || car.Room_temp > 30) {
                        car.AC_state = 1;
                        car.Room_temp = 20;
                    }
                    print_car_state();
                    break;

                case 'd':
                case 'D':		//Setting the engine temperature
                    printf("Enter the required Engine temperature: ");
                    scanf("%d", &car.Engine_temp);
                    if (car.Engine_temp < 100 || car.Engine_temp > 150) {
                        car.Engine_temp_controller = 1;
                        car.Engine_temp = 125;
                    }
                    print_car_state();
                    break;

                default:
                    printf("please enter a valid choice\n");
            }

            if (input == 'a'||input == 'A') {
                break; 						//back to the main menu
            }
        }
    }

    return 0;
}

void second_menu(void) {		//Function to print the second menu
    printf("a. Turn off the engine\n");
    printf("b. Set the traffic light color.\n");
    printf("c. Set the room temperature (Temperature Sensor)\n");
    printf("d. Set the engine temperature (Engine Temperature Sensor)\n");
}

void print_car_state(void) {		//Function to print car state
    if (car.Engine_state == 1) {
        printf("Engine is ON \n");
    } else {
        printf("Engine is OFF \n");
    }

    if (car.AC_state == 1) {
        printf("AC is ON \n");
    } else {
        printf("AC is OFF \n");
    }

    printf("Vehical speed: %d Km/Hr\n", car.Vehical_speed);
    printf("Room Temperature: %f C\n", car.Room_temp);

    if (car.Engine_temp_controller == 1) {
        printf("Engine Temp Controller is ON \n");
    } else {
        printf("Engine Temp Controller is OFF \n");
    }

    printf("Engine Temperature: %d C\n\n", car.Engine_temp);
}
