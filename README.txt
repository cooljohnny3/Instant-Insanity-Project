Instant Insanity Programming Project
	By: John Brehm
-------------------------------------

Use Generator.py to switch Threads.txt to either the pi or e input.

This code doesn't work.  After running for ~88 mins it craches due to 
somthing to do with pointers (ran out of room?).  The makeThreads funciton
in the LibraryChecker uses pointers to save space and would run out of memory 
if the pointers were not used.  This could all be avoided if I changed the 
implimentation but i'm turning in what I have.