package littleGo;

import java.awt.Button;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class EndButton extends Button{
	private static final long serialVersionUID = 1L;
	public EndButton(){
		addActionListener( new ButtonListener());
		setLabel("end");
	}
	
	private class ButtonListener implements ActionListener{
		public void actionPerformed(ActionEvent arg0) {
			Window.getWindow().dispose();
		}
	}
}
