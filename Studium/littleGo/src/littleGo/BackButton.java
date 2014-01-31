package littleGo;

import java.awt.Button;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class BackButton extends Button{
	private static final long serialVersionUID = 1L;
	static private BackButton theButton;
	private boolean deactivated;
	
	public BackButton(){
		deactivated = false;
		theButton = this;
		setBackground( Color.LIGHT_GRAY);
		setForeground(Color.BLACK);
		setLabel( "back");
		addActionListener( new ButtonListener());
	}
	
	static public BackButton getButton(){
		return theButton;
	}
	
	public void setActive(){
		deactivated = false;
	}
	
	public void setBack(){
		ForthButton.getButton().setEnabled( true);
		PlayedStones.getPlayedStones().getLastStone();
		if( !deactivated ){ 
			Window.getWindow().deactiveField();
			deactivated = true;
		}
		if( !PlayedStones.getPlayedStones().hasBefore()){
			BackButton.getButton().setEnabled( false);
		}
	}
	
	private class ButtonListener implements ActionListener{
		public void actionPerformed(ActionEvent arg0) {
			setBack();
		}
	}
}
