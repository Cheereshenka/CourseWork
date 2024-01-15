#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void step_stairs_output();
int step_stairs_calc(int numStairs, int numPlate);

void flight_stairs_output();
double flight_stairs_calc(int numFlight, int numPlate);

void save_to_file(char* filename);
void load_from_file(char filename[100]);

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

    printf("��������� ��� ������� ���������� ������ ��� ��������� �������� ��� ��������.\n\n");

    do
    {
        printf("\n����:\n");
        printf("1. ������� �������\n");
        printf("2. ������� ��������\n");
        printf("3. ��������� ��������\n");
        printf("4. ��������� ��������\n");
        printf("5. ��������� ������ � ����\n");
        printf("0. �����\n");
        printf("�������� ��������: \n");
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
            if (numStairs == 0) printf("��� �������.\n");
            else
            {
                printf("\n���������� � ���������:\n");
                for (int i = 0; i < numStairs; i++)
                {
                    printf("�������� %d\n", i + 1);
                    printf("������ ���������: %d �.\n", objectsStairs[i].stepHeight);
                    printf("������ ���������: %d �.\n", objectsStairs[i].stepWidth);
                    printf("����� ���������: %d �.\n", objectsStairs[i].stepLength);
                    printf("���������� ��������: %d\n", objectsStairs[i].stepAmount);
                    printf("\n");
                }
            }
            break;

        case 4:
            if (numFlight == 0) printf("��� ��������.\n");
            else
            {
                printf("\n���������� � ���������:\n");
                for (int i = 0; i < numFlight; i++)
                {
                    printf("�������� %d\n", i + 1);
                    printf("������ ��������: %g �.\n", objectsFlight[i].flightHeight);
                    printf("������ ��������: %g �.\n", objectsFlight[i].flightWidth);
                    printf("����� ��������: %g �.\n", objectsFlight[i].flightLength);
                    printf("\n");
                }
            }
            break;

        case 5:
            printf("������� �������� ������������ �����: ");
            scanf("%s", filename);
            save_to_file(filename);
            break;

        case 0:
            break;

        default:printf("������������ ����. ���������� ��� ���.\n");
            break;
        }
    } while (choice != 0);
    return 0;
}


void step_stairs_output()
{
    int result;
    printf("������� ����� ����� ������ (� ������): ");
    scanf("%lf", &objectsPlate[numPlate].plateLength);
    printf("������� ������ ����� ������ (� ������): ");
    scanf("%lf", &objectsPlate[numPlate].plateWidth);
    printf("������� ������ ��������� (� ������): ");
    scanf("%lf", &objectsStairs[numStairs].stepHeight);
    printf("������� ������ ��������� (� ������): ");
    scanf("%lf", &objectsStairs[numStairs].stepWidth);
    printf("������� ����� ��������� (� ������): ");
    scanf("%lf", &objectsStairs[numStairs].stepLength);
    printf("������� ���������� ��������: ");
    scanf("%d", &objectsStairs[numStairs].stepAmount);

    printf("�� ����� ��������� ������:\n");
    printf("����� ����� ������: %g �.\n", objectsPlate[numPlate].plateLength);
    printf("������ ����� ������: %g �.\n", objectsPlate[numPlate].plateWidth);
    printf("������ ���������: %g �.\n", objectsStairs[numStairs].stepHeight);
    printf("������ ���������: %g �.\n", objectsStairs[numStairs].stepWidth);
    printf("����� ���������: %g �.\n", objectsStairs[numStairs].stepLength);
    printf("���������� ��������: %d\n", objectsStairs[numStairs].stepAmount);

    result = step_stairs_calc(numStairs, numPlate);

    printf("��� ��������� �������� ��� ����������: %d ������\n", result);

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
    printf("������� ����� ����� ������ (� ������): ");
    scanf("%lf", &objectsPlate[numPlate].plateLength);
    printf("������� ������ ����� ������ (� ������): ");
    scanf("%lf", &objectsPlate[numPlate].plateWidth);
    printf("������� ������ �������� (� ������): ");
    scanf("%lf", &objectsFlight[numFlight].flightHeight);
    printf("������� ������ �������� (� ������): ");
    scanf("%lf", &objectsFlight[numFlight].flightWidth);
    printf("������� ����� �������� (� ������): ");
    scanf("%lf", &objectsFlight[numFlight].flightLength);

    printf("�� ����� ��������� ������:\n");
    printf("����� ����� ������: %g �.\n", objectsPlate[numPlate].plateLength);
    printf("������ ����� ������: %g �.\n", objectsPlate[numPlate].plateWidth);
    printf("������ ��������: %g �.\n", objectsFlight[numFlight].flightHeight);
    printf("������ ��������: %g �.\n", objectsFlight[numFlight].flightWidth);
    printf("����� ���������: %g �.\n", objectsFlight[numFlight].flightLength);

    result = flight_stairs_calc(numFlight, numPlate);

    printf("��� ��������� �������� ��� ����������: %d ������.", result);

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
        printf("��� �������� ��� ����������.\n");
        return;
    }

    FILE* file = fopen(filename, "w");

    if (file == NULL) {
        printf("�� ������� ������� ���� ��� ������.\n");
        return;
    }

    fprintf(file, "��������:\n");
    for (int i = 0; i < numStairs; i++) {
        fprintf(file, "�������� %d\n", i + 1);
        fprintf(file, "������ ���������: %g �.\n", objectsStairs[i].stepHeight);
        fprintf(file, "������ ���������: %g �.\n", objectsStairs[i].stepWidth);
        fprintf(file, "����� ���������: %g �.\n", objectsStairs[i].stepLength);
        fprintf(file, "���������� ��������: %d\n", objectsStairs[i].stepAmount);
        fprintf(file, "\n");
    }

    fprintf(file, "��������:\n");
    for (int i = 0; i < numFlight; i++) {
        fprintf(file, "�������� %d\n", i + 1);
        fprintf(file, "������ ��������: %g �.\n", objectsFlight[i].flightHeight);
        fprintf(file, "������ ��������: %g �.\n", objectsFlight[i].flightWidth);
        fprintf(file, "����� ��������: %g �.\n", objectsFlight[i].flightLength);
        fprintf(file, "\n");
    }

    fclose(file);
    printf("������ ������� ��������� � ���� '%s'.\n", filename);
}
