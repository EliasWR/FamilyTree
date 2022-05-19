#FamilyTree

This is a school project created by students at NTNU Ålesund. \
Institusjonsnummer: 194 \
Emnekode: AIS1002_1 \
Emnetittel: Objektorientert programmering og algoritmer \
Eksamenstype: Mappevurdering \
GruppeNr: 18

KandidatNr: 10025 \
KanditatNr: 10026

##Table of contents
- [Classes](#classes)
- [Documentation](#documentation)
- [Assumptions](#assumptions)
- [Known bugs](#known-bugs)
- [Our solution](#our-solution)
- [Tests](#tests)

##Classes
###UML Schematics
![img.png](Images/img.png)

##Documentation
The code documentation style is written in the following format:

/// @what:      Describing what the function does. \
/// @bigO:      Included where it is relevant to mathematically describe the limits of the functions. \
/// @param      Describes the parameters the function takes.\
/// @returns    Describes the return value of the function.\
/// @usage      Describes where the function has been used in this project.\
/// @example    Show an example of how the function can be implemented.

##Assumptions
###We have made the following assumptions for our program:
    - Every name is unique
    - No more than one person is emptied at the time
        - Tree structure will chose first person with correlating name when traversing
        - To fill, every attribute can be edited
    - We have taken it one step further by making a general tree and this will satisfy the task

##Known bugs 
- Birth and death limits have not been implemented.
  - This allows the user to get negative ages and set both birth and death in the future.
  - Program will also print the age even though the person is dead.

##Our solution
###General tree
We have made a general tree. This means that it is preferable to start with your ancestor. \
Pros:
- Each node can have as many children as desired. 
- This code can become a binary tree if the children vector is limited to two elements.
- In this program each node can see both ways.
- More traversals possible \

Cons:
- Requires more data per node than a binary tree.
- Not very suitable to chose yourself for root node.

###Traversal
- We have chosen to focus on the depth first traversal
- We have not yet implemented breadth first traversal. We have made a working upwards traversal though.

##Tests
###Improvements
- Corner cases of persons, nodes, traversal and filewriting being tested.
- There could have been more tests testing even smaller corner cases.

##Future TODOs
###Gender
Persons gender value should be of type enum and not string. \
It was previously made string because of convenience of all attributes being string. \
This is a priority for future versions.

###GUI
In the future we would prefer to implement a GUI with QT cpp library.
This could also be done with python. 
This is not prioritized as of now.

###Traversal
Implementation of breadth first traversal is prioritized to be implemented.

###Remove person function
Implement that if user wants to delete a node and node is a leaf it will be removed from the parents vector

###Remove private variables from Date class
Make functions return the right values instead.

##Big O
Both depth first and upwards traversal algorithms have been included in Node.hpp. \
The big O notation for both of these traversal algorithms are O(n). \
This is because it requires the function to visit once per node in the worst case.


##References
###In Node.hpp
We started off the project getting inspiration from "Folders" written by Lars Ivar Hatledal \
Link: https://github.com/AIS1002-OOP/folders/blob/master/main.cpp \
Date of information: (05.05.2022).\
Justification: As we learned Object oriented programming this was a good place to start our journey.
It inspired our traversal algorithms.

###In json.hpp
Json file handling library Nhlohmannjson.hpp \
Link: https://github.com/nlohmann/json \
Date of information: (20.04.2022) \
Justification: This library really helped write and read json to file. Library is recognized for .json file handling.

### In config.yml
Macos - github build (conan-on-darwin) \
Link: https://github.com/markaren/threepp/blob/master/.github/workflows/config.yml \
Date of information: (20.04.2022) \
Justification: This helped building our program on MacOs on github.

###In ExceptionHandling.hpp
Inspiration for checking integer input (checkStateInput function) \
Link: https://stackoverflow.com/questions/19696442/how-to-catch-invalid-input-in-c \
Date of information:(26.04.2022) \
Justification: This helped us implement a neat way to get the right user input for integers.

###In Date.hpp
Inspiration for date class \
Link: http://gauss.ececs.uc.edu/Courses/C321/html/date.html \
Date of information: (03.05.2022) \
Justification: Date and age calculation is not that simple. This page helped form the logic behind the date class.

###In Date.hpp
Inspiration for splitting date string (setDate function) \
Link: https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c \
Date of information: (03.05.2022) \
Justification: This helped us split the date strings in the right places in order to convert to integers.

###In Date.hpp
Inspiration for age calculation (calculateAge function) \
Link: https://www.codespeedy.com/calculate-age-from-date-of-birth-in-cpp/ \
Date of information: (03.05.2022) \
Justification: Helped creating the logic for calculating the age of person. 

###In JsonFile.hpp
Checking for empty file (isEmpty function) \
Link: https://tousu.in/qa/?qa=486809/ \
Date of information: (19.05.2022) \
Justification: This is a neat way to check werther the file is empty.

###In Date.hpp
Time tracking (getCurrentDate function) \
Link: https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm \
Date of information: (16.05.2022) \
Justification: This helped us get the current date in a neat date.