#include <stdio.h> // Include stdio.h header file for standard input and output operations

struct Candidates{ // Define a structure named Candidates with three members: name, age, and votes
 char name[30]; // Array to store candidate's name
int age; // Integer to store candidate's age
int votes; // Integer to store candidate's votes
};

void candInfo(struct Candidates* cand); // Prototype for candInfo function to input candidate information
void dispCands(struct Candidates* cand_list, int n); // Prototype for dispCands function to display candidate list
void castVote(struct Candidates* cand_list, int n); // Prototype for castVote function to allow casting votes
void dispCandsNameOnly(struct Candidates* cand_list, int n); // Prototype for dispCandsNameOnly function to display only candidate names
int maxVote(struct Candidates* cand_list, int n); // Prototype for maxVote function to find the candidate with the most votes
void result(struct Candidates* cand_list, int n); // Prototype for result function to display the election result

int main() { // Main function to execute the program
    int n; // Declare an integer variable to store the number of candidates
    printf("Enter number of candidates :"); // Prompt user to enter the number of candidates
    scanf("%d", &n); // Read input for the number of candidates

    struct Candidates cand_list[n]; // Create an array of Candidates structures to store candidate information

    for(int i=0;i<n;i++){
        printf("please fill Candidate no.%d info:\n", i + 1); // Prompt for candidate's information
        candInfo(&cand_list[i]); // Call candInfo function to input candidate's information
    }


    

    for (;;) { // Infinite loop for user interaction
        dispCands(cand_list, n); // Display the list of candidates with their information
        int key = 0; // Declare an integer variable to store user's selection
        printf("\nTASKS:\n"); // Display the menu options
        printf("1) Cast Vote\n2)Display Final Result\n3)Exit System Without Result\nEnter Task :"); // Prompt user to select an option
        scanf("%d", &key); // Read input for user's selection

        if (key == 1) { // Option 1: Cast Vote
            castVote(cand_list, n); // Call castVote function to allow casting votes
        }

        if (key == 2) { // Option 2: Display Final Result
            dispCands(cand_list, n); // Display the list of candidates with their information
            result(cand_list, n); // Call result function to display the election result
            break; // Exit the loop after displaying the result
        }

        if (key == 3) { // Option 3: Exit System Without Result
            break; // Exit the loop immediately
        }
    }
}

 void candInfo(struct Candidates *cand){ // Function to input candidate information
 char ch, read = 0; // Declare variables for input handling
 scanf("%c", &ch); // Read a character to handle newline character
 printf("Name :"); // Prompt for candidate's name
 for (int i = 0; read != '\n'; i++) { // Loop until the newline character is encountered
scanf("%c", &read); // Read the next character
 cand->name[i] = read;
} // Store the character in the candidate's name
printf("Age :"); // Prompt for candidate's age
scanf("%d",&(cand->age)); // Read input for candidate's age
cand->votes=0; // Initialize the candidate's votes to 0

}
void dispCands(struct Candidates* cand_list,int n){ // Function to display candidate list
for(int i=0;i<n;i++){ // Loop through each candidate in the list
printf("\nCANDIDATE NO.%d>>\n",i+1); // Display candidate number
printf("NAME :"); // Prompt for candidate's name
for(int j =0;cand_list[i].name[j]!='\n';j++){ // Loop through each character in the candidate's name
printf("%c",cand_list[i].name[j]); // Display the character
}
printf("\nAGE :%d",cand_list[i].age); // Display candidate's age
printf("\nVOTES :%d\n",cand_list[i].votes); // Display candidate's votes
}
}
void dispCandsNameOnly(struct Candidates* cand_list,int n){ // Function to display only candidate names
printf("\n"); // Add a newline character
for(int i=0;i<n;i++){ // Loop through each candidate in the list
printf("%d> ",i+1); // Display candidate number
for(int j =0;cand_list[i].name[j]!='\n';j++){ // Loop through each character in the candidate's name
printf("%c",cand_list[i].name[j]); // Display the character
}
printf("\n"); // Add a newline character
}
}
void castVote(struct Candidates* cand_list,int n){ // Function to allow casting votes
dispCandsNameOnly(cand_list,n); // Display candidate names only
int cand_no=-1; // Declare a variable to store the candidate number
printf("Enter Cand. no :"); // Prompt for candidate number
scanf("%d",&cand_no); // Read input for candidate number

if(!(cand_no>n||cand_no<=0)){ // Check if the candidate number is within the valid range
cand_list[cand_no-1].votes++; // Increment the votes for the selected candidate
}

if((cand_no>n||cand_no<0)){ // Check if the candidate number is invalid
printf("Wrong Candidate Number!!"); // Display error message
}
}
int maxVote(struct Candidates* cand_list,int n){ // Function to find the candidate with the most votes
int maxValue = cand_list[0].votes; // Initialize maximum votes to the first candidate's votes
int maxIndex = 0; // Initialize index of the candidate with the most votes to 0

for(int i=0;i<n;i++){ // Loop through each candidate in the list
if(cand_list[i].votes>maxValue){ // Check if the current candidate has more votes
maxValue = cand_list[i].votes; // Update maximum votes
maxIndex = i; // Update index of the candidate with the most votes
}
}
return(maxIndex+1); // Return the index of the candidate with the most votes (plus 1 to account for array indexing starting from 0)
}


void result(struct Candidates* cand_list,int n){ // Function to display the election result
int winnerIndex=maxVote(cand_list,n); // Get the index of the candidate with the most votes
printf("\nWINNER :"); // Display the winner message
for(int j =0;cand_list[winnerIndex-1].name[j]!='\n';j++){ // Loop through each character in the winner's name
printf("%c",cand_list[winnerIndex-1].name[j]); // Display the character
}
printf("\n"); // Add a newline character
}
