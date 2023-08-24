Vehicle Control System

This project is an implementation of a Vehicle Control system using C programming language. The system allows the user to interactively control various aspects of the vehicle, including engine control, sensor readings, and system states.


Features

User Interaction:


Turn on the vehicle engine.
Turn off the vehicle engine.
Quit the system.

System State:


Once a choice has been made, the current system state is displayed.
Engine Control:

When turning off the vehicle engine, the user is prompted again for further actions.
Sensor Readings:

When the vehicle engine is turned on, a "Sensors set menu" is displayed.
The menu provides options for simulating vehicle sensor readings:
Turn off the engine.
Set the traffic light color.
Set the room temperature (Temperature Sensor).
Set the engine temperature (Engine Temperature Sensor).
Continuous Menu Display:

While the engine is ON, the sensor menu is continuously displayed and awaits user input.
Sensor-based Actions:

Based on the sensor inputs from the console, the following actions are performed:
Traffic Light Data:
If the traffic light is 'G', set vehicle speed to 100 km/hr.
If the traffic light is 'O', set vehicle speed to 30 km/hr.
If the traffic light is 'R', set vehicle speed to 0 km/h.
Room Temperature Data:
If temperature is less than 10, turn AC ON and set temperature to 20.
If temperature is greater than 30, turn AC ON and set temperature to 20.
If temperature is otherwise, turn AC OFF.
Engine Temperature Data:
If temperature is less than 100, turn "Engine Temperature Controller" ON and set temperature to 125.
If temperature is greater than 150, turn "Engine Temperature Controller" ON and set temperature to 125.
If temperature is otherwise, turn "Engine Temperature Controller" OFF.
Vehicle State Display:

After applying the actions based on sensor inputs, the current vehicle state is displayed, including:
Engine state: ON/OFF.
AC: ON/OFF.
Vehicle Speed.
Room Temperature.
Engine Temperature Controller State.
Engine Temperature.
Engine Shutdown:

If the user chooses to "Turn off the engine" in the sensor menu, the initial menu from requirement 1 is displayed.
Usage
To use this Vehicle Control system, simply compile and run the provided C program. Follow the on-screen prompts to interact with the system and control various aspects of the vehicle.

Note: This project assumes that the user inputs for sensor readings and menu choices are provided through the console.
