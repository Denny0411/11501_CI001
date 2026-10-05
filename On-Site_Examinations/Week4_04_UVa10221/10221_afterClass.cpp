#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	double s; // the distance of the satellite from the surface of the earth
	double a; // the angle that the satellites make with the center of earth
	string unit;
	//double PI = 3.14159;
	const double pi = acos(-1);

	while (cin >> s >> a >> unit)
	{
		double arc = 0;
		double chord = 0;
		double length = s + 6440;

		if (unit == "deg")
		{
			if (a > 180)
        		a = 360 - a;
			arc = 2 * length * pi * (a / 360);
			chord = length * sin( (a / 2) / 360 * 2 * pi ) * 2;
			//cout << sin(a) << "\n";
			// sin() 使用的引數是弧度，不是角度
		}
		else if (unit == "min")
		{
			double deg = a / 60;
			if (deg > 180)
        		deg = 360 - deg;
			arc = 2 * length * pi * (deg / 360);
			chord = length * sin( (deg / 2) / 360 * 2 * pi) * 2;
		}

		cout << fixed << setprecision(6) << arc << " " << chord << "\n";

		/*switch (unit)
		{
			case "deg";
				break;

		}*/
	}

	return 0;
}