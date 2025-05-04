//Program to calculate the areas of Square, Cube, Rectangle, and Cuboid using a menu getting dimensions as input
#include <stdio.h>

class AreaCal {
    private:
        float length, breadth, height;
    public:
        AreaCal() : length(0), breadth(0), height(0) {}

        void Length(float);
        void DimRect(float,float);
        void setCuboidDimensions(double, double, double);
        

        double calculateSquareArea() const;
        double calculateCubeArea() const;
        double calculateRectangleArea() const;
        double calculateCuboidArea() const;

};

int main(){
    AreaCal cal;
    int choice;
    float l,b,h;
    do {
        printf("\nMENU\n");
        printf("1. Square\n2. Cube\n3. Rectangle\n4. Cuboid\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if ((choice)>=1 && (choice)<=4){
            switch(choice){
                case 1:
                    printf("Enter side of square:");
                    scanf("%f", &l);
                    cal.Length(l);
                    printf("Area of square= %f", cal.calculateSquareArea());
                    break;
                case 2:
                    printf("Enter side of cube:");
                    scanf("%f", &l);
                    cal.Length(l);
                    printf("Area of cube= %f", cal.calculateCubeArea());
                    break;
                case 3:
                    printf("Enter length of rectangle:");
                    scanf("%f", &l);
                    printf("Enter breadth of rectangle:");
                    scanf("%f", &b);
                    cal.DimRect(l,b);
                    printf("Area of rectangle= %f", cal.calculateRectangleArea());
                    break;
                case 4:
                    printf("Enter length of cuboid:");
                    scanf("%f", &l);
                    printf("Enter breadth of cuboid:");
                    scanf("%f", &b);
                    printf("Enter height of cuboid:");
                    scanf("%f", &h);
                    cal.setCuboidDimensions(l,h,b);
                    printf("Area of cuboid= %f", cal.calculateCuboidArea());
                    break;
            }
        } 
        else if ((choice)!=5){
            printf("Invalid choice. Try again\n");
        }
        printf("\n");
    } while ((choice)!=5);
    return 0;
}

// Function to set dimensions for square and cube
void AreaCal::Length(float l){
    if (l<=0){
        printf("\nLength must be greater than zero.\n");
        return;
    }
    length= l;

} 

// Function to set dimensions for rectangle
void AreaCal::DimRect(float l,float b){
    if (l <= 0 || b <= 0) {
        printf("\nLength and breadth must be greater than zero.\n");
        return;
}
length = l;
breadth = b;
}   

// Function to set dimensions for cuboid
void AreaCal::setCuboidDimensions(double l, double b, double h) {
    if (l <= 0 || b <= 0 || h <= 0) {
        printf("\nLength, breadth, and height must be greater than zero.\n");
        return;
    }
    length = l;
    breadth = b;
    height = h;
}

 // Function to calculate and return the area of a square
 double AreaCal::calculateSquareArea() const {
    return length * length;
}

// Function to calculate and return the surface area of a cube
double AreaCal::calculateCubeArea() const {
    return 6 * length * length;
}

// Function to calculate and return the area of a rectangle
double AreaCal::calculateRectangleArea() const {
    return length * breadth;
}

// Function to calculate and return the surface area of a cuboid
double AreaCal::calculateCuboidArea() const {
    return 2 * (length * breadth + breadth * height + height * length);
}