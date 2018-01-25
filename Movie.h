/*
	Title:  Movie.h
	Author:  April Crockett, modified by David Wallace
	Date:  1/25/2018
	Purpose:  Be able to create, manage, print & delete a single movie.
*/
#ifndef MOVIE_H
#define MOVIE_H

#include "Text.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Movie
{	private:
		Text* movieTitle;  //title of movie
		int movieLength; //length of movie in minutes
		int movieYear; //year released
		Text* movieGenre; //comedy, horror, sci-fi, fantasy, romance, thriller, drama, action, biography
		Text* movieRating; //G, PG, PG-13, R, MA
		int movieOscars; //number of oscars won
		float movieNumStars; //taken from IMDB on 10 star scale

	
public:
	Movie(Text* , int );
	Movie(Text* , int, int , Text* , Text* , int , float );
	~Movie();

/*
	Function name:  editMovie 
	Parameters:  	none
	Returns: 		nothing (void)
	Purpose:  		This function should be called when the user wants to edit a single
					movie's data
*/
	void editMovie();

	/*
		Function name:  printMovieDetails 
		Parameters:  	none
		Returns: 		nothing (void)
		Purpose:  		This function should be called when the user wants to print ALL
						the movie information to the screen.
	*/
	void printMovieDetails();

	/*
		Function name:  printMovieDetailsToFile 
		Parameters:  	a file stream object (sent by reference)
		Returns: 		nothing (void)
		Purpose:  		This function should be called when the user wants to print ALL
						the movie information to the file.
	*/
	void printMovieDetailsToFile( ofstream &outFile);

//Accessor Functions
	Text* getMovieTitle(){		return movieTitle;	}  
	int getMovieLength(){		return movieLength;	}
	int getMovieYear(){			return movieYear;	} 
	Text* getMovieGenre(){		return  movieGenre;	}
	Text* getMovieRating(){		return  movieRating;	}
	int getMovieOscars(){		return  movieOscars; } 
	float getMovieNumStars(){	return  movieNumStars;}

//Mutator Functions
	void setMovieTitle(Text* title){movieTitle = title;}  
	void setMovieLength(int length){movieLength = length;}
	void setMovieYear(int year){movieYear = year;} 
	void setMovieGenre(Text* genre){movieGenre = genre;}
	void setMovieRating(Text* rating){movieRating = rating;}
	void setMovieOscars(int oscars){movieOscars = oscars;} 
	void setMovieNumStars(float numStars){movieNumStars = numStars;}
	};
#endif