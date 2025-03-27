# Caesar Cipher

The Caesar Cipher is the most famous old historical symmetric encryption scheme, using a simple substitution cipher.  It was indeed most famously used by Julius Caesar and thereby received the name.  The Caesar Cipher replaces all the letters in an input message with the letters that are X higher or lower in the alphabet, e.g. Caesar Cipher of 1 of "HAL" is "IBM" -- each letter H, A, L plus one is I, B, M.  And the Caesar Cipher of -1 of IBM is HAL, as this is simply the reverse of the previous example.

For this application, only uppercase ASCII letters (A-Z) need to be handled, which is 26 characters.

## The Story

You have just inherited a codebase that encrypts and decrypts Caesar Cipher-ed text.  It has been worked upon by a series of previous developers, each in their own way, with their own mistakes, all of whom have since left, and their code is bug ridden with no guarantees about code quality or consistency.

Some tests have been added for the desired behavior, but the current code has failures galore, and it is up to you to get the code to work now. :)

## The Interview Question

Get as many failing unit tests to pass as you can by running:

`./run.sh`

And fixing each failing function as needed.

This interview is about your habits and instincts as a developer.  The question is intentionally (seemingly) vague and open ended.

## Notes

Fixing all the bugs is not required to pass -- get as far as you can.

You will have roughly 40-45 minutes, with a slight change in the process about halfway through, which the interviewer will explain once that point is reached.

The internet is free to use for any questions about language specific features or the ASCII chart, you should not need it for anything else.  Googling is encouraged.

The unit tests can be added to but not removed from.  The custom test harness can be modified as desired, without changing its announcing of failed tests.

All tests will pass once the functions are fixed, and all the tests are doing what they should do, there are no "trick" tests: you can always trust the tests.  All arguments will be valid and no error checking is required.

The class method signatures (API) cannot be broken -- backwards compatible changes are OK.  Existing functionality must continue to work as-is.

Most of the errors are trivial, there are 2 that are slightly more involved.

This code does not need to be thread safe.

You can ask whatever you want but your interviewer will almost always answer your questions with more questions like "where would you find the answer to that?" or "are you sure?" or "what does the error message say?" etc.  Your ability to think clearly about what to do next in each situation is what is being evaluated, not just the accuracy of your solutions.
