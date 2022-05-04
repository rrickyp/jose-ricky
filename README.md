# Jose-Ricky
Group Project for ENGG1340 and COMP2133 with Jose Christian Abraham(3035868762) and Ricky Purnama(3035890583)
Game Descriptions:
  NerdBlackJack
  In the beginning, the player will get the initial two cards, as well as the dealer(1 card is closed and the other is opened).
  The Player had two options that they need to opt for. Such as "Hit" and "Stand".
  "Hit" is when the player wants to add additional cards on top of the player's cards.
  "Stand" is when the player does not want to add their cards, and then the cards will proceed to be compared against dealer's cards.
  Each time player wants to make an action, they have to complete a simple mathematical equation within 15 seconds to continue the game.
  To win the game, the player needs to have a higher value of cards than the dealer, or the total cards' value is 21.

Rules for The Game:
  1. Each participant attempts to beat the dealer by getting a count as close to 21 as possible, without going over 21.
  2. If the player opt to hit, and apparently the sum exceeds 21, the player would consequently lose the game.
  3. the value of cards from 2 to 10 is equal to their face value, and the value of J,Q,K, has a value of 10. While A has a value of either 1 or 11.
  4. For the aforementioned math questions in each actions, the player only had 2 attempts within 15 seconds to answer the questions. If the player failed to do so, they would promptly lose the game.
  5. Only when the player opt "Stand" that the code reveal the dealer's card.
  6. If the dealer's card exceed 21, likewise the player promptly wins the game.

Code Requirement:
  1. Generation of random game sets or events --> we generate random cards for the player and dealer, as well as random mathematical equation.
  2. Data structures for storing game status --> we store each player, and dealer's cards using vector.
  3. Dynamic memory management --> we use vectors in storing cards, and calling cards from files.
  4. File input/output (e.g., for loading/saving game status) --> every time the game starts, there is a file that kept track of the fastest time a user can answer.
  5. Program codes in multiple files --> we will divide the modules according to the features, such as, MathProblem, and CardFeatuers.cpp.
  
