CXX = g++


NOMBRE = Ejecutable

ejecutar: $(NOMBRE)
	./$(NOMBRE) Esfera.asc config.xml

$(NOMBRE): *.cpp
	g++ *.cpp -o $(NOMBRE) -lGL -lGLU -lglut

