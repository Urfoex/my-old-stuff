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
import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;

public class LoadButton extends Button{
	private static final long serialVersionUID = 1L;
	
	public LoadButton(){
		setBackground( Color.RED);
		setForeground(Color.BLACK);
		setLabel( "load");
		addActionListener( new ButtonListener());
	}
	
	private class ButtonListener implements ActionListener{
		public void actionPerformed(ActionEvent arg0) {
			new LoadWindow();
		}
	}
	
	private class LoadWindow extends Frame{
		private static final long serialVersionUID = 1L;
		private TextField toLoad;
		public LoadWindow(){
			setTitle( "-load- littleGo");
			setSize( 160, 50);
			setResizable( false);
			addWindowListener( new WindowListener());
			
			setLayout( new GridLayout(1,2));
			toLoad = new TextField();
			add( toLoad);
			add( new littleLoad());
			
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
		
		private class littleLoad extends Button{
			private static final long serialVersionUID = 1L;
			public littleLoad(){
				setLabel("load");
				setEnabled( true);
				setForeground( Color.BLACK);
				setBackground( Color.WHITE);
				addActionListener( new ButtonListener());
			}
			
			private class ButtonListener implements ActionListener{
				public void actionPerformed(ActionEvent arg0) {
					if( toLoad.getText().length() > 0){
						try{
							FileInputStream FOS = new FileInputStream(toLoad.getText());
							ObjectInputStream OIS = new ObjectInputStream( FOS);
							
							SaveLoadObject SLO = new SaveLoadObject();
							SLO = (SaveLoadObject) OIS.readObject();
							OIS.close();
							
							Window.getWindow().resetIt();
							Window.getWindow().setPointsBlack( SLO.getPointsBlack());
							Window.getWindow().setPointsWhite( SLO.getPointsWhite());
							Stone.setPlayedStones( SLO.getPlayedStones());
							Window.getWindow().setTo( SLO.getNextToPlay());
							

							System.out.println( "File loaded");
							toLoad.setText("loaded");
							littleLoad test = (littleLoad) arg0.getSource();
							test.setEnabled( false);
						}catch( IOException e ){
							System.out.println( "Error: " + e);
						}catch( ClassNotFoundException e){
							System.out.println( "Error: " + e);
						}
					}
				}
			}
		}
		
	}
	
}
