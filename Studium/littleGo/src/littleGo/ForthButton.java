package littleGo;

import java.awt.Button;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ForthButton extends Button{
	private static final long serialVersionUID = 1L;
	static private ForthButton theButton;

	public ForthButton(){
		theButton = this;
		setBackground( Color.LIGHT_GRAY);
		setForeground(Color.BLACK);
		setLabel( "forth");
		addActionListener( new ButtonListener());
	}
	
	static public ForthButton getButton(){
		return theButton;
	}

	public void setForth(){
		BackButton.getButton().setEnabled(true);
		PlayedStones.getPlayedStones().getNextStone();
		if( !PlayedStones.getPlayedStones().hasAfter()){
			ForthButton.getButton().setEnabled( false);
			BackButton.getButton().setActive();
			Window.getWindow().activeField();
		}
	}
	
	private class ButtonListener implements ActionListener{
		public void actionPerformed(ActionEvent arg0) {
			setForth();
		}
	}
}
