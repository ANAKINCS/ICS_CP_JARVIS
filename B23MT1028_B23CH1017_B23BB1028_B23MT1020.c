#include <stdio.h> 

struct Candidates{ 
 char name[30]; 
int age; 
int votes; 
};

void candInfo(struct Candidates* cand);
void dispCands(struct Candidates* cand_list, int n);
void castVote(struct Candidates* cand_list, int n);
void dispCandsNameOnly(struct Candidates* cand_list, int n);
int maxVote(struct Candidates* cand_list, int n);
void result(struct Candidates* cand_list, int n);

int main() {
    int n;
    printf("Enter number of candidates :");
    scanf("%d", &n);

    struct Candidates cand_list[n];

    for(int i=0; i<n; i++) {
        printf("please fill Candidate no.%d info:\n", i + 1);
        candInfo(&cand_list[i]);
    }

    for (;;) {
        dispCands(cand_list, n);
        int key = 0;
        printf("\nTASKS:\n");
        printf("1) Cast Vote\n2)Display Final Result\n3)Exit System Without Result\nEnter Task :");
        scanf("%d", &key);

        if (key == 1) {
            castVote(cand_list, n);
        }

        if (key == 2) {
            dispCands(cand_list, n);
            result(cand_list, n);
            break;
        }

        if (key == 3) {
            break;
        }
    }
}

void candInfo(struct Candidates *cand) {
    char ch, read = 0;
    scanf("%c", &ch);
    printf("Name :");
    for (int i = 0; read != '\n'; i++) {
        scanf("%c", &read);
        cand->name[i] = read;
    }
    printf("Age :");
    scanf("%d", &(cand->age));
    cand->votes = 0;
}

void dispCands(struct Candidates* cand_list, int n) {
    for(int i = 0; i < n; i++) {
        printf("\nCANDIDATE NO.%d>>\n", i + 1);
        printf("NAME :");
        for(int j = 0; cand_list[i].name[j] != '\n'; j++) {
            printf("%c", cand_list[i].name[j]);
        }
        printf("\nAGE :%d", cand_list[i].age);
        printf("\nVOTES :%d\n", cand_list[i].votes);
    }
}

void dispCandsNameOnly(struct Candidates* cand_list, int n) {
    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("%d> ", i + 1);
        for(int j = 0; cand_list[i].name[j] != '\n'; j++) {
            printf("%c", cand_list[i].name[j]);
        }
        printf("\n");
    }
}

void castVote(struct Candidates* cand_list, int n) {
    dispCandsNameOnly(cand_list, n);
    int cand_no = -1;
    printf("Enter Cand. no :");
    scanf("%d", &cand_no);

    if(!(cand_no > n || cand_no <= 0)) {
        cand_list[cand_no - 1].votes++;
    }

    if((cand_no > n || cand_no < 0)) {
        printf("Wrong Candidate Number!!");
    }
}

int maxVote(struct Candidates* cand_list, int n) {
    int maxValue = cand_list[0].votes;
    int maxIndex = 0;

    for(int i = 0; i < n; i++) {
        if(cand_list[i].votes > maxValue) {
            maxValue = cand_list[i].votes;
            maxIndex = i;
        }
    }
    return(maxIndex + 1);
}

void result(struct Candidates* cand_list, int n) {
    int winnerIndex = maxVote(cand_list, n);
    printf("\nWINNER :");
    for(int j = 0; cand_list[winnerIndex - 1].name[j] != '\n'; j++) {
        printf("%c", cand_list[winnerIndex - 1].name[j]);
    }
    printf("\n");
}
