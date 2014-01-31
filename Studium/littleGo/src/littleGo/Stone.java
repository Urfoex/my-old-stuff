package littleGo;

import java.awt.Button;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Stone extends Button{
	private static final long serialVersionUID = 1L;
	final static private int ORANGE = 0;
	final static private int BLACK = 1;
	final static private int WHITE = 2;
	private int status = ORANGE;
	private int number = 1;
	static private int number_current = 1;
	static private int max_number_used = 1;
	static int NEXT = BLACK;
	static private CurrentStone nextStone;
	static private PlayedStones playedStones;
	
	public Stone(){
		number = max_number_used++;
		
		setForeground( Color.ORANGE);
		setBackground( Color.ORANGE);
		addActionListener( new ButtonListener());
	}
	
	public int getStoneNumber(){
		return number-1;
	}
	
	public int getColor(){
		return status;
	}
	
	public void setColor( int COLOR){
		status = COLOR;
	}
	
	static public int getStone(){
		return number_current;
	}
	
	static public void setPlayedStones( PlayedStones stones){
		playedStones = stones;
		PlayedStones.setLastList( stones);
	}
	
	public void Reset(){
		status = ORANGE;
		setForeground( Color.ORANGE);
		setBackground( Color.ORANGE);
	}
	
	private void setBlack(){
		status = BLACK;
		setForeground( Color.BLACK);
		setBackground( Color.BLACK);
	}
	
	private void setWhite(){
		status = WHITE;
		setForeground( Color.WHITE);
		setBackground( Color.WHITE);
	}
	
	static public int getNext(){
		return NEXT;
	}
	
	static public void setNext( int Next){
		NEXT = Next;
	}
	
	static public void setCurrentStone( CurrentStone STONE){
		nextStone = STONE;
	}
	
	public void setToStatus( int STATUS){
		switch( STATUS){
		case ORANGE:	Reset();
						break;
		case BLACK:		setBlack();
						break;
		case WHITE:		setWhite();
						break;
		default:	 	break;
		}
	}
	
	private void setStone(){
		playedStones.addStone( this);
		BackButton.getButton().setEnabled( true);
		if( status != ORANGE)
			Reset();
		else{
			if( NEXT == BLACK){
				setBlack();
				nextStone.setStone();
				NEXT = WHITE;
			}else{
				setWhite();
				nextStone.setStone();
				NEXT = BLACK;
			}
		}
	}
	
	private class ButtonListener implements ActionListener{
		public void actionPerformed(ActionEvent arg0) {
			number_current = number;
			setStone();
		}
	}
}
