/*
	Title:  Movie.cpp
	Author:  April Crockett, modified by David Wallace******************************************************
	Date:  11/7/2017
	Purpose:  Be able to create, manage, print & delete a single movie.
*/
#include "Movie.h"
#include "Text.h"


Movie* createMovie(Text* title, int length, int year, Text* genre, Text* rating, int numOscars, float IMDBRating){
	Movie* myMovie = new Movie;
	
	myMovie->movieTitle = title;
	myMovie->movieLength = length;
	myMovie->movieYear = year;
	myMovie->movieGenre = genre;
	myMovie->movieRating = rating;
	myMovie->movieOscars = numOscars;
	myMovie->movieNumStars = IMDBRating;
	
	return myMovie;
}

void editMovie(Movie* myMovie){
	int userChoice=1;
	int movieInt;
	float movieFloat;
	char userInput[100];
	while(userChoice != 8){
		cout<<endl<<"Which detail do you wish to edit?"<<endl;
		cout<<"1.  Title"<<endl;
		cout<<"2.  Length"<<endl;
		cout<<"3.  Year"<<endl;
		cout<<"4.  Genre"<<endl;
		cout<<"5.  Rating"<<endl;
		cout<<"6.  Number of Oscars won"<<endl;
		cout<<"7.  Number of Stars"<<endl;
		cout<<"8.  DONE EDITING"<<endl;
		cout<<"CHOOSE 1-8:  ";
		cin>>userChoice;
		
		while(userChoice>8 || userChoice<1){
			cout<<"Please choose a valid value"<<endl;
			cout<<"CHOOSE 1-8:  ";
			cin>>userChoice;	
		}
		
		Text* movie = createText(userInput);
			switch(userChoice){
				case 1:				
					cout<<"Current Title: ";
					displayText(myMovie->movieTitle);
					cout<<endl;
					cout<<"NEW TITLE:  ";
					cin.ignore();
					cin.getline(userInput,100);
					movie = createText(userInput);
					destroyText(myMovie->movieTitle);
					setMovieTitle(myMovie,movie);	
					break;
				
				case 2:
					cout<<"Current Length: "<<myMovie->movieLength<<endl;
					cout<<"NEW Length:  ";
					cin>>movieInt;
					setMovieLength(myMovie,movieInt);				
					break;
				
				case 3:
					cout<<"Current Year: "<<myMovie->movieYear<<endl;
					cout<<"NEW Year:  ";
					cin>>movieInt;
					setMovieYear(myMovie,movieInt);			
					break;
				
				case 4:
					cout<<"Current Genre: ";
					displayText(myMovie->movieGenre);
					cout<<endl;
					cout<<"NEW Genre:  ";
					cin.ignore();
					cin.getline(userInput,100);
					movie = createText(userInput);
					destroyText(myMovie->movieGenre);
					setMovieGenre(myMovie,movie);				
					break;
				
				case 5:
					cout<<"Current Rating: ";
					displayText(myMovie->movieRating);
					cout<<endl;
					cout<<"NEW Rating:  ";
					cin>>userInput;
					movie = createText(userInput);
					destroyText(myMovie->movieRating);
					setMovieRating(myMovie,movie);				
					break;
				
				case 6:
					cout<<"Current Number of Oscars won: "<<myMovie->movieOscars<<endl;
					cout<<"NEW Number of Oscars won:  ";
					cin>>movieInt;
					setMovieOscars(myMovie,movieInt);				
					break;
				
				case 7:
					cout<<"Current Number of Stars: "<<myMovie->movieNumStars<<endl;
					cout<<"NEW Number of Stars:  ";
					cin>>movieFloat;
					setMovieNumStars(myMovie,movieFloat);
					break;
				
				case 8:
					userChoice = 8;
					break;
			
			}
		}
}

Movie* createMovie(Text* title, int length)
{
	//dynamically allocate a new Movie
	Movie* myMovie = new Movie;
	
	//assign parameter data to structure memebers
	myMovie->movieTitle = title;
	myMovie->movieLength = length;
	
	return myMovie;
}

void destroyMovie(Movie* myMovie)
{
	destroyText(myMovie->movieTitle);
	destroyText(myMovie->movieGenre);
	destroyText(myMovie->movieRating);
	delete myMovie;
}

void printMovieDetails(Movie* myMovie)
{
	cout << endl;
	cout << right << setw(30) << "Movie Title:  " << left;
	displayText(myMovie->movieTitle);
	cout << endl;
	cout << right << setw(30) << "Length (minutes):  " << left << myMovie->movieLength << endl;
	cout << right << setw(30) << "Year Released:  " << left << myMovie->movieYear << endl;
	cout << right << setw(30) << "Genre:  " << left;
	displayText(myMovie->movieGenre);
	cout << endl;
	cout << right << setw(30) << "Rating:  " << left;
	displayText(myMovie->movieRating);
	cout << endl;
	cout << right << setw(30) << "Number of Oscars Won:  " << left << myMovie->movieOscars << endl;
	cout << right << setw(30) << "Number of Stars:  " << left << myMovie->movieNumStars << endl << endl;
}

void printMovieDetailsToFile(Movie* myMovie, ofstream &outFile)
{
	char temp[1000];
	strncpy(temp, getText(myMovie->movieTitle), 1000);
	outFile << temp << endl;
	outFile << myMovie->movieLength << endl;
	outFile << myMovie->movieYear << endl;
	strncpy(temp, getText(myMovie->movieGenre), 1000);
	outFile << temp << endl;
	strncpy(temp, getText(myMovie->movieRating), 1000);
	outFile << temp << endl;
	outFile << myMovie->movieOscars << endl;
	outFile << myMovie->movieNumStars << endl;
}

Text* getMovieTitle(Movie* myMovie)
{
	return myMovie->movieTitle;
}

int getMovieLength(Movie* myMovie)
{
	return myMovie->movieLength;
}

int getMovieYear(Movie* myMovie)
{
	return myMovie->movieYear;
}

Text* getMovieGenre(Movie* myMovie)
{
	return myMovie->movieGenre;
}

Text* getMovieRating(Movie* myMovie)
{
	return myMovie->movieRating;
}

int getMovieOscars(Movie* myMovie)
{
	return myMovie->movieOscars;
}

float getMovieNumStars(Movie* myMovie)
{
	return myMovie->movieNumStars;
}

void setMovieTitle(Movie* myMovie, Text* title)
{
	myMovie->movieTitle = title;
}

void setMovieLength(Movie* myMovie, int length)
{
	myMovie->movieLength = length;
}

void setMovieYear(Movie* myMovie, int year)
{
	myMovie->movieLength = year;
}

void setMovieGenre(Movie* myMovie, Text* genre)
{
	myMovie->movieGenre = genre;
}

void setMovieRating(Movie* myMovie, Text* rating)
{
	myMovie->movieRating = rating;
}

void setMovieOscars(Movie* myMovie, int nom)
{
	myMovie->movieOscars = nom;
}

void setMovieNumStars(Movie* myMovie, int stars)
{
	myMovie->movieNumStars = stars;
}
