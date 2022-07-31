                                        HANGMAN GAME IN PERL
    
Explaining the Program:

    1.  We create a string "$string" which contains all the words which will be used to play
        the game separated by a "|".

    2.  The array "@list" stores all the words of "$string" in a list. It does by using the split() function.
        Thus we have "@list = (computer, radio, ........, experiment)

    3.  A string "$word" stores a random element of the array "@list". Hence $word will be ($word = 'computer')
        or ($word = 'calculator') or it can be any word from "@list" as it is completely random.
    
    4.  "$dashes" stores the length of "$word". For example, if ($word = 'thousand') then ($dashes = 8)
        "$dashes" is later used mainly to print underscores '_' instead of the characters so that player
         can see the length of the word he/she has to guess but doesn't knows the actual characters of the
         world as onlu underscores will be printed.

    5.  The array "@pick" stores the characters of the string "$word" letter by letter in a list by using
        the split function. For e.g., if ($word = 'design') then {@pick =(d, e, s, i, g, n)}

    6.  Initialise ($x = -1).
        The arrays "@guess" & "@misses" stores all the alphabets guessed by the player and the incorrect
        alphabets guessed by the user respectively in list.
        Let's say, the word that the user has to guess is 'radio'. 
        If we assume the user guesses to be ('a','f','r','i','x','o','t') in a sequential manner then,
         @guess will be equal to - ('a') when ($x = 0) ('a','f') when ($x=1), ('a','f','r') when ($x=2), and so on....
        However @misses will be equal to- ('a') when ($x=0), ('a','f') when ($x=1), ('a','f','x') when ($x=4) and so on....

    7.  START: label is used mainly for the "goto" function. Lines 38 to 45 check if the player has won
        the game or not. If yes goto label EXIT: and exit and game and if no, the program continues.

    8.  Lines 46 to 52 take user input of a letter.

    9.  Lines 54 to 67 are used to print the underscores and the correct guessed letters at their respective
        positions in a single line. For e.g., _ _ _e _ _a_ Here 'e' and 'a' are the correct guessed letters. 
    
    10. Lines 71 to 78 check the letter input from the user to see whether it is correct or not. If yes,
        continue with the program, else store the user input to the "@misses" and then continue the program.

    11. Line 81 prints all the incorrect inputs from the user separated by a comma (,).

    12. The Given-When loop starting from Line 84 till Line 158 is basically used to tell the user how many
        for playing the game are left and for printing the progressive hangman diagram for each lost chance.
        Chance is lost when user inputs an incorrect guess. A player is given 5 chances when the game starts.

    13. Line 159 & Line 160 are used to exit the game in case the user has won by guessing all the words
        correctly while the number of incorrect remains less than 5.

    14. If the player loses all 5 chances, i.e., number of incorrect guesses gets equal to 5, then 
        the game is over, player has lost and the complete hangman diagram is printed.