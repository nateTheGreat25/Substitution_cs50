#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int indexOfAlpha (char letter_to_index);

#define MAX_INPUT_SIZE 4096

char alpha_lower[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char alpha_upper[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int main (int argc, char *argv[]) {
    char cipher[50];
    //char text_to_cipher[50];

    if (argc > 1) {
        strncpy(cipher, argv[1], sizeof(cipher) - 1);
        cipher[sizeof(cipher) - 1] = '\0';
        printf("Your Cipher is: %s\n", cipher);
    }else {
        fprintf(stderr, "error reading Cipher.\n");
        return 1;
    }

    char* text_to_cipher = (char*)malloc(MAX_INPUT_SIZE * sizeof(char));
    if (text_to_cipher == NULL){
        perror("Memory Allocation failed!!");
        return 1;
    }

    printf("Enter the text you would like to cipher\n");

    if(fgets(text_to_cipher, MAX_INPUT_SIZE, stdin) != NULL){
        text_to_cipher[strcspn(text_to_cipher, "\n")] = '\0';

        printf("The text you entered to cipher is: %s\n", text_to_cipher);
    }else {
        perror("Error reading text to cipher");
        free(text_to_cipher);
        return 1;
    }
// to test index function
    //char x ='z';
   // int test = indexOfAlpha(x);

    //printf("this number is %d\n", test);

    char ciphered_text[200];
    int i = 0;
    while (text_to_cipher[i] != '\0') {
        
        if (isalpha(text_to_cipher[i])){
            int index = indexOfAlpha(text_to_cipher[i]);
            ciphered_text[i] = cipher[index]; 
        }else {
            ciphered_text[i] = text_to_cipher[i];
        }  
        i++;      
    }
    i++;
    ciphered_text[i]= '\0';
    printf("The ciphered text is %s\n", ciphered_text);

    
    
    free(text_to_cipher);
    return 0;
}



int indexOfAlpha (char letter_to_index) {
    int array_index = 0;
    if (isupper(letter_to_index)){ 
        //printf("I ran upper\n");       
        for (int i = 0; i < 26; i++){
            if (letter_to_index == alpha_upper[i])
            {
                array_index = i;
            }          
        }                        
    }else if(islower(letter_to_index)){
         // runs to here
        for (int i = 0; i < 26; i++){
            ///printf("I ran lower\n");
            if (letter_to_index == alpha_lower[i])
            {
                array_index = i;
            }          
        }         
    }    
    return array_index;
}
