//Shahzodjon Ismatov (110518374)
// Partner: Richard Santella

//ESE 224 Final Project  

#include <string>
#include <stdio.h>
#include <vector>
#include<time.h>
#include <stdlib.h>
#include<iostream>
#include<cstdlib>
using namespace std;
class person {
private:
	int pickup[1000];
	int dropoff[1000];
	int currentpos[1000];
	string direction[1000];
	int elevatorid[1000] = { 0 };
public:
	person();
	void define(int a, int b, int c);
	void setpos(int a, int b);
	bool checkifempty(int b);
	int givepickup(int b);
	int givedropoff(int b);
	int givecurrentpos(int b);
	string givedirection(int b);
	bool gethappy(int a);
	int giveelevatorid(int a);
	void setID(int a, int b);
	int getid(int a);

};
int person::getid(int a) {
	return elevatorid[a];
}
void person::setID(int a, int b) {
	elevatorid[a] = b;
}
int person::giveelevatorid(int a) {
	return elevatorid[a];
}
bool person::gethappy(int a) {
	if (currentpos[a] == dropoff[a])
		return true;
	else return false;
}
person::person() {
}
string person::givedirection(int b) {
	return direction[b];
}
int person::givepickup(int b) {
	return pickup[b];
}
int person::givedropoff(int b) {
	return dropoff[b];
}
int person::givecurrentpos(int b) {
	return currentpos[b];
}
//person::person() {
//  pickup[] = { 0 };
//  dropoff[] = { 0 };
//}
void person::define(int a, int b, int c) {
	elevatorid[c] = 0;
	pickup[c] = a;
	dropoff[c] = b;
	currentpos[c] = a;
	int s = b - a;
	if (s >0) {
		direction[c] = "up";
	}
	else direction[c] = "down";
}
void person::setpos(int a, int b) {// sets the current postion to be able to change it.
	currentpos[b] = a;
}
bool person::checkifempty(int b) {
	if (currentpos[b] != dropoff[b]) {
		return true;  //not empty
	}
	else return false;
}


class elevator {
private:
	string direction[1000]; //{ "up", "down" };
	int capacity[1000];
	int postion[1000];
	int load[1000];//number of people on elevator
	int max;
public:
	elevator();
	void set2(int a, int c, int i);
	void define(int a, int b, int c);
	void set(int a, string b, int c, int i);
	void move(int a);
	string givedirection(int a);
	int givecapacity(int b);
	int givepostion(int b);
	int giveload(int b);

};
void elevator::set2(int a, int c, int i) {
	int w = load[i] + a;
	load[i] = w;
	postion[i] = c;
}

elevator::elevator() {
}
void elevator::move(int a) {
	int b;
	string c;
	b = postion[a];
	c = direction[a];
	if (c == "up") {
		b++;
	}
	if (c == "down") {
		b--;
	}
	if (b < 0) {
		b = 0;
		c = "up";
	}
	if (b >= max) {
		b = 9;
		c = "down";
	}
	postion[a] = b;
	direction[a] = c;
}
void elevator::set(int a, string b, int c, int i) {
	int w = load[i] + a;
	load[i] = w;
	direction[i] = b;
	postion[i] = c;
}
string elevator::givedirection(int a) {
	return direction[a];
}
int elevator::givecapacity(int b) {
	return capacity[b];
}
int elevator::givepostion(int b) {
	return postion[b];
}
int elevator::giveload(int b) {
	return load[b];
}
void elevator::define(int a, int b, int c) { //going to use  construtor to build each elevator
	postion[b] = 0;
	direction[b] = { "up" };//default up, starts at lowest floor*
	capacity[b] = a;
	load[b] = 0;
	max = c;
}
class controller {
private:
	int line[1000] = { 0 };
	int ids[1000][100] = { 0 };
public:
	controller();
	void define(int a, int b, int h);
	void adjust(int b); //adjusts the line
	int getline(int a);
	int getids(int a, int i);
	void output(int h);
};
int controller::getids(int a, int i) {
	//  int pep; 
	if (ids[a][i] == 0) {
		return 0;
	}
	if (ids[a][i] != 0) {
		return ids[a][i];
	}
}

controller::controller() {

}
void controller::adjust(int b) {

	line[b]--;
}
void controller::define(int a, int b, int h) {//declaring in such a way that the name of each controller i=0,1,2 corrosponds to each floor and the value inside is the number in line
	int c;
	c = line[b];
	line[b] = a + c;
	for (int i = 0; i < 1000; i++) {
		if (ids[b][i] == 0) {
			ids[b][i] = h;
			break;
		}
	}
}
void controller::output(int h) {
	cout << "Floors and Lines" << endl;
	for (int i = 0; i < h; i++) {
		cout << i << "   " << line[i] << endl;
	}
}
int controller::getline(int a) {
	return line[a];
}


void generatePeople(int number, int floor); //randomly places a set number of people throught the set number of floors
void generateElevators(int elevate, int cap); //generates a set number of elevators each with the same capacity 
void tellthecontroller(int talley[], int floor); //sends posiston of people on each floor
bool peopleleft(int floor);

int main() {
	person people;
	elevator ele;
	controller controll;
	int number, floor, elevate, cap, given;
	cout << "Please enter the number of floors: " << endl;
	cin >> floor;
	cout << "Please enter the number of elevators: " << endl;
	cin >> elevate;
	//number = 100; //number of people
	cout << "How many intervals of time? " << endl;
	cin >> given;
	/*floor = 50;
	elevate = 3;*/
	cap = 15;
	int start, stop, h = 0, id = 0;
	for (int i = 1; i <= elevate; i++) {
		ele.define(cap, i, floor);
	}
	for (int time = 0; time < given; time++) {

		int talley[1000] = { 0 };


		number = (rand() % 3) + h;

		//generatePeople(number, floor);
		//cout << h << endl << number; //h is the running number of people in the building
		for (h; h <= number; h++) {//generates h number of people
			start = (rand() % floor);
			stop = (rand() % floor);
			//cout << start << " " << stop << endl;

			if (start == stop) {
				h--;
				continue;
			}
			//cout << start << endl;
			talley[start]++;//keeps track of Lines based on starting location 
			people.define(start, stop, id);
			id++;
		}
		cout << endl;
		//tellthecontroller(talley, floor);
		for (int i = 0; i < floor; i++) {
			controll.define(talley[i], i, h);
		}
		controll.output(floor);
		int  l, c, p, line, pep, drop, oneattime, loop, eleid, q;
		string d, dir;
		// main function for program, should be able to tell elevators where to go and who gets dropped off at each floor
		//has to be able to set direction of elevator, maybe call for loops dependent of direction, possibly moving 1 tick at a time shift all elevators
		//than loop that part. when a person gets to a level ignore them
		//// I want to be able to call this which will call the the bool fucntion in person which SHOULD be able to eventualy give a false to keep this running
		{
			for (int i = 1; i <= elevate; i++) {
				d = ele.givedirection(i); //get direction of elevator
				l = ele.giveload(i); //get load
				c = ele.givecapacity(i); //get capacity             
				p = ele.givepostion(i); //get postion
				oneattime = 0;
				cout << " ELEVATOR # " << i << " load:  " << l <<  " postion:  " << p << endl;
				int x;
				for (x = 0; x < floor; x++) {
					line = controll.getline(x); //looks for a line
					if (line != 0) {
						//cout << x;
						//system("pause");
						break;
					}
				}
				cout << endl << x << endl;
				system("pause");
				for (int i = 0; i < h; i++) {
					int uper;
					q = controll.getids(x, i);//gets ids for people who havent been dropped off yet
					if (q == 0) {
						continue;
					}
					//cout << " id " << q << endl;
					pep = people.givecurrentpos(q);
					drop = people.givedropoff(q);
					dir = people.givedirection(q);
					eleid = people.getid(q);
					if (pep != drop && eleid == 0) {
						break;
					}
					if (pep != drop && eleid != 0 && eleid != 98765 && oneattime == 0) {//if a person is on a elevator move them setting eleid to random number so the person is out of system
						if (dir == "up") {
							uper = pep + 1;
							people.setpos(uper, q);
							if (pep == drop) {
								cout << "Person " << q << " has made it to the desired floor" << endl;
								int load = -1;
								d = ele.givedirection(i); //get direction of elevator
								l = ele.giveload(i); //get load
								c = ele.givecapacity(i); //get capacity             
								p = ele.givepostion(i); //get postion
								ele.set(load, dir, p, eleid);
								people.setID(q, 98665);
							}
						}
						if (dir == "lower") {
							uper = pep - 1;
							people.setpos(uper, q);
							if (pep == drop) {
								cout << "Person " << q << " has made it to the desired floor" << endl;
								int load = -1;
								d = ele.givedirection(i); //get direction of elevator
								l = ele.giveload(i); //get load
								c = ele.givecapacity(i); //get capacity             
								p = ele.givepostion(i); //get postion
								ele.set(load, dir, p, eleid);
								people.setID(q, 98665);
							}
							continue;
						}

					}
				}
				oneattime = 1;

				/*int x;
				for (x = 0;x < h;x++) {
				pep = people.givecurrentpos(x);
				drop = people.givedropoff(x);
				dir = people.givedirection(x);
				id = people.getid(x);
				if (pep != drop && id == 0) {
				break;
				}

				}*/
				d = ele.givedirection(i); //get direction of elevator
				l = ele.giveload(i); //get load
				c = ele.givecapacity(i); //get capacity             
				p = ele.givepostion(i); //get postion
				if (l == 0 && pep != p&&people.getid(q) == 0 && people.getid(q) != 98665) {//assigns an elevator to a person and moves it 
					people.setID(q, i);
					string direction;
					int uper;
					int load = 1;
					if ((pep - p) > 0) {
						direction = "up";
						uper = pep + 1;
					}
					if ((pep - p) < 0) {
						direction = "down";
						uper = pep - 1;
					}
					people.setpos(uper, q);
					ele.set(load, direction, p, i);
					ele.move(i);
					cout << endl <<  "Person " << q << " has been assigned to elevator " << i << endl;
					system("pause");
					if (pep == drop) {
						controll.adjust(x);
						cout << "Person " << q << " has made it to the desired floor" << endl;
						load = -1;
						ele.set(load, direction, p, i);
						people.setID(q, 98665);
					}
					//continue;
				}
				//ele.move(i);

				if (drop == p) {
					int load = -1;
					ele.set(load, dir, p, i);
				}

				for (int r = 0; r < h; r++) { //cycle through all people, not just the one in front of line to get all on elevator
					pep = people.givecurrentpos(r);
					drop = people.givedropoff(r);
					dir = people.givedirection(r);
					eleid = people.getid(r);
					if ((l != 0 && l < c &&pep == p && dir == d&& people.getid(r) != 98665)) {//if load doesnt eqal 0 load is less than capacity elevator on same floor as a person and same direction 
						people.setID(r, i);
						int load = 1;
						ele.set2(load, p, i);
						ele.move(i);
						int uper;
						if (dir == "up") {
							uper = pep + 1;
						}
						if (dir == "down") {
							uper = pep - 1;
						}
						people.setpos(uper, r);
						cout << "Person " << r << " has is on elevator " << i << endl;
						if (pep == drop) {
							load = -1;
							cout << "Person " << q << " has made it to the desired floor" << endl;
							ele.set(load, dir, p, i);
							people.setID(q, 98665);
							controll.adjust(x);
						}
					}


				}
				ele.move(i);
				continue;

			}

		}
	}
}









//
//      for (int i = 1; i <= elevate; i++) {//call each elevator, looks to see where it is, than if there is space than fills it to its Max if possible, than it will go either up or down one and****** UNLOADS passageners, important so people dont get trapped****
//          d = ele.givedirection(i); //get direction of elevator
//          l = ele.giveload(i); //get load
//          c = ele.givecapacity(i); //get capacity             
//          p = ele.givepostion(i); //get postion
//
//          system("pause");
//          if (l < c) {
//              loop = 0;
//          
//
//          while (line != 0) 
//              {
//                  //line = controll.getline(p);
//                  //check to see if there is a line, if there is a line than move people on to elevator,* make sure they are going the right direction*, keep track of who is on elevator somehow
//                  //for (int w = 0; w < number; w++) 
//                  {
//                      pep = people.givecurrentpos(w);
//                      dir = people.givedirection(w);
//                      drop = people.givedropoff(w);
//                      //cout << w << " " << pep << " " << drop<<endl;
//                  //  cout << w << "<--# and pos--> " << pep << " " << dir << "<--direction and dropff-->" << drop << endl;
//                      oneattime = 0;
//                      /* the person wants to go IP*/
//                      //cout << "load " << l << " capacity " << c<<endl;
//                      if (c == l || l > c) {
//                          break;
//                      }
//                      if (pep == p && dir == "up" && d == "up"&& l < c) {
//                          int uper = pep + 1;
//                          string up = "up";
//                          people.setpos(uper, w);
//                          int increase = 1;
//                          if (people.gethappy(w)) {
//                              increase = -1;
//                          }
//                          ele.set(increase, up, p, i);
//                          //add person to elevator and load +1
//                          int linedown = -1;
//                          int q = 0;
//                          controll.adjust(linedown, p, q);
//                          line = controll.getline(p);
//                          //  cout << "1"<<endl;
//                          oneattime = 1;
//                          continue;
//                      }
//                      /*the person wants to go DOWN*/
//                      if (pep == p && dir == "down" && d == "down"&& l < c) {
//                          //add person to elvator and load +1
//                          int downer = pep - 1;
//                          string down = "down";
//                          int decrease = 1;
//                          people.setpos(downer, w);
//                          if (people.gethappy(w)) {
//                              decrease = -1;
//                          }
//                          ele.set(decrease, down, p, i);
//                          int linedown = -1;
//                          int q = 0;
//                          controll.adjust(linedown, p, q);
//                          line = controll.getline(p);
//                          oneattime = 1;
//                          //cout << "2"<<endl;
//                          continue;
//                      }
//                      if (pep == p && l == 0 && oneattime == 0) {
//                          if (dir == "up") {
//                              int uper = pep + 1;
//                              string up = "up";
//                              people.setpos(uper, w);
//                              int increase = 1;
//                              if (people.gethappy(w)) {
//                                  increase = -1;
//                              }
//                              ele.set(increase, up, p, i);
//                              //add person to elevator and load +1
//                              int linedown = -1;
//                              int q = 0;
//                              controll.adjust(linedown, p, q);
//                              line = controll.getline(p);
//                              //  cout << "1"<<endl;
//                              oneattime = 1;
//                              continue;
//
//                          }
//                          if (dir == "down") {
//                              int downer = pep - 1;
//                              string down = "down";
//                              int decrease = 1;
//                              people.setpos(downer, w);
//                              if (people.gethappy(w)) {
//                                  decrease = -1;
//                              }
//                              ele.set(decrease, down, p, i);
//                              int linedown = -1;
//                              int q = 0;
//                              controll.adjust(linedown, p, q);
//                              line = controll.getline(p);
//                              oneattime = 1;
//                              continue;
//                          }
//                      }
//                      if (pep == drop) {
//                          continue;
//                      }
//                  }
//                  if (line == 0) {
//                      break;
//
//                  }
//                  if (l == c) {
//                      break;
//                  }
//
//
//                  if (loop == 1) {
//                      break;
//                  }
//
//                  loop++;
//              }
//
//          }
//              ele.move(i);
//              d = ele.givedirection(i); //get direction of elevator
//              l = ele.giveload(i); //get load
//              c = ele.givecapacity(i); //get capacity             
//              p = ele.givepostion(i); //get postion
//              cout << d << "<--direction   load-->" << l << " postion--> " << p << "#--> " << i << endl;
//
//          //have elevator look to see if people can get dropped off if no one can move in direction 
//      }
//      }
//  }
//  system("pause");
//}
//
//
//bool peopleleft(int number) {
//  int j;
//  return false;
//  for (int i = 0; i < number; i++) { //check each of the persons to see if each person is happy :)
//      elevator checkifempty(int number);  //call each name and retuns turn if 
//  }
//}
