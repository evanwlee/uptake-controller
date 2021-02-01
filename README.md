# uptake-controller
Arduino Microcontroller code for running a printer up-take using a ultrasonic sensor and a relay to send a 12v halt signal.

The use of the relay and design of the halt control circuit were based on documentation provided by the vendor. 

About the code:

1) Monitor the distance between the slack and the ultrasonic sensor (once per second). 
2) If:<br>
  a) the slack is within a predefined distance to the sensor, and<br>
  b) the take-up has not exceeded its allowed continous runtime.
3) Then set the relay high to add voltage to the halt circuit to take-up the slack.
4) When:<br>
  a) The slack is outside predifined distance or<br>
  b) the update has exceeded its maximum run time
5) Then set the relay low to remove voltage and halt the take-up.

<img src="https://github.com/evanwlee/uptake-controller/blob/master/PhysicalDiagram.png">
