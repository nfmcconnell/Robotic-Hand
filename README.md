# Robotic-Hand (in progress)

## Background
I began this personal project to further experience in robotics and to explore my interest in robotic prosthetics. The 3-D printed hand was designed in SolidWorks using similar dimension to my own hand for accurate proportions. Utilizig an Arduino Nano on the users glove and an Arduino Uno on the 3-D printed hand, the robotic hand will mimic the users motions. Two bluetooth modules perform the communication between the Arduinos allowing the user to be at a distance while still operating the hand. The forearm houses the 5 mini servo motors that contract and retract the fingers and thumb. Further development of this project could involve creating a more intricate hand design for a more realistic design with better accuracy and mobility.

## Hand Design
The hand was modeled off of the dimensions of my own hand to create proper proportions and an accurate design. The finger joints are revolute joints held together with pins to allow the finger to contract and retract. Each finger has two lines connected at the tip to the servo tensioners which control the movement of the fingers. The most challenging part of this process is the troubleshooting that occurs when discovering constraints in movement due to interferences in the design. The palm of the hand is connected to the forearm by a bracket. Within the forearm, the servo motors are mounted to brackets and spaced accordingly to be space efficient. There are two string brackets for orginazion and to minimze contact.

![Asssembly_Render_3](https://user-images.githubusercontent.com/60329920/117714749-3bb22300-b18c-11eb-8f27-2caad009e33e.JPG)

![Asssembly_Render_2](https://user-images.githubusercontent.com/60329920/117715895-c0517100-b18d-11eb-933f-50673c50359d.JPG)

## Current Stage
Currently, I have the hand assembled and am working on debuggnig and troubleshooting the motors and flex sensors. The next step is to begin putting the user glove together and attaching the flex sensors to each hand. Once that is done I will determine the resistance of each finger closed and open to properly assign values to the mapping of the servos. This will give more accuracy on each finger. 
