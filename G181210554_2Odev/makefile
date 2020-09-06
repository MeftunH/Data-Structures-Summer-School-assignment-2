hepsi: hazirlik derle calistir
hazirlik:
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/AVLTree.o -c ./src/AVLTree.cpp
	g++ -I ./include/ -o ./lib/Kisi.o -c ./src/Kisi.cpp
	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
derle:	
	g++ -I ./include/ -o ./bin/Test ./lib/Dugum.o ./lib/AVLTree.o ./lib/Kisi.o ./lib/Stack.o ./src/Test.cpp
calistir:
	./bin/Test