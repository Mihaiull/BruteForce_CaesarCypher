# A Brute Force Aproach to Caesar's Cypher

## Usage:
- Insert your encrypted text into **to_decrypt.txt**
- Your decrypted text will appear in **decrypted.txt**
- The key (aka the number of permutations it took to reach the decrypted code) will be displayed in the terminal

## How it works:
It breaks the Caesar's Cypher using frequency analisis. It shifts the encrypted message through all the possible permutations,
computes the Chi-square distance between each permutation and the approximate distribution 
of letters in English, and returns the permutation with the least Chi squared distance as the solution.
