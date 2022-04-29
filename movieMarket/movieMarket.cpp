#include <iostream>
#include <fstream>
#include <sstream>
#include <list>

using namespace std;

class Movie {
	
	private:		
		int id;
		float point;
		string name;
		int year;				
	public:				
		void setPoint(float new_point){
			point = new_point;
		}		
		void setId(int new_id){
			id = new_id;
		}		
		void setName(string new_name){
			name = new_name;
		}		
		void setYear(int new_year){
			year = new_year;
		}	    
		int getId(){
			return id;
		}			
		float getPoint(){
			return point;
		}		
		string getName(){
			return name;
		}			
		int getYear(){
			return year;
		}		
		void printMovie() {
            cout << "ID : " << id << " Point : " << point << " Name : " << name << " Year : " << year << endl;
        }
		
};

int main() {

    ifstream read_file;
    read_file.open(".../movies.txt");

    if (!read_file.is_open()) {
        cerr << "File  could not be opened" << endl;
        // Using function to stop execution of the code completely.
        exit(1);
    }

    string line;
    string point;
    string name;
    string year;
    
    Movie movie_list[250];
    int counter = 0;
    int id = 1;
    while (getline(read_file, line)) {
        
		stringstream line_stream(line);

        getline(line_stream, point, ';');
        getline(line_stream, name, '(');
        getline(line_stream, year, ')');

        int integer_year = stoi(year);
        float float_point = stof(point);
        
        movie_list[counter].setId(id);
        movie_list[counter].setPoint(float_point);
        movie_list[counter].setName(name);
        movie_list[counter].setYear(integer_year);
        
        counter++;
        id++;  
    }
    read_file.close();

    cout << "Welcome to the Movie Market. Please select an option." << endl;
    cout << "1 - Get movie details by ID" << endl;
    cout << "2 - List movies between the years entered" << endl;
    cout << "3 - Change the point of a movie" << endl;
    cout << "4 - Get movie details starting with the entered letter" << endl;
    cout << "5 - Exit" << endl;
    
    int x;
    cin >> x;
    
    if(x==1){
    	for (int i = 0; i < 250; i++) {
             movie_list[i].printMovie();             
        }
	
	}else if(x==2){
		cout << "Enter the year to list movies in that year: ";
		int y ;
        cin >> y;
		for (int i = 0; i < 250; i++) {
             
             if(y == movie_list[i].getYear()){
             	cout << movie_list[i].getName() << endl;
			 }else{
			 	cout << "" ;
			 }
        }	
	
	}else if(x==3){
		cout << "Enter the id of movie that you want to change point: " ;
		int i;
		cin >> i;
		cout << "The movie that you want to change point is" << movie_list[i].getName() << "with the current point of " << movie_list[i].getPoint() << endl; 
		cout << "Enter the point that you want to replace: " ;
		int p;
		cin >> p;
		movie_list[i].setPoint(p);
		cout << "You changed point of " << movie_list[i].getName()<< "to " << movie_list[i].getPoint() << endl;
	
	}else if(x==4){
		cout << "Enter first letter of a movie to get details: ";
		char l;
		cin >> l;
		for (int i = 0; i < 250; i++) {
             string x = movie_list[i].getName();
             char x_lower = tolower(x[0]);
             if( l == x_lower || l == x[0]){ //Uppercase&lowercase confusing is prevented
             	cout << movie_list[i].getName() << endl;
			 }else{
			 	cout << "" ;
			 }
        }
		
	}else if(x==5){
		cout << "EXIT" << endl;
	
	}else{
		cout << "invalid data is entered." << endl; // prevented the program from throwing an error when an undefined data is entered 
	}
    
    return 0;
}

