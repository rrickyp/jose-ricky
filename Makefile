FLAGS = -pedantic-errors -std=c++11
mathprob.o: mathprob.cpp mathprob.h
	g++ $(FLAGS) -c $<
CardFeatures.o: CardFeatures.cpp CardFeatures.h
	g++ $(FLAGS) -c $<
NerdBlackJack.o: NerdBlackJack.cpp mathprob.h CardFeatures.h
	g++ $(FLAGS) -c $<
game: NerdBlackJack.o CardFeatures.o mathprob.o
	g++ $(FLAGS) $^ -o $@
gameset: game
	./game
clean:
	rm -f game NerdBlackJack.o CardFeatures.o mathprob.o
.PHONY: clean tar

