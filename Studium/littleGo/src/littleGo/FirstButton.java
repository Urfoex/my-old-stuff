package littleGo;

import java.awt.Button;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class FirstButton extends Button{
	private static final long serialVersionUID = 1L;
	public FirstButton(){
		setLabel( "first");
		setForeground( Color.BLACK);
		setBackground( Color.LIGHT_GRAY);
		addActionListener( new ButtonListener());
	}
	
	public void setFirst(){
		while( PlayedStones.getPlayedStones().hasBefore())
			BackButton.getButton().setBack();
	}
	
	private class ButtonListener implements ActionListener{
		public void actionPerformed(ActionEvent arg0) {
			setFirst();
		}
	}
}
