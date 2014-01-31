package littleGo;

import java.awt.Button;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class NewButton extends Button{
	private static final long serialVersionUID = 1L;
	private Stone[] stones;

	public NewButton( Stone[] theStones){
		stones = theStones;
		setBackground( Color.WHITE);
		setForeground(Color.BLACK);
		setLabel( "new");
		addActionListener( new ButtonListener());
	}
	
	private class ButtonListener implements ActionListener{
		public void actionPerformed(ActionEvent arg0) {
			PlayedStones.getPlayedStones().newList();
			Window.getWindow().resetIt();
			for( int i = 0; i < stones.length; ++i){
				stones[i].Reset();
			}
		}
	}
}
