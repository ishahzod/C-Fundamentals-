
#include<iostream>
#include<string>
using namespace std;

class Cd { //represents a CD disk
private:
	string performers;
	string label;
	int selections; //number of selections
	double playtime; // playing time in minutes
public:
	Cd(const char * s1, const char * s2, int n, double x)
		:performers(s1)
		, label(s2)
		, selections(n)
		, playtime(x)
	{
	}

	Cd() {
	}

	Cd(const Cd& copy)
	{
		performers = copy.performers;
		label = copy.label;
		selections = copy.selections;
		playtime = copy.playtime;
	}
	virtual ~Cd() {
	}
	virtual void Report() const
	{

		cout << performers << endl;
		cout << label << endl;
		cout << selections << endl;
		cout << playtime << endl;
	} // reports all CD data
	virtual Cd & operator=(const Cd & d) {
		performers = d.performers;
		label = d.label;
		selections = d.selections;
		playtime = d.playtime;
		return *this;
	}
};

class Classic : public Cd
{
private:
	string primarywork;
public:
	Classic() {}
	Classic(const char *s, const char * s1, const char* s2, int n, double x) :Cd(s1, s2, n, x), primarywork(s)
	{
	}

	Classic(const Classic& copy) :Cd(copy)
	{
		primarywork = copy.primarywork;
	}

	Classic& operator=(const Classic& copy)
	{
		primarywork = copy.primarywork;
		this->Cd::operator=(copy);
		return *this;
	}
	void Report() const
	{
		cout << primarywork << endl;
		Cd::Report();
	}
	~Classic() {}
};

void Bravo(const Cd & disk) {}

int main()
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
	Cd *pcd = &c1;
	cout << "Using object directly: " << endl; ;
	c1.Report(); //use Cd method
	c2.Report(); //use Classic method
	cout << "Using type cd * pointer to object: "<< endl;
	pcd->Report(); //use Cd method for cd object
	pcd = &c2;
	pcd->Report(); //use Classic method for classic object
	cout << "calling a function with a Cd reference argument: " << endl;
	Bravo(c1);
	Bravo(c2);
	cout << "Testing assignment: " << endl;
	Classic copy;
	copy = c2;
	copy.Report();
	system("pause");
	return 0;
}