# $Id: Makefile,v 1.14 2014-06-25 17:42:27-07 - - $

MKFILE      = Makefile

COMPILECPP  = g++

CPPSOURCE   = main.cpp src/character.cpp src/level.cpp src/pacman.cpp src/level1.cpp src/ghost.cpp src/pinky.cpp src/food.cpp src/powerpellet.cpp src/blinky.cpp src/inky.cpp src/clyde.cpp src/mainmenu.cpp src/Animation.cpp src/AnimatedSprite.cpp src/level2.cpp
OBJECTS     = ${CPPSOURCE:.cpp=.o}
SFML        = -o sfml-app -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

all : ${OBJECTS}
	g++ ${OBJECTS} ${SFML}
	- 

../%.o : %.cpp
	${COMPILECPP} -c $<

clean :
	- rm ${OBJECTS}
