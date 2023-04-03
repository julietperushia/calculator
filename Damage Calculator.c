#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//if you want to run this code please download Dev C or VST. Or just go to https://www.programiz.com/c-programming/online-compiler/ to run the code


int Menu() {
    int choice = -1;
    do {
    	printf("\n");
        printf("\n1. Normal damage calculator ");
        printf("\n2. Overload damage calculator: ");
        printf("\n3. ATK Trick damage caculator");
        printf("\n4. Def Trick damage calculator ");
        printf("\n5. Injection damage calculator ");
        printf("\n6. Def Breaker damage calculator ");
        printf("\n7. Help");
        printf("\n0. Exit");
        printf("\nPlease choose (1-7 or 0): ");
        scanf("%d", &choice);
        if (choice < 0 || choice > 7) {
            printf("Invalid choice. Please choose again.\n");
        }
    } while (choice < 0 || choice > 7);
    return choice;
}
int main(){
	int choice;
	double your_atk, your_def,raid_atk,raid_def,damage,crit_damage,ovl_atk,diff,raid_atk_trick,your_atk_trick,raid_def_trick,your_def_trick;
	double ele_mul,your_def_break;
	char rarity;
	do{
	
	choice = Menu();
	switch (choice) {
		case 1:
			printf("Enter raid boss's ATK: ");
			scanf ("%lf",&raid_atk);
			printf("Enter your DEF: ");
			scanf ("%lf",&your_def);
			printf("Enter element multipliers (same element +0.5): ");
			scanf ("%lf",&ele_mul);
			damage=(((raid_atk*100*raid_atk)+638000)/(8.7*your_def*10))*(1-(ele_mul/6));
			printf("\nThe RAID BOSS will deal %.lf damage (%.lf damage if crit)",damage,damage*1.85);
			
			break;
		case 2:
		    printf("Enter raid boss's ATK: ");
		    scanf ("%lf",&raid_atk);
		    printf("Enter your DEF: ");
		    scanf ("%lf",&your_def);
		    printf("Enter element multipliers (same element +0.5): ");
		    scanf ("%lf",&ele_mul);
		    do {
		        printf("Enter Raid boss's rarity (c,uc,r,sr,ur): ");
		        scanf(" %c", &rarity); // Note the space before %c to consume the newline character left in the buffer
		        switch (rarity) {
		            case 'uc':
		                ovl_atk=raid_atk*1.77;
		                break;
		            case 'c':
		                ovl_atk=raid_atk*1.66;
		                break;
		            case 'r':
		                ovl_atk=raid_atk*1.88;
		                break;
		            case 'sr':
		                ovl_atk=raid_atk*1.99;
		                break;
		            case 'ur':
		                ovl_atk=raid_atk*2.1;
		                break;
		            default:
		                printf("Invalid rarity. Please enter uc, c, r, sr, or ur.\n");
		                continue; // Continue the loop to prompt the user again
		        }
		        break; // Break out of the loop if a valid rarity is entered
		    } while (1);
		    damage=(((ovl_atk*100*raid_atk)+638000)/(87*your_def))*(1-(ele_mul/6));
		    printf("\nThe RAID BOSS will deal %.lf damage (%.lf damage if crit)",damage,damage*1.85);
		    break;
		case 3:
			printf("Enter your ATK: ");
		    scanf ("%lf",&your_atk);
		    printf("Enter your DEF: ");
		    scanf ("%lf",&your_def);
			printf("Enter raid boss's ATK: ");
		    scanf ("%lf",&raid_atk);
		    printf("Enter raid boss's DEF: ");
		    scanf ("%lf",&raid_def);
		    printf("Enter element multipliers (same element +0.5): ");
		    scanf ("%lf",&ele_mul);
		    printf("Enter Raid boss's rarity (c,uc,r,sr,ur): ");
		    scanf(" %c", &rarity);
		    do {
		        printf("Enter Raid boss's rarity (c,uc,r,sr,ur): ");
		        scanf(" %c", &rarity); // Note the space before %c to consume the newline character left in the buffer
		        switch (rarity) {
		            case 'c':
		            	diff = raid_atk-your_atk;
		                raid_atk_trick = raid_atk-(diff*0.72);
		                your_atk_trick = your_atk+(diff*0.72);
		                break;
		            case 'uc':
		                diff = raid_atk-your_atk;
		                raid_atk_trick= raid_atk-(diff*0.84);
		                your_atk_trick= your_atk+(diff*0.84);
		                break;
		            case 'r':
		                diff = raid_atk-your_atk;
		                raid_atk_trick= raid_atk-(diff*0.96);
		                your_atk_trick= your_atk+(diff*0.96);
		                break;
		            case 'sr':
		                diff = raid_atk-your_atk;
		                raid_atk_trick= raid_atk-(diff*1.08);
		                your_atk_trick= your_atk+(diff*1.08);
		                break;
		            case 'ur':
		                diff = raid_atk-your_atk;
		                raid_atk_trick= raid_atk-(diff*1.2);
		                your_atk_trick= your_atk+(diff*1.2);
		                break;
		            default:
		                printf("Invalid rarity. Please enter uc, c, r, sr, or ur.\n");
		                continue; // Continue the loop to prompt the user again
		        }
		        break; // Break out of the loop if a valid rarity is entered
		    	} while (1);
				damage=(((raid_atk_trick*100*raid_atk)+638000)/(87*your_def))*(1-(ele_mul/6));
		    	printf("\nThe RAID BOSS will deal %.lf damage (%.lf damage if crit)",damage,damage*1.85);
		    	damage=(((your_atk_trick*100*your_atk)+638000)/(87*raid_def))*(1+(ele_mul/6));
		    	printf("\nYou will deal %.lf damage (%.lf damage if crit).",damage,damage*1.85);
			break;	
		case 4:
			printf("Not done yet xD:");
			printf("Enter your ATK: ");
		    scanf ("%lf",&your_atk);
		    printf("Enter your DEF: ");
		    scanf ("%lf",&your_def);
			printf("Enter raid boss's ATK: ");
		    scanf ("%lf",&raid_atk);
		    printf("Enter raid boss's DEF: ");
		    scanf ("%lf",&raid_def);
		    printf("Enter element multipliers (same element +0.5): ");
		    scanf ("%lf",&ele_mul);
		    printf("Enter Raid boss's rarity (c,uc,r,sr,ur): ");
		    scanf(" %c", &rarity);
		    do {
		        printf("Enter Raid boss's rarity (c,uc,r,sr,ur): ");
		        scanf(" %c", &rarity); // Note the space before %c to consume the newline character left in the buffer
		        switch (rarity) {
		            case 'c':
		            	diff = raid_def-your_def;
		                raid_def_trick = raid_def-(diff*0.72);
		                your_def_trick = your_def+(diff*0.72);
		                break;
		            case 'uc':
		            	diff = raid_def-your_def;
		                raid_def_trick= raid_def-(diff*0.84);
		                your_def_trick= your_def+(diff*0.84);
		                break;
		            case 'r':
		               	diff = raid_def-your_def;
		                raid_def_trick= raid_def-(diff*0.96);
		                your_def_trick= your_def+(diff*0.96);
		                break;
		            case 'sr':
		                diff = raid_def-your_def;
		                raid_def_trick= raid_def-(diff*1.08);
		                your_def_trick= your_def+(diff*1.08);
		                break;
		            case 'ur':
		                diff = raid_def-your_def;
		                raid_def_trick= raid_def-(diff*1.2);
		                your_def_trick= your_def+(diff*1.2);
		                break;
		            default:
		                printf("Invalid rarity. Please enter uc, c, r, sr, or ur.\n");
		                continue; // Continue the loop to prompt the user again
		        }
		        break; // Break out of the loop if a valid rarity is entered
		    	} while (1);
				damage=(((raid_atk*100*raid_atk)+638000)/(87*your_def_trick))*(1-(ele_mul/6));
		    	printf("\nThe RAID BOSS will deal %.lf damage (%.lf damage if crit)",damage,damage*1.85);
		    	damage=(((your_atk*100*your_atk)+638000)/(87*raid_def_trick))*(1+(ele_mul/6));
		    	printf("\nYou will deal %.lf damage (%.lf damage if crit).",damage,damage*1.85);
			break;	
		case 5:
			printf("Not done yet or never xD");
			break;
		case 6:
			printf("Enter raid boss's ATK: ");
			scanf ("%lf",&raid_atk);
			printf("Enter your DEF: ");
			scanf ("%lf",&your_def);
			printf("Enter element multipliers (same element +0.5): ");
			scanf ("%lf",&ele_mul);
			do {
		        printf("Enter Raid boss's rarity (c,uc,r,sr,ur): ");
		        scanf(" %c", &rarity); // Note the space before %c to consume the newline character left in the buffer
		        switch (rarity) {
		            case 'c':
		            	your_def=your_def*0.76;
		                break;
		            case 'uc':
		            	your_def=your_def*0.72;
		                break;
		            case 'r':
		               	your_def=your_def*0.68;
		                break;
		            case 'sr':
		                your_def=your_def*0.64;
		                break;
		            case 'ur':
		                your_def=your_def*0.6;
		                break;
		            default:
		                printf("Invalid rarity. Please enter uc, c, r, sr, or ur.\n");
		                continue; // Continue the loop to prompt the user again
		        }
		        break; // Break out of the loop if a valid rarity is entered
		    	} while (1);
				damage = (((raid_atk / your_def) * (raid_atk / 0.29) + (22000 / your_def)) / 3) * (1 + (ele_mul / 6));

				printf("\nYou will deal %.lf damage (%.lf damage if crit).\nThe damage in this case may have a slight difference from the actual one.",damage,damage*1.85);
			break;
		case 7:
			printf("Element multipliers: Counter element +1, uncounter element +1, same element +0.5\nFor example you are going to deal with an electric boss.\nIf you use 3 ground cards, the ele_mul is (1+1+1)=3.\nIf you use 2 ground cards, the ele_mul is (1+1)=2.\nIf you use 2 ground cards and 1 electric card, the ele_mul is (1+1+0.5)=2.5.\nIf you use 1 ground cards,1 electric card, 1 water card, the ele_mul is (1+0.5-1)=0.5.");
			break;
		case 0:
			printf("The program has been terminated since you typed 0");
			break;
		default:
			printf("Invalid choice. Please choose again.\n");
			break;
	}
} while (choice != 0);
}
