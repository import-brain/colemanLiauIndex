#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int count_letters(string word); // function prototypes so compiler doesn't sh*t itself
int count_words(string words);
int count_sentences(string sentence);

int main(void)
{
    string text = get_string("Text: "); // gets string of text from user
    
    int numLetters = count_letters(text); // number of stuff vars
    int numWords = count_words(text);
    int numSentences = count_sentences(text);
    
    double wordMultiplier = 100.0 / numWords; // multiplier to scale all "word counts" to 100
    // implementation of Coleman-Liau index
    double gradeIndex = 0.0588 * (numLetters * wordMultiplier) - 0.296 * (numSentences * wordMultiplier) - 15.8;
    // if grade is above 16, display 16+, if less than 1, display less than 1, else print rounded gradeIndex cast to int
    if (round(gradeIndex) >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (round(gradeIndex) < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", (int) round(gradeIndex));
    }

}

int count_letters(string word)
{
    int numLetters = 0;
    // for every char in text, if word is in alphabet, add 1 to numLetters
    for (int i = 0; i < (int) strlen(word); i++)
    {
        if (isalpha(word[i]))
        {
            numLetters++;
        }
    }
    return numLetters;
}
// casting words[i] to int results in ASCII number of char
int count_words(string words)
{
    int numWords = 0;
    // for every char in text, when words[i] is a space, add 1 to words
    for (int i = 0; i < (int) strlen(words); i++)
    {    
        if ((int) words[i] == 32)
        {
            numWords++;
        }
    }
    numWords++;
    return numWords;
}

int count_sentences(string sentence)
{
    int numSentences = 0;
    // for every char in text, add 1 to number of sentences when '.', '?', or '!' is detected
    for (int i = 0; i < (int) strlen(sentence); i++)
    {
        if ((int) sentence[i] == 46 || (int) sentence[i] == 33 || (int) sentence[i] == 63)
        {
            numSentences++;
        }
    }
    return numSentences;
}