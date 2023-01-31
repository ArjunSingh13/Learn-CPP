
/* Define only one of below to get the code build */
#undef OBSOLETE_METHOD_1
#undef OBSOLETE_METHOD_2
#define LATEST_METHOD 1

/* to test various classes and functionality explained along with them*/
//For Constructors
#undef PLAYER
#undef PLAYER1
#undef PLAYER2
#undef PLAYER3

//For Inheritance
#undef BASE
#undef ACCOUNT

//For Polymorphism
#undef ACCOUNT1
#undef ACCOUNT2

#undef SMART_PTR

/* Only enable one macro from below, used in player2.h file 
to demonstrate deep or shallow copy mechanism */
#define SHALLOW_COPY_ENABLED 0
#define DEEP_COPY_ENABLED	 1