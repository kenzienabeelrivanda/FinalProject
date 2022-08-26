#include <stdio.h>
#include <string.h>

struct movie {
    char code[20];
    char title[50];
    char time[20];
    char studio[20];
    int price;
    long long int index;
}b;
struct movie search[50];

struct food {
    char code[20];
    char name[30];
    int cost;
    unsigned index;
}f;



struct payment {
    
    int jumlah_tiket;
    char moviecode[10];
    int index;
    char foodcode[10][13];  
    int jumlahmakanan[13];

}p;

int sudahbooking = 0;

int binarysearch(struct movie search[], int target, int lo, int hi){
    if(hi <= lo){
        return (target > search[lo].price) ? lo+1 : lo;
    }
    int mid = (lo + hi) / 2;
    if (target == search[mid].price)
        return mid + 1;
  
    if (target > search[mid].price)
        return binarysearch(search, target, 
                            mid + 1, hi);
    return binarysearch(search, target, lo, 
                        mid - 1);
}


void insertionSortMovie(struct movie search[], int len)
{
    int loc;
    for (int i = 1; i < len; ++i) 
    {
        char tmp[100];
        strcpy(tmp, search[i].code);
        char tmp2[100];
        strcpy(tmp2, search[i].title);
        char tmp3[100];
        strcpy(tmp3, search[i].time);
        char tmp4[100];
        strcpy(tmp4, search[i].studio);
        int tmp5 = search[i].price;
        loc = binarysearch(search, search[i].price, 0, i-1);
        for(int j=i-1; j>=loc;j--)
        {
            strcpy(search[j + 1].code, search[j].code);
            strcpy(search[j + 1].title, search[j].title);
            strcpy(search[j + 1].time, search[j].time);
            strcpy(search[j + 1].studio, search[j].studio);
            search[j + 1].price = search[j].price;
        }
        strcpy(search[loc].code, tmp);
        strcpy(search[loc].title, tmp2);
        strcpy(search[loc].time, tmp3);
        strcpy(search[loc].studio, tmp4);
        search[loc].price = tmp5;
    }
}    

void conquer(struct food arr[], int leftmostIndex, int middleIndex, int rightmostIndex) {
    struct food mergedArray[rightmostIndex-leftmostIndex+1];
    int firstArrayIndex = leftmostIndex; 
    int secondArrayIndex = middleIndex+1; 
    int mergedArrayIndex = 0; 
    

    while(firstArrayIndex <= middleIndex && secondArrayIndex <= rightmostIndex) {

        if(arr[firstArrayIndex].cost < arr[secondArrayIndex].cost) {
            mergedArray[mergedArrayIndex++] =  arr[firstArrayIndex++];
        } else {
            mergedArray[mergedArrayIndex++] = arr[secondArrayIndex++];
        }
    }


    while(firstArrayIndex <= middleIndex) {
        mergedArray[mergedArrayIndex++] = arr[firstArrayIndex++];
    }


    for(int i = 0; i < mergedArrayIndex; i++) {
        arr[i+leftmostIndex] = mergedArray[i];
    }
}



void divide(struct food arr[], int leftmostIndex, int rightmostIndex) {
    
    if(leftmostIndex != rightmostIndex) { 
        int middleIndex = leftmostIndex + (rightmostIndex - leftmostIndex) / 2; 
        divide(arr, leftmostIndex, middleIndex); 
        divide(arr, middleIndex+1, rightmostIndex); 
        conquer(arr, leftmostIndex, middleIndex, rightmostIndex); 
    }
}

// void merge(struct food arr[], int left, int mid, int right) {  
//     int i, h, k;
//     int subArray1 = mid - left + 1;
//     int subArray2 = right - mid;

//     /*  create temp array */ 
//     int L[subArray1], R[subArray2];

//     /* Copy data to temp arrays L[] and R[] */
//     for (int j=0; j < subArray1; j++) {
//         L[i] = arr[left + 1].cost;

//     for (int k=0; k < subArray2; k++) {
//         R[h] = arr[mid + left + h].cost;
//     }

//     /* merge the temp arrays back into arr[left .. right] */
//     i = 0; // initial index of first subarray
//     h = 0; // initial index of second subarray
//     k = left; // inial index of merged subarray

//     while (i < subArray1 && h < subArray2) {
//         if (L[i] <= R[h]) {
//             arr[k].cost = L[i];
//             i++;
//         } else {
//             arr[k].cost = R[h];
//             h++;
//         }
//         k++;
//     }

//     /* Copy the remaining elements of l[], if there any */
//     while (i < subArray1) {
//         arr[k].cost = L[i];
//         i++;
//         k++;
//     }

//     /* Copy the remaining elements of R[], if there any */
//     while (i < subArray1) {
//         arr[k].cost = R[h];
//         h++;
//         k++;
//     }
// }
// /* left is left index, Right is Right index of sub-array of arr to be sorted*/
// void mergesortFood(struct food arr[], int left, int right) {
//     // for (int j=0; j<3; j++) {
//     //     char tmp[100];
//     //     strcpy(tmp, arr[].code);
//     //     char tmp2[100];
//     //     strcpy(tmp2, arr[].name);
//     //     int tmp3 = arr[].cost;
//     // }
 
//     if (left < right) {
//         int mid = left + (right - 1) / 2;

//         // Sort first and second halves
//         mergesortFood(arr.cost, left, mid);
//         mergesortFood(arr.cost, mid + 1, right);

//         merge(arr.cost, left, mid, right);
//     }
// }   
void printTicket(char title[100], char ticket[100], char studio[100], char time[100], char price[100]){
    printf("---------------- TIKET ----------------\n");
    printf("|                                     |\n");
    printf("| Movie  :: %s", title); for (int i = 0; i < 26-strlen(title); i++){printf(" ");} printf("|\n");
    printf("| Jumlah :: %s", ticket); for (int i = 0; i < 26-strlen(ticket); i++){printf(" ");} printf("|\n");
    printf("| Studio :: %s", studio); for (int i = 0; i < 26-strlen(studio); i++){printf(" ");} printf("|\n");  
    printf("| Time   :: %s", time); for (int i = 0; i < 26-strlen(time); i++){printf(" ");} printf("|\n");
    printf("| Price  :: %s", price); for (int i = 0; i < 26-strlen(price); i++){printf(" ");} printf("|\n");
    printf("|                                     |\n");
    printf("---------------- TIKET ----------------\n");
}
struct food arr[50];
void viewMovie() {
    FILE *fp;
    fp = fopen("movielist.txt", "r");
    if(search[0].price == 0){
        for(int i=0; fscanf(fp, "%[^#]#%[^#]#%[^#]#%[^#]#%d\n", search[i].code, search[i].title, search[i].time, search[i].studio, &search[i].price) != EOF; i++) {b.index++;}
    }
    for(int i=0; i<b.index; i++){
        printf("Movie Code: %s\nTitle: %s\nTime: %s\nStudio: %s\nPrice: Rp%d\n \n", search[i].code, search[i].title, search[i].time, search[i].studio, search[i].price);
    }
    fclose(fp);
}

void viewFood() {
    FILE *fp;
    fp = fopen("viewfoodlist.txt", "r");
    if(arr[0].cost == 0){
        for(int i=0; fscanf(fp, "%[^#]#%[^#]#%d\n", arr[i].code, arr[i].name, &arr[i].cost) != EOF; i++) {f.index++;}
    }
    for(int i=0; i<f.index; i++){
        printf("Code: %s\nName: %s\nPrice: Rp%d\n \n", arr[i].code, arr[i].name, arr[i].cost);
    }
    fclose(fp);
}

void findFood() {
    int input;
    printf("\n ===> Please input <1> sort food by price");
    printf("\n ===> Please input <2> find food by code");
    printf("\n Enter your choice :: ");
    scanf("%d", &input);
    if (input == 1) {
        divide(arr, 0, f.index-1);
        for (int j=0; j<f.index; j++) {
            printf ("\n\tCode ::%s\n\tName :: %s\n\tPrice :: Rp%d\n", arr[j].code, arr[j].name, arr[j].cost);
        }
    }


    if(input == 2){    
        char ch[10];
        printf("Enter food code :");
        scanf("%s", ch);


        for(int i=0; i<f.index; i++){
            if(strcmp(arr[i].code, ch) == 0){
                printf("\n Record Found!\n");
                printf ("\n\t\tCode ::%s\n\t\tName :: %s\n\t\tPrice :: Rp%d\n", arr[i].code, arr[i].name, arr[i].cost);
                break;
            }
        }
        
    }   
    
} 
    
void findMovie()
{
    int input;
    printf("\n ===> Please input <1> sort movie by price");
    printf("\n ===> Please input <2> find movie by code");
    printf("\n Enter your choice :: ");
    scanf("%d", &input);
    if(input == 1){
        insertionSortMovie(search, b.index);
        for(int i=0; i<b.index; i++){
            printf("Movie Code: %s\nTitle: %s\nTime: %s\nStudio: %s\nPrice: Rp%d\n \n", search[i].code, search[i].title, search[i].time, search[i].studio, search[i].price);
        }
    }
    if(input == 2){    
        char ch[10];
        printf("Enter movie code :");
        scanf("%s", ch);


        for(int i=0; i<b.index; i++){
            if(strcmp(arr[i].code, ch) == 0){
                printf("\n Record Found!\n");
                printf ("\n\t\tCode ::%s\n\t\tTitle :: %s\n\t\tTime :: %s\n\t\tStudio :: %s\n\t\tPrice :: Rp%d\n", arr[i].code, arr[i].name, arr[i].cost);
                break;
            }
        }
        
    }   
}

void bookTicket() {
    if (!sudahbooking)
    {
        char ch[10];
        int jumlah_tiket;
        char tiket[10];
        char pricech[20];
        printf("Enter your movie code: ");
        scanf("%s", ch);
        printf("Enter the ticket amount: ");
        scanf("%d", &jumlah_tiket);
        strcpy(p.moviecode, ch);
        p.jumlah_tiket = jumlah_tiket;
    
        puts("\nThank you for booking ^_^");
        sudahbooking = 1;

    } else {
      puts("\nYou have booked your ticket");
  
    }
}

void orderFood() {
    char ch[10];
    int jumlah_makanan;
    printf("Enter your food code: ");
    scanf("%s", ch);
    printf("Enter the food amount: ");
    scanf("%d", &jumlah_makanan);
    strcpy(p.foodcode[p.index], ch);
    p.jumlahmakanan[p.index] = jumlah_makanan;
    p.index++;
    
    puts("\nThank you for ordering ^_^");
}

void pembayaran() {
    FILE* fp = fopen("movielist.txt","r");
    FILE* fp2 = fopen("viewfoodlist.txt", "r");
    char tiket[10];
    char pricech[10];
    char title[100];
    char studio[100];
    char time[100];
    int tagihan = 0;
    int total;
    while(fscanf(fp, "%[^#]#%[^#]#%[^#]#%[^#]#%d\n", b.code, b.title, b.time, b.studio, &b.price) !=EOF) {
        if(strcmp(b.code, p.moviecode) == 0)
        {
            sprintf(tiket, "%d", p.jumlah_tiket);
            sprintf(pricech, "%d", b.price);   
            total =  b.price*p.jumlah_tiket;
            printf("%s  x%d    Rp%d", b.title, p.jumlah_tiket, total);
            tagihan += b.price*p.jumlah_tiket;
            break;
        }
    }

    for(int i=0; i <= p.index; i++){
        while((fscanf(fp2, "%[^#]#%[^#]#%d\n", f.code, f.name, &f.cost)) !=EOF) {
            if(strcmp(f.code, p.foodcode[i]) == 0)
            {
                total = (f.cost) * (p.jumlahmakanan[i]);
                printf("\n%s  x%d    Rp%d\n", f.name, p.jumlahmakanan[i], total);
                tagihan += total;
                break;
            }
        }
    }

    printf("Total :: Rp%d\n", tagihan);

    int nominal;
    while(1){
        printf("Masukkan nominal pembayaran: ");
        scanf("%d", &nominal);
        if(nominal < tagihan){
            printf("Uangmu tidak cukup!\n");
        }
        else{
            printf("Kembalianmu: Rp%d\n\n", nominal-tagihan);
            break;
        } 
    }
    printf("Thank you and enjoy your movie!\n\n");
    printTicket(b.title, tiket, b.studio, b.time, pricech);

    fclose(fp);
    fclose(fp2);
}

int main() {
    p.index = 0;
    int inputs;
    do {
    printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    puts(
"\ndb   d8b   db d88888b db       .o88b.  .d88b.  .88b  d88. d88888b \n"
"88   I8I   88 88'     88      d8P  Y8 .8P  Y8. 88'YbdP`88 88'     \n"
"88   I8I   88 88ooooo 88      8P      88    88 88  88  88 88ooooo \n"
"Y8   I8I   88 88~~~~~ 88      8b      88    88 88  88  88 88~~~~~ \n" 
"`8b d8'8b d8' 88.     88booo. Y8b  d8 `8b  d8' 88  88  88 88.     \n"
" `8b8' `8d8'  Y88888P Y88888P  `Y88P'  `Y88P'  YP  YP  YP Y88888P \n"


                                                                  
                                                                         
                                                                        
                                                                        );

//     puts(
// "8b    d8    db    88 88b 88     8b    d8 888888 88b 88 88   88  \n"
// "88b  d88   dPYb   88 88Yb88     88b  d88 88__   88Yb88 88   88  \n"
// "88YbdP88  dP__Yb  88 88 Y88     88YbdP88 88""   88 Y88 Y8   8P  \n"
// "88 YY 88 dP""""Yb 88 88  Y8     88 YY 88 888888 88  Y8 `YbodP'  \n");

    printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");

    printf("\n ===> Please input <1> to VIEW all movie");
    printf("\n ===> Please input <2> to VIEW all food");
    printf("\n ===> Please input <3> to FIND certain food");
    printf("\n ===> Please input <4> to FIND certain movie");
    printf("\n ===> Please input <5> to BOOK a ticket");
    printf("\n ===> Please input <6> to ORDER food");
    printf("\n ===> Please input <7> to CHECKOUT");
    printf("\n ===> Please input <0> to EXIt program");
    printf("\n Enter your choice :: ");
    scanf("%d", &inputs);
    
        switch (inputs) {
        case 1 :
        viewMovie();
        break;

        case 2 :
        viewFood();
        break;

        case 3:
        findFood();
        break;

        case 4:
        findMovie();
        break;

        case 5:
        bookTicket();
        break;

        case 6:
        orderFood();
        break;

        case 7:
        pembayaran();
        break;

        case 0:
        printf("\nThank You For Using our Program!");
        break;

        default:
        printf("\nInvalid input, Please try again - Jesslyn");
        break;
    }
    } while (inputs != 0);
    return 0;
} 




