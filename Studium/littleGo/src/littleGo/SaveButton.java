package littleGo;

import java.awt.Button;
import java.awt.Color;
import java.awt.Frame;
import java.awt.GridLayout;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

public class SaveButton extends Button{
	private static final long serialVersionUID = 1L;
	
	public SaveButton(){
		setBackground( Color.GREEN);
		setForeground(Color.BLACK);
		setLabel( "save");
		addActionListener( new ButtonListener());
	}
	
	private class ButtonListener implements ActionListener{
		public void actionPerformed(ActionEvent arg0) {
			new SaveWindow();
		}
	}
	
	private class SaveWindow extends Frame{
		private static final long serialVersionUID = 1L;
		private TextField toSave;
		public SaveWindow(){
			setTitle( "-save- littleGo");
			setSize( 160, 50);
			setResizable( false);
			addWindowListener( new WindowListener());
			
			setLayout( new GridLayout(1,2));
			toSave = new TextField();
			add( toSave);
			add( new littleSave());
			
			setVisible( true);
		}
		
		public class WindowListener extends WindowAdapter{
			public void windowClosing( WindowEvent e){
				e.getWindow().dispose();
			}
			public void windowLostFocus(WindowEvent e){
				e.getWindow().dispose();
			}
			public void windowDeactivated(WindowEvent e){
				e.getWindow().dispose();
			}
		};
		
		private class littleSave extends Button{
			private static final long serialVersionUID = 1L;
			public littleSave(){
				setLabel("save");
				setEnabled( true);
				setForeground( Color.BLACK);
				setBackground( Color.WHITE);
				addActionListener( new ButtonListener());
			}
			
			private class ButtonListener implements ActionListener{
				public void actionPerformed(ActionEvent arg0) {
					if( toSave.getText().length() > 0){
						try{
							FileOutputStream FOS = new FileOutputStream(toSave.getText());
							ObjectOutputStream OOS = new ObjectOutputStream( FOS);
							SaveLoadObject SLO = new SaveLoadObject();
							SLO.setIt( PlayedStones.getPlayedStones(),
										Window.getWindow().getPointsBlack(),
										Window.getWindow().getPointsWhite(),
										Stone.getNext());
							OOS.writeObject( SLO);
							
							OOS.close();
							System.out.println( "File written");
							toSave.setText("saved");
							littleSave test = (littleSave) arg0.getSource();
							test.setEnabled( false);
						}catch( IOException e){
							System.out.println( "Error: " + e);
						}
					}
				}
			}
		}
	}
}
