/*
 ===================================================================================================
 Name        : Project1
 Author      : Mohammad Hatem Mohammad Saeed
 Description : Code to demonstrate the project1
 ===================================================================================================
 */
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define WITH_ENGINE_TEMP_CONTROLLER 1

struct sensor_reading{  /*Creating a structure containing sensor readings (room_temp, engine_temp) and ..
  one parameter which is (vehicle speed)*/

	float room_temp, engine_temp; //FLoat is chosen to be more general
	float vehicle_speed;
};

int main(void){

	char main_menu;  //The variable refers to the main menu declaration
	char sensors_set_menu;  //The variable refers to the sensors set menu declaration
	char color_choice;  //The variable contains the inserted color declaration
	float scanned_room_temp;  //The variable contains the inserted room temperature declaration
	float scanned_engine_temp; //The variable contains the inserted engine temperature declaration
	int set_menu_state; // State of set menu during the program
	setbuf(stdout,NULL);

	/*Initializing the values of the sensor readings*/
	struct sensor_reading vehicle_speed,room_temp,engine_temp;
	vehicle_speed.vehicle_speed = 100;
	room_temp.room_temp = 35;
	engine_temp.engine_temp = 90;



	while(TRUE){  // The main menu

		printf("a. Turn on the vehicle engine\n");
		printf("b. Turn off the vehicle engine\n");
		printf("c. Quit the system\n");
		printf("Please enter a choice: ");

		scanf(" %c",&main_menu); //The user inserts a choice from the main menu (Turn on the vehicle engine)

		if(main_menu  == 'a' || main_menu  == 'A'){ //The first choice of main menu
			set_menu_state = TRUE;  //While the set menu is chosen
			while(set_menu_state){

				printf("\n");
				printf("a. Turn off the vehicle engine\n");
				printf("b. Set the traffic light color\n");
				printf("c. Set the room temperature (Temperature Sensor)\n");
				printf("d. Set the engine temperature\n");
				printf("Please enter a choice: ");

				scanf(" %c",&sensors_set_menu); //The user inserts a choice from the sensor set menu

				if(sensors_set_menu =='a'||sensors_set_menu =='A'){ // a. Turn off the engine
					printf("\n");
					break; //After a. is chosen breaks the loop and returns to the main menu
				}

				else if(sensors_set_menu =='b'||sensors_set_menu =='B'){  // b. Set the traffic light color
					printf("\n");
					printf("Please enter the required color: ");
					scanf(" %c",&color_choice);

					if(color_choice =='g'||color_choice =='G'){ //Case of green color
						printf("\n");
						struct sensor_reading *vehicle_speed_ptr = &vehicle_speed,*room_temp_ptr=&room_temp; /*using a pointers to structure members */
						(*vehicle_speed_ptr).vehicle_speed = 100; //pointer to vehicle speed
						(*room_temp_ptr).room_temp = 20; //pointer to room tempt

						printf("Engine is ON\n");
						printf("AC is OFF\n");
						printf("Vehicle speed: %.2f Km/Hr\n",vehicle_speed.vehicle_speed); //The value of the pointer to vehicle speed
						printf("Room Temperature: %.2f C\n",room_temp.room_temp); //The value of the pointer to room tempt
						printf("Engine Temperature Controller is OFF\n");
						printf("Engine Temperature: %.2f C\n",engine_temp.engine_temp); //The value of the pointer to engine tempt
						printf("\n");}

					else if(color_choice =='o'||color_choice =='O'){ //Case of orange color
						printf("\n");
						struct sensor_reading *vehicle_speed_ptr = &vehicle_speed,*room_temp_ptr=&room_temp,*engine_temp_ptr=&engine_temp;
						(*vehicle_speed_ptr).vehicle_speed = 30;
						(*room_temp_ptr).room_temp = (float)(room_temp.room_temp*(1.25)+1); //pointer to room tempt 7.d.i
						(*engine_temp_ptr).engine_temp = (float)(engine_temp.engine_temp*(1.25)+1); //pointer to room tempt 7.d.ii

						printf("Engine is ON\n");
						printf("AC is ON\n");
						printf("Vehicle speed: %.2f Km/Hr\n",vehicle_speed.vehicle_speed);
						printf("Room Temperature: %.2f C\n",room_temp.room_temp);
						printf("Engine Temperature Controller is ON\n");
						printf("Engine Temperature: %.2f C\n",engine_temp.engine_temp);
						printf("\n");}

					else if(color_choice =='r'||color_choice =='R'){ //Case of red color
						printf("\n");
						struct sensor_reading *vehicle_speed_ptr = &vehicle_speed,*room_temp_ptr=&room_temp;
						(*vehicle_speed_ptr).vehicle_speed = 0;
						(*room_temp_ptr).room_temp = 20;

						printf("Engine is ON\n");
						printf("AC is OFF\n");
						printf("Vehicle Speed: %.2f Km/Hr\n",vehicle_speed.vehicle_speed);
						printf("Room Temperature: %.2f C\n",room_temp.room_temp);
						printf("Engine Temperature Controller is OFF\n");
						printf("Engine Temperature: %.2f C\n",engine_temp.engine_temp);
						printf("\n");}
				}

				else if(sensors_set_menu =='c'|| sensors_set_menu =='C'){ // c. Set the room temperature
					printf("\n");
					printf("Please enter the room temperature: ");
					scanf(" %f",&scanned_room_temp);
					if(scanned_room_temp<10 || scanned_room_temp>30){ //Requirement 7.b.i & 7.b.ii together
						struct sensor_reading *room_temp_ptr = &room_temp;
						(*room_temp_ptr).room_temp = 20;

						printf("\n");
						printf("Engine is ON\n");
						printf("AC is ON\n");
						printf("Vehicle Speed: %.2f Km/Hr\n",vehicle_speed.vehicle_speed);
						printf("Room Temperature: %.2f C\n",room_temp.room_temp);
						printf("Engine Temperature Controller is OFF\n");
						printf("Engine Temperature: %.2f C\n",engine_temp.engine_temp);
						printf("\n");}

					else{
						struct sensor_reading *room_temp_ptr = &room_temp;
						(*room_temp_ptr).room_temp = scanned_room_temp;

						printf("\n");
						printf("Engine is ON\n");
						printf("AC is OFF\n");
						printf("Vehicle Speed: %.2f Km/Hr\n",vehicle_speed.vehicle_speed);
						printf("Room Temperature: %.2f C\n",room_temp.room_temp);
						printf("Engine Temperature Controller is OFF\n");
						printf("Engine Temperature: %.2f C\n",engine_temp.engine_temp);
						printf("\n");}
				}


				else if(sensors_set_menu =='d'||sensors_set_menu =='D'){ // d. Set the engine temperature
					printf("\n");
					printf("Please enter the engine temperature: ");
					scanf(" %f",&scanned_engine_temp);
					if(scanned_engine_temp<100 || scanned_engine_temp>150){ //Requirement 7.c.i & 7.c.ii together

#if WITH_ENGINE_TEMP_CONTROLLER == 1 //Bonus Requirement, Preprocessor *This is what I reached for in preprocessor*

						struct sensor_reading *engine_temp_ptr = &engine_temp,*room_temp_ptr=&room_temp;
						(*engine_temp_ptr).engine_temp = 125;
						(*room_temp_ptr).room_temp = 20;

						printf("\n");
						printf("Engine is ON\n");
						printf("AC is ON\n");
						printf("Vehicle Speed: %.2f Km/Hr\n",vehicle_speed.vehicle_speed);
						printf("Room Temperature: %.2f C\n",room_temp.room_temp);
						printf("Engine Temperature Controller is ON\n");
						printf("Engine Temperature: %.2f C\n",engine_temp.engine_temp);
						printf("\n");}

#elif WITH_ENGINE_TEMP_CONTROLLER == 0
					printf("The engine controller is not working");
#endif

					else{
						struct sensor_reading *engine_temp_ptr = &engine_temp;
						(*engine_temp_ptr).engine_temp = scanned_engine_temp;

						printf("\n");
						printf("Engine is ON\n");
						printf("AC is OFF\n");
						printf("Vehicle Speed: %.2f Km/Hr\n",vehicle_speed.vehicle_speed);
						printf("Room Temperature: %.2f C\n",room_temp.room_temp);
						printf("Engine Temperature Controller is OFF\n");
						printf("Engine Temperature: %.2f C\n",engine_temp.engine_temp);
						printf("\n");}

				}

			}
		} //End of main menu
		else if(main_menu  == 'b'){ //The second choice of main menu (Turn OFF the vehicle)
			set_menu_state = FALSE; //This line could be deleted without affecting on the program
			printf("\n");
			printf("Turn OFF the Vehicle Engine\n");
			printf("\n");
		}

		else{ //The third choice of main menu (Quit the system)
			return 0; //Case of quit; the program terminated
		}
	}
}
