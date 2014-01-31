package littleGo;

import java.awt.*;
import java.awt.event.*;

public class Window extends Frame{
	private static final long serialVersionUID = 1L;
	private TextField pointsBlack;
	private TextField pointsWhite;
	static private Window lastActive;
	private BackButton backButton;
	private ForthButton forthButton;
	private CurrentStone nextStone;
	private Stone[] stones;
	
	public Window(){
		lastActive = this;
		setTitle( "littleGo");
		setSize( 606, 450);
		setResizable( false);
		addWindowListener( new WindowListener());
		
		setLayout( new GridLayout(19,20));
		nextStone = new CurrentStone();
		Stone.setCurrentStone( nextStone);
		Stone.setPlayedStones( new PlayedStones());
		
		stones = new Stone[361];
		for( int x = 0; x < 361; ++x){
			stones[x] = new Stone();
			add( stones[x],x );
		}
		
		PlayedStones.getPlayedStones().setStones( stones);

		pointsBlack = new TextField( "0");
		pointsWhite = new TextField( "0");
		backButton = new BackButton();
		forthButton = new ForthButton();
		backButton.setEnabled( false);
		forthButton.setEnabled( false);
		
		add( new Label( "score", Label.CENTER),19);
		add( new Label( "black", Label.CENTER),39);
		add( pointsBlack,59);
		
		add( new Label( "score", Label.CENTER),79);
		add( new Label( "white", Label.CENTER),99);
		add( pointsWhite,119);
		
		add( new Label( "next", Label.CENTER),139);
		add( new Label( "stone", Label.CENTER),159);
		add( nextStone,179);
		
		add( new Label(), 199);
		add( new FirstButton(), 219);
		add ( backButton, 239);
		add ( forthButton, 259);
		add( new LastButton(), 279);
		add( new Label(), 299);
		
		add( new NewButton(stones),319);
		add( new LoadButton(),339);
		add( new SaveButton(),359);
		add( new EndButton(), 379);
		
		setVisible( true);
	}
	
	public void deactiveField(){
		for( int i = 0; i < 361; ++i){
			stones[i].setEnabled( false);
		}
	}
	
	public void activeField(){
		for( int i = 0; i < 361; ++i){
			stones[i].setEnabled( true);
		}
	}
	
	public void resetIt(){
		pointsBlack.setText("0");
		pointsWhite.setText("0");
		forthButton.setEnabled( false);
		backButton.setEnabled( false);
		nextStone.resetIt();
		activeField();
	}
	
	public void setTo( int nextOne){
		for( int i = 0; i < 361; ++i){
			stones[i].setToStatus( PlayedStones.getPlayedStones().getStones()[i].getColor());
		}
		PlayedStones.getPlayedStones().setStones( stones);
		nextStone.setLastTo(nextOne);
		Stone.setNext( nextOne);
		if( PlayedStones.getPlayedStones().hasAfter()) 
			ForthButton.getButton().setEnabled( true);
		if( PlayedStones.getPlayedStones().hasBefore())
			BackButton.getButton().setEnabled( true);
	}
	
	public String getPointsBlack(){
		return pointsBlack.getText();
	}
	
	public String getPointsWhite(){
		return pointsWhite.getText();
	}
	
	public void setPointsBlack( String points){
		pointsBlack.setText( points);
	}
	
	public void setPointsWhite( String points){
		pointsWhite.setText( points);
	}
	
	public Stone[] getStones(){
		return stones;
	}
	
	public void setStone( int number, int color){
		stones[number].setToStatus( color);
	}
	
	static public Window getWindow() {
		return lastActive;
	}
	
	public CurrentStone getNextStone(){
		return nextStone;
	}
	
	public class WindowListener extends WindowAdapter{
		public void windowClosing( WindowEvent e){
			e.getWindow().dispose();
			System.exit( 0);
		}
		
		public void windowGainedFocus(WindowEvent e){
			lastActive = (Window) e.getWindow();
			
		}
	};
}
