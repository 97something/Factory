#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Votes {
  public:
  
    static Votes *count_votes(string choice);
  
    virtual void io() = 0;
    
    virtual ~Votes() = default;

    int total_number_of_votes = 0;
    int alex_number_of_votes = 0;
    int nate_number_of_votes = 0;
    int cam_number_of_votes = 0;
    //my end goal was to get a total vote count and compare them. However, I couldn't seem to get my vote values to increase.


};

class Alex: public Votes {
  public:
    void io() {
      alex_number_of_votes = alex_number_of_votes +1; // my first thought was to try different types of increments. Both styles worked to add 1 but none more.
        cout << "One vote for Alex. Total = "<<alex_number_of_votes<< "\n" ;
    }
};

class Nate: public Votes {
  public:
    void io() {
      ++nate_number_of_votes;// same here
        cout << "One vote for Nate. Total = "<<nate_number_of_votes<< "\n" ;
    }
};

class Cam: public Votes {
  public:
    void io() {
      ++cam_number_of_votes;// same here
        cout << "One vote for Cam. Total = "<<cam_number_of_votes<< "\n" ;
    }
};



Votes *Votes::count_votes(string choice) {
  if (choice ==  "Alex")
  //++alex_number_of_votes; I attempted to include the increment here though that didn't work either due to Votes being within a static memeber?
    return new Alex;
    
  else if (choice == "Nate")
    return new Nate;
  else
    return new Cam;
}

//as we are counting a general number of ballots I didn't think we could increment our values in the main method. I didn't take the time to create a way to find a winner as I couldn't get the increments to work. I imagine I could have done this within the main method though.

int main() {
  vector<Votes*> ballots;
  string choice;
  while (true) {
    cout << "Enter who you are voting for Alex, Nate, or Cam. When all votes are entered enter 0 to count: ";
    cin >> choice;
    if (choice == "0") break;
    ballots.push_back(Votes::count_votes(choice));
  }
  for (int i = 0; i < ballots.size(); i++) {
    ballots[i]->io();
  }
  for (int i = 0; i < ballots.size(); i++) {
    delete ballots[i];
  }
}