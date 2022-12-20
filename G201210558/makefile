all:compile link run

compile:	
	g++ -I ./include/ -o ./lib/SatirDugum.o -c ./src/SatirDugum.cpp
	g++ -I ./include/ -o ./lib/SatirListesi.o -c ./src/SatirListesi.cpp	
	g++ -I ./include/ -o ./lib/YoneticiDugum.o -c ./src/YoneticiDugum.cpp
	g++ -I ./include/ -o ./lib/Exception.o -c ./src/Exception.cpp
	g++ -I ./include/ -o ./lib/YoneticiListesi.o -c ./src/YoneticiListesi.cpp
	g++ -I ./include/ -o ./lib/DosyaOku.o -c ./src/DosyaOku.cpp
	g++ -I ./include/ -o ./lib/Program.o -c ./src/Program.cpp
	g++ -I ./include/ -o ./lib/Main.o -c ./src/Main.cpp
link:
	g++ ./lib/SatirDugum.o ./lib/SatirListesi.o ./lib/YoneticiDugum.o ./lib/Exception.o ./lib/YoneticiListesi.o ./lib/DosyaOku.o ./lib/Program.o ./lib/Main.o -o ./bin/run.exe
run:
	./bin/run