#include <stdio.h>;
#include <math.h>;

double ChanceOfPet(double dropRate, double totalChances) {
    double netChance;

    netChance = 1.0 - pow(1.0 - (1.0 / dropRate), totalChances);

    return netChance;
}

int main() {
    double dropRate = 0.0;
    double totalChances = 0.0;
    double netChance = 0.0;

    printf("The chance of getting the pet or item is 1 out of x, what is x?:\n");
    scanf_s("%lf", &dropRate);

    printf("How many chances have you had in total?:\n");
    scanf_s("%lf",&totalChances);

    netChance = ChanceOfPet(dropRate, totalChances);
    printf("the chance is %lf%s \n", netChance * 100,%);
    
    return 0;
} 