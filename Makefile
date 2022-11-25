FLAGS = -pedantic-errors -std=c++11

mathprob.o: features_and_mathprob/mathprob.cpp features_and_mathprob/mathprob.h
	g++ $(FLAGS) -c  
CardFeatures.o: features_and_mathprob/CardFeatures.cpp features_and_mathprob/CardFeatures.h
	g++ $(FLAGS) -c 
NerdBlackJack.o: NerdBlackJack.cpp features_and_mathprob/mathprob.h features_and_mathprob/CardFeatures.h
	g++ $(FLAGS) -c 
gameset: NerdBlackJack.o features_and_mathprob/CardFeatures.o features_and_mathprob/mathprob.o
	g++ $(FLAGS) $^ -o $@
game: gameset
	./gameset
	rm -f gameset NerdBlackJack.o CardFeatures.o mathprob.o gameset.o
clean:
	rm -f gameset NerdBlackJack.o CardFeatures.o mathprob.o gameset.o
.PHONY: clean tar

