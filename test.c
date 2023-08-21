#include <stdio.h>
#include <stdlib.h>


int NFA[100][100] = {-1};
int stateCount, symCount;
char input[256];
char symbols[256];
int finalStates[100], finStateCount;


int symbolIndex(char c) {
	for(int i=0; i<symCount; i++) {
		if(symbols[i] == c) {
			return i;
		}
	}

	return -1;
}

int isFinalState(int index) {
	for(int i=0; i<finStateCount; i++) {
		if(index == finalStates[i]) {
			return 1;
		}
	}

	return -1;
}

int main() {
	printf("Enter number of states: ");
	scanf("%d", &stateCount);

	printf("Enter number of alphabets: ");
	scanf("%d", &symCount);

	printf("Enter Symbols: \n");
	for(int i=0; i<symCount; i++) {
		scanf(" %c", &symbols[i]);
	}

	printf("Enter State info\n");

	for(int i=0; i<stateCount; i++) {
		for(int j=0; j<symCount; j++) {
			scanf("%d", &NFA[i][j]);
		}
	}

	printf("Enter number of final states: ");
	scanf("%d", &finStateCount);
	printf("Enter final state indexes: ");
	for(int i=0; i<finStateCount; i++) {
		scanf("%d", &finalStates[i]);
	}

	printf("Enter an input string: ");
	scanf("%s", input);

	for(int i=0 ; input[i]!='\0'; i++) {
		if(symbolIndex(input[i]) == -1) {
			printf("UNKNOWN SYMBOL: %c", input[i]);
			exit(0);
		}
		printf("%c", input[i]);
	}
	printf("\n");

	int currState = 0;

	for(int i=0; input[i]; i++) {
		printf("Current State: %d\n", currState);
		int symIndex = symbolIndex(input[i]);

		int nextState = NFA[currState][symIndex];
		if(nextState == -1) {
			printf("No transition found for state %d for symbol index %d for symbol %c\n", currState, symIndex, input[i]);
			exit(0);
		}
		currState = nextState;
	}

	if(isFinalState(currState)) {
		printf("Input accepted\n");
	} else {
		printf("Input rejected");
	}

	return 0;
}











