package littleGo;

import java.awt.Button;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class LastButton extends Button{
	private static final long serialVersionUID = 1L;

	public LastButton(){
		setLabel( "last");
		setForeground( Color.BLACK);
		setBackground( Color.LIGHT_GRAY);
		addActionListener( new ButtonListener());
	}
	
	public void setLast(){
		while( PlayedStones.getPlayedStones().hasAfter())
			ForthButton.getButton().setForth();
	}
	
	private class ButtonListener implements ActionListener{
		public void actionPerformed(ActionEvent arg0) {
			setLast();
		}
	}
}
