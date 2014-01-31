package belegdrei;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;

public class Katalog_mbellers implements Katalog {
	private class item{
		public int id;
		public int price;
		public item( int id, int price){
			this.id = id;
			this.price = price;
		}
	}

	private class list{
		private list next = null;
		private list previous = null;
		private item entity = null;
		private list master;
		
		public void setMaster( list master){
			this.master = master;
		}
		
		public list( list master){
			this.master = master;
		}
		
		public list( ){
			master = null;
		}
		
		public Katalog_mbellers.item getEntity(){ return entity;};
		
		// Hinweis: benoetigt fuer entsprechend grosse Listen hohe Laufzeit,
		//		da fuer jedes Hinzufuegen neu vom Listenanfang an zu suchen angefangen werden muss
		boolean add( Katalog_mbellers.item temp_entity){
			if( master == null) return false;
			if( master.entity == null){
				master.entity = temp_entity;
				return true;
			}
			list temp_list = master;
			while( temp_list.entity.id < temp_entity.id && temp_list.next != null){
				temp_list = temp_list.next;
			};
			if( temp_list.entity.id == temp_entity.id){
				if( temp_list.entity.price == temp_entity.price)
					return false;
				temp_list.entity.price = temp_entity.price;
				return true;
			}
			if( temp_list.next == null && temp_list.entity.id < temp_entity.id){
				list foo = new list( master);
				foo.entity = temp_entity;
				temp_list.next = foo;
				foo.previous = temp_list;
				return true;
			}
			if( temp_list.previous == null){
				list foo = new list( master);
				foo.entity = temp_list.getEntity();
				temp_list.getEntity().id = temp_entity.id;
				temp_list.getEntity().price = temp_entity.price;
				this.add( foo.getEntity());
				return true;
			}
				
			list foo = new list( master);
			foo.entity = temp_entity;
			foo.next = temp_list;
			foo.previous = temp_list.previous;
			temp_list.previous = foo;
			foo.previous.next = foo;
			return true;
		}
		
		boolean remove( Katalog_mbellers.item temp_entity){
			if( master == null) return false;
			if( master.entity.id == temp_entity.id){
				if( master.next == null){
					master.entity = null;
					return true;
				}
				master.entity = master.next.entity;
				if( master.next.next == null){
					master.next = null;
					return true;
				}
				master.next = master.next.next;
				master.next.previous = master;
				return true;
			}
			list foo = master;
			while( foo.entity.id != temp_entity.id){
				if( foo.next == null) return false;
				foo = foo.next;
			}
			if( foo.next == null){
				foo.previous.next = null;
				return true;
			}
			foo.previous.next = foo.next;
			foo.next.previous = foo.previous;
			return true;
		}
	}
	
	static private  Katalog_mbellers foo;
	private Katalog_mbellers.list Masterlist;
	static private boolean stop = false; 
	
	public Katalog_mbellers(){
		if( !stop){
			stop = true;
			foo = new Katalog_mbellers();
			Masterlist = foo.new list( );
			Masterlist.setMaster( Masterlist);
		}
	}
	
	public boolean importiereTeilkatalog(String datei) {
		boolean result = true;
		long odd = 0;
		
		try{
			InputStream istream = new FileInputStream( datei);
			InputStreamReader inp = new InputStreamReader( istream);
			BufferedReader reader = new BufferedReader( inp);
				
			String  temp_line = "";
			String[] temp_split;
			int id = 0;
			int price = 0;
		
			while( true){
				temp_line = reader.readLine();
				if( temp_line == null) break;
				temp_split = temp_line.split(" ");
				if( temp_split.length != 2 || temp_line.length() < 8 ){
					result = false;
					break;
				}
				if( temp_split[0].length() != 6 && temp_split[1].length() < 1){
					result = false;
					break;
				}
				id = Integer.parseInt( temp_split[0]);
				price = Integer.parseInt( temp_split[1]);
				++odd;
				if( Masterlist.add( foo.new item( id, price)) == false)
					--odd;
			};
			if( odd == 0) result = false;
			reader.close();
		}catch( Exception e){
			System.out.println(" error while trying to open and read " +datei+ " : " +e.getMessage());
			result = false;
			return false;
		}
		return result;
	}

	public void loescheKataloginhalt() {
			while( Masterlist.getEntity() != null)
				Masterlist.remove( Masterlist.getEntity());
	}
	
	// Hinweis: praefix = 0 heisst durchsuchen der gesamten Liste
	public int zeigeDurchschnittspreis(int praefix) {
		if( praefix > 999999 || praefix < 0) return 0;
		if( Masterlist == null || Masterlist.getEntity() == null) return 0;
		int temp_max = praefix + 1;
		long intersection = 0;
		int counter = 0;
		if( praefix == 0){
			praefix = 100000;
			temp_max = 1000000;
		}
		while( praefix < 100000){
			praefix *= 10;
			temp_max *= 10;
		}
		if( temp_max > 1000000) temp_max = 1000000;
		Katalog_mbellers.list temp_list = Masterlist;
		while( temp_list.getEntity().id < praefix){
			if( temp_list.next == null) return 0;
			temp_list = temp_list.next;
		}
		while( temp_list.getEntity().id < temp_max){
			intersection += temp_list.getEntity().price;
			++counter;
			if( temp_list.next == null) break;
			temp_list = temp_list.next;
		}
		if( counter == 0) return 0;
		return (int)( intersection / counter);
	}
	
	// Hinweis: praefix = 0 heisst durchsuchen der gesamten Liste
	// Hinweis: praefix = 0 heisst durchsuchen der gesamten Liste
	public int zeigeMaximalenPreis(int praefix) {
		if( praefix > 999999 || praefix < 0) return 0;
		if( Masterlist == null) return 0;
		if( Masterlist.getEntity() == null) return 0;
		int temp_max = praefix + 1;
		if( praefix == 0){
			praefix = 100000;
			temp_max = 1000000;
		}
		while( praefix < 100000){
			praefix *= 10;
			temp_max *= 10;
		}
		if( temp_max > 1000000) temp_max = 1000000;
		Katalog_mbellers.item temp_item = foo.new item( praefix, 0);
		Katalog_mbellers.list temp_list = Masterlist;
		while( temp_list.getEntity().id < temp_item.id){
			if( temp_list.next == null) return 0;
			temp_list = temp_list.next;
		}
		while( temp_list.getEntity().id < temp_max){
			if(temp_list.getEntity().price > temp_item.price)
				temp_item.price = temp_list.getEntity().price;
			if( temp_list.next == null)
				break;
			temp_list = temp_list.next;
		}
		return temp_item.price;
	}
	
	// Hinweis: praefix = 0 heisst durchsuchen der gesamten Liste
	public int zeigeMinimalenPreis(int praefix) {
		if( praefix > 999999 || praefix < 0) return 0;
		if( Masterlist == null) return 0;
		if( Masterlist.getEntity() == null) return 0;
		int temp_max = praefix + 1;
		if( praefix == 0){
			praefix = 100000;
			temp_max = 1000000;
		}
		while( praefix < 100000){
			praefix *= 10;
			temp_max *= 10;
		}
		if( temp_max > 1000000) temp_max = 1000000;
		Katalog_mbellers.item temp_item = foo.new item( praefix, Integer.MAX_VALUE);
		boolean check = false;
		Katalog_mbellers.list temp_list = Masterlist;
		while( temp_list.getEntity().id < temp_item.id){
			if( temp_list.next == null) return 0;
			temp_list = temp_list.next;
		}
		while( temp_list.getEntity().id < temp_max){
			if( temp_list.getEntity().price < temp_item.price){
				temp_item.price = temp_list.getEntity().price;
				check = true;
			}
			if( temp_list.next== null) 
				break;
			temp_list = temp_list.next;
		}
		if( !check) return 0;
		return temp_item.price;
	}

}
