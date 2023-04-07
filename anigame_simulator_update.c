#include<stdio.h>


int Menu(){
 int choice;
 do{
 
 printf("\n0.Attack!");
 printf("\n1.Crit Attack!!!");
 printf("\n2.Increase DEF:");
 printf("\n3.Increase ATK:");
 printf("\n4.Decrease opponent DEF:");
 printf("\n5.Decrease opponent ATK:");
 printf("\n6.Deal DMG:");
 printf("\n7.Trigger Surge/Blood thirster effect:");
 printf("\n8.Heal:\n");
 scanf("%d",&choice);
 if (choice < 0 || choice > 8) {
            printf("Invalid choice. Please choose again.\n");
        }
}while(choice<0 || choice>8);
 return(choice);
}

int main(){
	int player_current_atk,raid_current_atk;
	int player_current_hp,raid_current_hp;
	int choice;
	int ele_mul;
	int temp;
	int player_atk, player_def, player_hp;
	int raid_atk, raid_def, raid_hp;
	double raid_heal,damage,player_heal;
	 // Get input for player's stats
    printf("Player's stats:\n");
    printf("ATK: ");
    scanf("%d", &player_atk);
    printf("DEF: ");
    scanf("%d", &player_def);
    printf("HP: ");
    scanf("%d", &player_hp);
	player_heal=0;
	raid_heal=0;

    // Get input for raid's stats
    printf("RAID's stats:\n");
    printf("ATK: ");
    scanf("%d", &raid_atk);
    printf("DEF: ");
    scanf("%d", &raid_def);
    printf("HP: ");
    scanf("%d", &raid_hp);
    
    printf("Enter element multipliers (same element + 0.5): ");
    scanf("%d",&ele_mul);
    //Asign some variables to temporary variables
    player_hp= player_hp*10;
    raid_hp=raid_hp*10;
    player_current_hp= player_hp;
    raid_current_hp= raid_hp;
    raid_current_atk=raid_atk;
    player_current_atk=player_atk;
    
    //Game loop
    while (player_current_hp > 0 && raid_current_hp > 0){
    	printf("\nRaid has faster speed! It goes first!");
    	//raid turn
    	do{
    	choice=Menu();
    		switch(choice){
    			case 0: //normal attack
    				damage=(((raid_atk*100*raid_current_atk)+638000)/(8.7*player_def*10))*(1-(ele_mul/6));
    				player_current_hp= player_current_hp-damage;
    				raid_current_hp=raid_current_hp+damage*raid_heal;
    				printf("\nThe Raid deals %.0lf to the player and heals %.0lf.",damage,damage*raid_heal);
					printf("\nPlayer's HP remaining: \n%d / %d\nRaid's HP remaining: \n%d / %d\n",player_current_hp,player_hp,raid_current_hp,raid_hp);
    				break;
    			case 1: //crit attack
    				damage=(((raid_atk*100*raid_current_atk)+638000)/(8.7*player_def*10))*(1-(ele_mul/6));
    				player_current_hp= player_current_hp-(damage*1.85);
    				raid_current_hp=raid_current_hp+damage*raid_heal*1.85;
    				printf("\nThe Raid deals %.0lf to the player (CRITICAL HIT!) and heals %.0lf.",damage*1.85,damage*raid_heal*1.85);
    				printf("\nPlayer's HP remaining: %d / %d\nRaid's HP remaining: \n%d / %d\n",player_current_hp,player_hp,raid_current_hp,raid_hp);
    				break;
    			case 2: //increase raid's DEF
    				printf("\nEnter amount of DEF increase (in percentage): ");
    				scanf("%d",&temp);
    				raid_def=raid_def+raid_def*(temp/100);
    				printf("The Raid's DEF has increased by %d%%.%d",temp,raid_def);
    				break;
    			case 3://increase raid's ATK
    				printf("\nEnter amount of ATK increase (in percentage): ");
    				scanf("%d",&temp);
    				raid_current_atk=raid_current_atk+raid_current_atk*(temp/100);
    				printf("The Raid's ATK has increased by %d%%.",temp);
    				break;
    			case 4://decrease player's DEF
    				printf("\nEnter amount of DEF decrease (in percentage): ");
    				scanf("%d",&temp);
    				player_def=player_def-player_def*(temp/100);
    				printf("Player's DEF has decreased by %d%%.",temp);
    				break;
    			case 5://decrease player's ATK
    				printf("\nEnter amount of ATK decrease (in percentage): ");
    				scanf("%d",&temp);
    				player_current_atk=player_current_atk-player_current_atk*(temp/100);
    				printf("Player's DEF has decreased by %d%%.",temp);
    				break;
    			case 6://deal dmg to player (by some talents)
    				printf("Enter amount of HP: ");
    				scanf("%d",&temp);
    				player_current_hp=player_current_hp-temp;
    				printf("The RAID has deal %d DMG to player. Player's HP remaining: %d / %d",temp,player_current_hp,player_hp);
    				break;
    			case 7://Trigger Surge/Blood thirster effect
    			printf("Enter the LIFESTEAL increase: ");
    			scanf("%lf",&raid_heal);
    				break;
    			case 8://heal
    			printf("Enter number of HP: ");
    			scanf("%d",&temp);
    			raid_current_hp=raid_current_hp+temp;
    			if(raid_current_hp>raid_hp) raid_current_hp=raid_hp;
    			printf("The Raid has gained %d HP. Raid's HP remaining: %d / %d",temp,raid_current_hp,raid_hp);
    				break;
		}
		if (player_current_hp < 0 || raid_current_hp < 0) break;
		}while(choice>1);
		
    	printf("Player strikes back fiercely");
    	do{
    	choice=Menu();
    		switch(choice){
    			case 0: //normal attack
    				damage=(((player_atk*100*player_current_atk)+638000)/(8.7*raid_def*10))*(1+(ele_mul/6));
    				raid_current_hp= raid_current_hp-damage;
    				player_current_hp=player_current_hp+damage*player_heal;
    				printf("\nPlayer deals %.0lf to Raid boss and heals %.0lf.",damage,damage*player_heal);
					printf("\nRaid's HP remaining: \n%d / %d\nPlayer's HP remaining: \n%d / %d\n",raid_current_hp,raid_hp,player_current_hp,player_hp);
    				break;
    			case 1: //crit attack
    				damage=(((player_atk*100*player_current_atk)+638000)/(8.7*raid_def*10))*(1+(ele_mul/6));
    				raid_current_hp= raid_current_hp-(damage*1.85);
    				player_current_hp=player_current_hp+damage*player_heal*1.85;
    				printf("\nPlayer deals %.0lf to Raid boss (CRITICAL HIT!) and heals %.0lf.",damage*1.85,damage*player_heal*1.85);
    				printf("\nRaid's HP remaining: %d / %d\nPlayer's HP remaining: \n%d / %d\n",raid_current_hp,raid_hp,player_current_hp,player_hp);
    				break;
    			case 2: //increase player's DEF
    				printf("\nEnter amount of DEF increase (in percentage): ");
    				scanf("%d",&temp);
    				player_def=player_def+player_def*(temp/100);
    				printf("Player's DEF has increased by %d%%.%d",temp,player_def);
    				break;
    			case 3://increase player's ATK
    				printf("\nEnter amount of ATK increase (in percentage): ");
    				scanf("%d",&temp);
    				player_current_atk=player_current_atk+player_current_atk*(temp/100);
    				printf("Player's ATK has increased by %d%%.",temp);
    				break;
    			case 4://decrease raid's DEF
    				printf("\nEnter amount of DEF decrease (in percentage): ");
    				scanf("%d",&temp);
    				raid_def=raid_def-raid_def*(temp/100);
    				printf("The Raid's DEF has decreased by %d%%.",temp);
    				break;
    			case 5://decrease raid's ATK
    				printf("\nEnter amount of ATK decrease (in percentage): ");
    				scanf("%d",&temp);
    				raid_current_atk=raid_current_atk-raid_current_atk*(temp/100);
    				printf("The Raid's DEF has decreased by %d%%.",temp);
    				break;
    			case 6://deal dmg to raid (by some talents)
    				printf("Enter amount of HP: ");
    				scanf("%d",&temp);
    				raid_current_hp=raid_current_hp-temp;
    				printf("Player has deal %d DMG to Raid boss. Raid's HP remaining: %d / %d",temp,raid_current_hp,raid_hp);
    				break;
    			case 7://Trigger Surge/Blood thirster effect
    			printf("Enter the LIFESTEAL increase: ");
    			scanf("%lf",&player_heal);
    				break;
    			case 8://heal
    			printf("Enter number of HP: ");
    			scanf("%d",&temp);
    			player_current_hp=player_current_hp+temp;
    			if(player_current_hp>player_hp) player_current_hp=player_hp;
    			printf("Player has gained %d HP. Player's HP remaining: %d / %d",temp,player_current_hp,player_hp);
    				break;
		}
		if (player_current_hp < 0 || raid_current_hp < 0) break;
		
		}while(choice>1);
    	
    
    
    
    
	}
    
    
    

}