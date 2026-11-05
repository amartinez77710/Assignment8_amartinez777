#include <iostream>
#include <cmath>

class Field
{
	protected: //Using protected or the operator wont work
	double *value;

	public:
	double x, y ,z;

	//Setters
        void setX(double x_value) { value[0] = x_value; }
        void setY(double y_value) { value[1] = y_value; }
        void setZ(double z_value) { value[2] = z_value; }

        //Getters
	double getX() const { return value[0]; }
	double getY() const { return value[1]; }
	double getZ() const { return value[2]; }
	
	//Default Constructor
	Field() : x(0.0), y(0.0), z(0.0) { value = new double[3]; }
	
	//Parameterized Constructor
	Field(double x_value, double y_value, double z_value) {
		value = new double[3];
		setX(x_value);
		setY(y_value);
 		setZ(z_value);
	}
	
	//Function for magnitude and component print
	void printData(){
		std::cout << "Components: (" << getX() << ", " << getY() << ", " << getZ() << ")" << std::endl;
		double magnitude;
		magnitude = sqrt(getX()*getX() + getY()*getY() + getZ()*getZ());
		std::cout << "Magnitude: " << magnitude;
	}

	//Destructor
	~Field(){
		delete[] value;
	}


};

//Electric Field Inheritance
class Electric_Field : public Field {
	private:
	double E;

	public:
	
	//Default Constructor
	Electric_Field() : Field() {
		setX(1e1);
		setY(1e2);
		setZ(1e3);
	}
	
	//Parameterized Constructor
	Electric_Field(double x_value, double y_value, double z_value) : Field(x_value, y_value, z_value) {
		setX(x_value);
		setY(y_value);
		setZ(z_value);
	}

	//OPERATOR so E3 = E1 + E2 is possible
	Electric_Field operator+(const Electric_Field& other) const {
        	return Electric_Field(value[0] + other.value[0], value[1] + other.value[1], value[2] + other.value[2]);
	}
	
	//Using Gauss's law equation, Q is charge, and R is radius
	void gaussLaw(double Q, double R){
		double E;
		double epsilon_o = 8.854e-12;
		double pi = 3.141;
		E = Q/(4.0*pi*(R*R)*epsilon_o);
		std::cout << "\nElectric Field Value: " << E << " N * m^2/C" << std::endl;
	}
};

//Magnetic Field Inheritance
class Magnetic_Field : public Field {
	private:
        double B;

        public:

	//Default constructor
        Magnetic_Field() : Field() {
                setX(1e1);
                setY(1e2);
                setZ(1e3);
        }
	
	//Parameterized constructor
        Magnetic_Field(double x_value, double y_value, double z_value) : Field(x_value, y_value, z_value) {
                setX(x_value);
                setY(y_value);
                setZ(z_value);
        }
	
	//OPERATOR So B3 = B1 + B2 is possible
	Magnetic_Field operator+(const Magnetic_Field& other) const {
                return Magnetic_Field(value[0] + other.value[0], value[1] + other.value[1], value[2] + other.value[2]);
        }
	
	//Function to print amperes law equation, I is current, R is radius
	void ampereLaw(double I, double R){
		double pi = 3.141;
		double mu = 4.0*pi*1e-7;
		B = I/(2.0*pi*R*mu);
		std::cout << "\nMagnetic Field Value: " <<  B << " T" << std::endl;
	}
};

int main(){
	
	//3 electric field objects
	Electric_Field E1(0,1,2);
	Electric_Field E2(1e-2, 2e-1, 2e-1);
	Electric_Field E3 = E1 + E2; //Operator usage
	
	//3 magnetic field objects
	Magnetic_Field B1(2,1,0);
	Magnetic_Field B2(11e-1, 1e-1, 9e-1);
	Magnetic_Field B3 = B1 + B2; //Operator usage

	//ELECTRIC FIELD PRINT
	std::cout << "\n--Electric Field 1--" << std::endl;
	E1.printData();
	E1.gaussLaw(1.6e-19, 0.5); //1.6e-19 coulombs, 0.5 meters

	std::cout << "\n\n--Electric Field 2--" << std::endl;
        E2.printData();
	E2.gaussLaw(3.6e-19, 1); //3.6e-19 coulombs, 1 meter

	std::cout << "\n\n--Electric Field 3--" << std::endl;
	E3.printData();
	E3.gaussLaw(12e-19, 2); //12e-19 coulombs, 2 meters
	

	//MAGNETIC FIELD PRINTING
	std::cout << "\n--Magnetic Field 1--" << std::endl;
        B1.printData();
        B1.ampereLaw(0.3, 0.5); //0.3 Amps, 0.5 meters

        std::cout << "\n\n--Magnetic Field 2--" << std::endl;
        B2.printData();
        B2.ampereLaw(0.9, 1); //0.9 Amps, 1 meter

        std::cout << "\n\n--Magnetic Field 3--" << std::endl;
        B3.printData();
        B3.ampereLaw(1, 2); //1 Amps, 2 meters
	
	return 0;
}
	


