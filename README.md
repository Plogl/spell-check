# spell check
 Spell checker

Spellcheck that stores a dictionary as an unordered map, and displays all 
possible mispellings when it finds a word that isn't found in the dictionary.
Once a word is detected, it will try one of four methods, swapping adjacent
characters, deleting characters, adding a character, or swapping a character for
another one. If a correction is detected, it's added to a vector of suggested 
corrections, and once all methods have been attempted, the corrections are 
returned if any are found.