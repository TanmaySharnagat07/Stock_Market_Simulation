#include <stdio.h>
#include <string.h>
#define num_of_com 10  // Number of Comapnies
#define num_of_days 21 // Number of Days
#define dayStart 10    // Starting date
#define dayEnd dayStart + num_of_days // Ending Date
#define id 101    //Starting ID of Company

//Structure for Date
typedef struct Day
{
    int date; 
    int month;
    int year;
} Day;

//Structure for Stock of Companies
typedef struct Stock
{
    char name[100];
    float Open[num_of_days];
    float High[num_of_days];
    float Low[num_of_days];
    float Close[num_of_days];
    int volume[num_of_days];
    int stockID;
    Day DMY[num_of_days];

} Stock;

//Structur to store Overall Performance
typedef struct OvrPerformance
{
    char names[100];
    float Op;

} OvrPerformance;

void Question1(Stock S[num_of_com], int start_day, char type_startPrice, int end_day, char type_endPrice, int StockID)
{   
    float diff, change;
    int com;
    for (int i = 0; i < num_of_com; i++)
    {
        if (S[i].stockID == StockID)
        {
            com = i;
        }
    }
    float start_price, end_price; 
    if (type_startPrice == 'O')
        start_price = S[com].Open[start_day];

    else if (type_startPrice == 'L')
        start_price = S[com].Low[start_day];

    else if (type_startPrice == 'H')
        start_price = S[com].High[start_day];

    else
        start_price = S[com].Close[start_day];

    if (type_endPrice == 'O')
        end_price = S[com].Open[end_day];

    else if (type_endPrice == 'L')
        end_price = S[com].Low[end_day];

    else if (type_endPrice == 'H')
        end_price = S[com].High[end_day];

    else
        end_price = S[com].Close[end_day];

    printf("\nPercentage change in prices from date %d to date %d are:\n", start_day + dayStart, end_day + dayStart);
    diff = end_price - start_price;
    change = (diff / start_price) * 100;
    printf("%s  ->  %f %% \n", S[com].name, change);
}

void Question2(Stock S[num_of_com], int ChosenDay)
{
    int i, j, flag = 1;
    for (i = 0; i < num_of_com && flag == 1; i++)
    {
        flag = 0;
        for (j = 0; j < num_of_com - 1; j++)
        {
            if (S[j].volume[ChosenDay] > S[j + 1].volume[ChosenDay])
            {
                Stock temp = S[j]; // temporary structure for swapping
                S[j] = S[j + 1];
                S[j + 1] = temp;

                flag = 1;
            }
            else if (S[j].volume[ChosenDay] == S[j + 1].volume[ChosenDay]) // If Volumes are same 
            {
                if (S[j].Close[ChosenDay] > S[j + 1].Close[ChosenDay]) // Comparing Close prices
                {
                    Stock temp = S[j]; // temporary structure for swapping
                    S[j] = S[j + 1];
                    S[j + 1] = temp;
                }
                flag = 1;
            }
        }
    }
    printf("Sorted according to <Volume,Close price> on %d-03-2023\n",ChosenDay+dayStart);
    for (int i = 0; i < num_of_com; i++)
    {
        printf("%s --> %d \t %f\n", S[i].name, S[i].volume[ChosenDay], S[i].Close[ChosenDay]);
    }
}

void Question3(Stock S[num_of_com], int buy_day, char buytype, int sell_day, char selltype, int NumStocks, int Chosen[])
{
    for (int i = 0; i < NumStocks; i++) // NumStocks is number of stocks chosen and Chosen[] is array storing them
    {
        float buy_price, sell_price;

        int x = Chosen[i], num;
        int flag = 1;
        for (int i = 0; i < num_of_com && flag == 1; i++)
        {
            if (x == S[i].stockID)
            {
                num = i;
                flag = 0;
            }
        }

        if (buytype == 'O')
            buy_price = S[num].Open[buy_day];

        else if (buytype == 'H')
            buy_price = S[num].High[buy_day];

        else if (buytype == 'L')
            buy_price = S[num].Low[buy_day];

        else
            buy_price = S[num].Close[buy_day];

        if (selltype == 'O')
            sell_price = S[num].Open[sell_day];

        else if (selltype == 'H')
            sell_price = S[num].High[sell_day];

        else if (selltype == 'L')
            sell_price = S[num].Low[sell_day];

        else
            sell_price = S[num].Close[sell_day];

        float change = sell_price - buy_price;
        if (change < 0)
        {
            change *= (-1);
            printf("%s\t --> %0.3f Rs Loss\n", S[num].name, change);
        }
        else
        {
            printf("%s\t --> %0.3f Rs Profit\n", S[num].name, change);
        }
    }
}

void Question4(Stock S[num_of_com], int buy_day, char buytype, int sell_day, char selltype)
{
    int j;
    int check = 1;
    float buy, sell;
    float performance, high_performance = 0;
    printf("The Highest Preforming Stock is :- \n");
    for (int i = 0; i < num_of_com; i++)
    {

        {if (buytype == 'O')
            buy = S[i].Open[buy_day];

        else if (buytype == 'H')
            buy = S[i].High[buy_day];

        else if (buytype == 'L')
            buy = S[i].Low[buy_day];

        else
            buy = S[i].Close[buy_day];

        if (selltype == 'O')
            sell = S[i].Open[sell_day];

        else if (selltype == 'H')
            sell = S[i].High[sell_day];

        else if (selltype == 'L')
            sell = S[i].Low[sell_day];

        else
            sell = S[i].Close[sell_day];}

        performance = 100 * (sell - buy) / buy;
        if (performance > high_performance)
        {
            high_performance = performance;
            j = i;
        }
    }
    printf("%s \t->\t %f  ", S[j].name, high_performance);
}

void Question5(Stock S[num_of_com], int buy_day, char buytype, int sell_day, char selltype)
{
    int j;
    int check = 1;
    float buy, sell;
    float performance, low_performance = 0;
    printf("The Lowest Preforming Stock is :- \n");
    for (int i = 0; i < num_of_com; i++)
    {

        {if (buytype == 'O')
            buy = S[i].Open[buy_day];

        else if (buytype == 'C')
            buy = S[i].Close[buy_day];

        else if (buytype == 'H')
            buy = S[i].High[buy_day];

        else
            buy = S[i].Low[buy_day];

        if (selltype == 'O')
            sell = S[i].Open[sell_day];

        else if (selltype == 'C')
            sell = S[i].Close[sell_day];

        else if (selltype == 'H')
            sell = S[i].High[sell_day];

        else
            sell = S[i].Low[sell_day];}

        performance = 100 * (sell - buy) / buy;
        if (performance < low_performance)
        {
            low_performance = performance;
            j = i;
        }
    }
    printf(" %s \t\t\t %f", S[j].name, low_performance);
}

void Question6(Stock S[num_of_com], int starting_day, int ending_day)
{
    OvrPerformance P[num_of_com]; // Structure storing Overall performance with name of the stock.

    for (int i = 0; i < num_of_com; i++)
    {
        float ovr_per = 0;
        for (int j = starting_day; j <= ending_day; j++)
        {
            float change = 0;
            change = S[i].Close[j] - S[i].Open[j];
            change = (change / S[i].Open[j]) * S[i].volume[j];
            ovr_per += change;
        }
        strcpy(P[i].names, S[i].name);
        P[i].Op = ovr_per;
    }

    int flag = 1;
    // Sorting Data
    for (int i = 0; i < num_of_com - 1 && flag == 1; i++)
    {
        flag = 0;
        for (int j = 0; j < num_of_com - i - 1; j++)
        {
            if (P[j].Op > P[j + 1].Op)
            {
                OvrPerformance temp = P[j];
                P[j] = P[j + 1];
                P[j + 1] = temp;
                flag = 1;
            }
        }
    }
    for (int i = 0; i < num_of_com; i++)
    {
        printf("%s --> %0.2f\n", P[i].names, P[i].Op);
    }
}

void Question7(Stock S[num_of_com], int day, int start_day, int end_day)
{
    float avg_val; // Stores average value at a particular day 
    printf("Average price of a Stock on %d-03-2023\n",day);
    for (int i = 0; i < num_of_com; i++)
    {
        avg_val = (S[i].Open[day] + S[i].Close[day]) / 2;
        printf("%s -> %0.3f\n", S[i].name, avg_val);
    }
    printf("\n");
    float avg_avg_val; // Storing average of average value between starting and ending day
    printf("Average of average price of a Stock on %d-03-2023 to %d-03-2023\n",start_day+dayStart,end_day+dayStart);
    for (int i = 0; i < num_of_com; i++)
    {
        float weighted_Sum = 0, Vol_Sum = 0;
        for (int j = start_day; j <= end_day; j++)
        {
            avg_val = (S[i].Open[j] + S[i].Close[j]) / 2;
            weighted_Sum += avg_val * S[i].volume[j];
            Vol_Sum += S[i].volume[j];
        }
        avg_avg_val = weighted_Sum / Vol_Sum;
        printf("%s -> %0.3f \n", S[i].name, avg_avg_val);
    }
}

// void Question7a(Stock S[num_of_com],int day , int start_day , int end_day){}

// This Function is for checking type of price chosen.
char checkType_price()
{
    int flag = 1;
    char type_price[10], ans, result;
    while (flag == 1)
    {

        printf("Enter type of price (Open , High , Low , Close):- ");
        scanf("%s", &type_price);
        if (strcmp(type_price, "Open") == 0 || strcmp(type_price, "Close") == 0 || strcmp(type_price, "High") == 0 || strcmp(type_price, "Low") == 0)
        {
            flag = 0;
            result = type_price[0];
        }
        else
        {
            printf("!! Invalid Input !! (Invalid PriceType) \nDo you want to continue?(Y/N): ");
            scanf(" %c", &ans);
            if (ans != 'Y')
            {
                result = 'z';
                flag = 0;
            }
        }
    }
    return result;
}

// This Function is for taking input of day.
int date_Input(Stock S[num_of_com], char day_type[])
{
    int store = -1;
    int day, flag = 1;
    int check = 1;
    char ans;

    while (flag == 1)
    {
        printf("Enter the %s date(%d-%d): ", day_type, dayStart, dayEnd - 1);
        scanf("%d", &day);
        if (day >= dayStart && day < dayEnd)
        {
            for (int i = 0; i < num_of_days && check == 1; i++)
            {
                if (day == S[0].DMY[i].date)
                {
                    check = 0;
                    store = i;
                }
            }
            flag = 0;
        }
        else
        {
            printf("!!Invalid Input!! (Input is not in range)\n");
            printf("Do you want change the input?(Y/N)- ");
            scanf(" %c", &ans);
            if (ans != 'Y')
            {
                flag = 0;
            }
        }
    }
    return store;
}

// This Function is for checking valid buying and selling day.
int checkDay(Stock S[num_of_com], int *buy_day, int *sell_day)
{
    int flag = 1;
    char choice, choice1;
    int ans;
    while (flag == 1)
    {
        if (*buy_day > *sell_day)
        {
            printf("!!Invalid Input!! (Buying date should be less than Selling date)\nDo you wnat to change(Y/N):-  ");
            scanf(" %c", &choice);
            if (choice == 'Y')
            {
                printf("Do you want to change Buy Day?(Y/N) ");
                scanf(" %c", &choice1);
                if (choice1 == 'Y')
                {
                    *buy_day = date_Input(S, "New buy");
                }
                else
                {
                    *sell_day = date_Input(S, "New sell");
                }
            }
            else
            {
                return -1;
                flag = 0;
            }
        }
        else
        {
            flag = 0;
        }
    }
    return ans;
}

// This Function is for Q3 to take input number of companies and their StockID.
void ChosenStockID(Stock S[num_of_com], int NumCompany, int Ans[])
{
    int ChosenID[NumCompany];

    printf("Enter the Stock ID's of companies to choose:\n");
    for (int i = 0; i < NumCompany; i++)
    {
        printf("Enter Company %d Stock ID (%d-%d): ", i + 1, id, id + num_of_com - 1);
        scanf("%d", &ChosenID[i]);
    }
    int index = 0;
    for (int i = 0; i < num_of_com; i++)
    {
        int flag = 1;
        for (int j = 0; j < NumCompany && flag == 1; j++)
        {
            if (ChosenID[j] == S[i].stockID)
            {
                Ans[index] = S[i].stockID;
                index++;
                flag = 0;
            }
        }
    }
}

// This Function is taking all the required inputs for functions to run.
void input(Stock S[num_of_com])
{
    int flag = 1, check = 1;
    char ans;
    int no;
    while (flag == 1)
    {

        printf("Enter the Question Number:- ");
        scanf("%d", &no);
        if (no == 1)
        {
            int check = 1, final_check;
            int buy, sell;
            char buy_type, sell_type;
            while (check != -1)
            {
                buy = date_Input(S, "buy");
                if (buy != -1)
                {
                    buy_type = checkType_price();
                    if (buy_type != 'z')
                    {
                        sell = date_Input(S, "sell");
                        if (sell != -1 && buy_type != 'z')
                        {
                            int x;
                            x = checkDay(S, &buy, &sell);
                            if (x != -1)
                            {
                                sell_type = checkType_price();
                                if (sell_type != 'z')
                                {
                                    check = -1;
                                    final_check = -1;
                                }
                                else
                                {
                                    check = -1;
                                }
                            }
                            else
                            {
                                check = -1;
                            }
                        }
                        else
                        {
                            check = -1;
                        }
                    }
                    else
                    {
                        check = -1;
                    }
                }
                else
                {
                    check = -1;
                }
            }
            while (final_check == -1)
            {
                int num;
                char res;
                printf("Enter the StockID:- ");
                scanf("%d", &num);
                if (num >= id && num < id + num_of_com - 1)
                {
                    Question1(S, buy, buy_type, sell, sell_type, num);
                    final_check = 0;
                }
                else
                {
                    printf("!!Invalid ID \nDo You want to continue?(Y/N) ");
                    scanf(" %c", &res);
                    if (res != 'Y')
                    {
                        final_check = 0;
                    }
                }
            }

            printf("Next Question?(Y/N):- ");
            scanf(" %c", &ans);
            if (ans != 'Y')
            {
                flag = 0;
                check = 0;
            }
        }
        else if (no == 2)
        {
            int check = 1;
            int buy;

            while (check != -1)
            {
                buy = date_Input(S, "");
                if (buy != -1)
                {
                    check = -1;
                    Question2(S, buy);
                }
                else
                {
                    check = -1;
                }
            }
            printf("Next Question?(Y/N):- ");
            scanf(" %c", &ans);
            if (ans != 'Y')
            {
                flag = 0;
            }
        }
        else if (no == 3)
        {
            int check = 1, final_check;
            int buy, sell;
            char buy_type, sell_type, res;
            while (check != -1)
            {
                buy = date_Input(S, "buy");
                if (buy != -1)
                {
                    buy_type = checkType_price();
                    if (buy_type != 'z')
                    {
                        sell = date_Input(S, "sell");
                        if (sell != -1 && buy_type != 'z')
                        {
                            int x;
                            x = checkDay(S, &buy, &sell);
                            if (x != -1)
                            {
                                sell_type = checkType_price();
                                if (sell_type != 'z')
                                {
                                    check = -1;
                                    final_check = -1;
                                }
                                else
                                {
                                    check = -1;
                                }
                            }
                            else
                            {
                                check = -1;
                            }
                        }
                        else
                        {
                            check = -1;
                        }
                    }
                    else
                    {
                        check = -1;
                    }
                }
                else
                {
                    check = -1;
                }
            }

            while (final_check == -1)
            {
                int numChosen;
                printf("Enter the number of companies to choose:- ");
                scanf("%d", &numChosen);
                int chosen[numChosen];
                if (2 <= numChosen && numChosen < num_of_com)
                {
                    ChosenStockID(S, numChosen, chosen);
                    Question3(S, buy, buy_type, sell, sell_type, numChosen, chosen);
                    final_check = 0;
                }
                else
                {
                    printf("!!Invalid Input!! (Enter number of companies in range(2-10)) \nDo you want to continue?(Y/N)");
                    scanf(" %c", &res);
                    if (res != 'Y')
                    {
                        flag = 0;
                    }
                }
            }

            printf("Next Question?(Y/N):- ");
            scanf(" %c", &ans);
            if (ans != 'Y')
            {
                flag = 0;
            }
        }
        else if (no == 4)
        {
            int check = 1, final_check;
            int buy, sell;
            char buy_type, sell_type;
            while (check != -1)
            {
                buy = date_Input(S, "buy");
                if (buy != -1)
                {
                    buy_type = checkType_price();
                    if (buy_type != 'z')
                    {
                        sell = date_Input(S, "sell");
                        if (sell != -1 && buy_type != 'z')
                        {
                            int x;
                            x = checkDay(S, &buy, &sell);
                            if (x != -1)
                            {
                                sell_type = checkType_price();
                                if (sell_type != 'z')
                                {
                                    check = -1;
                                    final_check = -1;
                                }
                                else
                                {
                                    check = -1;
                                }
                            }
                            else
                            {
                                check = -1;
                            }
                        }
                        else
                        {
                            check = -1;
                        }
                    }
                    else
                    {
                        check = -1;
                    }
                }
                else
                {
                    check = -1;
                }
            }
            if (final_check == -1)
            {
                Question4(S, buy, buy_type, sell, sell_type);
            }

            printf("\nNext Question?(Y/N):- ");
            scanf(" %c", &ans);
            if (ans != 'Y')
            {
                flag = 0;
            }
        }
        else if (no == 5)
        {
            int check = 1, final_check;
            int buy, sell;
            char buy_type, sell_type;
            while (check != -1)
            {
                buy = date_Input(S, "buy");
                if (buy != -1)
                {
                    buy_type = checkType_price();
                    if (buy_type != 'z')
                    {
                        sell = date_Input(S, "sell");
                        if (sell != -1 && buy_type != 'z')
                        {
                            int x;
                            x = checkDay(S, &buy, &sell);
                            if (x != -1)
                            {
                                sell_type = checkType_price();
                                if (sell_type != 'z')
                                {
                                    check = -1;
                                    final_check = -1;
                                }
                                else
                                {
                                    check = -1;
                                }
                            }
                            else
                            {
                                check = -1;
                            }
                        }
                        else
                        {
                            check = -1;
                        }
                    }
                    else
                    {
                        check = -1;
                    }
                }
                else
                {
                    check = -1;
                }
            }
            if (final_check == -1)
            {
                Question5(S, buy, buy_type, sell, sell_type);
            }
            printf("\nNext Question?(Y/N):- ");
            scanf(" %c", &ans);
            if (ans != 'Y')
            {
                flag = 0;
                check = 0;
            }
        }
        else if (no == 6)
        {
            int buy, sell;
            int check = 1;
            char res;
            while (check != -1)
            {
                buy = date_Input(S, "buy");
                if (buy != -1)
                {
                    sell = date_Input(S, "sell");
                    int x = checkDay(S, &buy, &sell);
                    if (x != -1)
                    {
                        if (sell != -1)
                        {
                            Question6(S, buy, sell);
                            check = -1;
                        }

                        else
                        {
                            printf("!!Invalid Input!!\nDo you want to continue(Y/N) ");
                            scanf(" %c", &res);
                            if (res != 'Y')
                            {
                                check = -1;
                            }
                        }
                    }
                    else
                    {
                        check = -1;
                    }
                }
                else
                {
                    printf("!!Invalid Input!!\nDo you want to continue(Y/N) ");
                    scanf(" %c", &res);
                    if (res != 'Y')
                    {
                        check = -1;
                    }
                }
            }
            printf("Next Question?(Y/N):- ");
            scanf(" %c", &ans);
            if (ans != 'Y')
            {
                flag = 0;
                check = 0;
            }
        }
        else if (no == 7)
        {
            int buy, sell, now, check = 0;
            char res;
            while (check != -1)
            {
                now = date_Input(S, "");
                if (now != -1)
                {
                    buy = date_Input(S, "Start");
                    if (buy != -1)
                    {
                        int x;
                        sell = date_Input(S, "End");
                        x = checkDay(S, &buy, &sell);
                        if (x != -1)
                        {
                            if (sell != -1)
                            {
                                Question7(S, now, buy, sell);
                                check = -1;
                            }
                            else
                            {
                                printf("!!Invalid Input!!\nDo you want to continue(Y/N) ");
                                scanf(" %c", &res);
                                if (res != 'Y')
                                {
                                    check = -1;
                                }
                            }
                        }
                        else
                        {
                            check = -1;
                        }
                    }
                    else
                    {
                        printf("!!Invalid Input!!\nDo you want to continue(Y/N) ");
                        scanf(" %c", &res);
                        if (res != 'Y')
                        {
                            check = -1;
                        }
                    }
                }
                else
                {
                    printf("Do you want to continue?(Y/N)");
                    scanf(" %c", &res);
                    if (res != 'Y')
                    {
                        check = -1;
                    }
                }
            }
            printf("Next Question?(Y/N):- ");
            scanf(" %c", &ans);
            if (ans != 'Y')
            {
                check = 0;
                flag = 0;
            }
        }
        else
        {
            int thisv;
            printf("!!Invalid Input!!\nDo you want to continue?(Y/N):\n");
            scanf(" %c", &thisv);
            if (thisv != 'Y')
            {
                flag = 0;
            }
        }
    
    }
    printf("\t\t\t\t\t\t\t\tHappy Coding");
}


int main()
{
    Stock Company[num_of_com];

    // Naming the companies
    {
        strcpy(Company[0].name, "TATASTEEL");
        strcpy(Company[1].name, "COALINDIA");
        strcpy(Company[2].name, "ICICIBANK");
        strcpy(Company[3].name, "ADANIENT ");
        strcpy(Company[4].name, "BAJAJFIN ");
        strcpy(Company[5].name, "ONGC     ");
        strcpy(Company[6].name, "WIPRO    ");
        strcpy(Company[7].name, "RELIANCE ");
        strcpy(Company[8].name, "ITC      ");
        strcpy(Company[9].name, "BPCL     ");
    }

    // Assigning StockID to companies
    for (int i = 0; i < num_of_com; i++)
    {
        Company[i].stockID = id + i;
    }

    // Adding Date to 'Day' structure
    for (int i = 0; i < num_of_com; i++)
    {
        for (int j = 0; j < num_of_days; j++)
        {
            Company[i].DMY[j].date = dayStart + j;
            Company[i].DMY[j].month = 3;
            Company[i].DMY[j].year = 2023;
        }
    }

    // File Handling 

    FILE *file[num_of_com];

    {   file[0] = fopen("TataSteel.txt", "r");
        file[1] = fopen("CoalIndia.txt", "r");
        file[2] = fopen("ICICI.txt", "r");
        file[3] = fopen("Adanient.txt", "r");
        file[4] = fopen("BajajFin.txt", "r");
        file[5] = fopen("ONGC.txt", "r");
        file[6] = fopen("Wipro.txt", "r");
        file[7] = fopen("Reliance.txt", "r");
        file[8] = fopen("ITC.txt", "r");
        file[9] = fopen("BPCL.txt", "r");}
    
    if (file == NULL)
    {
        printf("Error.\n");
        return 1;
    }

    for (int j = 0; j < num_of_com; j++)
    {
        if (ferror(file[j]))
        {
            printf("Error in reading file");
            return 1;
        }

        for (int i = 0; i < num_of_days; i++)
        {
            if (fscanf(file[j], "%f", &Company[j].Open[i]) == EOF)
                break;
            if (fscanf(file[j], "%f", &Company[j].High[i]) == EOF)
                break;
            if (fscanf(file[j], "%f", &Company[j].Low[i]) == EOF)
                break;
            if (fscanf(file[j], "%f", &Company[j].Close[i]) == EOF)
                break;
            if (fscanf(file[j], "%d", &Company[j].volume[i]) == EOF)
                break;
        }
        fclose(file[j]);
    }

    for (int i = 0; i < num_of_com; i++)
    {
        printf("Company name:- %s\n", Company[i].name);
        printf("Stock ID: %d\n", Company[i].stockID);
        printf("Price Types:");
        printf(" \t  Open   High   Low    Close   Volume\n");
        printf(" Date  \t \t   |      |      |       |       |    \n");
        for (int j = 0; j < num_of_days; j++)
        {
            printf("%d-0%d-%d \t  %0.2f %0.2f %0.2f %0.2f %d \n", Company[i].DMY[j].date, Company[i].DMY[j].month, Company[i].DMY[j].year, Company[i].Open[j], Company[i].High[j], Company[i].Low[j], Company[i].Close[j], Company[i].volume[j]);
        }
        printf("\n\n");
    }

    //

    input(Company);

    return 0;
}
