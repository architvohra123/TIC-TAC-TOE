# Projects-in-C
This repository consists of project tic.c which is based on the implementation of TIC-TAC-TOE Game.

We know a Tic-Tac-Toe game looks like :
      |  |   
  ____|__|____
      |  |
  ____|__|____
      |  |
      |  |
This game is based on 2 players , one plays as X and other as O
Creating a game in C where both the players are human is an obvious approach.
But what if we want to play it against a BOT.

So we would first be thinking that how would that bot place its moves?
This will also affect the difficulty level of playing the game with bot.
As per my knowledge, we can use two approaches:
      -> Random moves - Because these are random moves it can fluctuate the level of difficulty.
                        We have to keep in mind that the player or the bot don't take move on already placed ones.
      -> Min-Max Algorithm -  This is by far the best technique to tackle these type of games with very small Event Space.
                              As this algorithm is based on taking up minimum and maximum values based on the depth of game tree (evaluating each and every possible valid moves until it reaches win/lose/draw).
I have used this algorithm to increase the difficulty level and always making smart and obvious moves.

                            
