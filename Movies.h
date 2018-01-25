/*
	Title:  Movies.h
	Author:  April R Crockett, modified by David Wallace
	Date:  1/25/2018
	Purpose:  Be able to create, manage, print, save & delete a movie library
*/
#ifndef MOVIES_H
#define MOVIES_H

#include "Movie.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Movies
{

	private:
		Movie** moviesArray; //an array of pointers - each pointer points to a single Movie
		int maxMovies; //maximum number of elements in the array
		int numMovies; //current number of movies in the array
		
		/*
				Function name:  displayMovieTitles 
				Parameters:  	none 
				Returns: 		none (void)
				Purpose:  		This function should be called when you want to print only the movie titles
								out of the movie library
		*/
		void displayMovieTitles();
			
		/*
				Function name:  resizeMovieArray 
				Parameters:  	none 
				Returns: 		none (void)
				Purpose:  		This function is called by addMovieToArray when the array size is not big enough
								to hold a new movie that needs to be added.  The function makes the array twice
								as big as it currently is and then moves all the movie pointers to this new array.
		*/
		void resizeMovieArray();	

	public:
			Movies(int);
			~Movies();
			/*
				Function name:  addMovieToArray 
				Parameters:  	none 
				Returns: 		none
				Purpose:  		This function should be called when you need to add a single movie to the
								movie library.
			*/
			void addMovieToArray();  



			/*
				Function name:  editMovieInArray 
				Parameters:  	none 
				Returns: 		none
				Purpose:  		This function should be called when you need to edit a movie in the array
			*/
			void editMovieInArray();



			
			

			/*
				Function name:  displayMovies 
				Parameters:  	none 
				Returns: 		none (void)
				Purpose:  		This function should be called when the user wants to have all the movies
								in the library printed to the screen.
			*/
			void displayMovies();

			

			/*
				Function name:  readMoviesFromFile 
				Parameters:  	1) A pointer to a character (c-string or string literal argument) containing the filename
								
				Returns: 		none (void)
				Purpose:  		This function should be called when the user wants to read movie data from a file
								and add the movies to the movie library.  The file must have data in the following order:
								title, length, year, genre, rating, num oscars won, star rating
			*/
			void readMoviesFromFile(char* filename);

			/*
				Function name:  removeMovieFromArray 
				Parameters:  	none 
				Returns: 		none (void)
				Purpose:  		This function should be called when the user wants to remove one single movie
								from the movie library.  The function will list all the movie names and allow
								the user to select the movie that they wish to remove. Then this function removes the movie.
			*/
			void removeMovieFromArray();

			/*
				Function name:  saveToFile 
				Parameters:  	1) A pointer to a character (c-string or string literal argument) containing the filename
								 
				Returns: 		none (void)
				Purpose:  		This function should be called when the user wants to print all the movie data
								from the movie library to a file.  The data is printed in the following order (one piece
								of data per line):
								title, length, year, genre, rating, num oscars won, star rating
			*/
			void saveToFile(char *filename);

			
			
		//accessor methods
		Movie** getMoviesArray(){return this->moviesArray;}
		int getMaxMovies(){return this->maxMovies;}
		int getNumMovies(){return this->numMovies;}
		//Mutator methods
		void setMoviesArray(Movie** m){this->moviesArray = m ;}
		void setMaxMovies(int max){this->maxMovies = max;}
		void setNumMovies(int n){this->numMovies = n;}
	};
#endif