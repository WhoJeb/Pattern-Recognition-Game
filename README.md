# Pattern Game
A game built around the same principles that [L-Systems](www.wikepidia/l-systems) are based on. However it uses those principles to generate a random string of text that is then printed to the user, the job of the user is to recognise the pattern and type it into the input field, the input will then be evaluated against the origional string and a correct/incorrect result will be determined. 

## How
L-Systems

F = "|"
FF = "||"
G = "{"
GG = "}"
H = ":"
HH = "::"

1. For len in system: make string of possible value letters.
2. Add same string on to end x times.
3. Add some random cheeky variations.
4. String replace letters with values.
5. Print String
6. Check if input matches the string from step 1:
    - If so: you win
    - Else: You Loose


