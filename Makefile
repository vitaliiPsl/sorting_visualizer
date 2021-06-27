sources = $(wildcard src/*.cpp)
objects = $(sources:.cpp=.o)

all: visualizer

visualizer: $(objects)
	g++ $^ -o $@ -LSFML/lib -lsfml-graphics -lsfml-window -lsfml-system

src/%.o: %.cpp
	g++ -c $? -ISFML/include

clean: 
	rm visualizer src/*.o