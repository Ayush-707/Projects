import java.util.Scanner;
import java.util.Random;

public class TicTacToe
{    
     Scanner scanner;
     Board board;
     private TicTacToe ()
     {  
        board = new Board();
        scanner = new Scanner(System.in);
      }
     private void run (){
       board.theLayout();
        System.out.println("Number of players: 1 or 2 ? ");
        Scanner version = new Scanner(System.in);
        int player = version.nextInt(); 
        
        while (true)
        {   
            playerTurn(1); 
            if(board.theExit(1))
            break;
            if(player==2)
            board.theLayout();
            

            if(player==2)
            {
                playerTurn(2); 
                if(board.theExit(2))
                {break;}
                board.theLayout(); 
            }
            
            else
            {
            systemTurn();
            if (board.theExit(player))
            {break;}
            board.theLayout();
            }

            
        }
            
        version.close();    
    }
        
      
     public static void main( String args []) 
    {   
        TicTacToe game = new TicTacToe();
        game.run();   
    }

     private void playerTurn(int player)
     {
		String playerData;
		while (true) {
			System.out.println("Player " + player + "- Enter a valid position from 1 to 9 ");
			playerData = scanner.nextLine();
			if (board.checkTurn(playerData))
            {
				break;
			} 
            else 
            {
				System.out.println( "This is not a valid move.");
			}
		}
		board.makeTurn( playerData, (player == 1 ? 'X' : 'O'));
     }
    
     private void systemTurn()
    {
    Random rand = new Random();
    int systemMove;
    while (true) {
        systemMove = rand.nextInt(9) + 1;
        if (board.checkTurn( Integer.toString(systemMove)))
        {
            break;
        }
    }
    board.makeTurn( Integer.toString(systemMove), 'O');
}

    
}