package littleGo;

import java.awt.Button;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CurrentStone extends Button{
	private static final long serialVersionUID = 1L;
	final static private int BLACK = 1;
	final static private int WHITE = 2;
	
	public CurrentStone(){
		setForeground( Color.WHITE);
		setBackground( Color.BLACK);
		addActionListener( new ButtonListener());
	}
	
	private void setBlack(){
		setForeground( Color.WHITE);
		setBackground( Color.BLACK);
	}
	
	public void resetIt(){
		if( Stone.getNext() == WHITE){
			setBlack();
			Stone.setNext( BLACK);
		}
	}
	
	private void setWhite(){
		setForeground( Color.BLACK);
		setBackground( Color.WHITE);
	}
	
	public void setTo(){
		if( Stone.getNext() == WHITE){
			setWhite();	
		}else{
			setBlack();
		}
	}
	
	public void setLastTo( int nextOne){
		if( nextOne == WHITE)
			setWhite();
		else
			setBlack();
	}
	
	public void setStone(){
			if( Stone.getNext() == BLACK){
				setWhite();
				Stone.setNext( WHITE);	
			}else{
				setBlack();
				Stone.setNext( BLACK);
			}
	}

	private class ButtonListener implements ActionListener{
		public void actionPerformed(ActionEvent arg0) {
			setStone();
		}
	}
}
