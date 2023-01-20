# spell check
 Spell checker

Spellcheck that stores a dictionary as an unordered map, and displays all 
possible mispellings when it finds a word that isn't found in the dictionary.
Once a word is detected, it will try one of four methods, swapping adjacent
characters, deleting characters, adding a character, or swapping a character for
another one. If a correction is detected, it's added to a vector of suggested 
corrections, and once all methods have been attempted, the corrections are 
returned if any are found.

Sample run:

Enter the message you'd like to spell check: hwo aree you donig

        Potential corrections for word 1 (hwo)
Replacing characters, we have these corrections: two
Deleting characters, we have these corrections: ho
Swapping adjacent characters, we have these corrections: who how
~
        Potential corrections for word 2 (aree)
Replacing characters, we have these corrections: free tree arse area
Inserting characters, we have these corrections: agree
Deleting characters, we have these corrections: are
~
Word 3 (you) is Ok!
~
        Potential corrections for word 4 (donig)
Deleting characters, we have these corrections: dong doni
Swapping adjacent characters, we have these corrections: doing
~
