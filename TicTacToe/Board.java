

public class Board
{   
    char[][] game;

    Board()
    {
       game = new char[][]{{' ', ' ', ' '},
                           {' ', ' ', ' '},
                           {' ', ' ', ' '}};
    }

    void theLayout()
    {
        System.out.println("  " + game[0][0] + "| " + game[0][1] + " |" + game[0][2]);
        System.out.println("------------");
        System.out.println("  " + game[1][0] + "| " + game[1][1] + " |" + game[1][2]);
        System.out.println("------------");
        System.out.println("  " + game[2][0] + "| " + game[2][1] + " |" + game[2][2]);

    }
    
    boolean checkTurn ( String position) {
        switch(position) {
            case "1":
                return (game[0][0] == ' ');
            case "2":
                return (game[0][1] == ' ');
            case "3":
                return (game[0][2] == ' ');
            case "4":
                return (game[1][0] == ' ');
            case "5":
                return (game[1][1] == ' ');
            case "6":
                return (game[1][2] == ' ');
            case "7":
                return (game[2][0] == ' ');
            case "8":
                return (game[2][1] == ' ');
            case "9":
                return (game[2][2] == ' ');
            default:
                return false;
        }
    }
    
    void makeTurn( String position, char key) {
		switch(position) {
			case "1":
				game[0][0] = key;
				break;
			case "2":
				game[0][1] = key;
				break;
			case "3":
				game[0][2] = key;
				break;
			case "4":
				game[1][0] = key;
				break;
			case "5":
				game[1][1] = key;
				break;
			case "6":
				game[1][2] = key;
				break;
			case "7":
				game[2][0] = key;
				break;
			case "8":
				game[2][1] = key;
				break;
			case "9":
				game[2][2] = key;
				break;
			default:
				System.out.println("T-T");
		}
	}

    boolean theWin( char key) 
    {
        if ((game[0][0] == key && game [0][1] == key && game [0][2] == key) ||
            (game[1][0] == key && game [1][1] == key && game [1][2] == key) ||
            (game[2][0] == key && game [2][1] == key && game [2][2] == key) ||
            
            (game[0][0] == key && game [1][0] == key && game [2][0] == key) ||
            (game[0][1] == key && game [1][1] == key && game [2][1] == key) ||
            (game[0][2] == key && game [1][2] == key && game [2][2] == key) ||
            
            (game[0][0] == key && game [1][1] == key && game [2][2] == key) ||
            (game[0][2] == key && game [1][1] == key && game [2][0] == key) ) 
            {
            return true;
            }
        return false;
    }
    
    boolean theExit(int player) {
		
        if (theWin( 'X')) {	
            theLayout();
            System.out.println("Player1 won :)");
            return true;
        }
        
        if (theWin( 'O')) {	
            theLayout();
            if (player==2)
            {System.out.println("Player2 won :)");}
            else
            {System.out.println("Computer won :(");}
            return true;
        }
        
        for (int i = 0; i < game.length; i++) {
            for (int j = 0; j < game[i].length; j++) {
                if (game[i][j] == ' ') {
                    return false;
                }
            }
        }
        theLayout();
        System.out.println(" It's a Draw :-| ");
        return true;
    }
    
}
