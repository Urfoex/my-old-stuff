package littleGo;

import java.io.Serializable;

public class SaveLoadObject implements Serializable{
	private static final long serialVersionUID = 1L;
	private PlayedStones stones;
	private String pointsBlack;
	private String pointsWhite;
	private int nextToPlay;
	
	public SaveLoadObject(){
	}
	
	public void setIt( PlayedStones PS, String pB, String pW, int ntp){
		stones = PS;
		pointsBlack = pB;
		pointsWhite = pW;
		nextToPlay = ntp;
	}
	
	public PlayedStones getPlayedStones(){
		return stones;
	}
	
	public String getPointsBlack(){
		return pointsBlack;
	}
	
	public String getPointsWhite(){
		return pointsWhite;
	}
	
	public int getNextToPlay(){
		return nextToPlay;
	}
}
