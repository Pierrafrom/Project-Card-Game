# Project-Card-Game

### Created by <a href="https://github.com/Pierrafrom" target="_blank">Pierre Fromont Boissel</a> and <a href="https://github.com/Samuelito78" target="_blank">Samuel Boix-Segura</a> on January 2023. <br>

## 🖥️ Setup
1. Define the path and the name of the file that contains the data for cards. <br>
To do this, open the file "Card.h". <br>
Then define the path and the filename in the constants.
![Path](img/Path.PNG)
2. Do you want to see the test of the functions or not? <br>
If you want to see them, open main.cpp and define TEST like this: <br>
![testOn](img/testOn.PNG) <br>
If you don't want to see them just comment this line. <br>
![testOff](img/testOff.PNG)

## 📃 Rules
Here are the rules of the game : <br>
- The game is basically player versus player game but you can be alone and face a bot.
- Each player has a pile of 20 cards wich they took from the same reserve.
- Each card has a name, an attack, a defense and a magic value.
- Your goal is to reduce the prestige poins of your ennemy and to protect yours.
- Each player sorts his deck according to his strategy, then plays the card on top of his deck each turn. <br>

The winner will be the first to take down the ennemy or the the one who has the most prestige points when one of the two players has no more cards left !

Choose your strategy and your cards wisely knowing that : <br>
- The player having the biggest amount of attack (physical damages) will decrease the prestige of his
  opponent by the difference between his attack value and the defense value of the other player
- If both of the players have the same amount of attack, no harm to any players prestige will be caused
- If the defender has more defense than the attack value of the other player, the defender
  does not gain any prestige points
- The player having the biggest amount of magical power will reduce
  the prestige of his ennemy by the difference of the magical power of value of the two player <br>

## 🎮 How to play
1. Choose the number of player 
2. Enter your nam
3. Choose how do you want fill your deck
4. Choose how do you want to sort your deck
5. If you play alone, choose the difficulty of the AI
6. The game start automaticly

## ‼️ If you have an error
- If you have this error
  ![error](img/fileOpen.PNG)
  Be sure that you've entered the correct path and file name in the constants found on "Card.h"
- If you have this error
  ![error](img/data.PNG)
  Check if you've download the correct file, you can find it on our github project page <a href="https://github.com/Pierrafrom/Project-Card-Game/blob/main/cards_data.txt" target="_blank">cards_data.txt</a> on our project page.
