#include <iostream>
#include <cmath>

class Field
{
	private:
	double *value

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

	Field() : x(0.0), y(0.0), z(0.0) {}
	Field(double x_value, double y_value, double z_value) {
		setX(x_value);
		setY(y_value);
 		setZ(z_value);
	}


};

class Field : public Electric_Field {
	private:
	double E;

	public:
	Electric_Field() : Field(), {
		setX(1e1);
		setY(1e2);
		setZ(1e3);
	}

	Electric_Field(double x_value, double y_value, double z_value) : Field(x_value, y_value, z_value) {
		setX(x_value);
		setY(y_value);
		setZ(z_value);
	}

	void gaussLaw(){
		E = 
};


class Field : public Magnetic_Field {
	private:
        double B;

        public:
        Magnetic_Field() : Field(), {
                setX(1e1);
                setY(1e2);
                setZ(1e3);
        }

        Magnetic_Field(double x_value, double y_value, double z_value) : Field(x_value, y_value, z_value) {
                setX(x_value);
                setY(y_value);
                setZ(z_value);
        }

	void ampereLaw(
};

int main(){


