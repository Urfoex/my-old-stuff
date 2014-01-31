package littleGo;

import java.io.Serializable;
import java.util.LinkedList;

public class PlayedStones implements Serializable{
	private static final long serialVersionUID = 1L;
	private LinkedList<ColorStonePair> stones;
	private LinkedList<ColorStonePair> stonesBefore;
	private LinkedList<ColorStonePair> stonesAfter;
	static private PlayedStones lastList; 
	private Stone[] theStones;
	
	public PlayedStones(){
		stones = new LinkedList<ColorStonePair>();
		stonesBefore = new LinkedList<ColorStonePair>();
		stonesAfter = new LinkedList<ColorStonePair>();
		
		lastList = this;
	}
	
	public void setStones( Stone[] stones) {
		theStones = stones;
	}
	
	public Stone[] getStones(){
		return theStones;
	}
	
	public void addStone( Stone stone){
		ColorStonePair aPair = new ColorStonePair( stone.getStoneNumber(), new Integer( stone.getColor()));
		stones.addLast( aPair);
		stonesBefore.addLast( aPair);
	}
	
	static public void setLastList( PlayedStones list){
		lastList = list;
	}
	
	public boolean hasAfter(){
		return !stonesAfter.isEmpty();
	}
	
	public boolean hasBefore(){
		return !stonesBefore.isEmpty();
	}
	
	public Stone getLastStone(){
		ColorStonePair stone = stonesBefore.removeLast();
		int color = theStones[ stone.getStone()].getColor();
		theStones[ stone.getStone()].setToStatus( stone.getColor());
		stone.setColor( color);
		stonesAfter.addFirst( stone);
		return theStones[ stone.getStone()];
	}
	
	public Stone getNextStone(){
		ColorStonePair stone = stonesAfter.removeFirst();
		int color = theStones[ stone.getStone()].getColor();
		theStones[ stone.getStone()].setToStatus( stone.getColor());
		stone.setColor( color);
		stonesBefore.addLast( stone);
		return theStones[ stone.getStone()];
	}
	
	public void newList(){
		stones.clear();
		stonesAfter.clear();
		stonesBefore.clear();
	}
	
	static public PlayedStones getPlayedStones(){
		return lastList;
	}
	
	private class ColorStonePair implements Serializable{
		private static final long serialVersionUID = 1L;
		private int theStone;
		private int theColor;
		public ColorStonePair( int stone, int Color){
			theStone = stone;
			theColor = Color;
		}
		
		public int getStone(){
			return theStone;
		}
		
		public int getColor(){
			return theColor;
		}
		
		public void setColor( int COLOR){
			theColor = COLOR;
		}
	}
}
