C = g++ 
FLAGS = -O3 -pg -Wall -W
RM  = rm -f
EXEC = run

OBJECTS = \
	 main.o \

all: $(OBJECTS) compile touch 

main.o : main.cpp
					 $(C) $(FLAGS) -c main.cpp

clean:  
					 $(RM) $(OBJECTS) $(EXEC) 

compile: 
					 $(C) $(FLAGS) $(OBJECTS) -o $(EXEC) 

touch:
					 @echo " "
					 @echo "Compilation done successfully..................."
					 @echo " "