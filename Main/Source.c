#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void step_stairs_output();
int step_stairs_calc(int numStairs, int numPlate);

void flight_stairs_output();
double flight_stairs_calc(int numFlight, int numPlate);

void save_to_file(char* filename);

typedef struct {
    double plateLength;
    double plateWidth;
} plate;

typedef struct {
    double stepHeight;
    double stepWidth;
    double stepLength;
    int stepAmount;
} stairs;

typedef struct {
    double flightHeight;
    double flightWidth;
    double flightLength;
} flight;

plate objectsPlate[100];
int numPlate = 0;

stairs objectsStairs[100];
int numStairs = 0;

flight objectsFlight[100];
int numFlight = 0;

int main()
{
    setlocale(LC_CTYPE, "RUS");

    char filename[100];
    char loadfile[100];

    int choice;

    printf("Ïðîãðàììà äëÿ ðàñ÷¸òà êîëè÷åñòâà ïëèòîê äëÿ îáëèöîâêè ñòóïåíåê èëè ïëîùàäêè.\n\n");

    do
    {
        printf("\nÌåíþ:\n");
        printf("1. Ñîçäàòü ñòóïåíè\n");
        printf("2. Ñîçäàòü ïëîùàäêè\n");
        printf("3. Ñîçäàííûå ëåñòíèöû\n");
        printf("4. Ñîçäàííûå ïëîùàäêè\n");
        printf("5. Ñîõðàíèòü äàííûå â ôàéë\n");
        printf("0. Âûéòè\n");
        printf("Âûáåðèòå äåéñòâèå: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            step_stairs_output();
            break;

        case 2:
            flight_stairs_output();
            break;

        case 3:
            if (numStairs == 0) printf("Íåò ëåñòíèö.\n");
            else
            {
                printf("\nÈíôîðìàöèÿ î ëåñòíèöàõ:\n");
                for (int i = 0; i < numStairs; i++)
                {
                    printf("Ëåñòíèöà %d\n", i + 1);
                    printf("Âûñîòà ñòóïåíüêè: %d ì.\n", objectsStairs[i].stepHeight);
                    printf("Øèðèíà ñòóïåíüêè: %d ì.\n", objectsStairs[i].stepWidth);
                    printf("Äëèíà ñòóïåíüêè: %d ì.\n", objectsStairs[i].stepLength);
                    printf("Êîëè÷åñòâî ñòóïåíåê: %d\n", objectsStairs[i].stepAmount);
                    printf("\n");
                }
            }
            break;

        case 4:
            if (numFlight == 0) printf("Íåò ïëîùàäîê.\n");
            else
            {
                printf("\nÈíôîðìàöèÿ î ïëîùàäêàõ:\n");
                for (int i = 0; i < numFlight; i++)
                {
                    printf("Ïëîùàäêà %d\n", i + 1);
                    printf("Âûñîòà ïëîùàäêè: %g ì.\n", objectsFlight[i].flightHeight);
                    printf("Øèðèíà ïëîùàäêè: %g ì.\n", objectsFlight[i].flightWidth);
                    printf("Äëèíà ïëîùàäêè: %g ì.\n", objectsFlight[i].flightLength);
                    printf("\n");
                }
            }
            break;

        case 5:
            printf("Ââåäèòå íàçâàíèå ñîõðàíÿåìîãî ôàéëà: ");
            scanf("%s", filename);
            save_to_file(filename);
            break;

        case 0:
            break;

        default:printf("Íåêîððåêòíûé ââîä. Ïîïðîáóéòå åù¸ ðàç.\n");
            break;
        }
    } while (choice != 0);
    return 0;
}


void step_stairs_output()
{
    int result;
    printf("Ââåäèòå äëèíó îäíîé ïëèòêè (â ìåòðàõ): ");
    scanf("%lf", &objectsPlate[numPlate].plateLength);
    printf("Ââåäèòå øèðèíó îäíîé ïëèòêè (â ìåòðàõ): ");
    scanf("%lf", &objectsPlate[numPlate].plateWidth);
    printf("Ââåäèòå âûñîòó ñòóïåíüêè (â ìåòðàõ): ");
    scanf("%lf", &objectsStairs[numStairs].stepHeight);
    printf("Ââåäèòå øèðèíó ñòóïåíüêè (â ìåòðàõ): ");
    scanf("%lf", &objectsStairs[numStairs].stepWidth);
    printf("Ââåäèòå äëèíó ñòóïåíüêè (â ìåòðàõ): ");
    scanf("%lf", &objectsStairs[numStairs].stepLength);
    printf("Ââåäèòå êîëè÷åñòâî ñòóïåíåê: ");
    scanf("%d", &objectsStairs[numStairs].stepAmount);

    printf("Âû ââåëè ñëåäóþùèå äàííûå:\n");
    printf("Äëèíà îäíîé ïëèòêè: %g ì.\n", objectsPlate[numPlate].plateLength);
    printf("Øèðèíà îäíîé ïëèòêè: %g ì.\n", objectsPlate[numPlate].plateWidth);
    printf("Âûñîòà ñòóïåíüêè: %g ì.\n", objectsStairs[numStairs].stepHeight);
    printf("Øèðèíà ñòóïåíüêè: %g ì.\n", objectsStairs[numStairs].stepWidth);
    printf("Äëèíà ñòóïåíüêè: %g ì.\n", objectsStairs[numStairs].stepLength);
    printf("Êîëè÷åñòâî ñòóïåíåê: %d\n", objectsStairs[numStairs].stepAmount);

    result = step_stairs_calc(numStairs, numPlate);

    printf("Äëÿ îáëèöîâêè ñòóïåíåê âàì íåîáõîäèìî: %d ïëèòîê\n", result);

    numStairs++;

}

int step_stairs_calc(int numStairs, int numPlate)
{
    double step_width = objectsStairs[numStairs].stepWidth;
    double step_length = objectsStairs[numStairs].stepLength;
    double step_height = objectsStairs[numStairs].stepHeight;
    int step_amount = objectsStairs[numStairs].stepAmount;
    double plate_width = objectsPlate[numPlate].plateWidth;
    double plate_length = objectsPlate[numPlate].plateLength;

    double hor_square, ver_square, plate_square;
    int result;

    plate_square = plate_width * plate_length;
    hor_square = step_width * step_length;
    ver_square = step_length * step_height;
    result = ((ceil(hor_square / plate_square) + ceil(ver_square / plate_square)) * step_amount);
    return result;
}

void flight_stairs_output()
{
    int result;
    printf("Ââåäèòå äëèíó îäíîé ïëèòêè (â ìåòðàõ): ");
    scanf("%lf", &objectsPlate[numPlate].plateLength);
    printf("Ââåäèòå øèðèíó îäíîé ïëèòêè (â ìåòðàõ): ");
    scanf("%lf", &objectsPlate[numPlate].plateWidth);
    printf("Ââåäèòå âûñîòó ïëîùàäêè (â ìåòðàõ): ");
    scanf("%lf", &objectsFlight[numFlight].flightHeight);
    printf("Ââåäèòå øèðèíó ïëîùàäêè (â ìåòðàõ): ");
    scanf("%lf", &objectsFlight[numFlight].flightWidth);
    printf("Ââåäèòå äëèíó ïëîùàäêè (â ìåòðàõ): ");
    scanf("%lf", &objectsFlight[numFlight].flightLength);

    printf("Âû ââåëè ñëåäóþùèå äàííûå:\n");
    printf("Äëèíà îäíîé ïëèòêè: %g ì.\n", objectsPlate[numPlate].plateLength);
    printf("Øèðèíà îäíîé ïëèòêè: %g ì.\n", objectsPlate[numPlate].plateWidth);
    printf("Âûñîòà ïëîùàäêè: %g ì.\n", objectsFlight[numFlight].flightHeight);
    printf("Øèðèíà ïëîùàäêè: %g ì.\n", objectsFlight[numFlight].flightWidth);
    printf("Äëèíà ñòóïåíüêè: %g ì.\n", objectsFlight[numFlight].flightLength);

    result = flight_stairs_calc(numFlight, numPlate);

    printf("Äëÿ îáëèöîâêè ïëîùàäêè âàì íåîáõîäèìî: %d ïëèòîê.", result);

    numFlight++;

}

double flight_stairs_calc(int numFlight, int numPlate)
{
    double flight_width = objectsFlight[numFlight].flightWidth;
    double flight_length = objectsFlight[numFlight].flightLength;
    double flight_height = objectsFlight[numFlight].flightHeight;
    double plate_width = objectsPlate[numPlate].plateWidth;
    double plate_length = objectsPlate[numPlate].plateLength;

    double hor_square, ver_square, plate_square;
    int result;

    plate_square = plate_width * plate_length;
    hor_square = flight_width * flight_length;
    ver_square = flight_length * flight_height;
    result = (ceil(hor_square / plate_square) + ceil(ver_square / plate_square));
    return result;
}

void save_to_file(char* filename) {

    if (numStairs == 0 && numFlight == 0) {
        printf("Íåò îáúåêòîâ äëÿ ñîõðàíåíèÿ.\n");
        return;
    }

    FILE* file = fopen(filename, "w");

    if (file == NULL) {
        printf("Íå óäàëîñü îòêðûòü ôàéë äëÿ çàïèñè.\n");
        return;
    }

    fprintf(file, "Ëåñòíèöû:\n");
    for (int i = 0; i < numStairs; i++) {
        fprintf(file, "Ëåñòíèöà %d\n", i + 1);
        fprintf(file, "Âûñîòà ñòóïåíüêè: %g ì.\n", objectsStairs[i].stepHeight);
        fprintf(file, "Øèðèíà ñòóïåíüêè: %g ì.\n", objectsStairs[i].stepWidth);
        fprintf(file, "Äëèíà ñòóïåíüêè: %g ì.\n", objectsStairs[i].stepLength);
        fprintf(file, "Êîëè÷åñòâî ñòóïåíåê: %d\n", objectsStairs[i].stepAmount);
        fprintf(file, "\n");
    }

    fprintf(file, "Ïëîùàäêè:\n");
    for (int i = 0; i < numFlight; i++) {
        fprintf(file, "Ïëîùàäêà %d\n", i + 1);
        fprintf(file, "Âûñîòà ïëîùàäêè: %g ì.\n", objectsFlight[i].flightHeight);
        fprintf(file, "Øèðèíà ïëîùàäêè: %g ì.\n", objectsFlight[i].flightWidth);
        fprintf(file, "Äëèíà ïëîùàäêè: %g ì.\n", objectsFlight[i].flightLength);
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Äàííûå óñïåøíî ñîõðàíåíû â ôàéë '%s'.\n", filename);
}
