# FamilyTree
##Group 18

This is a school project created by students at NTNU ålesund.

##Documentation
The code documentation style is written in the following format:

/// @what:      Describing what the function does.
/// @bigO:      Included where it is relevant to mathematically describe the limits of the functions.
/// @param      Describes the parameters the function takes.
/// @returns    Describes the return value of the function.
/// @usage      Describes where the function has been used in this project.
/// @example    Show an example of how the function can be implemented.

##Assumptions
#We have made the following assumptions for our program:
    - 


##Known bugs

##Our solution

##Klasser

##Tests


##Future TODOs
###Gender
Enum

###GUI
QT cpp library
Evt skrive i python

###Traversal
Implement breadth first traversal

##Big O
Both depth first and upwards traversal algorithms have been included in Node.hpp.
The big O notation for both of these traversal algorithms are O(n).
This is because of the 

##TODO
TODO Fjerne autogenererte notater øverst og legge til kandidatnr i ReadMe
Klasseforklaring

### Gender of type enum
Gender should preferably be of type enum. This is a priority for future versions.

###GUI
Not prioritized to implement a GUI but it would improve the user experience of the program. 
We would probably use the QT cpp library. Could be done with python as well.

##References
###In Node.hpp
We started off the project getting inspiration from "Folders" written by Lars Ivar Hatledal
Link: https://github.com/AIS1002-OOP/folders/blob/master/main.cpp
Date of information: (05.05.2022).

###In json.hpp
Json file handling library Nhlohmannjson.hpp
Link: https://github.com/nlohmann/json
Date of information:(20.04.2022)

### In config.yml
Macos - github build (conan-on-darwin)
Link: https://github.com/markaren/threepp/blob/master/.github/workflows/config.yml
Date of information: (20.04.2022)

###In ExceptionHandling.hpp
Inspiration for checking integer input (checkStateInput function)
Link: https://stackoverflow.com/questions/19696442/how-to-catch-invalid-input-in-c
Date of information:(26.04.2022)

###In Date.hpp
Inspiration for date class
Link: http://gauss.ececs.uc.edu/Courses/C321/html/date.html
Date of information: (03.05.2022)

###In Date.hpp
Inspiration for splitting date string (setDate function)
Link: https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
Date of information: (03.05.2022)

###In Date.hpp
Inspiration for age calculation (calculateAge function)
Link: https://www.codespeedy.com/calculate-age-from-date-of-birth-in-cpp/
Date of information: (03.05.2022)

###In JsonFile.hpp
Checking for empty file (isEmpty function)
Link: https://tousu.in/qa/?qa=486809/
Date of information: (19.05.2022)

###In Date.hpp
Time tracking (getCurrentDate function)
Link: https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
Date of information: (16.05.2022)